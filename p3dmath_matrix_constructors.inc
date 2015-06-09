
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
  Result:= mat3( c1.x, c1.y, c1.z,
                 c2.x, c2.y, c2.z,
                 c3.x, c3.y, c3.z );
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
  Result._00:= w; Result._01:= 0; Result._02:= 0;                          Result._03:= 0;
  Result._10:= 0; Result._11:= h; Result._12:= 0;                          Result._13:= 0;
  Result._20:= 0; Result._21:= 0; Result._22:= Far/( Near - Far );         Result._23:= -1;
  Result._30:= 0; Result._31:= 0; Result._32:= Near * Far/( Near - Far );  Result._33:= 0;
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
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

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
