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

{$IF FIELDTYPE=Float}
  {$DEFINE TV2:= TVec2}
  {$DEFINE v2:= vec2}
  {$DEFINE TV3:= TVec3}
  {$DEFINE v3:= vec3}
  {$DEFINE TV4:= TVec4}
  {$DEFINE v4:= vec4}
{$ENDIF}
{$IF FIELDTYPE=Double}
  {$DEFINE TV2:= TDVec2}
  {$DEFINE v2:= dvec2}
  {$DEFINE TV3:= TDVec3}
  {$DEFINE v3:= dvec3}
  {$DEFINE TV4:= TDVec4}
  {$DEFINE v4:= dvec4}
{$ENDIF}
{$IF FIELDTYPE=Int}
  {$DEFINE TV2:= TIVec2}
  {$DEFINE v2:= ivec2}
  {$DEFINE TV3:= TIVec3}
  {$DEFINE v3:= ivec3}
  {$DEFINE TV4:= TIVec4}
  {$DEFINE v4:= ivec4}
{$ENDIF}


  {CONSTRUCTORS}
  { TV2 }

  {@abbr`constructor for v2 with two FieldTypes`}
  function v2( x: FieldType; y: FieldType ): TV2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
  end;
  {$ENDIF}

  {@abbr`constructor for v2 with one FieldType, which is taken for x and y`}
  function v2( xy: FieldType ): TV2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xy;
    Result.y:= xy;
  end;
  {$ENDIF}


  {@abbr`constructor for v2 with one v3, where z is truncated`}
  function v2( xy: TV3 ): TV2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  {@abbr`constructor for v2 with one v3, where z and w is truncated`}
  function v2( xy: TV4 ): TV2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  {@abbr`constructor for v3 with three FieldTypes`}
  function v3( x: FieldType; y: FieldType; z: FieldType ): TV3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
  end;
  {$ENDIF}

  function v3( xyz: FieldType ): TV3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyz;
    Result.y:= xyz;
    Result.z:= xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for v3 with one FieldType, which is taken for x, y and z`}

  function v3( xy: TV2; z: FieldType ): TV3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
  end;
  {$ENDIF}

  {@abbr`constructor for v2 with one v2 which is taken for x and y and one FieldType, which is taken for z`}

  function v3( x: FieldType; yz: TV2 ): TV3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
  end;
  {$ENDIF}

  {@abbr`constructor for v2 with one FieldType, which is taken for x and one v2 which is taken for y and z`}

  function v3( xyz: TV4 ): TV3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xyz.xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for v3 with one v4, where w is truncated`}

  { TV4 }
  function v4( x: FieldType; y: FieldType; z: FieldType; w: FieldType ): TV4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for v4 with four FieldTypes`}

  function v4( xyzw: FieldType ): TV4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyzw;
    Result.y:= xyzw;
    Result.z:= xyzw;
    Result.w:= xyzw;
  end;
  {$ENDIF}

  {@abbr`constructor for v4 with one FieldType, which is taken for x, y, z and w`}

  function v4( xy: TV2; z: FieldType; w: FieldType ): TV4;
  {@abbr`constructor for v4 with one v2 which is taken for x and y and two FieldType, which are taken for z and w`}
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  function v4( x: FieldType; yz: TV2; w: FieldType ): TV4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for v4 with one FieldType, which is taken for x, one v2, which is taken for y and z and one FieldType, which is taken for w`}

  function v4( x: FieldType; y: FieldType; zw: TV2 ): TV4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for v4 with two FieldType, which are taken for x and y and one v2 which is taken for z and w`}

  function v4( xy: TV2; zw: TV2 ): TV4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for v4 with one v2, which is taken for x and y and one v2, which is taken for z and w`}

  function v4( xyz: TV3; w: FieldType ): TV4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xyz:= xyz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for v4 with one v3, which is taken for x, y and z one FieldType, which is taken for w`}

  function v4( x: FieldType; yzw: TV3 ): TV4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yzw:= yzw;
  end;
  {$ENDIF}

  {@abbr`constructor for v4 with one FieldType, which is taken for x and one v3 which is taken for y, z and w`}
  {END CONSTRUCTORS}

{$UNDEF TV2} {$UNDEF TV3} {$UNDEF TV4}
{$UNDEF v2} {$UNDEF v3} {$UNDEF v4}

