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
  { TDVec2 }

  {@abbr`constructor for dvec2 with two Doubles`}
  function dvec2( x: Double; y: Double ): TDVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec2 with one Double, which is taken for x and y`}
  function dvec2( xy: Double ): TDVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xy;
    Result.y:= xy;
  end;
  {$ENDIF}


  {@abbr`constructor for dvec2 with one dvec3, where z is truncated`}
  function dvec2( xy: TDVec3 ): TDVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec2 with one dvec3, where z and w is truncated`}
  function dvec2( xy: TDVec4 ): TDVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  {TDVec3}
  
  {@abbr`constructor for dvec3 with three Doubles`}
  function dvec3( x: Double; y: Double; z: Double ): TDVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
  end;
  {$ENDIF}

  function dvec3( xyz: Double ): TDVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyz;
    Result.y:= xyz;
    Result.z:= xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec3 with one Double, which is taken for x, y and z`}

  function dvec3( xy: TDVec2; z: Double ): TDVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec2 with one dvec2 which is taken for x and y and one Double, which is taken for z`}

  function dvec3( x: Double; yz: TDVec2 ): TDVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec2 with one Double, which is taken for x and one dvec2 which is taken for y and z`}

  function dvec3( xyz: TDVec4 ): TDVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xyz.xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec3 with one dvec4, where w is truncated`}

  { TDVec4 }
  function dvec4( x: Double; y: Double; z: Double; w: Double ): TDVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec4 with four Doubles`}

  function dvec4( xyzw: Double ): TDVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyzw;
    Result.y:= xyzw;
    Result.z:= xyzw;
    Result.w:= xyzw;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec4 with one Double, which is taken for x, y, z and w`}

  function dvec4( xy: TDVec2; z: Double; w: Double ): TDVec4;
  {@abbr`constructor for dvec4 with one dvec2 which is taken for x and y and two Double, which are taken for z and w`}
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  function dvec4( x: Double; yz: TDVec2; w: Double ): TDVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec4 with one Double, which is taken for x, one dvec2, which is taken for y and z and one Double, which is taken for w`}

  function dvec4( x: Double; y: Double; zw: TDVec2 ): TDVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec4 with two Double, which are taken for x and y and one dvec2 which is taken for z and w`}

  function dvec4( xy: TDVec2; zw: TDVec2 ): TDVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec4 with one dvec2, which is taken for x and y and one dvec2, which is taken for z and w`}

  function dvec4( xyz: TDVec3; w: Double ): TDVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xyz:= xyz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec4 with one dvec3, which is taken for x, y and z one Double, which is taken for w`}

  function dvec4( x: Double; yzw: TDVec3 ): TDVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yzw:= yzw;
  end;
  {$ENDIF}

  {@abbr`constructor for dvec4 with one Double, which is taken for x and one dvec3 which is taken for y, z and w`}
  {END CONSTRUCTORS}

