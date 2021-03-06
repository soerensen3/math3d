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
//while all other values are 0. So @code`imat2( 1 )` will generate a 2 by 2 identity matrix.
function imat2( F: Int ): TIMat2;
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
//imat2( 1, 0, 0, 1 ) will generate an identity matrix.
function imat2( aa, ba, ab, bb: Int ): TIMat2;
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
//@code`imat2( vec2( 1, 0 ), vec2( 0, 1 ))` will generate an identity matrix.
function imat2( c1, c2: TIVec2 ): TIMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat2( c1.x, c1.y,
                 c2.x, c2.y );
end;
{$ENDIF}

//@abbr`Will create a two by two matrix from a three by three matrix`. The additional row and column are truncated.
function imat2( mat: TIMat3 ): TIMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat2( mat._00, mat._01,
                 mat._10, mat._11 );
end;
{$ENDIF}

//@abbr`Will create a two by two matrix from a four by four matrix`. The additional rows and columns are truncated.
function imat2( mat: TIMat4 ): TIMat2;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat2( mat._00, mat._01,
                 mat._10, mat._11 );
end;
{$ENDIF}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a three by three matrix using one float`. The float is used in a diagonal
//while all other values are 0. So @code`imat3( 1 )` will generate a 3 by 3 identity matrix.
function imat3( F: Int ): TIMat3;
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
//@code`imat3( 1, 0, 0, 0, 1, 0, 0, 0, 1 )` will generate an identity matrix.
function imat3( aa, ab, ac, ba, bb, bc, ca, cb, cc: Int ): TIMat3;
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
function imat3( imat4: TIMat4 ): TIMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat3( imat4._00, imat4._01, imat4._02,
                 imat4._10, imat4._11, imat4._12,
                 imat4._20, imat4._21, imat4._22 );
end;
{$ENDIF}

//@abbr`Will create a three by three matrix using three vectors`.
//So code`imat3( vec3( 1, 0, 0 ), vec3( 0, 1, 0 ), vec3( 0, 0, 1 ))` will generate an identity matrix.
function imat3( c1, c2, c3: TIVec3 ): TIMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat3( c1.x, c2.x, c3.x,
                 c1.y, c2.y, c3.y,
                 c1.z, c2.z, c3.z );
end;
{$ENDIF}

//@abbr`Will create a three by three matrix from a two by two matrix`.
//The additional row and column are set to 0 except for _22 which is set to 1.
function imat3( mat: TIMat2 ): TIMat3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat3( mat._00, mat._01, 0,
                 mat._10, mat._11, 0,
                 0,       0,       1 );

end;
{$ENDIF}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will create a four by four matrix using one float`. The float is used in a diagonal
//while all other values are 0. So imat4( 1 ) will generate a 4 by 4 identity matrix.
function imat4( F: Int ): TIMat4;
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
//stand for the rows and columns. So code`imat4( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 )` will generate an identity matrix.
function imat4( aa, ab, ac, ad, ba, bb, bc, bd, ca, cb, cc, cd, da, db, dc, dd: Int ): TIMat4;
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
//So code`imat4( vec4( 1, 0, 0, 0 ), vec4( 0, 1, 0, 0 ), vec4( 0, 0, 1, 0 ), vec4( 0, 0, 0, 1 ))` will generate an identity matrix.
function imat4( c1, c2, c3, c4: TIVec4 ): TIMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat4( c1.x, c1.y, c1.z, c1.w,
                 c2.x, c2.y, c2.z, c2.w,
                 c3.x, c3.y, c3.z, c3.w,
                 c4.x, c4.y, c4.z, c4.w );
end;
{$ENDIF}

//@abbr`Will create a four by four matrix from a two by two matrix`.
//The additional rows and columns are set to 0 except for _33 which is set to 1.
function imat4( mat: TIMat2 ): TIMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat4( mat._00, mat._01, 0, 0,
                 mat._10, mat._11, 0, 0,
                 0,       0,       1, 0,
                 0,       0,       0, 1 );
end;
{$ENDIF}

//@abbr`Will create a four by four matrix from a three by three matrix`.
//The additional row and column are set to 0 except for _33 which is set to 1.
function imat4( mat: TIMat3 ): TIMat4;
{$IFDEF IMPLEMENTATION}
begin
  Result:= imat4( mat._00, mat._01, mat._02, 0,
                 mat._10, mat._11, mat._12, 0,
                 mat._20, mat._21, mat._22, 0,
                 0,       0,       0,       1 );
end;

{$ENDIF}

