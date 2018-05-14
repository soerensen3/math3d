{$IFDEF INTERFACE}
function EulerToQuat( Euler: TVec3; Order: TRotationOrder ): TQuat;
function QuatToEuler( Q: TQuat; OldRotation:TVec3; Order: TRotationOrder ): TVec3;
procedure MatToEuler2( M: TMat3; out Euler1, Euler2: TVec3; Order: TRotationOrder );
function MatToEuler( M: TMat3; OldRot: TVec3; Order: TRotationOrder ): TVec3;

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x: Float; minVal, maxVal: Float ): Float; overload;

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x: Integer; minVal, maxVal: Integer ): Integer; overload;

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function mix( x: Float; y: Float; a: Float ): Float; overload;

function vec2( xy: TIVec2 ): TVec2;
function vec3( xyz: TIVec3 ): TVec3;
function vec4( xyzw: TIVec4 ): TVec4;
function vec2( xy: TDVec2 ): TVec2;
function vec3( xyz: TDVec3 ): TVec3;
function vec4( xyzw: TDVec4 ): TVec4;
function vec4( xyzw: TQuat ): TVec4; inline;
function dvec2( xy: TVec2 ): TDVec2;
function dvec3( xyz: TVec3 ): TDVec3;
function dvec4( xyzw: TVec4 ): TDVec4;
function dvec2( xy: TIVec2 ): TDVec2;
function dvec3( xyz: TIVec3 ): TDVec3;
function dvec4( xyzw: TIVec4 ): TDVec4;
function dvec4( xyzw: TQuat ): TDVec4;
function ivec2( xy: TVec2 ): TIVec2;
function ivec3( xyz: TVec3 ): TIVec3;
function ivec4( xyzw: TVec4 ): TIVec4;
function ivec2( xy: TDVec2 ): TIVec2;
function ivec3( xyz: TDVec3 ): TIVec3;
function ivec4( xyzw: TDVec4 ): TIVec4;
function round( a: TVec2 ): TIVec2;
function round( a: TVec3 ): TIVec3;
function round( a: TVec4 ): TIVec4;
function round( a: TDVec2 ): TIVec2;
function round( a: TDVec3 ): TIVec3;
function round( a: TDVec4 ): TIVec4;
function quat( x, y, z, w: Float ): TQuat;
function quat( xyzw: TVec4 ): TQuat;
function quat( xyzw: TDVec4 ): TQuat;
function quat( mat: TMat3 ): TQuat;

operator mod(const a,b:double) c:double;inline;

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
function EulerToQuat( Euler: TVec3; Order: TRotationOrder ): TQuat;
var
  R: TRotOrderInfo;
  i,j,k: Byte;
  ti, tj, th,
  ci, cj, ch,
  si, sj, sh,
  cc, cs, sc, ss: Float;
  a: TVec3;
begin
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

function QuatToEuler( Q: TQuat; OldRotation:TVec3; Order: TRotationOrder ): TVec3;
begin
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
  R:= RotOrderInfo[ Order ];
  i:= R.axis[ 0 ];
  j:= R.axis[ 1 ];
  k:= R.axis[ 2 ];

  (* process the matrix first *)
  m:= mat3normalize(m);

  cy:= sqrt( m.Row[ i ][ i ] * m.Row[ i ][ i ] + m.Row[ i ][ j ] * m.Row[ i ][ j ]);

  if (cy > 16.0 * epsilon ) then //TODO: MatToEuler2 causes exception on (+-)NAN
    begin
      Euler1[ i ]:= arctan2(  m.Row[ j ][ k ],  m.Row[ k ][ k ]);
      Euler1[ j ]:= arctan2( -m.Row[ i ][ k ],  cy );
      Euler1[ k ]:= arctan2(  m.Row[ i ][ j ],  m.Row[ i ][ i ]);

      Euler2[ i ]:= arctan2( -m.Row[ j ][ k ], -m.Row[ k ][ k ]);
      Euler2[ j ]:= arctan2( -m.Row[ i ][ k ], -cy );
      Euler2[ k ]:= arctan2( -m.Row[ i ][ j ], -m.Row[ i ][ i ]);
    end
  else
    begin
      Euler1[ i ]:= arctan2( -m.Row[ k ][ j ], m.Row[ j ][ j ]);
      Euler1[ j ]:= arctan2( -m.Row[ i ][ k ], cy );
      Euler1[ k ]:= 0;

      Euler2:= Euler1;
    end;

  if ( R.parity ) then
    begin
      Euler1[ 0 ]:= -Euler1[ 0 ];
      Euler1[ 1 ]:= -Euler1[ 1 ];
      Euler1[ 2 ]:= -Euler1[ 2 ];

      Euler2[ 0 ]:= -Euler2[ 0 ];
      Euler2[ 1 ]:= -Euler2[ 1 ];
      Euler2[ 2 ]:= -Euler2[ 2 ];
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
  (* correct differences of about 360 degrees first *)
  for i:= 0 to 2 do
    begin
      deul[ i ]:= Euler[ i ] - OldRot[ i ];
      if ( deul[ i ] > pi_thresh ) then
        begin
	  Euler[ i ]:= Euler[ i ] - floor(( deul[ i ] / pi_x2 ) + 0.5 ) * pi_x2;
	  deul[ i ]:= Euler[ i ] - OldRot[ i ];
	end
      else if ( deul[ i ] < -pi_thresh) then
        begin
	  Euler[ i ]:= Euler[ i ] + floor(( -deul[ i ] / pi_x2 ) + 0.5 ) * pi_x2;
	  deul[ i ]:= Euler[ i ] - OldRot[ i ];
	end;
    end;

  (* is 1 of the axis rotations larger than 180 degrees and the other small? NO ELSE IF!! *)
  if (( abs( deul[ 0 ]) > 3.2 ) and ( abs( deul[ 1 ]) < 1.6 ) and ( abs( deul[ 2 ]) < 1.6 )) then
    if ( deul[ 0 ] > 0.0) then
      Euler[ 0 ]:= Euler[ 0 ] - pi_x2
    else
      Euler[ 0 ]:= Euler[ 0 ] + pi_x2;
  if (( abs( deul[ 1 ]) > 3.2 ) and ( abs( deul[ 2 ]) < 1.6 ) and ( abs( deul[ 0 ]) < 1.6 )) then
    if (deul[ 1 ] > 0.0) then
      Euler[ 1 ]:= Euler[ 1 ] - pi_x2
    else
      Euler[ 1 ]:= Euler[ 1 ] + pi_x2;

  if (( abs(deul[ 2 ]) > 3.2 ) and ( abs( deul[ 0 ]) < 1.6 ) and ( abs( deul[ 1 ]) < 1.6 )) then
    if (deul[ 2 ] > 0.0) then
      Euler[ 2 ]:= Euler[ 2 ] - pi_x2
    else
      Euler[ 2 ]:= Euler[ 2 ] + pi_x2;
end;

(* uses 2 methods to retrieve eulers, and picks the closest *)
function MatToEuler( M: TMat3; OldRot: TVec3; Order: TRotationOrder ): TVec3;
var
  eul1, eul2: TVec3;
  d1, d2: Float;
begin
  MatToEuler2( M, eul1, eul2, Order );

  compatible_eul( eul1, oldrot );
  compatible_eul( eul2, oldrot );

  d1:= abs( eul1[ 0 ] - OldRot[ 0 ]) + abs( eul1[ 1 ] - OldRot[ 1 ]) + abs( eul1[ 2 ] - OldRot[ 2 ]);
  d2:= abs( eul2[ 0 ] - OldRot[ 0 ]) + abs( eul2[ 1 ] - OldRot[ 1 ]) + abs( eul2[ 2 ] - OldRot[ 2 ]);

  (* return best, which is just the one with lowest difference *)
  if ( d1 > d2 ) then
    Result:= eul2
  else
    Result:= eul1;
end;

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x: Float; minVal, maxVal: Float ): Float; overload;
begin
  Result:= min( max( x, minVal ), maxVal );
end;



//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x: Integer; minVal, maxVal: Integer ): Integer; overload;
begin
  Result:= min( max( x, minVal ), maxVal );
end;

function mix(x: Float; y: Float; a: Float): Float;
begin
  Result:= x * ( 1 - a)+y*a;
end;

function vec2(xy: TIVec2): TVec2;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xy[ i ];
end;

function vec3(xyz: TIVec3): TVec3;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyz[ i ];
end;

function vec4(xyzw: TIVec4): TVec4;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyzw[ i ];
end;

function vec2( xy: TDVec2 ): TVec2;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xy[ i ];
end;

function vec3( xyz: TDVec3 ): TVec3;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyz[ i ];
end;

function vec4( xyzw: TDVec4 ): TVec4;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyzw[ i ];
end;

function vec4( xyzw: TQuat ): TVec4;
begin
  Result:= TVec4( xyzw );
end;

function dvec2( xy: TVec2 ): TDVec2;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xy[ i ];
end;

function dvec3( xyz: TVec3 ): TDVec3;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyz[ i ];
end;

function dvec4( xyzw: TVec4 ): TDVec4;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyzw[ i ];
end;

function dvec2( xy: TIVec2 ): TDVec2;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xy[ i ];
end;

function dvec3( xyz: TIVec3 ): TDVec3;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyz[ i ];
end;

function dvec4( xyzw: TIVec4 ): TDVec4;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= xyzw[ i ];
end;

function dvec4( xyzw: TQuat ): TDVec4;
begin
  Result:= dvec4( TVec4( xyzw ));
end;

function ivec2(xy: TVec2): TIVec2;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= round( xy[ i ]);
end;

function ivec3(xyz: TVec3): TIVec3;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= round( xyz[ i ]);
end;

function ivec4(xyzw: TVec4): TIVec4;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= round( xyzw[ i ]);
end;

function ivec2( xy: TDVec2 ): TIVec2;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= round( xy[ i ]);
end;

function ivec3( xyz: TDVec3 ): TIVec3;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= round( xyz[ i ]);
end;

function ivec4( xyzw: TDVec4 ): TIVec4;
var
  i: Integer;
begin
  for i:= low( Result.FCoord ) to high( Result.FCoord ) do
    Result[ i ]:= round( xyzw[ i ]);
end;

operator mod(const a,b:double) c:double;inline;
begin
  c:= a-b * system.int(a/b);
end;

function round( a: TVec2 ): TIVec2;
begin
  Result:= ivec2( a );
end;

function round( a: TVec3 ): TIVec3;
begin
  Result:= ivec3( a );
end;

function round( a: TVec4 ): TIVec4;
begin
  Result:= ivec4( a );
end;

function round( a: TDVec2 ): TIVec2;
begin
  Result:= ivec2( a );
end;

function round( a: TDVec3 ): TIVec3;
begin
  Result:= ivec3( a );
end;

function round( a: TDVec4 ): TIVec4;
begin
  Result:= ivec4( a );
end;

function quat( x, y, z, w: Float ): TQuat;
begin
  Result.x:= x;
  Result.y:= y;
  Result.z:= z;
  Result.w:= w;
end;

function quat( xyzw: TVec4 ): TQuat;
begin
  Result:= TQuat( xyzw );
end;

function quat( xyzw: TDVec4 ): TQuat;
begin
  Result:= TQuat( vec4( xyzw ));
end;

//Converted from math_rotation.c from blender
function quat( mat: TMat3 ): TQuat;
var
  tr, s: Double;
begin
  mat.Col[ 0 ]:= normalize( mat.Col[ 0 ]);// this is needed AND a 'normalize_qt' in the end
  mat.Col[ 1 ]:= normalize( mat.Col[ 1 ]);
  mat.Col[ 2 ]:= normalize( mat.Col[ 2 ]);

  tr:= 0.25 * (1.0 + mat.Col[0][0] + mat.Col[1][1] + mat.Col[2][2]);

  if (tr > epsilon) then
    begin
      s:= sqrt( tr );
      Result.w:= s;
      s:= 1.0 / (4.0 * s);
      Result.x:= ( mat.Col[1][2] - mat.Col[2][1]) * s;
      Result.y:= ( mat.Col[2][0] - mat.Col[0][2]) * s;
      Result.z:= ( mat.Col[0][1] - mat.Col[1][0]) * s;
    end
  else
    begin
      if (( mat.Col[0][0] > mat.Col[1][1]) AND ( mat.Col[0][0] > mat.Col[2][2])) then
        begin
  	  s:= 2.0 * sqrt( 1.0 + mat.Col[0][0] - mat.Col[1][1] - mat.Col[2][2]);
  	  Result.x:= (0.25 * s);

  	  s:= 1.0 / s;
  	  Result.w:= (mat.Col[2][1] - mat.Col[1][2]) * s;
  	  Result.y:= (mat.Col[1][0] + mat.Col[0][1]) * s;
  	  Result.z:= (mat.Col[2][0] + mat.Col[0][2]) * s;
  	end
      else if (mat.Col[1][1] > mat.Col[2][2]) then
        begin
  	  s:= 2.0 * sqrt(1.0 + mat.Col[1][1] - mat.Col[0][0] - mat.Col[2][2]);
  	  Result.y:= (0.25 * s);

  	  s:= 1.0 / s;
  	  Result.w:= (mat.Col[2][0] - mat.Col[0][2]) * s;
  	  Result.x:= (mat.Col[1][0] + mat.Col[0][1]) * s;
  	  Result.z:= (mat.Col[2][1] + mat.Col[1][2]) * s;
      end
      else
        begin
  	  s:= 2.0 * sqrt(1.0 + mat.Col[2][2] - mat.Col[0][0] - mat.Col[1][1]);
  	  Result.z:= (0.25 * s);

  	  s:= 1.0 / s;
  	  Result.w:= (mat.Col[1][0] - mat.Col[0][1]) * s;
  	  Result.x:= (mat.Col[2][0] + mat.Col[0][2]) * s;
  	  Result.y:= (mat.Col[2][1] + mat.Col[1][2]) * s;
  	end;
    end;

  Result.Normalize;
  //Result.w:= sqrt( 1 + mat._00 + mat._11 + mat._22) /2;
  //Result.x:= (mat._21 - mat._12)/( 4 * Result.w);
  //Result.y:= (mat._02 - mat._20)/( 4 * Result.w);
  //Result.z:= (mat._10 - mat._01)/( 4 * Result.w);
end;

{$ENDIF}
