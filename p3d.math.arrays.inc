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
{$INCLUDE p3d.math.arrays.generics.inc}

{$IFDEF INTERFACE}

  TByteList = specialize gItemList < Byte >;
  TShortIntList = specialize gItemList < ShortInt >;
  TWordList = specialize gItemList < Word >;
  TSmallIntList = specialize gItemList < SmallInt >;
  TIntList = specialize gItemList < Int >;
  TFloatList = specialize gItemList < Float >;
  TDoubleList = specialize gItemList < Double >;
  TVec2List = specialize gItemList < TVec2 >;
  TVec3List = specialize gItemList < TVec3 >;
  TVec4List = specialize gItemList < TVec4 >;
  TDVec2List = specialize gItemList < TDVec2 >;
  TDVec3List = specialize gItemList < TDVec3 >;
  TDVec4List = specialize gItemList < TDVec4 >;
  TIVec2List = specialize gItemList < TIVec2 >;
  TIVec3List = specialize gItemList < TIVec3 >;
  TIVec4List = specialize gItemList < TIVec4 >;
  TQuatList = specialize gItemList < TQuat >;

  TMat2List = specialize gItemList < TMat2 >;
  TMat3List = specialize gItemList < TMat3 >;
  TMat4List = specialize gItemList < TMat4 >;
  TDMat2List = specialize gItemList < TDMat2 >;
  TDMat3List = specialize gItemList < TDMat3 >;
  TDMat4List = specialize gItemList < TDMat4 >;
  TIMat2List = specialize gItemList < TIMat2 >;
  TIMat3List = specialize gItemList < TIMat3 >;
  TIMat4List = specialize gItemList < TIMat4 >;
{$ENDIF}
