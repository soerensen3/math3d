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

unit p3d.math;

{$mode objfpc}{$H+}
{$ModeSwitch advancedrecords}

interface

uses
  Classes, SysUtils, Math, autoobj;

type
  Int = Integer;
  Float = Single;

  TRotationOrder = ( roXYZ = 0, roXZY = 1, roYXZ = 2, roYZX = 3, roZXY = 4, roZYX = 5 );


  {$MACRO ON}

  {$DEFINE INTERFACE}

  {$INCLUDE p3d.math.vector.inc}

  {$INCLUDE p3d.math.matrix.inc}

  {$INCLUDE p3d.math.consts.inc}

  {$INCLUDE p3d.math.conversion.inc}

  {$INCLUDE p3d.math.arrays.inc}

  {$UNDEF INTERFACE}


implementation

{$DEFINE IMPLEMENTATION}

{$INCLUDE p3d.math.vector.inc}

{$INCLUDE p3d.math.matrix.inc}

{$INCLUDE p3d.math.conversion.inc}

{$INCLUDE p3d.math.arrays.inc}

{$UNDEF IMPLEMENTATION}

end.
