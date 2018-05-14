{
The MIT License (MIT)

Copyright (c) [2015] [Johannes Rosleff Soerensen]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a two by two matrix using one float`. The float is used in a diagonal
//while all other values are 0. So @code`dmat2( 1 )` will generate a 2 by 2 identity matrix.
function dmat2( F: Double ): TDMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= F;
  Result._01:= 0;
  Result._10:= 0;
  Result._11:= 1;
end;
{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a two by two matrix using four float`.
//dmat2( 1, 0, 0, 1 ) will generate an identity matrix.
function dmat2( aa, ba, ab, bb: Double ): TDMat2;
  {$IFDEF IMPLEMENTATION}
begin
  Result._00:= aa;
  Result._01:= ab;
  Result._10:= ba;
  Result._11:= bb;
end;
  {$ENDIF}
{$WARNINGS ON}

//@abbr`Will create a two by two matrix using two vectors`.
//@code`dmat2( vec2( 1, 0 ), vec2( 0, 1 ))` will generate an identity matrix.
function dmat2( c1, c2: TDVec2 ): TDMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat2( c1.x, c1.y,
                 c2.x, c2.y );
end;
{$ENDIF}

//@abbr`Will create a two by two matrix from a three by three matrix`. The additional row and column are truncated.
function dmat2( mat: TDMat3 ): TDMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat2( mat._00, mat._01,
                 mat._10, mat._11 );
end;
{$ENDIF}

//@abbr`Will create a two by two matrix from a four by four matrix`. The additional rows and columns are truncated.
function dmat2( mat: TDMat4 ): TDMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat2( mat._00, mat._01,
                 mat._10, mat._11 );
end;
{$ENDIF}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a three by three matrix using one float`. The float is used in a diagonal
//while all other values are 0. So @code`dmat3( 1 )` will generate a 3 by 3 identity matrix.
function dmat3( F: Double ): TDMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= F;
  Result._01:= 0;
  Result._02:= 0;
  Result._10:= 0;
  Result._11:= F;
  Result._12:= 0;
  Result._20:= 0;
  Result._21:= 0;
  Result._22:= 1;
end;
{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a three by three matrix using nine float`.
//@code`dmat3( 1, 0, 0, 0, 1, 0, 0, 0, 1 )` will generate an identity matrix.
function dmat3( aa, ab, ac, ba, bb, bc, ca, cb, cc: Double ): TDMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= aa;
  Result._01:= ab;
  Result._02:= ac;

  Result._10:= ba;
  Result._11:= bb;
  Result._12:= bc;

  Result._20:= ca;
  Result._21:= cb;
  Result._22:= cc;
end;
{$ENDIF}
{$WARNINGS ON}

//@abbr`Will create a three by three matrix from a four by four matrix`. The additional row and column are truncated.
function dmat3( dmat4: TDMat4 ): TDMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat3( dmat4._00, dmat4._01, dmat4._02,
                 dmat4._10, dmat4._11, dmat4._12,
                 dmat4._20, dmat4._21, dmat4._22 );
end;
{$ENDIF}

//@abbr`Will create a three by three matrix using three vectors`.
//So code`dmat3( vec3( 1, 0, 0 ), vec3( 0, 1, 0 ), vec3( 0, 0, 1 ))` will generate an identity matrix.
function dmat3( c1, c2, c3: TDVec3 ): TDMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat3( c1.x, c2.x, c3.x,
                 c1.y, c2.y, c3.y,
                 c1.z, c2.z, c3.z );
end;
{$ENDIF}

//@abbr`Will create a three by three matrix from a two by two matrix`.
//The additional row and column are set to 0 except for _22 which is set to 1.
function dmat3( mat: TDMat2 ): TDMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat3( mat._00, mat._01, 0,
                 mat._10, mat._11, 0,
                 0,       0,       1 );

end;
{$ENDIF}

function dmat3( quat: TQuat ): TDMat3;
{$IFDEF IMPLEMENTATION}
const M_SQRT2 = 1.41421356237309504880;
var
  qw, qx, qy, qz, qda, qdb, qdc, qaa, qab, qac, qbb, qbc, qcc: Double;
begin
  qw:= M_SQRT2 * quat.W;
  qx:= M_SQRT2 * quat.X;
  qy:= M_SQRT2 * quat.Y;
  qz:= M_SQRT2 * quat.Z;

  qda:= qw * qx;
  qdb:= qw * qy;
  qdc:= qw * qz;
  qaa:= qx * qx;
  qab:= qx * qy;
  qac:= qx * qz;
  qbb:= qy * qy;
  qbc:= qy * qz;
  qcc:= qz * qz;

  Result._00:= 1.0 - qbb - qcc;
  Result._01:= qdc + qab;
  Result._02:= -qdb + qac;

  Result._10:= -qdc + qab;
  Result._11:= 1.0 - qaa - qcc;
  Result._12:= qda + qbc;

  Result._20:= qdb + qac;
  Result._21:= -qda + qbc;
  Result._22:= 1.0 - qaa - qbb;
end;
{$ENDIF}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a four by four matrix using one float`. The float is used in a diagonal
//while all other values are 0. So dmat4( 1 ) will generate a 4 by 4 identity matrix.
function dmat4( F: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= F;
  Result._01:= 0;
  Result._02:= 0;
  Result._03:= 0;
  Result._10:= 0;
  Result._11:= F;
  Result._12:= 0;
  Result._13:= 0;
  Result._20:= 0;
  Result._21:= 0;
  Result._22:= F;
  Result._23:= 0;
  Result._30:= 0;
  Result._31:= 0;
  Result._32:= 0;
  Result._33:= 1;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a four by four matrix using sixteen float`. The letters in the parameters
//stand for the rows and columns. So code`dmat4( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 )` will generate an identity matrix.
function dmat4( aa, ab, ac, ad, ba, bb, bc, bd, ca, cb, cc, cd, da, db, dc, dd: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= aa;
  Result._01:= ab;
  Result._02:= ac;
  Result._03:= ad;

  Result._10:= ba;
  Result._11:= bb;
  Result._12:= bc;
  Result._13:= bd;

  Result._20:= ca;
  Result._21:= cb;
  Result._22:= cc;
  Result._23:= cd;

  Result._30:= da;
  Result._31:= db;
  Result._32:= dc;
  Result._33:= dd;
end;
{$ENDIF}
{$WARNINGS ON}

//@abbr`Will create a four by four matrix using three vectors`. The vectors are used as rows.
//So code`dmat4( vec4( 1, 0, 0, 0 ), vec4( 0, 1, 0, 0 ), vec4( 0, 0, 1, 0 ), vec4( 0, 0, 0, 1 ))` will generate an identity matrix.
function dmat4( c1, c2, c3, c4: TDVec4 ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat4( c1.x, c1.y, c1.z, c1.w,
                 c2.x, c2.y, c2.z, c2.w,
                 c3.x, c3.y, c3.z, c3.w,
                 c4.x, c4.y, c4.z, c4.w );
end;
{$ENDIF}

//@abbr`Will create a four by four matrix from a two by two matrix`.
//The additional rows and columns are set to 0 except for _33 which is set to 1.
function dmat4( mat: TDMat2 ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat4( mat._00, mat._01, 0, 0,
                 mat._10, mat._11, 0, 0,
                 0,       0,       1, 0,
                 0,       0,       0, 1 );
end;
{$ENDIF}

//@abbr`Will create a four by four matrix from a three by three matrix`.
//The additional row and column are set to 0 except for _33 which is set to 1.
function dmat4( mat: TDMat3 ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= dmat4( mat._00, mat._01, mat._02, 0,
                 mat._10, mat._11, mat._12, 0,
                 mat._20, mat._21, mat._22, 0,
                 0,       0,       0,       1 );
end;

{$ENDIF}
{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a left handed perspective 4 by 4 projection matrix`.
function dmat4perspectiveFOVLH( FOV, Aspect, Near, Far: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
var
  w, h: Double;
begin
  h:= Cot( FOV / 2 );
  w:= h / Aspect;
  Result._00:= w;       Result._01:= 0;           Result._02:= 0;                                 Result._03:= 0;
  Result._10:= 0;       Result._11:= h;           Result._12:= 0;                                 Result._13:= 0;
  Result._20:= 0;       Result._21:= 0;           Result._22:= ( Far + Near )/( Near - Far );     Result._23:= -1;
  Result._30:= 0;       Result._31:= 0;           Result._32:= (2 * Far * Near )/( Near - Far );  Result._33:= 0;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a right handed perspective 4 by 4 projection matrix`.
function dmat4perspectiveFOVRH( FOV, Aspect, Near, Far: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
var
  w, h: Double;
begin
  h:= Cot( FOV / 2 );
  w:= h / Aspect;
  Result._00:= 2/( w ); Result._01:= 0;           Result._02:= 0;                          Result._03:= 0;
  Result._10:= 0;       Result._11:= 2/( h );     Result._12:= 0;                          Result._13:= 0;
  Result._20:= 0;       Result._21:= 0;           Result._22:= Far/( Near - Far );         Result._23:= 0;
  Result._30:= 0;       Result._31:= 0;           Result._32:= Near * Far/( Near - Far );  Result._33:= 1;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a left handed orthogonal 4 by 4 projection matrix`.
function dmat4orthoLH( w, h: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= 2/( w );                             Result._01:= 0;                                   Result._02:= 0;    Result._03:= 0;
  Result._10:= 0;                                   Result._11:= 2/( h );                             Result._12:= 0;    Result._13:= 0;
  Result._20:= 0;                                   Result._21:= 0;                                   Result._22:= 1;    Result._23:= 0;
  Result._30:= 0;                                   Result._31:= 0;                                   Result._32:= 0;    Result._33:= 1;
end;
{$ENDIF}

//@abbr`Returns a left handed orthogonal 4 by 4 projection matrix`.
function dmat4orthoLH( w, h: Double; zNear, zFar: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= 2/( w );                             Result._01:= 0;                                   Result._02:= 0;                     Result._03:= 0;
  Result._10:= 0;                                   Result._11:= 2/( h );                             Result._12:= 0;                     Result._13:= 0;
  Result._20:= 0;                                   Result._21:= 0;                                   Result._22:= 2/ ( zNear - zFar );   Result._23:= 0;
  Result._30:= 0;                                   Result._31:= 0;                  Result._32:= ( zFar + zNear ) / ( zNear - zFar );    Result._33:= 1;
end;
{$ENDIF}
{
//@abbr`Returns a left handed orthogonal 4 by 4 projection matrix`.
function dmat4orthoRH( w, h, zNear, zFar: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= 2/( w );                             Result._01:= 0;                                   Result._02:= 0;                     Result._03:= 0;
  Result._10:= 0;                                   Result._11:= 2/( h );                             Result._12:= 0;                     Result._13:= 0;
  Result._20:= 0;                                   Result._21:= 0;                                   Result._22:= 2/ ( zFar - zNear );   Result._23:= 0;
  Result._30:= 0;                                   Result._31:= 0;                  Result._32:= ( zFar + zNear ) / ( zFar - zNear );    Result._33:= 1;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
}
//@abbr`Returns a right handed orthogonal 4 by 4 projection matrix`.
function dmat4orthoRH( left, right, top, bottom: Double ): TDMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= 2/( right - left );                  Result._01:= 0;                                   Result._02:= 0;    Result._03:= 0;
  Result._10:= 0;                                   Result._11:= 2/( top - bottom );                  Result._12:= 0;    Result._13:= 0;
  Result._20:= 0;                                   Result._21:= 0;                                   Result._22:= -1;   Result._23:= 0;
  Result._30:= - (right + left) / (right - left);   Result._31:= - (top + bottom) / (top - bottom);   Result._32:= 0;    Result._33:= 1;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a left handed 4 by 4 lookat matrix which can be used for cameras`.
function dmat4lookatLH( EyePt, LookAt, UpDir: TDVec3 ): TDMat4;
{$IFDEF IMPLEMENTATION}
var
  left, up, forw: TDVec3;
begin
  forw:= Normalize ( LookAt - EyePt );
  left:= Normalize( cross( UpDir, forw ));
  up:= cross( forw, left );

  Result._00:= left.x; Result._01:= up.x; Result._02:= forw.x; Result._03:= 0;
  Result._10:= left.y; Result._11:= up.y; Result._12:= forw.y; Result._13:= 0;
  Result._20:= left.z; Result._21:= up.z; Result._22:= forw.z; Result._23:= 0;

  Result._30:= -Dot( left, EyePt );
  Result._31:= -Dot( up, EyePt );
  Result._32:= -Dot( forw, EyePt );
  Result._33:= 1;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a right handed 4 by 4 lookat matrix which can be used for cameras`.
function dmat4lookatRH( EyePt, LookAt, UpDir: TDVec3 ): TDMat4;
{$IFDEF IMPLEMENTATION}
var
  right, up, forw: TDVec3;
begin
  forw:= Normalize( EyePt - LookAt );
  right:= Normalize( cross( UpDir, forw ));
  up:= cross( forw, right );

  Result._00:= right.x; Result._01:= up.x; Result._02:= forw.x; Result._03:= 0;
  Result._10:= right.y; Result._11:= up.y; Result._12:= forw.y; Result._13:= 0;
  Result._20:= right.z; Result._21:= up.z; Result._22:= forw.z; Result._23:= 0;

  Result._30:= -Dot( right, EyePt );
  Result._31:= -Dot( up, EyePt );
  Result._32:= -Dot( forw, EyePt );
  Result._33:= 1;
end;
{$ENDIF}
(*
//@abbr`Returns a 4 by 4 Euler rotation matrix.` The vector PitchYawRoll is used for the angles Y, X, Z..
function dmat4rotateEuler( PitchYawRoll: TDVec3 ): TDMat4;
{$IFDEF IMPLEMENTATION}
// E( y, p, r ) = R_z( r ) * R_x( p ) * R_y( y )
begin
  Result:= dmat4rotate( vec3_Axis_NZ, PitchYawRoll.Y ) *
           dmat4rotate( vec3_Axis_PX, PitchYawRoll.X ) *
           dmat4rotate( vec3_Axis_PY, PitchYawRoll.Z );
end;
{$ENDIF}

//@abbr`Returns a 4 by 4 Euler rotation matrix.` Yaw, pitch and roll are used as angles..
function dmat4rotateEuler( Pitch, Yaw, Roll: Single ): TDMat4;
{$IFDEF IMPLEMENTATION}
// E( y, p, r ) = R_z( r ) * R_x( p ) * R_y( y )
begin
  Result:= dmat4rotate( vec3_Axis_NZ, Yaw ) *
           dmat4rotate( vec3_Axis_PX, Pitch ) *
           dmat4rotate( vec3_Axis_PY, Roll );
end;

{$ENDIF}

function dmat4toEuler( Matrix: TDMat4 ): TDVec3;
{$IFDEF IMPLEMENTATION}
begin
  if ( abs( Matrix._20 ) <> 1 ) then //TWO SOLUTIONS, TAKE THE FIRST
    begin
      Result.Y:= -arcsin( Matrix._20 );
      Result.X:= arctan2( Matrix._21 / cos( Result.Y ), Matrix._22 / cos( Result.Y ));
      Result.Z:= arctan2( Matrix._10 / cos( Result.Y ), Matrix._00 / cos( Result.Y ));
    end
  else
    begin // UNLIMITED SOLUTIONS, PICK ONE WHERE Z IS 0
      Result.Z:= 0;
      if ( Matrix._20 = -1 ) then
        begin
          Result.Y:= PI/2;
          Result.X:= arctan2( Matrix._01, Matrix._02 );
        end
      else
        begin
          Result.Y:= PI/2;
          Result.X:= arctan2( -Matrix._01, -Matrix._02 );
        end;
    end;
end;
{$ENDIF} *)

