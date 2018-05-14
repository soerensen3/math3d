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
  { TVec2 }

  {@abbr`constructor for vec2 with two Floats`}
  function vec2( x: Float; y: Float ): TVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
  end;
  {$ENDIF}

  {@abbr`constructor for vec2 with one Float, which is taken for x and y`}
  function vec2( xy: Float ): TVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xy;
    Result.y:= xy;
  end;
  {$ENDIF}


  {@abbr`constructor for vec2 with one vec3, where z is truncated`}
  function vec2( xy: TVec3 ): TVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  {@abbr`constructor for vec2 with one vec3, where z and w is truncated`}
  function vec2( xy: TVec4 ): TVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xy.xy;
  end;
  {$ENDIF}

  function vec2( xy: String ): TVec2;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.FromString( xy );
  end;
  {$ENDIF}


  {TVec3}
  
  {@abbr`constructor for vec3 with three Floats`}
  function vec3( x: Float; y: Float; z: Float ): TVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
  end;
  {$ENDIF}

  function vec3( xyz: Float ): TVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyz;
    Result.y:= xyz;
    Result.z:= xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for vec3 with one Float, which is taken for x, y and z`}

  function vec3( xy: TVec2; z: Float ): TVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
  end;
  {$ENDIF}

  {@abbr`constructor for vec2 with one vec2 which is taken for x and y and one Float, which is taken for z`}

  function vec3( x: Float; yz: TVec2 ): TVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
  end;
  {$ENDIF}

  {@abbr`constructor for vec2 with one Float, which is taken for x and one vec2 which is taken for y and z`}

  function vec3( xyz: TVec4 ): TVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result:= xyz.xyz;
  end;
  {$ENDIF}

  {@abbr`constructor for vec3 with one vec4, where w is truncated`}
  function vec3( xyz: String ): TVec3;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.FromString( xyz );
  end;
  {$ENDIF}

  { TVec4 }
  function vec4( x: Float; y: Float; z: Float; w: Float ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for vec4 with four Floats`}

  function vec4( xyzw: Float ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= xyzw;
    Result.y:= xyzw;
    Result.z:= xyzw;
    Result.w:= xyzw;
  end;
  {$ENDIF}

  {@abbr`constructor for vec4 with one Float, which is taken for x, y, z and w`}

  function vec4( xy: TVec2; z: Float; w: Float ): TVec4;
  {@abbr`constructor for vec4 with one vec2 which is taken for x and y and two Float, which are taken for z and w`}
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.z:= z;
    Result.w:= w;
  end;
  {$ENDIF}

  function vec4( x: Float; yz: TVec2; w: Float ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yz:= yz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for vec4 with one Float, which is taken for x, one vec2, which is taken for y and z and one Float, which is taken for w`}

  function vec4( x: Float; y: Float; zw: TVec2 ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.y:= y;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for vec4 with two Float, which are taken for x and y and one vec2 which is taken for z and w`}

  function vec4( xy: TVec2; zw: TVec2 ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xy:= xy;
    Result.zw:= zw;
  end;
  {$ENDIF}

  {@abbr`constructor for vec4 with one vec2, which is taken for x and y and one vec2, which is taken for z and w`}

  function vec4( xyz: TVec3; w: Float ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.xyz:= xyz;
    Result.w:= w;
  end;
  {$ENDIF}

  {@abbr`constructor for vec4 with one vec3, which is taken for x, y and z one Float, which is taken for w`}

  function vec4( x: Float; yzw: TVec3 ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.x:= x;
    Result.yzw:= yzw;
  end;
  {$ENDIF}

  {@abbr`constructor for vec4 with one Float, which is taken for x and one vec3 which is taken for y, z and w`}
  {END CONSTRUCTORS}

  function vec4( xyzw: String ): TVec4;
  {$IFDEF IMPLEMENTATION}
  begin
    Result.FromString( xyzw );
  end;
  {$ENDIF}

