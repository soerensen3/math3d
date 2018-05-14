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


  {CONSTRUCTORS}
  { TIVec2 }

  {@abbr`constructor for ivec2 with two Ints`}
  function ivec2( x: Int; y: Int ): TIVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec2 with one Int, which is taken for x and y`}
  function ivec2( xy: Int ): TIVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xy;
    Result.y:= xy;
  end;
  {$ENDIF}


  {@abbr`constructor for ivec2 with one ivec3, where z is truncated`}
  function ivec2( xy: TIVec3 ): TIVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec2 with one ivec3, where z and w is truncated`}
  function ivec2( xy: TIVec4 ): TIVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  {TIVec3}
  
  {@abbr`constructor for ivec3 with three Ints`}
  function ivec3( x: Int; y: Int; z: Int ): TIVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
  end;
  {$ENDIF}

  function ivec3( xyz: Int ): TIVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyz;
    Result.y:= xyz;
    Result.z:= xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec3 with one Int, which is taken for x, y and z`}

  function ivec3( xy: TIVec2; z: Int ): TIVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec2 with one ivec2 which is taken for x and y and one Int, which is taken for z`}

  function ivec3( x: Int; yz: TIVec2 ): TIVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec2 with one Int, which is taken for x and one ivec2 which is taken for y and z`}

  function ivec3( xyz: TIVec4 ): TIVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xyz.xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec3 with one ivec4, where w is truncated`}

  { TIVec4 }
  function ivec4( x: Int; y: Int; z: Int; w: Int ): TIVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec4 with four Ints`}

  function ivec4( xyzw: Int ): TIVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyzw;
    Result.y:= xyzw;
    Result.z:= xyzw;
    Result.w:= xyzw;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec4 with one Int, which is taken for x, y, z and w`}

  function ivec4( xy: TIVec2; z: Int; w: Int ): TIVec4;
  {@abbr`constructor for ivec4 with one ivec2 which is taken for x and y and two Int, which are taken for z and w`}
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  function ivec4( x: Int; yz: TIVec2; w: Int ): TIVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec4 with one Int, which is taken for x, one ivec2, which is taken for y and z and one Int, which is taken for w`}

  function ivec4( x: Int; y: Int; zw: TIVec2 ): TIVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec4 with two Int, which are taken for x and y and one ivec2 which is taken for z and w`}

  function ivec4( xy: TIVec2; zw: TIVec2 ): TIVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec4 with one ivec2, which is taken for x and y and one ivec2, which is taken for z and w`}

  function ivec4( xyz: TIVec3; w: Int ): TIVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xyz:= xyz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec4 with one ivec3, which is taken for x, y and z one Int, which is taken for w`}

  function ivec4( x: Int; yzw: TIVec3 ): TIVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yzw:= yzw;
  end;
  {$ENDIF}

  {@abbr`constructor for ivec4 with one Int, which is taken for x and one ivec3 which is taken for y, z and w`}
  {END CONSTRUCTORS}

