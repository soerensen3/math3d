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
//while all other values are 0. So @code`mat2( 1 )` will generate a 2 by 2 identity matrix.
function mat2( F: Float ): TMat2;
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
//mat2( 1, 0, 0, 1 ) will generate an identity matrix.
function mat2( aa, ba, ab, bb: Float ): TMat2;
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
//@code`mat2( vec2( 1, 0 ), vec2( 0, 1 ))` will generate an identity matrix.
function mat2( c1, c2: TVec2 ): TMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat2( c1.x, c1.y,
                 c2.x, c2.y );
end;
{$ENDIF}

//@abbr`Will create a two by two matrix from a three by three matrix`. The additional row and column are truncated.
function mat2( mat: TMat3 ): TMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat2( mat._00, mat._01,
                 mat._10, mat._11 );
end;
{$ENDIF}

//@abbr`Will create a two by two matrix from a four by four matrix`. The additional rows and columns are truncated.
function mat2( mat: TMat4 ): TMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat2( mat._00, mat._01,
                 mat._10, mat._11 );
end;
{$ENDIF}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a three by three matrix using one float`. The float is used in a diagonal
//while all other values are 0. So @code`mat3( 1 )` will generate a 3 by 3 identity matrix.
function mat3( F: Float ): TMat3;
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
//@code`mat3( 1, 0, 0, 0, 1, 0, 0, 0, 1 )` will generate an identity matrix.
function mat3( aa, ab, ac, ba, bb, bc, ca, cb, cc: Float ): TMat3;
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
function mat3( mat4: TMat4 ): TMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat3( mat4._00, mat4._01, mat4._02,
                 mat4._10, mat4._11, mat4._12,
                 mat4._20, mat4._21, mat4._22 );
end;
{$ENDIF}

//@abbr`Will create a three by three matrix using three vectors`.
//So code`mat3( vec3( 1, 0, 0 ), vec3( 0, 1, 0 ), vec3( 0, 0, 1 ))` will generate an identity matrix.
function mat3( c1, c2, c3: TVec3 ): TMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat3( c1.x, c2.x, c3.x,
                 c1.y, c2.y, c3.y,
                 c1.z, c2.z, c3.z );
end;
{$ENDIF}

//@abbr`Will create a three by three matrix from a two by two matrix`.
//The additional row and column are set to 0 except for _22 which is set to 1.
function mat3( mat: TMat2 ): TMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat3( mat._00, mat._01, 0,
                 mat._10, mat._11, 0,
                 0,       0,       1 );

end;
{$ENDIF}

function mat3( quat: TQuaternion ): TMat3;
{$IFDEF IMPLEMENTATION}
const M_SQRT2 = 1.41421356237309504880;
var
  qw, qx, qy, qz, qda, qdb, qdc, qaa, qab, qac, qbb, qbc, qcc: Float;
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

{
function mat3( quat: TQuaternion ): TMat3;
//1 - 2*qy2 - 2*qz2 	2*qx*qy - 2*qz*qw 	2*qx*qz + 2*qy*qw
//2*qx*qy + 2*qz*qw 	1 - 2*qx2 - 2*qz2 	2*qy*qz - 2*qx*qw
//2*qx*qz - 2*qy*qw 	2*qy*qz + 2*qx*qw 	1 - 2*qx2 - 2*qy2
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= 1 - 2 * quat[ 1 ] * quat[ 1 ] - 2 * quat[ 2 ] * quat[ 2 ];
  Result._01:=     2 * quat[ 0 ] * quat[ 1 ] - 2 * quat[ 2 ] * quat[ 3 ];
  Result._02:=     2 * quat[ 0 ] * quat[ 2 ] + 2 * quat[ 1 ] * quat[ 3 ];

  Result._10:=     2 * quat[ 0 ] * quat[ 1 ] + 2 * quat[ 2 ] * quat[ 3 ];
  Result._11:= 1 - 2 * quat[ 0 ] * quat[ 0 ] - 2 * quat[ 2 ] * quat[ 2 ];
  Result._12:=     2 * quat[ 1 ] * quat[ 2 ] - 2 * quat[ 0 ] * quat[ 3 ];

  Result._20:=     2 * quat[ 0 ] * quat[ 2 ] - 2 * quat[ 1 ] * quat[ 3 ];
  Result._21:=     2 * quat[ 1 ] * quat[ 2 ] + 2 * quat[ 0 ] * quat[ 3 ];
  Result._22:= 1 - 2 * quat[ 0 ] * quat[ 0 ] - 2 * quat[ 1 ] * quat[ 1 ];
end;
{$ENDIF}
}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a four by four matrix using one float`. The float is used in a diagonal
//while all other values are 0. So mat4( 1 ) will generate a 4 by 4 identity matrix.
function mat4( F: Float ): TMat4;
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
//stand for the rows and columns. So code`mat4( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 )` will generate an identity matrix.
function mat4( aa, ab, ac, ad, ba, bb, bc, bd, ca, cb, cc, cd, da, db, dc, dd: Float ): TMat4;
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
//So code`mat4( vec4( 1, 0, 0, 0 ), vec4( 0, 1, 0, 0 ), vec4( 0, 0, 1, 0 ), vec4( 0, 0, 0, 1 ))` will generate an identity matrix.
function mat4( c1, c2, c3, c4: TVec4 ): TMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat4( c1.x, c1.y, c1.z, c1.w,
                 c2.x, c2.y, c2.z, c2.w,
                 c3.x, c3.y, c3.z, c3.w,
                 c4.x, c4.y, c4.z, c4.w );
end;
{$ENDIF}

//@abbr`Will create a four by four matrix from a two by two matrix`.
//The additional rows and columns are set to 0 except for _33 which is set to 1.
function mat4( mat: TMat2 ): TMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat4( mat._00, mat._01, 0, 0,
                 mat._10, mat._11, 0, 0,
                 0,       0,       1, 0,
                 0,       0,       0, 1 );
end;
{$ENDIF}

//@abbr`Will create a four by four matrix from a three by three matrix`.
//The additional row and column are set to 0 except for _33 which is set to 1.
function mat4( mat: TMat3 ): TMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= mat4( mat._00, mat._01, mat._02, 0,
                 mat._10, mat._11, mat._12, 0,
                 mat._20, mat._21, mat._22, 0,
                 0,       0,       0,       1 );
end;

{$ENDIF}
{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a left handed perspective 4 by 4 projection matrix`.
function mat4perspectiveFOVLH( FOV, Aspect, Near, Far: Float ): TMat4;
{$IFDEF IMPLEMENTATION}
var
  w, h: Float;
begin
  h:= Cot( FOV / 2 );
  w:= h / Aspect;
  Result._00:= w; Result._01:= 0; Result._02:= 0;                          Result._03:= 0;
  Result._10:= 0; Result._11:= h; Result._12:= 0;                          Result._13:= 0;
  Result._20:= 0; Result._21:= 0; Result._22:= ( Far + Near )/( Near - Far ); Result._23:= -1;
  Result._30:= 0; Result._31:= 0; Result._32:= (2 * Far * Near )/( Near - Far ); Result._33:= 0;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a right handed perspective 4 by 4 projection matrix`.
function mat4perspectiveFOVRH( FOV, Aspect, Near, Far: Float ): TMat4;
{$IFDEF IMPLEMENTATION}
var
  w, h: Float;
begin
  h:= Cot( FOV / 2 );
  w:= h / Aspect;
  Result._00:= 2/( w ); Result._01:= 0; Result._02:= 0;                          Result._03:= 0;
  Result._10:= 0; Result._11:= 2/( h ); Result._12:= 0;                          Result._13:= 0;
  Result._20:= 0; Result._21:= 0; Result._22:= Far/( Near - Far );         Result._23:= 0;
  Result._30:= 0; Result._31:= 0; Result._32:= Near * Far/( Near - Far );  Result._33:= 1;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a left handed orthogonal 4 by 4 projection matrix`.
function mat4orthoLH( w, h: Float ): TMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= 2/( w );                             Result._01:= 0;                                   Result._02:= 0;    Result._03:= 0;
  Result._10:= 0;                                   Result._11:= 2/( h );                             Result._12:= 0;    Result._13:= 0;
  Result._20:= 0;                                   Result._21:= 0;                                   Result._22:= 1;    Result._23:= 0;
  Result._30:= 0;                                   Result._31:= 0;                                   Result._32:= 0;    Result._33:= 1;
end;
{$ENDIF}

//@abbr`Returns a left handed orthogonal 4 by 4 projection matrix`.
function mat4orthoLH( w, h: Float; zNear, zFar: Float ): TMat4;
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
function mat4orthoRH( w, h, zNear, zFar: Float ): TMat4;
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
function mat4orthoRH( left, right, top, bottom: Float ): TMat4;
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
function mat4lookatLH( EyePt, LookAt, UpDir: TVec3 ): TMat4;
{$IFDEF IMPLEMENTATION}
var
  xa, ya, za: TVec3;
begin
  za:= Normalize ( LookAt - EyePt );
  xa:= Normalize( cross( UpDir, za ));
  ya:= cross( za, xa );

  Result._00:= xa.x; Result._01:= ya.x; Result._02:= za.x; Result._03:= 0;
  Result._10:= xa.y; Result._11:= ya.y; Result._12:= za.y; Result._13:= 0;
  Result._20:= xa.z; Result._21:= ya.z; Result._22:= za.z; Result._23:= 0;

  Result._30:= -Dot( xa, EyePt );
  Result._31:= -Dot( ya, EyePt );
  Result._32:= -Dot( za, EyePt );
  Result._33:= 1;
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a right handed 4 by 4 lookat matrix which can be used for cameras`.
function mat4lookatRH( EyePt, LookAt, UpDir: TVec3 ): TMat4;
{$IFDEF IMPLEMENTATION}
var
  xa, ya, za: TVec3;
begin
  za:= Normalize( EyePt - LookAt );
  xa:= Normalize( cross( UpDir, za ));
  ya:= cross( za, xa );

  Result._00:= xa.x; Result._01:= ya.x; Result._02:= za.x; Result._03:= 0;
  Result._10:= xa.y; Result._11:= ya.y; Result._12:= za.y; Result._13:= 0;
  Result._20:= xa.z; Result._21:= ya.z; Result._22:= za.z; Result._23:= 0;

  Result._30:= -Dot( xa, EyePt );
  Result._31:= -Dot( ya, EyePt );
  Result._32:= -Dot( za, EyePt );
  Result._33:= 1;
end;
{$ENDIF}
(*
//@abbr`Returns a 4 by 4 Euler rotation matrix.` The vector PitchYawRoll is used for the angles Y, X, Z..
function mat4rotateEuler( PitchYawRoll: TVec3 ): TMat4;
{$IFDEF IMPLEMENTATION}
// E( y, p, r ) = R_z( r ) * R_x( p ) * R_y( y )
begin
  Result:= mat4rotate( vec3_Axis_NZ, PitchYawRoll.Y ) *
           mat4rotate( vec3_Axis_PX, PitchYawRoll.X ) *
           mat4rotate( vec3_Axis_PY, PitchYawRoll.Z );
end;
{$ENDIF}

//@abbr`Returns a 4 by 4 Euler rotation matrix.` Yaw, pitch and roll are used as angles..
function mat4rotateEuler( Pitch, Yaw, Roll: Single ): TMat4;
{$IFDEF IMPLEMENTATION}
// E( y, p, r ) = R_z( r ) * R_x( p ) * R_y( y )
begin
  Result:= mat4rotate( vec3_Axis_NZ, Yaw ) *
           mat4rotate( vec3_Axis_PX, Pitch ) *
           mat4rotate( vec3_Axis_PY, Roll );
end;

{$ENDIF}

function mat4toEuler( Matrix: TMat4 ): TVec3;
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

function mat3toScale( Matrix: TMat3 ): TVec3;
{$IFDEF IMPLEMENTATION}
begin
  Result.X:= len( vec3( Matrix._00, Matrix._01, Matrix._02 ));
  Result.Y:= len( vec3( Matrix._10, Matrix._11, Matrix._12 ));
  Result.Z:= len( vec3( Matrix._20, Matrix._21, Matrix._22 ));
end;
{$ENDIF}
