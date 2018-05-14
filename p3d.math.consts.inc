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

const
  //@abstract( Constant for converting degrees to radians by multiplying and radians to degress by dividing. ) @br
  //@bold( Example )@br@br
  //@longcode(
  //angle_rad:= 180 * deg2rad; //180 degrees or Pi
  //angle_deg:= Pi / deg2rad; //180 degrees or Pi
  //)

  PI = 3.14159265358979323846264338327950288;
  deg2rad = 0.017453292;
  //Constant used internally to eliminate precision errors.
  epsilon = 1e-40;

  //This is a @link( TVec2 ) constant for the positive X-Axis when working with two dimension.
  vec2_Axis_PX: TVec2 = ( FCoord: ( 1.0, 0.0 ));
  //This is a @link( TVec2 ) constant for the positive Y-Axis when working with two dimension.
  vec2_Axis_PY: TVec2 = ( FCoord: ( 0.0, 1.0 ));
  //This is a @link( TVec2 ) constant for the negative X-Axis when working with two dimension.
  vec2_Axis_NX: TVec2 = ( FCoord: ( -1.0, 0.0 ));
  //This is a @link( TVec2 ) constant for the negative Y-Axis when working with two dimension.
  vec2_Axis_NY: TVec2 = ( FCoord: ( 0.0, -1.0 ));

  //This is a @link( TVec3 ) constant for the positive X-Axis when working with three dimension.
  vec3_Axis_PX: TVec3 = ( FCoord: ( 1.0, 0.0, 0.0 ));
  //This is a @link( TVec3 ) constant for the positive Y-Axis when working with three dimension.
  vec3_Axis_PY: TVec3 = ( FCoord: ( 0.0, 1.0, 0.0 ));
  //This is a @link( TVec3 ) constant for the positive Z-Axis when working with three dimension.
  vec3_Axis_PZ: TVec3 = ( FCoord: ( 0.0, 0.0, 1.0 ));
  //This is a @link( TVec3 ) constant for the negative X-Axis when working with three dimension.
  vec3_Axis_NX: TVec3 = ( FCoord: ( -1.0, 0.0, 0.0 ));
  //This is a @link( TVec3 ) constant for the negative Y-Axis when working with three dimension.
  vec3_Axis_NY: TVec3 = ( FCoord: ( 0.0, -1.0, 0.0 ));
  //This is a @link( TVec3 ) constant for the negative Z-Axis when working with three dimension.
  vec3_Axis_NZ: TVec3 = ( FCoord: ( 0.0, 0.0, -1.0 ));

  //This is a @link(TMat2) constant for an identity matrix. It is almost equivalent to @link(mat2)( 1 )
  //except for the fact that @link(mat2)() calls a function wheras @name is a constant and
  //probably faster.
  Mat2Identity: TMat2 = ( m: ( 1.0, 0.0,
                               0.0, 1.0 ));
  //This is a @link(TMat3) constant for an identity matrix. It is almost equivalent to @link(mat3)( 1 )
  //except for the fact that @link(mat3)() calls a function wheras @name is a constant and
  //probably faster.
  Mat3Identity: TMat3 = ( m: ( 1.0, 0.0, 0.0,
                               0.0, 1.0, 0.0,
                               0.0, 0.0, 1.0 ));
  //This is a @link(TMat4) constant for an identity matrix. It is almost equivalent to @link(mat4)( 1 )
  //except for the fact that @link(mat4)() calls a function wheras @name is a constant and
  //probably faster.
  Mat4Identity: TMat4 = ( m: ( 1.0, 0.0, 0.0, 0.0,
                               0.0, 1.0, 0.0, 0.0,
                               0.0, 0.0, 1.0, 0.0,
                               0.0, 0.0, 0.0, 1.0 ));

  DMat2Identity: TDMat2 = ( m: ( 1.0, 0.0,
                                 0.0, 1.0 ));
  //This is a @link(TMat3) constant for an identity matrix. It is almost equivalent to @link(mat3)( 1 )
  //except for the fact that @link(mat3)() calls a function wheras @name is a constant and
  //probably faster.
  DMat3Identity: TDMat3 = ( m: ( 1.0, 0.0, 0.0,
                                 0.0, 1.0, 0.0,
                                 0.0, 0.0, 1.0 ));
  //This is a @link(TMat4) constant for an identity matrix. It is almost equivalent to @link(mat4)( 1 )
  //except for the fact that @link(mat4)() calls a function wheras @name is a constant and
  //probably faster.
  DMat4Identity: TDMat4 = ( m: ( 1.0, 0.0, 0.0, 0.0,
                                 0.0, 1.0, 0.0, 0.0,
                                 0.0, 0.0, 1.0, 0.0,
                                 0.0, 0.0, 0.0, 1.0 ));

