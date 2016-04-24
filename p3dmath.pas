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

unit p3dMath;

{$mode objfpc}{$H+}

interface

uses
  Classes,
  SysUtils,
  Math;


type
  {$MACRO ON}
  Float = Single;

  { TVec2 }
  {$DEFINE INTERFACE}

  {$DEFINE TVECTOR:= TVec2}
  {$DEFINE NUMFIELD:=2}
  {$INCLUDE p3dmath_vector.inc}

  { TVec3 }
  {$DEFINE TVECTOR:= TVec3}
  {$DEFINE NUMFIELD:=3}
  {$INCLUDE p3dmath_vector.inc}

  { TVec4 }
  {$DEFINE TVECTOR:= TVec4}
  {$DEFINE NUMFIELD:=4}
  {$INCLUDE p3dmath_vector.inc}

  { TMat2 }
  {$DEFINE TMATRIX:= TMat2}
  {$DEFINE TVECTOR:= TVec2}
  {$DEFINE NUMFIELD:=2}
  {$INCLUDE p3dmath_matrix.inc}

  { TMat3 }
  {$DEFINE TMATRIX:= TMat3}
  {$DEFINE TVECTOR:= TVec3}
  {$DEFINE NUMFIELD:=3}
  {$INCLUDE p3dmath_matrix.inc}

  { TMat4 }
  {$DEFINE TMATRIX:= TMat4}
  {$DEFINE TVECTOR:= TVec4}
  {$DEFINE NUMFIELD:=4}
  {$INCLUDE p3dmath_matrix.inc}

  { TQuaternion }
  {$DEFINE TVECTOR:= TVec4}
  {$INCLUDE p3dmath_quaternion.inc}

  {$INCLUDE p3dmath_consts.inc}

  //CONSTRUCTORS
  {$INCLUDE p3dmath_vector_constructors.inc}
  {$INCLUDE p3dmath_matrix_constructors.inc}

  { TVec2 }
  {$DEFINE TVECTOR:= TVec2}
  {$DEFINE NUMFIELD:=2}
  //HELPER FUNCTIONS AND OPERATORS
  {$INCLUDE p3dmath_vector_functions.inc}
  {$INCLUDE p3dmath_vector_op.inc}

  { TVec3 }
  {$DEFINE TVECTOR:= TVec3}
  {$DEFINE NUMFIELD:=3}
  //HELPER FUNCTIONS AND OPERATORS
  {$INCLUDE p3dmath_vector_functions.inc}
  {$INCLUDE p3dmath_vector_op.inc}

  { TVec4 }
  {$DEFINE TVECTOR:= TVec4}
  {$DEFINE NUMFIELD:=4}
  //HELPER FUNCTIONS AND OPERATORS
  {$INCLUDE p3dmath_vector_functions.inc}
  {$INCLUDE p3dmath_vector_op.inc}

  {Type Arrays}
  {$INCLUDE p3dmath_arrays_decl.inc}

  {$UNDEF INTERFACE}

implementation

{$DEFINE IMPLEMENTATION}
{$INCLUDE p3dmath_vector_constructors.inc}
{$INCLUDE p3dmath_matrix_constructors.inc}

{ TVec2 }
{$DEFINE TVECTOR:= TVec2}
{$DEFINE NUMFIELD:=2}
{$DEFINE IMPLEMENTATION}
{$INCLUDE p3dmath_vector.inc}

{ TVec3 }
{$DEFINE TVECTOR:= TVec3}
{$DEFINE NUMFIELD:=3}
{$DEFINE IMPLEMENTATION}
{$INCLUDE p3dmath_vector.inc}

{ TVec4 }
{$DEFINE TVECTOR:= TVec4}
{$DEFINE NUMFIELD:=4}
{$DEFINE IMPLEMENTATION}
{$INCLUDE p3dmath_vector.inc}

{ TMat2 }
{$DEFINE IMPLEMENTATION}
{$DEFINE TMATRIX:= TMat2}
{$DEFINE TVECTOR:= TVec2}
{$DEFINE NUMFIELD:=2}
{$INCLUDE p3dmath_matrix.inc}

{ TMat3 }
{$DEFINE IMPLEMENTATION}
{$DEFINE TMATRIX:= TMat3}
{$DEFINE TVECTOR:= TVec3}
{$DEFINE NUMFIELD:=3}
{$INCLUDE p3dmath_matrix.inc}

{ TMat4 }
{$DEFINE IMPLEMENTATION}
{$DEFINE TMATRIX:= TMat4}
{$DEFINE TVECTOR:= TVec4}
{$DEFINE NUMFIELD:=4}
{$INCLUDE p3dmath_matrix.inc}

{ TQuaternion }
{$DEFINE IMPLEMENTATION}
{$DEFINE TVECTOR:= TVec4}
{$INCLUDE p3dmath_quaternion.inc}


{Type Arrays}
{$DEFINE IMPLEMENTATION}

{$INCLUDE p3dmath_arrays_decl.inc}

end.

