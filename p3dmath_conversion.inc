{$IFDEF INTERFACE}
function EulerToQuat( Euler: TVec3; Order: TRotationOrder ): TQuaternion;
function QuatToEuler( Q: TQuaternion; OldRotation:TVec3; Order: TRotationOrder ): TVec3;
procedure MatToEuler2( M: TMat3; out Euler1, Euler2: TVec3; Order: TRotationOrder );
function MatToEuler( M: TMat3; OldRot: TVec3; Order: TRotationOrder ): TVec3;

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x: Float; minVal, maxVal: Float ): Float; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
// Converted from blender's math_rotation.c to free pascal
(************************** Arbitrary Order Eulers ***************************)

(* Euler Rotation Order Code:
 * was adapted from
 *      ANSI C code from the article
 *      "Euler Angle Conversion"
 *      by Ken Shoemake, shoemake@graphics.cis.upenn.edu
 *      in "Graphics Gems IV", Academic Press, 1994
 * for use in Blender
 *)

(* Type for rotation order info - see wiki for derivation details *)
type
  TRotOrderInfo = record
	  axis: array [ 0..2 ] of Byte;
	  parity: Boolean; (* parity of axis permutation (even=0, odd=1) - 'n' in original code *)
  end;

(* Array of info for Rotation Order calculations
 * WARNING: must be kept in same order as eEulerRotationOrders
 *)
const RotOrderInfo: array [roXYZ..roZYX] of TRotOrderInfo = (
	    (* i, j, k, n *)
	(Axis:(0, 1, 2);parity: False), (* XYZ *)
	(Axis:(0, 2, 1);parity: True),  (* XZY *)
	(Axis:(1, 0, 2);parity: True),  (* YXZ *)
	(Axis:(1, 2, 0);parity: False), (* YZX *)
	(Axis:(2, 0, 1);parity: False), (* ZXY *)
	(Axis:(2, 1, 0);parity: True)   (* ZYX *)
);

(* Construct quaternion from Euler angles (in radians). *)
function EulerToQuat( Euler: TVec3; Order: TRotationOrder ): TQuaternion;
var
  R: TRotOrderInfo;
  i,j,k: Byte;
  ti, tj, th,
  ci, cj, ch,
  si, sj, sh,
  cc, cs, sc, ss: Float;
  a: TVec3;
begin
  WriteLn( 'Euler to Quat!' );
  R:= RotOrderInfo[ Order ];
	i:= R.axis[ 0 ];
  j:= R.axis[ 1 ];
  k:= R.axis[ 2 ];

	ti:= Euler[ i ] / 2;
  if ( R.parity ) then
	  tj:= Euler[ j ] / ( -2 )
  else
    tj:= Euler[ j ] / (  2 );
	th:= Euler[ k ] / 2;

	ci:= cos(ti);
	cj:= cos(tj);
	ch:= cos(th);
	si:= sin(ti);
	sj:= sin(tj);
	sh:= sin(th);

	cc:= ci * ch;
	cs:= ci * sh;
	sc:= si * ch;
	ss:= si * sh;

	a[i]:= cj * sc - sj * cs;
	a[j]:= cj * ss + sj * cc;
	a[k]:= cj * cs - sj * sc;

	Result.w:= cj * cc + sj * ss;
	Result.x:= a[0];
	Result.y:= a[1];
	Result.z:= a[2];

	if ( R.parity ) then
    Result[ j ]:= -Result[ j ];
end;

function QuatToEuler( Q: TQuaternion; OldRotation:TVec3; Order: TRotationOrder ): TVec3;
begin
  WriteLn( 'Quat to Euler!' );
  Result:= MatToEuler( mat3( Q ), OldRotation, Order );
end;

(* Convert quaternion to Euler angles (in radians). */
void quat_to_eulO(float e[3], short const order, const float q[4])*)
{
	float M[3][3];

	quat_to_mat3(M, q);
	mat3_to_eulO(e, order, M);
}

(* Construct 3x3 matrix from Euler angles (in radians). *)
function EulerToMat( Euler: TVec3; Order: TRotationOrder ): TMat3;
var
  R: TRotOrderInfo;
  i, j, k: Byte;
  ti, tj, th,
  ci, cj, ch,
  si, sj, sh,
  cc, cs, sc, ss: Float;
begin
  WriteLn( 'Euler to Mat!' );
  R:= RotOrderInfo[ Order ];
	i:= R.axis[ 0 ];
  j:= R.axis[ 1 ];
  k:= R.axis[ 2 ];

	if ( R.parity ) then
    begin
		  ti:= -Euler[ i ];
		  tj:= -Euler[ j ];
		  th:= -Euler[ k ];
	  end
	else
    begin
		  ti:= Euler[ i ];
		  tj:= Euler[ j ];
		  th:= Euler[ k ];
	  end;

	ci:= cos( ti );
	cj:= cos( tj );
	ch:= cos( th );
	si:= sin( ti );
	sj:= sin( tj );
	sh:= sin( th );

	cc:= ci * ch;
	cs:= ci * sh;
	sc:= si * ch;
	ss:= si * sh;

	Result.Row[i][i]:= cj * ch;
	Result.Row[j][i]:= sj * sc - cs;
	Result.Row[k][i]:= sj * cc + ss;
	Result.Row[i][j]:= cj * sh;
	Result.Row[j][j]:= sj * ss + cc;
	Result.Row[k][j]:= sj * cs - sc;
	Result.Row[i][k]:= -sj;
	Result.Row[j][k]:= cj * si;
	Result.Row[k][k]:= cj * ci;
end;

(* returns two euler calculation methods, so we can pick the best *)
procedure MatToEuler2( M: TMat3; out Euler1, Euler2: TVec3; Order: TRotationOrder );
var
  R: TRotOrderInfo;
  i, j, k: Byte;
  cy: Float;
begin
  WriteLn( 'Matrix to euler 2!' );
  R:= RotOrderInfo[ Order ];
	i:= R.axis[ 0 ];
  j:= R.axis[ 1 ];
  k:= R.axis[ 2 ];

	(* process the matrix first *)
	m:= mat3normalize(m);

	cy:= sqrt( m.Row[i][i] * m.Row[i][i] + m.Row[i][j] * m.Row[i][j]);

	if (cy > 16.0 * epsilon ) then //TODO: MatToEuler2 causes exception on (+-)NAN
    begin
		  Euler1[ i ]:= arctan2(m.Row[j][k], m.Row[k][k]);
		  Euler1[ j ]:= arctan2(-m.Row[i][k], cy);
		  Euler1[ k ]:= arctan2(m.Row[i][j], m.Row[i][i]);

		  Euler2[ i ]:= arctan2(-m.Row[j][k], -m.Row[k][k]);
		  Euler2[ j ]:= arctan2(-m.Row[i][k], -cy);
		  Euler2[ k ]:= arctan2(-m.Row[i][j], -m.Row[i][i]);
	  end
	else
    begin
		  Euler1[ i ]:= arctan2(-m.Row[k][j], m.Row[j][j]);
		  Euler1[ j ]:= arctan2(-m.Row[i][k], cy);
		  Euler1[ k ]:= 0;

		  Euler2:= Euler1;
	  end;

	if (R.parity) then
    begin
		  Euler1[0]:= -Euler1[0];
		  Euler1[1]:= -Euler1[1];
		  Euler1[2]:= -Euler1[2];

		  Euler2[0]:= -Euler2[0];
		  Euler2[1]:= -Euler2[1];
		  Euler2[2]:= -Euler2[2];
	  end;
end;

(* order independent! *)
procedure compatible_eul( var Euler: TVec3; OldRot: TVec3 );
(* we could use M_PI as pi_thresh: which is correct but 5.1 gives better results.
 * Checked with baking actions to fcurves - campbell *)
const
  pi_thresh = 5.1;
  pi_x2     = 2.0 * PI;
var
  i: Integer;
  deul: TVec3;
begin
  WriteLn( 'Compatible Euler!' );
	(* correct differences of about 360 degrees first *)
	for i:= 0 to 2 do
    begin
		  deul[i]:= Euler[i] - OldRot[i];
		  if (deul[i] > pi_thresh) then
        begin
			    Euler[i]:= Euler[i] - floor(( deul[i] / pi_x2) + 0.5) * pi_x2;
			    deul[i]:= Euler[i] - OldRot[i];
		    end
		  else if (deul[i] < -pi_thresh) then
        begin
			    Euler[i]:= Euler[i] + floor((-deul[i] / pi_x2) + 0.5) * pi_x2;
			    deul[i]:= Euler[i] - OldRot[i];
		    end;
	end;

	(* is 1 of the axis rotations larger than 180 degrees and the other small? NO ELSE IF!! *)
	if (( abs(deul[0]) > 3.2 ) and ( abs(deul[1]) < 1.6 ) and ( abs(deul[2]) < 1.6)) then
		if (deul[0] > 0.0) then
      Euler[0]:= Euler[0] - pi_x2
		else
      Euler[0]:= Euler[0] + pi_x2;
	if (( abs(deul[1]) > 3.2 ) and ( abs(deul[2]) < 1.6 ) and ( abs(deul[0]) < 1.6)) then
		if (deul[1] > 0.0) then
      Euler[1]:= Euler[1] - pi_x2
		else
      Euler[1]:= Euler[1] + pi_x2;
	if (( abs(deul[2]) > 3.2 ) and ( abs(deul[0]) < 1.6 ) and ( abs(deul[1]) < 1.6)) then
		if (deul[2] > 0.0) then
      Euler[2]:= Euler[2] - pi_x2
		else
      Euler[2]:= Euler[2] + pi_x2;
end;

(* uses 2 methods to retrieve eulers, and picks the closest *)
function MatToEuler( M: TMat3; OldRot: TVec3; Order: TRotationOrder ): TVec3;
var
  eul1, eul2: TVec3;
  d1, d2: Float;
begin
  WriteLn( 'Matrix to euler!' );
	MatToEuler2( M, eul1, eul2, Order );

	compatible_eul(eul1, oldrot);
	compatible_eul(eul2, oldrot);

	d1:= abs(eul1[0] - OldRot[0]) + abs(eul1[1] - OldRot[1]) + abs(eul1[2] - OldRot[2]);
	d2:= abs(eul2[0] - OldRot[0]) + abs(eul2[1] - OldRot[1]) + abs(eul2[2] - OldRot[2]);

	(* return best, which is just the one with lowest difference *)
	if (d1 > d2) then
		Result:= eul2
	else
		Result:= eul1;
end;

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x: Float; minVal, maxVal: Float ): Float; overload;
begin
  Result:= min( max( x, minVal ), maxVal );
end;

{$ENDIF}
