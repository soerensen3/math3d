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

  {$DEFINE FieldType:=Float}

  {CONSTRUCTORS}
  { TVec2 }
  {$DEFINE TVECTOR:= TVec2}
  {$DEFINE NUMFIELD:=2}
  {$DEFINE VECTOR:= vec2}

  //function vec2( x: Float; y: Float ); TVec2;
  {@abbr`constructor for vec2 with two floats`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec2( xy: Float ); TVec2;
  {@abbr`constructor for vec2 with one float, which is taken for x and y`}
  {$DEFINE TYPEX:=Fieldtype}
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
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
  {$DEFINE TYPEZ:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec3( xyz: Float ); TVec3;
  {@abbr`constructor for vec3 with one float, which is taken for x, y and z`}
  {$DEFINE TYPEX:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec3( xy: TVec2; z: Float ); TVec3;
  {@abbr`constructor for vec2 with one vec2 which is taken for x and y and one float, which is taken for z`}
  {$DEFINE TYPEX:=TVec2}
  {$DEFINE TYPEZ:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec3( x: Float; yz: TVec2 ); TVec3;
  {@abbr`constructor for vec2 with one float, which is taken for x and one vec2 which is taken for y and z`}
  {$DEFINE TYPEX:=Fieldtype}
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
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
  {$DEFINE TYPEZ:=Fieldtype}
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( xyzw: Float ); TVec4;
  {@abbr`constructor for vec4 with one float, which is taken for x, y, z and w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( xy: TVec2; z: Float; w: Float ); TVec4;
  {@abbr`constructor for vec4 with one vec2 which is taken for x and y and two float, which are taken for z and w`}
  {$DEFINE TYPEX:=TVec2}
  {$DEFINE TYPEZ:=Fieldtype}
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( x: Float; yz: TVec2; w: Float ); TVec4;
  {@abbr`constructor for vec4 with one float, which is taken for x, one vec2, which is taken for y and z and one float, which is taken for w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=TVec2}
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( x: Float; y: Float; zw: TVec2 ); TVec4;
  {@abbr`constructor for vec4 with two float, which are taken for x and y and one vec2 which is taken for z and w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
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
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function vec4( x: Float; yzw: TVec3 ); TVec4;
  {@abbr`constructor for vec4 with one float, which is taken for x and one vec3 which is taken for y, z and w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=TVec3}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  {$DEFINE FieldType:=Int}
  { TIVec2 }
  {$DEFINE TVECTOR:= TIVec2}
  {$DEFINE NUMFIELD:=2}
  {$DEFINE VECTOR:= ivec2}

  //function ivec2( x: Integer; y: Integer ); TIVec2;
  {@abbr`constructor for ivec2 with two floats`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec2( xy: Integer ); TIVec2;
  {@abbr`constructor for ivec2 with one Integer, which is taken for x and y`}
  {$DEFINE TYPEX:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec2( xy: TIVec3 ); TIVec2;
  {@abbr`constructor for ivec2 with one ivec3, where z is truncated`}
  {$DEFINE TYPEX:=TIVec3}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec2( xy: TIVec4 ); TIVec2;
  {@abbr`constructor for ivec2 with one ivec3, where z and w is truncated`}
  {$DEFINE TYPEX:=TIVec4}
  {$INCLUDE p3dmath_vector_constructor_template.inc}


  { TIVec3 }
  {$DEFINE TVECTOR:= TIVec3}
  {$DEFINE NUMFIELD:=3}
  {$DEFINE VECTOR:= ivec3}

  //function ivec3( x: Integer; y: Integer; z: Integer ); TIVec3;
  {@abbr`constructor for ivec3 with three floats`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
  {$DEFINE TYPEZ:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec3( xyz: Integer ); TIVec3;
  {@abbr`constructor for ivec3 with one Integer, which is taken for x, y and z`}
  {$DEFINE TYPEX:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec3( xy: TIVec2; z: Integer ); TIVec3;
  {@abbr`constructor for ivec2 with one ivec2 which is taken for x and y and one Integer, which is taken for z`}
  {$DEFINE TYPEX:=TIVec2}
  {$DEFINE TYPEZ:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec3( x: Integer; yz: TIVec2 ); TIVec3;
  {@abbr`constructor for ivec2 with one Integer, which is taken for x and one ivec2 which is taken for y and z`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=TIVec2}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec3( xyz: TIVec4 ); TIVec3;
  {@abbr`constructor for ivec3 with one ivec4, where w is truncated`}
  {$DEFINE TYPEX:=TIVec4}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  { TIVec4 }
  {$DEFINE TVECTOR:= TIVec4}
  {$DEFINE NUMFIELD:=4}
  {$DEFINE VECTOR:= ivec4}

  //function ivec4( x: Integer; y: Integer; z: Integer; w: Integer ); TIVec4;
  {@abbr`constructor for ivec4 with four floats`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
  {$DEFINE TYPEZ:=Fieldtype}
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec4( xyzw: Integer ); TIVec4;
  {@abbr`constructor for ivec4 with one Integer, which is taken for x, y, z and w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec4( xy: TIVec2; z: Integer; w: Integer ); TIVec4;
  {@abbr`constructor for ivec4 with one ivec2 which is taken for x and y and two Integer, which are taken for z and w`}
  {$DEFINE TYPEX:=TIVec2}
  {$DEFINE TYPEZ:=Fieldtype}
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec4( x: Integer; yz: TIVec2; w: Integer ); TIVec4;
  {@abbr`constructor for ivec4 with one Integer, which is taken for x, one ivec2, which is taken for y and z and one Integer, which is taken for w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=TIVec2}
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec4( x: Integer; y: Integer; zw: TIVec2 ); TIVec4;
  {@abbr`constructor for ivec4 with two Integer, which are taken for x and y and one ivec2 which is taken for z and w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=Fieldtype}
  {$DEFINE TYPEZ:=TIVec2}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec4( xy: TIVec2; zw: TIVec2 ); TIVec4;
  {@abbr`constructor for ivec4 with one ivec2, which is taken for x and y and one ivec2, which is taken for z and w`}
  {$DEFINE TYPEX:=TIVec2}
  {$DEFINE TYPEZ:=TIVec2}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec4( xyz: TIVec3; w: Integer ); TIVec4;
  {@abbr`constructor for ivec4 with one ivec3, which is taken for x, y and z one Integer, which is taken for w`}
  {$DEFINE TYPEX:=TIVec3}
  {$DEFINE TYPEW:=Fieldtype}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  //function ivec4( x: Integer; yzw: TIVec3 ); TIVec4;
  {@abbr`constructor for ivec4 with one Integer, which is taken for x and one ivec3 which is taken for y, z and w`}
  {$DEFINE TYPEX:=Fieldtype}
  {$DEFINE TYPEY:=TIVec3}
  {$INCLUDE p3dmath_vector_constructor_template.inc}

  {$DEFINE FieldType:=Float}

  {END CONSTRUCTORS}
