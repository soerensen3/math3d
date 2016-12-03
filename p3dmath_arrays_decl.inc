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
  {$IFDEF INTERFACE}
  type
    TItemListOnChangeAction = ( actAdd, actDelete, actClear, actAssignBefore, actAssignAfter, actSet );
    TItemListOnChangeEvent = procedure ( Sender: TPersistent; ItemIndex: Integer; Action: TItemListOnChangeAction ) of object;
  {$ENDIF}

  {$DEFINE TItem:= Byte}
  {$DEFINE TItemArray:= TByteArray}
  {$DEFINE TItemList:=
    { TByteList }

    { TByteList }

    { TByteList }

    TByteList}
  {$DEFINE pItemArray:= pByteArray}
  {$DEFINE TListEnumerator:= TByteListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= ShortInt}
  {$DEFINE TItemArray:= TShortIntArray}
  {$DEFINE TItemList:= TShortIntList}
  {$DEFINE pItemArray:= pShortIntArray}
  {$DEFINE TListEnumerator:= TShortIntListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= Word}
  {$DEFINE TItemArray:= TWordArray}
  {$DEFINE TItemList:= TWordList}
  {$DEFINE pItemArray:= pWordArray}
  {$DEFINE TListEnumerator:= TWordListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= SmallInt}
  {$DEFINE TItemArray:= TSmallIntArray}
  {$DEFINE TItemList:= TSmallIntList}
  {$DEFINE pItemArray:= pSmallIntArray}
  {$DEFINE TListEnumerator:= TSmallIntListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= LongInt}
  {$DEFINE TItemArray:= TIntArray}
  {$DEFINE TItemList:= TIntList}
  {$DEFINE pItemArray:= pIntArray}
  {$DEFINE TListEnumerator:= TIntListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= Float}
  {$DEFINE TItemArray:= TFloatArray}
  {$DEFINE TItemList:= TFloatList}
  {$DEFINE pItemArray:= pFloatArray}
  {$DEFINE TListEnumerator:= TFloatListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TVec2}
  {$DEFINE TItemArray:= TVec2Array}
  {$DEFINE TItemList:= TVec2List}
  {$DEFINE pItemArray:= pVec2Array}
  {$DEFINE TListEnumerator:= TVec2ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TVec3}
  {$DEFINE TItemArray:= TVec3Array}
  {$DEFINE TItemList:= TVec3List}
  {$DEFINE pItemArray:= pVec3Array}
  {$DEFINE TListEnumerator:= TVec3ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TVec4}
  {$DEFINE TItemArray:= TVec4Array}
  {$DEFINE TItemList:= TVec4List}
  {$DEFINE pItemArray:= pVec4Array}
  {$DEFINE TListEnumerator:= TVec4ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TQuaternion}
  {$DEFINE TItemArray:= TQuaternionArray}
  {$DEFINE TItemList:= TQuaternionList}
  {$DEFINE pItemArray:= pQuaternionArray}
  {$DEFINE TListEnumerator:= TQuaternionListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TIVec2}
  {$DEFINE TItemArray:= TIVec2Array}
  {$DEFINE TItemList:= TIVec2List}
  {$DEFINE pItemArray:= pIVec2Array}
  {$DEFINE TListEnumerator:= TIVec2ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TIVec3}
  {$DEFINE TItemArray:= TIVec3Array}
  {$DEFINE TItemList:= TIVec3List}
  {$DEFINE pItemArray:= pIVec3Array}
  {$DEFINE TListEnumerator:= TIVec3ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TIVec4}
  {$DEFINE TItemArray:= TIVec4Array}
  {$DEFINE TItemList:= TIVec4List}
  {$DEFINE pItemArray:= pIVec4Array}
  {$DEFINE TListEnumerator:= TIVec4ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TMat2}
  {$DEFINE TItemArray:= TMat2Array}
  {$DEFINE TItemList:= TMat2List}
  {$DEFINE pItemArray:= pMat2Array}
  {$DEFINE TListEnumerator:= TMat2ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TMat3}
  {$DEFINE TItemArray:= TMat3Array}
  {$DEFINE TItemList:= TMat3List}
  {$DEFINE pItemArray:= pMat3Array}
  {$DEFINE TListEnumerator:= TMat3ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}

  {$DEFINE TItem:= TMat4}
  {$DEFINE TItemArray:= TMat4Array}
  {$DEFINE TItemList:= TMat4List}
  {$DEFINE pItemArray:= pMat4Array}
  {$DEFINE TListEnumerator:= TMat4ListEnumerator}
  {$INCLUDE p3dmath_arrays.inc}
