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
  {$DEFINE TVECTOR:= TVec2}
  {$DEFINE NUMFIELD:=2}
  {$DEFINE VECTOR:= vec2}

  //function vec2( x: Float; y: Float ); TVec2;
  {@abbr`constructor for vec2 with two floats`}
  {$DEFINE TYPEX:=Float}
  {$DEFINE TYPEY:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec2( xy: Float ); TVec2;
  {@abbr`constructor for vec2 with one float, which is taken for x and y`}
  {$DEFINE TYPEX:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec2( xy: TVec3 ); TVec2;
  {@abbr`constructor for vec2 with one vec3, where z is truncated`}
  {$DEFINE TYPEX:=TVec3}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec2( xy: TVec4 ); TVec2;
  {@abbr`constructor for vec2 with one vec3, where z and w is truncated`}
  {$DEFINE TYPEX:=TVec4}
  {$INCLUDE p3dmath_vector_constructor_template.inc}


  { TVec3 }
  {$DEFINE TVECTOR:= TVec3}
  {$DEFINE NUMFIELD:=3}
  {$DEFINE VECTOR:= vec3}

  //function vec3( x: Float; y: Float; z: Float ); TVec3;
  {@abbr`constructor for vec3 with three floats`}
  {$DEFINE TYPEX:=Float}
  {$DEFINE TYPEY:=Float}
  {$DEFINE TYPEZ:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec3( xyz: Float ); TVec3;
  {@abbr`constructor for vec3 with one float, which is taken for x, y and z`}
  {$DEFINE TYPEX:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec3( xy: TVec2; z: Float ); TVec3;
  {@abbr`constructor for vec2 with one vec2 which is taken for x and y and one float, which is taken for z`}
  {$DEFINE TYPEX:=TVec2}
  {$DEFINE TYPEZ:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec3( x: Float; yz: TVec2 ); TVec3;
  {@abbr`constructor for vec2 with one float, which is taken for x and one vec2 which is taken for y and z`}
  {$DEFINE TYPEX:=Float}
  {$DEFINE TYPEY:=TVec2}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec3( xyz: TVec4 ); TVec3;
  {@abbr`constructor for vec3 with one vec4, where w is truncated`}
  {$DEFINE TYPEX:=TVec4}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  { TVec4 }
  {$DEFINE TVECTOR:= TVec4}
  {$DEFINE NUMFIELD:=4}
  {$DEFINE VECTOR:= vec4}

  //function vec4( x: Float; y: Float; z: Float; w: Float ); TVec4;
  {@abbr`constructor for vec4 with four floats`}
  {$DEFINE TYPEX:=Float}
  {$DEFINE TYPEY:=Float}
  {$DEFINE TYPEZ:=Float}
  {$DEFINE TYPEW:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( xyzw: Float ); TVec4;
  {@abbr`constructor for vec4 with one float, which is taken for x, y, z and w`}
  {$DEFINE TYPEX:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( xy: TVec2; z: Float; w: Float ); TVec4;
  {@abbr`constructor for vec4 with one vec2 which is taken for x and y and two float, which are taken for z and w`}
  {$DEFINE TYPEX:=TVec2}
  {$DEFINE TYPEZ:=Float}
  {$DEFINE TYPEW:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( x: Float; yz: TVec2; w: Float ); TVec4;
  {@abbr`constructor for vec4 with one float, which is taken for x, one vec2, which is taken for y and z and one float, which is taken for w`}
  {$DEFINE TYPEX:=Float}
  {$DEFINE TYPEY:=TVec2}
  {$DEFINE TYPEW:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( x: Float; y: Float; zw: TVec2 ); TVec4;
  {@abbr`constructor for vec4 with two float, which are taken for x and y and one vec2 which is taken for z and w`}
  {$DEFINE TYPEX:=Float}
  {$DEFINE TYPEY:=Float}
  {$DEFINE TYPEZ:=TVec2}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( xy: TVec2; zw: TVec2 ); TVec4;
  {@abbr`constructor for vec4 with one vec2, which is taken for x and y and one vec2, which is taken for z and w`}
  {$DEFINE TYPEX:=TVec2}
  {$DEFINE TYPEZ:=TVec2}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( xyz: TVec3; w: Float ); TVec4;
  {@abbr`constructor for vec4 with one vec3, which is taken for x, y and z one float, which is taken for w`}
  {$DEFINE TYPEX:=TVec3}
  {$DEFINE TYPEW:=Float}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( x: Float; yzw: TVec3 ); TVec4;
  {@abbr`constructor for vec4 with one float, which is taken for x and one vec3 which is taken for y, z and w`}
  {$DEFINE TYPEX:=Float}
  {$DEFINE TYPEY:=TVec3}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  {END CONSTRUCTORS}
