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

{$IF FIELDTYPE = Float}
  {$DEFINE TV2:= TVec2}
  {$DEFINE v2:= vec2}
  {$DEFINE TV3:= TVec3}
  {$DEFINE v3:= vec3}
  {$DEFINE TV4:= TVec4}
  {$DEFINE v4:= vec4}
{$ENDIF}
{$IF FIELDTYPE = Double}
  {$DEFINE TV2:= TDVec2}
  {$DEFINE v2:= dvec2}
  {$DEFINE TV3:= TDVec3}
  {$DEFINE v3:= dvec3}
  {$DEFINE TV4:= TDVec4}
  {$DEFINE v4:= dvec4}
{$ENDIF}
{$IF FIELDTYPE = Int}
  {$DEFINE TV2:= TIVec2}
  {$DEFINE v2:= ivec2}
  {$DEFINE TV3:= TIVec3}
  {$DEFINE v3:= ivec3}
  {$DEFINE TV4:= TIVec4}
  {$DEFINE v4:= ivec4}
{$ENDIF}

{$IFDEF INTERFACE}

private
  {$IF NUMFIELD > 1}
  {@exclude} function GetVec2( AIndex: Integer ): TV2;
  {@exclude} procedure SetVec2( AIndex: Integer; AValue: TV2 );
  {$ENDIF}
  {$IF NUMFIELD > 2}
  {@exclude} function GetVec3( AIndex: Integer ): TV3;
  {@exclude} procedure SetVec3( AIndex: Integer; AValue: TV3 );
  {$ENDIF}
  {$IF NUMFIELD > 3}
  {@exclude} function GetVec4( AIndex: Integer ): TV4;
  //{@exclude} procedure SetVec4( AIndex: Integer; AValue: TV4 );
  {$ENDIF}
public
  {$IF NUMFIELD>1}
  {@exclude} property XX: TV2 index 00 read GetVec2;
  {@exclude} property XY: TV2 index 01 read GetVec2 write SetVec2;
    {$IF NUMFIELD>2}
  {@exclude} property XZ: TV2 index 02 read GetVec2 write SetVec2;
    {$ENDIF}
    {$IF NUMFIELD>3}
  {@exclude} property XW: TV2 index 03 read GetVec2 write SetVec2;
    {$ENDIF}

  {@exclude} property YX: TV2 index 10 read GetVec2 write SetVec2;
  {@exclude} property YY: TV2 index 11 read GetVec2;
    {$IF NUMFIELD>2}
  {@exclude} property YZ: TV2 index 12 read GetVec2 write SetVec2;
    {$ENDIF}
    {$IF NUMFIELD>3}
  {@exclude} property YW: TV2 index 13 read GetVec2 write SetVec2;
    {$ENDIF}
    {$IF NUMFIELD>2}
  {@exclude} property ZX: TV2 index 20 read GetVec2 write SetVec2;
  {@exclude} property ZY: TV2 index 21 read GetVec2 write SetVec2;
  {@exclude} property ZZ: TV2 index 22 read GetVec2;
    {$ENDIF}
    {$IF NUMFIELD>3}
  {@exclude} property ZW: TV2 index 23 read GetVec2 write SetVec2;

  {@exclude} property WX: TV2 index 30 read GetVec2 write SetVec2;
  {@exclude} property WY: TV2 index 31 read GetVec2 write SetVec2;
  {@exclude} property WZ: TV2 index 32 read GetVec2 write SetVec2;
  {@exclude} property WW: TV2 index 33 read GetVec2;
    {$ENDIF}
  {$ENDIF}

  {$IF NUMFIELD>2}
  {@exclude} property XXX: TV3 index 000 read GetVec3;
  {@exclude} property XXY: TV3 index 001 read GetVec3;
  {@exclude} property XXZ: TV3 index 002 read GetVec3;
  {$IF NUMFIELD>3}
  {@exclude} property XXW: TV3 index 003 read GetVec3;
  {$ENDIF}
  {@exclude} property XYX: TV3 index 010 read GetVec3;
  {@exclude} property XYY: TV3 index 011 read GetVec3;
  {@exclude} property XYZ: TV3 index 012 read GetVec3 write SetVec3;
  {$IF NUMFIELD>3}
  {@exclude} property XYW: TV3 index 013 read GetVec3 write SetVec3;
  {$ENDIF}
  {@exclude} property XZX: TV3 index 020 read GetVec3;
  {@exclude} property XZY: TV3 index 021 read GetVec3 write SetVec3;
  {@exclude} property XZZ: TV3 index 022 read GetVec3;
  {$IF NUMFIELD>3}
  {@exclude} property XZW: TV3 index 023 read GetVec3 write SetVec3;
  {$ENDIF}

  {@exclude} property YXX: TV3 index 100 read GetVec3;
  {@exclude} property YXY: TV3 index 101 read GetVec3;
  {@exclude} property YXZ: TV3 index 102 read GetVec3 write SetVec3;
  {$IF NUMFIELD>3}
  {@exclude} property YXW: TV3 index 103 read GetVec3 write SetVec3;
  {$ENDIF}

  {@exclude} property YYX: TV3 index 110 read GetVec3;
  {@exclude} property YYY: TV3 index 111 read GetVec3;
  {@exclude} property YYZ: TV3 index 112 read GetVec3;
  {$IF NUMFIELD>3}
  {@exclude} property YYW: TV3 index 113 read GetVec3;
  {$ENDIF}

  {@exclude} property YZX: TV3 index 120 read GetVec3 write SetVec3;
  {@exclude} property YZY: TV3 index 121 read GetVec3;
  {@exclude} property YZZ: TV3 index 122 read GetVec3;
  {$IF NUMFIELD>3}
  {@exclude} property YZW: TV3 index 123 read GetVec3 write SetVec3;
  {$ENDIF}

  {@exclude} property ZXX: TV3 index 200 read GetVec3;
  {@exclude} property ZXY: TV3 index 201 read GetVec3 write SetVec3;
  {@exclude} property ZXZ: TV3 index 202 read GetVec3;
  {$IF NUMFIELD>3}
  {@exclude} property ZXW: TV3 index 203 read GetVec3 write SetVec3;
  {$ENDIF}

  {@exclude} property ZYX: TV3 index 210 read GetVec3 write SetVec3;
  {@exclude} property ZYY: TV3 index 211 read GetVec3;
  {@exclude} property ZYZ: TV3 index 212 read GetVec3;
  {$IF NUMFIELD>3}
   {@exclude} property ZYW: TV3 index 213 read GetVec3 write SetVec3;
  {$ENDIF}

   {@exclude} property ZZX: TV3 index 220 read GetVec3;
   {@exclude} property ZZY: TV3 index 221 read GetVec3;
   {@exclude} property ZZZ: TV3 index 222 read GetVec3;
  {$IF NUMFIELD>3}
   {@exclude} property ZZW: TV3 index 223 read GetVec3;

   {@exclude} property WXX: TV3 index 300 read GetVec3;
   {@exclude} property WXY: TV3 index 301 read GetVec3 write SetVec3;
   {@exclude} property WXZ: TV3 index 302 read GetVec3 write SetVec3;
   {@exclude} property WXW: TV3 index 303 read GetVec3 write SetVec3;

   {@exclude} property WYX: TV3 index 310 read GetVec3 write SetVec3;
   {@exclude} property WYY: TV3 index 311 read GetVec3;
   {@exclude} property WYZ: TV3 index 312 read GetVec3 write SetVec3;
   {@exclude} property WYW: TV3 index 313 read GetVec3;

   {@exclude} property WZX: TV3 index 320 read GetVec3 write SetVec3;
   {@exclude} property WZY: TV3 index 321 read GetVec3 write SetVec3;
   {@exclude} property WZZ: TV3 index 322 read GetVec3;
   {@exclude} property WZW: TV3 index 323 read GetVec3;

   {@exclude} property WWX: TV3 index 330 read GetVec3;
   {@exclude} property WWY: TV3 index 331 read GetVec3;
   {@exclude} property WWZ: TV3 index 332 read GetVec3;
   {@exclude} property WWW: TV3 index 333 read GetVec3;

   {@exclude} property XXXX: TV4 index 0000 read GetVec4;
   {@exclude} property XXXY: TV4 index 0001 read GetVec4;
   {@exclude} property XXXZ: TV4 index 0002 read GetVec4;
   {@exclude} property XXXW: TV4 index 0003 read GetVec4;

   {@exclude} property XXYX: TV4 index 0010 read GetVec4;
   {@exclude} property XXYY: TV4 index 0011 read GetVec4;
   {@exclude} property XXYZ: TV4 index 0012 read GetVec4;
   {@exclude} property XXYW: TV4 index 0013 read GetVec4;

   {@exclude} property XXZX: TV4 index 0020 read GetVec4;
   {@exclude} property XXZY: TV4 index 0021 read GetVec4;
   {@exclude} property XXZZ: TV4 index 0022 read GetVec4;
   {@exclude} property XXZW: TV4 index 0023 read GetVec4;

   {@exclude} property XXWX: TV4 index 0030 read GetVec4;
   {@exclude} property XXWY: TV4 index 0031 read GetVec4;
   {@exclude} property XXWZ: TV4 index 0032 read GetVec4;
   {@exclude} property XXWW: TV4 index 0033 read GetVec4;


   {@exclude} property XYXX: TV4 index 0100 read GetVec4;
   {@exclude} property XYXY: TV4 index 0101 read GetVec4;
   {@exclude} property XYXZ: TV4 index 0102 read GetVec4;
   {@exclude} property XYXW: TV4 index 0103 read GetVec4;

   {@exclude} property XYYX: TV4 index 0110 read GetVec4;
   {@exclude} property XYYY: TV4 index 0111 read GetVec4;
   {@exclude} property XYYZ: TV4 index 0112 read GetVec4;
   {@exclude} property XYYW: TV4 index 0113 read GetVec4;

   {@exclude} property XYZX: TV4 index 0120 read GetVec4;
   {@exclude} property XYZY: TV4 index 0121 read GetVec4;
   {@exclude} property XYZZ: TV4 index 0122 read GetVec4;
   {@exclude} property XYZW: TV4 index 0123 read GetVec4;

   {@exclude} property XYWX: TV4 index 0130 read GetVec4;
   {@exclude} property XYWY: TV4 index 0131 read GetVec4;
   {@exclude} property XYWZ: TV4 index 0132 read GetVec4;
   {@exclude} property XYWW: TV4 index 0133 read GetVec4;


   {@exclude} property XZXX: TV4 index 0200 read GetVec4;
   {@exclude} property XZXY: TV4 index 0201 read GetVec4;
   {@exclude} property XZXZ: TV4 index 0202 read GetVec4;
   {@exclude} property XZXW: TV4 index 0203 read GetVec4;

   {@exclude} property XZYX: TV4 index 0210 read GetVec4;
   {@exclude} property XZYY: TV4 index 0211 read GetVec4;
   {@exclude} property XZYZ: TV4 index 0212 read GetVec4;
   {@exclude} property XZYW: TV4 index 0213 read GetVec4;

   {@exclude} property XZZX: TV4 index 0220 read GetVec4;
   {@exclude} property XZZY: TV4 index 0221 read GetVec4;
   {@exclude} property XZZZ: TV4 index 0222 read GetVec4;
   {@exclude} property XZZW: TV4 index 0223 read GetVec4;

   {@exclude} property XZWX: TV4 index 0230 read GetVec4;
   {@exclude} property XZWY: TV4 index 0231 read GetVec4;
   {@exclude} property XZWZ: TV4 index 0232 read GetVec4;
   {@exclude} property XZWW: TV4 index 0233 read GetVec4;


   {@exclude} property XWXX: TV4 index 0300 read GetVec4;
   {@exclude} property XWXY: TV4 index 0301 read GetVec4;
   {@exclude} property XWXZ: TV4 index 0302 read GetVec4;
   {@exclude} property XWXW: TV4 index 0303 read GetVec4;

   {@exclude} property XWYX: TV4 index 0310 read GetVec4;
   {@exclude} property XWYY: TV4 index 0311 read GetVec4;
   {@exclude} property XWYZ: TV4 index 0312 read GetVec4;
   {@exclude} property XWYW: TV4 index 0313 read GetVec4;

   {@exclude} property XWZX: TV4 index 0320 read GetVec4;
   {@exclude} property XWZY: TV4 index 0321 read GetVec4;
   {@exclude} property XWZZ: TV4 index 0322 read GetVec4;
   {@exclude} property XWZW: TV4 index 0323 read GetVec4;

   {@exclude} property XWWX: TV4 index 0330 read GetVec4;
   {@exclude} property XWWY: TV4 index 0331 read GetVec4;
   {@exclude} property XWWZ: TV4 index 0332 read GetVec4;
   {@exclude} property XWWW: TV4 index 0333 read GetVec4;



   {@exclude} property YXXX: TV4 index 1000 read GetVec4;
   {@exclude} property YXXY: TV4 index 1001 read GetVec4;
   {@exclude} property YXXZ: TV4 index 1002 read GetVec4;
   {@exclude} property YXXW: TV4 index 1003 read GetVec4;

   {@exclude} property YXYX: TV4 index 1010 read GetVec4;
   {@exclude} property YXYY: TV4 index 1011 read GetVec4;
   {@exclude} property YXYZ: TV4 index 1012 read GetVec4;
   {@exclude} property YXYW: TV4 index 1013 read GetVec4;

   {@exclude} property YXZX: TV4 index 1020 read GetVec4;
   {@exclude} property YXZY: TV4 index 1021 read GetVec4;
   {@exclude} property YXZZ: TV4 index 1022 read GetVec4;
   {@exclude} property YXZW: TV4 index 1023 read GetVec4;

   {@exclude} property YXWX: TV4 index 1030 read GetVec4;
   {@exclude} property YXWY: TV4 index 1031 read GetVec4;
   {@exclude} property YXWZ: TV4 index 1032 read GetVec4;
   {@exclude} property YXWW: TV4 index 1033 read GetVec4;


   {@exclude} property YYXX: TV4 index 1100 read GetVec4;
   {@exclude} property YYXY: TV4 index 1101 read GetVec4;
   {@exclude} property YYXZ: TV4 index 1102 read GetVec4;
   {@exclude} property YYXW: TV4 index 1103 read GetVec4;

   {@exclude} property YYYX: TV4 index 1110 read GetVec4;
   {@exclude} property YYYY: TV4 index 1111 read GetVec4;
   {@exclude} property YYYZ: TV4 index 1112 read GetVec4;
   {@exclude} property YYYW: TV4 index 1113 read GetVec4;

   {@exclude} property YYZX: TV4 index 1120 read GetVec4;
   {@exclude} property YYZY: TV4 index 1121 read GetVec4;
   {@exclude} property YYZZ: TV4 index 1122 read GetVec4;
   {@exclude} property YYZW: TV4 index 1123 read GetVec4;

   {@exclude} property YYWX: TV4 index 1130 read GetVec4;
   {@exclude} property YYWY: TV4 index 1131 read GetVec4;
   {@exclude} property YYWZ: TV4 index 1132 read GetVec4;
   {@exclude} property YYWW: TV4 index 1133 read GetVec4;


   {@exclude} property YZXX: TV4 index 1200 read GetVec4;
   {@exclude} property YZXY: TV4 index 1201 read GetVec4;
   {@exclude} property YZXZ: TV4 index 1202 read GetVec4;
   {@exclude} property YZXW: TV4 index 1203 read GetVec4;

   {@exclude} property YZYX: TV4 index 1210 read GetVec4;
   {@exclude} property YZYY: TV4 index 1211 read GetVec4;
   {@exclude} property YZYZ: TV4 index 1212 read GetVec4;
   {@exclude} property YZYW: TV4 index 1213 read GetVec4;

   {@exclude} property YZZX: TV4 index 1220 read GetVec4;
   {@exclude} property YZZY: TV4 index 1221 read GetVec4;
   {@exclude} property YZZZ: TV4 index 1222 read GetVec4;
   {@exclude} property YZZW: TV4 index 1223 read GetVec4;

   {@exclude} property YZWX: TV4 index 1230 read GetVec4;
   {@exclude} property YZWY: TV4 index 1231 read GetVec4;
   {@exclude} property YZWZ: TV4 index 1232 read GetVec4;
   {@exclude} property YZWW: TV4 index 1233 read GetVec4;


   {@exclude} property YWXX: TV4 index 1300 read GetVec4;
   {@exclude} property YWXY: TV4 index 1301 read GetVec4;
   {@exclude} property YWXZ: TV4 index 1302 read GetVec4;
   {@exclude} property YWXW: TV4 index 1303 read GetVec4;

   {@exclude} property YWYX: TV4 index 1310 read GetVec4;
   {@exclude} property YWYY: TV4 index 1311 read GetVec4;
   {@exclude} property YWYZ: TV4 index 1312 read GetVec4;
   {@exclude} property YWYW: TV4 index 1313 read GetVec4;

   {@exclude} property YWZX: TV4 index 1320 read GetVec4;
   {@exclude} property YWZY: TV4 index 1321 read GetVec4;
   {@exclude} property YWZZ: TV4 index 1322 read GetVec4;
   {@exclude} property YWZW: TV4 index 1323 read GetVec4;

   {@exclude} property YWWX: TV4 index 1330 read GetVec4;
   {@exclude} property YWWY: TV4 index 1331 read GetVec4;
   {@exclude} property YWWZ: TV4 index 1332 read GetVec4;
   {@exclude} property YWWW: TV4 index 1333 read GetVec4;

   {@exclude} property ZXXX: TV4 index 2000 read GetVec4;
   {@exclude} property ZXXY: TV4 index 2001 read GetVec4;
   {@exclude} property ZXXZ: TV4 index 2002 read GetVec4;
   {@exclude} property ZXXW: TV4 index 2003 read GetVec4;

   {@exclude} property ZXYX: TV4 index 2010 read GetVec4;
   {@exclude} property ZXYY: TV4 index 2011 read GetVec4;
   {@exclude} property ZXYZ: TV4 index 2012 read GetVec4;
   {@exclude} property ZXYW: TV4 index 2013 read GetVec4;

   {@exclude} property ZXZX: TV4 index 2020 read GetVec4;
   {@exclude} property ZXZY: TV4 index 2021 read GetVec4;
   {@exclude} property ZXZZ: TV4 index 2022 read GetVec4;
   {@exclude} property ZXZW: TV4 index 2023 read GetVec4;

   {@exclude} property ZXWX: TV4 index 2030 read GetVec4;
   {@exclude} property ZXWY: TV4 index 2031 read GetVec4;
   {@exclude} property ZXWZ: TV4 index 2032 read GetVec4;
   {@exclude} property ZXWW: TV4 index 2033 read GetVec4;


   {@exclude} property ZYXX: TV4 index 2100 read GetVec4;
   {@exclude} property ZYXY: TV4 index 2101 read GetVec4;
   {@exclude} property ZYXZ: TV4 index 2102 read GetVec4;
   {@exclude} property ZYXW: TV4 index 2103 read GetVec4;

   {@exclude} property ZYYX: TV4 index 2110 read GetVec4;
   {@exclude} property ZYYY: TV4 index 2111 read GetVec4;
   {@exclude} property ZYYZ: TV4 index 2112 read GetVec4;
   {@exclude} property ZYYW: TV4 index 2113 read GetVec4;

   {@exclude} property ZYZX: TV4 index 2120 read GetVec4;
   {@exclude} property ZYZY: TV4 index 2121 read GetVec4;
   {@exclude} property ZYZZ: TV4 index 2122 read GetVec4;
   {@exclude} property ZYZW: TV4 index 2123 read GetVec4;

   {@exclude} property ZYWX: TV4 index 2130 read GetVec4;
   {@exclude} property ZYWY: TV4 index 2131 read GetVec4;
   {@exclude} property ZYWZ: TV4 index 2132 read GetVec4;
   {@exclude} property ZYWW: TV4 index 2133 read GetVec4;


   {@exclude} property ZZXX: TV4 index 2200 read GetVec4;
   {@exclude} property ZZXY: TV4 index 2201 read GetVec4;
   {@exclude} property ZZXZ: TV4 index 2202 read GetVec4;
   {@exclude} property ZZXW: TV4 index 2203 read GetVec4;

   {@exclude} property ZZYX: TV4 index 2210 read GetVec4;
   {@exclude} property ZZYY: TV4 index 2211 read GetVec4;
   {@exclude} property ZZYZ: TV4 index 2212 read GetVec4;
   {@exclude} property ZZYW: TV4 index 2213 read GetVec4;

   {@exclude} property ZZZX: TV4 index 2220 read GetVec4;
   {@exclude} property ZZZY: TV4 index 2221 read GetVec4;
   {@exclude} property ZZZZ: TV4 index 2222 read GetVec4;
   {@exclude} property ZZZW: TV4 index 2223 read GetVec4;

   {@exclude} property ZZWX: TV4 index 2230 read GetVec4;
   {@exclude} property ZZWY: TV4 index 2231 read GetVec4;
   {@exclude} property ZZWZ: TV4 index 2232 read GetVec4;
   {@exclude} property ZZWW: TV4 index 2233 read GetVec4;


   {@exclude} property ZWXX: TV4 index 2300 read GetVec4;
   {@exclude} property ZWXY: TV4 index 2301 read GetVec4;
   {@exclude} property ZWXZ: TV4 index 2302 read GetVec4;
   {@exclude} property ZWXW: TV4 index 2303 read GetVec4;

   {@exclude} property ZWYX: TV4 index 2310 read GetVec4;
   {@exclude} property ZWYY: TV4 index 2311 read GetVec4;
   {@exclude} property ZWYZ: TV4 index 2312 read GetVec4;
   {@exclude} property ZWYW: TV4 index 2313 read GetVec4;

   {@exclude} property ZWZX: TV4 index 2320 read GetVec4;
   {@exclude} property ZWZY: TV4 index 2321 read GetVec4;
   {@exclude} property ZWZZ: TV4 index 2322 read GetVec4;
   {@exclude} property ZWZW: TV4 index 2323 read GetVec4;

   {@exclude} property ZWWX: TV4 index 2330 read GetVec4;
   {@exclude} property ZWWY: TV4 index 2331 read GetVec4;
   {@exclude} property ZWWZ: TV4 index 2332 read GetVec4;
   {@exclude} property ZWWW: TV4 index 2333 read GetVec4;

   {@exclude} property WXXX: TV4 index 3000 read GetVec4;
   {@exclude} property WXXY: TV4 index 3001 read GetVec4;
   {@exclude} property WXXZ: TV4 index 3002 read GetVec4;
   {@exclude} property WXXW: TV4 index 3003 read GetVec4;

   {@exclude} property WXYX: TV4 index 3010 read GetVec4;
   {@exclude} property WXYY: TV4 index 3011 read GetVec4;
   {@exclude} property WXYZ: TV4 index 3012 read GetVec4;
   {@exclude} property WXYW: TV4 index 3013 read GetVec4;

   {@exclude} property WXZX: TV4 index 3020 read GetVec4;
   {@exclude} property WXZY: TV4 index 3021 read GetVec4;
   {@exclude} property WXZZ: TV4 index 3022 read GetVec4;
   {@exclude} property WXZW: TV4 index 3023 read GetVec4;

   {@exclude} property WXWX: TV4 index 3030 read GetVec4;
   {@exclude} property WXWY: TV4 index 3031 read GetVec4;
   {@exclude} property WXWZ: TV4 index 3032 read GetVec4;
   {@exclude} property WXWW: TV4 index 3033 read GetVec4;


   {@exclude} property WYXX: TV4 index 3100 read GetVec4;
   {@exclude} property WYXY: TV4 index 3101 read GetVec4;
   {@exclude} property WYXZ: TV4 index 3102 read GetVec4;
   {@exclude} property WYXW: TV4 index 3103 read GetVec4;

   {@exclude} property WYYX: TV4 index 3110 read GetVec4;
   {@exclude} property WYYY: TV4 index 3111 read GetVec4;
   {@exclude} property WYYZ: TV4 index 3112 read GetVec4;
   {@exclude} property WYYW: TV4 index 3113 read GetVec4;

   {@exclude} property WYZX: TV4 index 3120 read GetVec4;
   {@exclude} property WYZY: TV4 index 3121 read GetVec4;
   {@exclude} property WYZZ: TV4 index 3122 read GetVec4;
   {@exclude} property WYZW: TV4 index 3123 read GetVec4;

   {@exclude} property WYWX: TV4 index 3130 read GetVec4;
   {@exclude} property WYWY: TV4 index 3131 read GetVec4;
   {@exclude} property WYWZ: TV4 index 3132 read GetVec4;
   {@exclude} property WYWW: TV4 index 3133 read GetVec4;


   {@exclude} property WZXX: TV4 index 3200 read GetVec4;
   {@exclude} property WZXY: TV4 index 3201 read GetVec4;
   {@exclude} property WZXZ: TV4 index 3202 read GetVec4;
   {@exclude} property WZXW: TV4 index 3203 read GetVec4;

   {@exclude} property WZYX: TV4 index 3210 read GetVec4;
   {@exclude} property WZYY: TV4 index 3211 read GetVec4;
   {@exclude} property WZYZ: TV4 index 3212 read GetVec4;
   {@exclude} property WZYW: TV4 index 3213 read GetVec4;

   {@exclude} property WZZX: TV4 index 3220 read GetVec4;
   {@exclude} property WZZY: TV4 index 3221 read GetVec4;
   {@exclude} property WZZZ: TV4 index 3222 read GetVec4;
   {@exclude} property WZZW: TV4 index 3223 read GetVec4;

   {@exclude} property WZWX: TV4 index 3230 read GetVec4;
   {@exclude} property WZWY: TV4 index 3231 read GetVec4;
   {@exclude} property WZWZ: TV4 index 3232 read GetVec4;
   {@exclude} property WZWW: TV4 index 3233 read GetVec4;


   {@exclude} property WWXX: TV4 index 3300 read GetVec4;
   {@exclude} property WWXY: TV4 index 3301 read GetVec4;
   {@exclude} property WWXZ: TV4 index 3302 read GetVec4;
   {@exclude} property WWXW: TV4 index 3303 read GetVec4;

   {@exclude} property WWYX: TV4 index 3310 read GetVec4;
   {@exclude} property WWYY: TV4 index 3311 read GetVec4;
   {@exclude} property WWYZ: TV4 index 3312 read GetVec4;
   {@exclude} property WWYW: TV4 index 3313 read GetVec4;

   {@exclude} property WWZX: TV4 index 3320 read GetVec4;
   {@exclude} property WWZY: TV4 index 3321 read GetVec4;
   {@exclude} property WWZZ: TV4 index 3322 read GetVec4;
   {@exclude} property WWZW: TV4 index 3323 read GetVec4;

   {@exclude} property WWWX: TV4 index 3330 read GetVec4;
   {@exclude} property WWWY: TV4 index 3331 read GetVec4;
   {@exclude} property WWWZ: TV4 index 3332 read GetVec4;
   {@exclude} property WWWW: TV4 index 3333 read GetVec4;
   {$ENDIF}
  {$ENDIF}

    {$IF NUMFIELD>1}
    {@exclude} property RR: TV2 index 00 read GetVec2 write SetVec2;
    {@exclude} property RG: TV2 index 01 read GetVec2 write SetVec2;
      {$IF NUMFIELD>2}
    {@exclude} property RB: TV2 index 02 read GetVec2 write SetVec2;
      {$ENDIF}
      {$IF NUMFIELD>3}
    {@exclude} property RA: TV2 index 03 read GetVec2 write SetVec2;
      {$ENDIF}

    {@exclude} property GR: TV2 index 10 read GetVec2 write SetVec2;
    {@exclude} property GG: TV2 index 11 read GetVec2 write SetVec2;
      {$IF NUMFIELD>2}
    {@exclude} property GB: TV2 index 12 read GetVec2 write SetVec2;
      {$ENDIF}
      {$IF NUMFIELD>3}
    {@exclude} property GA: TV2 index 13 read GetVec2 write SetVec2;
      {$ENDIF}
      {$IF NUMFIELD>2}
    {@exclude} property BR: TV2 index 20 read GetVec2 write SetVec2;
    {@exclude} property BG: TV2 index 21 read GetVec2 write SetVec2;
    {@exclude} property BB: TV2 index 22 read GetVec2 write SetVec2;
      {$ENDIF}
      {$IF NUMFIELD>3}
    {@exclude} property BA: TV2 index 23 read GetVec2 write SetVec2;

    {@exclude} property AR: TV2 index 30 read GetVec2 write SetVec2;
    {@exclude} property AG: TV2 index 31 read GetVec2 write SetVec2;
    {@exclude} property AB: TV2 index 32 read GetVec2 write SetVec2;
    {@exclude} property AA: TV2 index 33 read GetVec2 write SetVec2;
      {$ENDIF}
    {$ENDIF}

    {$IF NUMFIELD>2}
    {@exclude} property RRR: TV3 index 000 read GetVec3;
    {@exclude} property RRG: TV3 index 001 read GetVec3;
    {@exclude} property RRB: TV3 index 002 read GetVec3;
    {$IF NUMFIELD>3}
    {@exclude} property RRA: TV3 index 003 read GetVec3;
    {$ENDIF}
    {@exclude} property RGR: TV3 index 010 read GetVec3;
    {@exclude} property RGG: TV3 index 011 read GetVec3;
    {@exclude} property RGB: TV3 index 012 read GetVec3;
    {$IF NUMFIELD>3}
    {@exclude} property RGA: TV3 index 013 read GetVec3;
    {$ENDIF}
    {@exclude} property RBR: TV3 index 020 read GetVec3;
    {@exclude} property RBG: TV3 index 021 read GetVec3;
    {@exclude} property RBB: TV3 index 022 read GetVec3;
    {$IF NUMFIELD>3}
    {@exclude} property RBA: TV3 index 023 read GetVec3;
    {$ENDIF}

    {@exclude} property GRR: TV3 index 100 read GetVec3;
    {@exclude} property GRG: TV3 index 101 read GetVec3;
    {@exclude} property GRB: TV3 index 102 read GetVec3;
    {$IF NUMFIELD>3}
    {@exclude} property GRA: TV3 index 103 read GetVec3;
    {$ENDIF}

    {@exclude} property GGR: TV3 index 110 read GetVec3;
    {@exclude} property GGG: TV3 index 111 read GetVec3;
    {@exclude} property GGB: TV3 index 112 read GetVec3;
    {$IF NUMFIELD>3}
    {@exclude} property GGA: TV3 index 113 read GetVec3;
    {$ENDIF}

    {@exclude} property GBR: TV3 index 120 read GetVec3;
    {@exclude} property GBG: TV3 index 121 read GetVec3;
    {@exclude} property GBB: TV3 index 122 read GetVec3;
    {$IF NUMFIELD>3}
    {@exclude} property GBA: TV3 index 123 read GetVec3;
    {$ENDIF}

    {@exclude} property BRR: TV3 index 200 read GetVec3;
    {@exclude} property BRG: TV3 index 201 read GetVec3;
    {@exclude} property BRB: TV3 index 202 read GetVec3;
    {$IF NUMFIELD>3}
    {@exclude} property BRA: TV3 index 203 read GetVec3;
    {$ENDIF}

    {@exclude} property BGR: TV3 index 210 read GetVec3;
    {@exclude} property BGG: TV3 index 211 read GetVec3;
    {@exclude} property BGB: TV3 index 212 read GetVec3;
  {$IF NUMFIELD>3}
   {@exclude} property BGA: TV3 index 213 read GetVec3;
  {$ENDIF}

   {@exclude} property BBR: TV3 index 220 read GetVec3;
   {@exclude} property BBG: TV3 index 221 read GetVec3;
   {@exclude} property BBB: TV3 index 222 read GetVec3;
  {$IF NUMFIELD>3}
   {@exclude} property BBA: TV3 index 223 read GetVec3;

   {@exclude} property ARR: TV3 index 300 read GetVec3;
   {@exclude} property ARG: TV3 index 301 read GetVec3;
   {@exclude} property ARB: TV3 index 302 read GetVec3;
   {@exclude} property ARA: TV3 index 303 read GetVec3;

   {@exclude} property AGR: TV3 index 310 read GetVec3;
   {@exclude} property AGG: TV3 index 311 read GetVec3;
   {@exclude} property AGB: TV3 index 312 read GetVec3;
   {@exclude} property AGA: TV3 index 313 read GetVec3;

   {@exclude} property ABR: TV3 index 320 read GetVec3;
   {@exclude} property ABG: TV3 index 321 read GetVec3;
   {@exclude} property ABB: TV3 index 322 read GetVec3;
   {@exclude} property ABA: TV3 index 323 read GetVec3;

   {@exclude} property AAR: TV3 index 330 read GetVec3;
   {@exclude} property AAG: TV3 index 331 read GetVec3;
   {@exclude} property AAB: TV3 index 332 read GetVec3;
   {@exclude} property AAA: TV3 index 333 read GetVec3;

   {@exclude} property RRRR: TV4 index 0000 read GetVec4;
   {@exclude} property RRRG: TV4 index 0001 read GetVec4;
   {@exclude} property RRRB: TV4 index 0002 read GetVec4;
   {@exclude} property RRRA: TV4 index 0003 read GetVec4;

   {@exclude} property RRGR: TV4 index 0010 read GetVec4;
   {@exclude} property RRGG: TV4 index 0011 read GetVec4;
   {@exclude} property RRGB: TV4 index 0012 read GetVec4;
   {@exclude} property RRGA: TV4 index 0013 read GetVec4;

   {@exclude} property RRBR: TV4 index 0020 read GetVec4;
   {@exclude} property RRBG: TV4 index 0021 read GetVec4;
   {@exclude} property RRBB: TV4 index 0022 read GetVec4;
   {@exclude} property RRBA: TV4 index 0023 read GetVec4;

   {@exclude} property RRAR: TV4 index 0030 read GetVec4;
   {@exclude} property RRAG: TV4 index 0031 read GetVec4;
   {@exclude} property RRAB: TV4 index 0032 read GetVec4;
   {@exclude} property RRAA: TV4 index 0033 read GetVec4;


   {@exclude} property RGRR: TV4 index 0100 read GetVec4;
   {@exclude} property RGRG: TV4 index 0101 read GetVec4;
   {@exclude} property RGRB: TV4 index 0102 read GetVec4;
   {@exclude} property RGRA: TV4 index 0103 read GetVec4;

   {@exclude} property RGGR: TV4 index 0110 read GetVec4;
   {@exclude} property RGGG: TV4 index 0111 read GetVec4;
   {@exclude} property RGGB: TV4 index 0112 read GetVec4;
   {@exclude} property RGGA: TV4 index 0113 read GetVec4;

   {@exclude} property RGBR: TV4 index 0120 read GetVec4;
   {@exclude} property RGBG: TV4 index 0121 read GetVec4;
   {@exclude} property RGBB: TV4 index 0122 read GetVec4;
   {@exclude} property RGBA: TV4 index 0123 read GetVec4;

   {@exclude} property RGAR: TV4 index 0130 read GetVec4;
   {@exclude} property RGAG: TV4 index 0131 read GetVec4;
   {@exclude} property RGAB: TV4 index 0132 read GetVec4;
   {@exclude} property RGAA: TV4 index 0133 read GetVec4;


   {@exclude} property RBRR: TV4 index 0200 read GetVec4;
   {@exclude} property RBRG: TV4 index 0201 read GetVec4;
   {@exclude} property RBRB: TV4 index 0202 read GetVec4;
   {@exclude} property RBRA: TV4 index 0203 read GetVec4;

   {@exclude} property RBGR: TV4 index 0210 read GetVec4;
   {@exclude} property RBGG: TV4 index 0211 read GetVec4;
   {@exclude} property RBGB: TV4 index 0212 read GetVec4;
   {@exclude} property RBGA: TV4 index 0213 read GetVec4;

   {@exclude} property RBBR: TV4 index 0220 read GetVec4;
   {@exclude} property RBBG: TV4 index 0221 read GetVec4;
   {@exclude} property RBBB: TV4 index 0222 read GetVec4;
   {@exclude} property RBBA: TV4 index 0223 read GetVec4;

   {@exclude} property RBAR: TV4 index 0230 read GetVec4;
   {@exclude} property RBAG: TV4 index 0231 read GetVec4;
   {@exclude} property RBAB: TV4 index 0232 read GetVec4;
   {@exclude} property RBAA: TV4 index 0233 read GetVec4;


   {@exclude} property RARR: TV4 index 0300 read GetVec4;
   {@exclude} property RARG: TV4 index 0301 read GetVec4;
   {@exclude} property RARB: TV4 index 0302 read GetVec4;
   {@exclude} property RARA: TV4 index 0303 read GetVec4;

   {@exclude} property RAGR: TV4 index 0310 read GetVec4;
   {@exclude} property RAGG: TV4 index 0311 read GetVec4;
   {@exclude} property RAGB: TV4 index 0312 read GetVec4;
   {@exclude} property RAGA: TV4 index 0313 read GetVec4;

   {@exclude} property RABR: TV4 index 0320 read GetVec4;
   {@exclude} property RABG: TV4 index 0321 read GetVec4;
   {@exclude} property RABB: TV4 index 0322 read GetVec4;
   {@exclude} property RABA: TV4 index 0323 read GetVec4;

   {@exclude} property RAAR: TV4 index 0330 read GetVec4;
   {@exclude} property RAAG: TV4 index 0331 read GetVec4;
   {@exclude} property RAAB: TV4 index 0332 read GetVec4;
   {@exclude} property RAAA: TV4 index 0333 read GetVec4;



   {@exclude} property GRRR: TV4 index 1000 read GetVec4;
   {@exclude} property GRRG: TV4 index 1001 read GetVec4;
   {@exclude} property GRRB: TV4 index 1002 read GetVec4;
   {@exclude} property GRRA: TV4 index 1003 read GetVec4;

   {@exclude} property GRGR: TV4 index 1010 read GetVec4;
   {@exclude} property GRGG: TV4 index 1011 read GetVec4;
   {@exclude} property GRGB: TV4 index 1012 read GetVec4;
   {@exclude} property GRGA: TV4 index 1013 read GetVec4;

   {@exclude} property GRBR: TV4 index 1020 read GetVec4;
   {@exclude} property GRBG: TV4 index 1021 read GetVec4;
   {@exclude} property GRBB: TV4 index 1022 read GetVec4;
   {@exclude} property GRBA: TV4 index 1023 read GetVec4;

   {@exclude} property GRAR: TV4 index 1030 read GetVec4;
   {@exclude} property GRAG: TV4 index 1031 read GetVec4;
   {@exclude} property GRAB: TV4 index 1032 read GetVec4;
   {@exclude} property GRAA: TV4 index 1033 read GetVec4;


   {@exclude} property GGRR: TV4 index 1100 read GetVec4;
   {@exclude} property GGRG: TV4 index 1101 read GetVec4;
   {@exclude} property GGRB: TV4 index 1102 read GetVec4;
   {@exclude} property GGRA: TV4 index 1103 read GetVec4;

   {@exclude} property GGGR: TV4 index 1110 read GetVec4;
   {@exclude} property GGGG: TV4 index 1111 read GetVec4;
   {@exclude} property GGGB: TV4 index 1112 read GetVec4;
   {@exclude} property GGGA: TV4 index 1113 read GetVec4;

   {@exclude} property GGBR: TV4 index 1120 read GetVec4;
   {@exclude} property GGBG: TV4 index 1121 read GetVec4;
   {@exclude} property GGBB: TV4 index 1122 read GetVec4;
   {@exclude} property GGBA: TV4 index 1123 read GetVec4;

   {@exclude} property GGAR: TV4 index 1130 read GetVec4;
   {@exclude} property GGAG: TV4 index 1131 read GetVec4;
   {@exclude} property GGAB: TV4 index 1132 read GetVec4;
   {@exclude} property GGAA: TV4 index 1133 read GetVec4;


   {@exclude} property GBRR: TV4 index 1200 read GetVec4;
   {@exclude} property GBRG: TV4 index 1201 read GetVec4;
   {@exclude} property GBRB: TV4 index 1202 read GetVec4;
   {@exclude} property GBRA: TV4 index 1203 read GetVec4;

   {@exclude} property GBGR: TV4 index 1210 read GetVec4;
   {@exclude} property GBGG: TV4 index 1211 read GetVec4;
   {@exclude} property GBGB: TV4 index 1212 read GetVec4;
   {@exclude} property GBGA: TV4 index 1213 read GetVec4;

   {@exclude} property GBBR: TV4 index 1220 read GetVec4;
   {@exclude} property GBBG: TV4 index 1221 read GetVec4;
   {@exclude} property GBBB: TV4 index 1222 read GetVec4;
   {@exclude} property GBBA: TV4 index 1223 read GetVec4;

   {@exclude} property GBAR: TV4 index 1230 read GetVec4;
   {@exclude} property GBAG: TV4 index 1231 read GetVec4;
   {@exclude} property GBAB: TV4 index 1232 read GetVec4;
   {@exclude} property GBAA: TV4 index 1233 read GetVec4;


   {@exclude} property GARR: TV4 index 1300 read GetVec4;
   {@exclude} property GARG: TV4 index 1301 read GetVec4;
   {@exclude} property GARB: TV4 index 1302 read GetVec4;
   {@exclude} property GARA: TV4 index 1303 read GetVec4;

   {@exclude} property GAGR: TV4 index 1310 read GetVec4;
   {@exclude} property GAGG: TV4 index 1311 read GetVec4;
   {@exclude} property GAGB: TV4 index 1312 read GetVec4;
   {@exclude} property GAGA: TV4 index 1313 read GetVec4;

   {@exclude} property GABR: TV4 index 1320 read GetVec4;
   {@exclude} property GABG: TV4 index 1321 read GetVec4;
   {@exclude} property GABB: TV4 index 1322 read GetVec4;
   {@exclude} property GABA: TV4 index 1323 read GetVec4;

   {@exclude} property GAAR: TV4 index 1330 read GetVec4;
   {@exclude} property GAAG: TV4 index 1331 read GetVec4;
   {@exclude} property GAAB: TV4 index 1332 read GetVec4;
   {@exclude} property GAAA: TV4 index 1333 read GetVec4;

   {@exclude} property BRRR: TV4 index 2000 read GetVec4;
   {@exclude} property BRRG: TV4 index 2001 read GetVec4;
   {@exclude} property BRRB: TV4 index 2002 read GetVec4;
   {@exclude} property BRRA: TV4 index 2003 read GetVec4;

   {@exclude} property BRGR: TV4 index 2010 read GetVec4;
   {@exclude} property BRGG: TV4 index 2011 read GetVec4;
   {@exclude} property BRGB: TV4 index 2012 read GetVec4;
   {@exclude} property BRGA: TV4 index 2013 read GetVec4;

   {@exclude} property BRBR: TV4 index 2020 read GetVec4;
   {@exclude} property BRBG: TV4 index 2021 read GetVec4;
   {@exclude} property BRBB: TV4 index 2022 read GetVec4;
   {@exclude} property BRBA: TV4 index 2023 read GetVec4;

   {@exclude} property BRAR: TV4 index 2030 read GetVec4;
   {@exclude} property BRAG: TV4 index 2031 read GetVec4;
   {@exclude} property BRAB: TV4 index 2032 read GetVec4;
   {@exclude} property BRAA: TV4 index 2033 read GetVec4;


   {@exclude} property BGRR: TV4 index 2100 read GetVec4;
   {@exclude} property BGRG: TV4 index 2101 read GetVec4;
   {@exclude} property BGRB: TV4 index 2102 read GetVec4;
   {@exclude} property BGRA: TV4 index 2103 read GetVec4;

   {@exclude} property BGGR: TV4 index 2110 read GetVec4;
   {@exclude} property BGGG: TV4 index 2111 read GetVec4;
   {@exclude} property BGGB: TV4 index 2112 read GetVec4;
   {@exclude} property BGGA: TV4 index 2113 read GetVec4;

   {@exclude} property BGBR: TV4 index 2120 read GetVec4;
   {@exclude} property BGBG: TV4 index 2121 read GetVec4;
   {@exclude} property BGBB: TV4 index 2122 read GetVec4;
   {@exclude} property BGBA: TV4 index 2123 read GetVec4;

   {@exclude} property BGAR: TV4 index 2130 read GetVec4;
   {@exclude} property BGAG: TV4 index 2131 read GetVec4;
   {@exclude} property BGAB: TV4 index 2132 read GetVec4;
   {@exclude} property BGAA: TV4 index 2133 read GetVec4;


   {@exclude} property BBRR: TV4 index 2200 read GetVec4;
   {@exclude} property BBRG: TV4 index 2201 read GetVec4;
   {@exclude} property BBRB: TV4 index 2202 read GetVec4;
   {@exclude} property BBRA: TV4 index 2203 read GetVec4;

   {@exclude} property BBGR: TV4 index 2210 read GetVec4;
   {@exclude} property BBGG: TV4 index 2211 read GetVec4;
   {@exclude} property BBGB: TV4 index 2212 read GetVec4;
   {@exclude} property BBGA: TV4 index 2213 read GetVec4;

   {@exclude} property BBBR: TV4 index 2220 read GetVec4;
   {@exclude} property BBBG: TV4 index 2221 read GetVec4;
   {@exclude} property BBBB: TV4 index 2222 read GetVec4;
   {@exclude} property BBBA: TV4 index 2223 read GetVec4;

   {@exclude} property BBAR: TV4 index 2230 read GetVec4;
   {@exclude} property BBAG: TV4 index 2231 read GetVec4;
   {@exclude} property BBAB: TV4 index 2232 read GetVec4;
   {@exclude} property BBAA: TV4 index 2233 read GetVec4;


   {@exclude} property BARR: TV4 index 2300 read GetVec4;
   {@exclude} property BARG: TV4 index 2301 read GetVec4;
   {@exclude} property BARB: TV4 index 2302 read GetVec4;
   {@exclude} property BARA: TV4 index 2303 read GetVec4;

   {@exclude} property BAGR: TV4 index 2310 read GetVec4;
   {@exclude} property BAGG: TV4 index 2311 read GetVec4;
   {@exclude} property BAGB: TV4 index 2312 read GetVec4;
   {@exclude} property BAGA: TV4 index 2313 read GetVec4;

   {@exclude} property BABR: TV4 index 2320 read GetVec4;
   {@exclude} property BABG: TV4 index 2321 read GetVec4;
   {@exclude} property BABB: TV4 index 2322 read GetVec4;
   {@exclude} property BABA: TV4 index 2323 read GetVec4;

   {@exclude} property BAAR: TV4 index 2330 read GetVec4;
   {@exclude} property BAAG: TV4 index 2331 read GetVec4;
   {@exclude} property BAAB: TV4 index 2332 read GetVec4;
   {@exclude} property BAAA: TV4 index 2333 read GetVec4;

   {@exclude} property ARRR: TV4 index 3000 read GetVec4;
   {@exclude} property ARRG: TV4 index 3001 read GetVec4;
   {@exclude} property ARRB: TV4 index 3002 read GetVec4;
   {@exclude} property ARRA: TV4 index 3003 read GetVec4;

   {@exclude} property ARGR: TV4 index 3010 read GetVec4;
   {@exclude} property ARGG: TV4 index 3011 read GetVec4;
   {@exclude} property ARGB: TV4 index 3012 read GetVec4;
   {@exclude} property ARGA: TV4 index 3013 read GetVec4;

   {@exclude} property ARBR: TV4 index 3020 read GetVec4;
   {@exclude} property ARBG: TV4 index 3021 read GetVec4;
   {@exclude} property ARBB: TV4 index 3022 read GetVec4;
   {@exclude} property ARBA: TV4 index 3023 read GetVec4;

   {@exclude} property ARAR: TV4 index 3030 read GetVec4;
   {@exclude} property ARAG: TV4 index 3031 read GetVec4;
   {@exclude} property ARAB: TV4 index 3032 read GetVec4;
   {@exclude} property ARAA: TV4 index 3033 read GetVec4;


   {@exclude} property AGRR: TV4 index 3100 read GetVec4;
   {@exclude} property AGRG: TV4 index 3101 read GetVec4;
   {@exclude} property AGRB: TV4 index 3102 read GetVec4;
   {@exclude} property AGRA: TV4 index 3103 read GetVec4;

   {@exclude} property AGGR: TV4 index 3110 read GetVec4;
   {@exclude} property AGGG: TV4 index 3111 read GetVec4;
   {@exclude} property AGGB: TV4 index 3112 read GetVec4;
   {@exclude} property AGGA: TV4 index 3113 read GetVec4;

   {@exclude} property AGBR: TV4 index 3120 read GetVec4;
   {@exclude} property AGBG: TV4 index 3121 read GetVec4;
   {@exclude} property AGBB: TV4 index 3122 read GetVec4;
   {@exclude} property AGBA: TV4 index 3123 read GetVec4;

   {@exclude} property AGAR: TV4 index 3130 read GetVec4;
   {@exclude} property AGAG: TV4 index 3131 read GetVec4;
   {@exclude} property AGAB: TV4 index 3132 read GetVec4;
   {@exclude} property AGAA: TV4 index 3133 read GetVec4;


   {@exclude} property ABRR: TV4 index 3200 read GetVec4;
   {@exclude} property ABRG: TV4 index 3201 read GetVec4;
   {@exclude} property ABRB: TV4 index 3202 read GetVec4;
   {@exclude} property ABRA: TV4 index 3203 read GetVec4;

   {@exclude} property ABGR: TV4 index 3210 read GetVec4;
   {@exclude} property ABGG: TV4 index 3211 read GetVec4;
   {@exclude} property ABGB: TV4 index 3212 read GetVec4;
   {@exclude} property ABGA: TV4 index 3213 read GetVec4;

   {@exclude} property ABBR: TV4 index 3220 read GetVec4;
   {@exclude} property ABBG: TV4 index 3221 read GetVec4;
   {@exclude} property ABBB: TV4 index 3222 read GetVec4;
   {@exclude} property ABBA: TV4 index 3223 read GetVec4;

   {@exclude} property ABAR: TV4 index 3230 read GetVec4;
   {@exclude} property ABAG: TV4 index 3231 read GetVec4;
   {@exclude} property ABAB: TV4 index 3232 read GetVec4;
   {@exclude} property ABAA: TV4 index 3233 read GetVec4;


   {@exclude} property AARR: TV4 index 3300 read GetVec4;
   {@exclude} property AARG: TV4 index 3301 read GetVec4;
   {@exclude} property AARB: TV4 index 3302 read GetVec4;
   {@exclude} property AARA: TV4 index 3303 read GetVec4;

   {@exclude} property AAGR: TV4 index 3310 read GetVec4;
   {@exclude} property AAGG: TV4 index 3311 read GetVec4;
   {@exclude} property AAGB: TV4 index 3312 read GetVec4;
   {@exclude} property AAGA: TV4 index 3313 read GetVec4;

   {@exclude} property AABR: TV4 index 3320 read GetVec4;
   {@exclude} property AABG: TV4 index 3321 read GetVec4;
   {@exclude} property AABB: TV4 index 3322 read GetVec4;
   {@exclude} property AABA: TV4 index 3323 read GetVec4;

   {@exclude} property AAAR: TV4 index 3330 read GetVec4;
   {@exclude} property AAAG: TV4 index 3331 read GetVec4;
   {@exclude} property AAAB: TV4 index 3332 read GetVec4;
   {@exclude} property AAAA: TV4 index 3333 read GetVec4;

  {$ENDIF}

  {$ENDIF}
{$ENDIF}
{$IFDEF IMPLEMENTATION}
  function TVector.GetVec2( AIndex: Integer ): TV2;
  begin
    case AIndex of
      00: Result:= v2( X );
      01: Result:= v2( X, Y );
      {$IF NUMFIELD > 2}
      02: Result:= v2( X, Z );
      {$ENDIF}
      {$IF NUMFIELD > 3}
      03: Result:= v2( X, W );
      {$ENDIF}

      10: Result:= v2( Y, X );
      11: Result:= v2( Y );
      {$IF NUMFIELD > 2}
      12: Result:= v2( Y, Z );
      {$ENDIF}
      {$IF NUMFIELD > 3}
      13: Result:= v2( Y, W );
      {$ENDIF}

      {$IF NUMFIELD > 2}
      20: Result:= v2( Z, X );
      21: Result:= v2( Z, Y );
      22: Result:= v2( Z );
      {$ENDIF}
      {$IF NUMFIELD > 3}
      23: Result:= v2( Z, W );
      {$ENDIF}
      {$IF NUMFIELD > 3}
      30: Result:= v2( W, X );
      31: Result:= v2( W, Y );
      32: Result:= v2( W, Z );
      33: Result:= v2( W );
      {$ENDIF}

      else Result:= v2( -1 ); //THIS SHOULD NEVER HAPPEN
    end;
  end;

  procedure TVector.SetVec2( AIndex: Integer; AValue: TV2 );
  begin
    case AIndex of
      00: begin x:= AValue.y; end;
      01: begin x:= AValue.x; y:= AValue.y; end;
      {$IF NUMFIELD > 2}
      02: begin x:= AValue.x; z:= AValue.y; end;
      {$ENDIF}
      {$IF NUMFIELD > 3}
      03: begin x:= AValue.x; w:= AValue.y; end;
      {$ENDIF}

      10: begin y:= AValue.x; x:= AValue.y; end;
      11: begin y:= AValue.y; end;
      {$IF NUMFIELD > 2}
      12: begin y:= AValue.x; z:= AValue.y; end;
      {$ENDIF}
      {$IF NUMFIELD > 3}
      13: begin y:= AValue.x; w:= AValue.y; end;
      {$ENDIF}

      {$IF NUMFIELD > 2}
      20: begin z:= AValue.x; x:= AValue.y; end;
      21: begin z:= AValue.x; y:= AValue.y; end;
      22: begin z:= AValue.y; end;
      {$ENDIF}
      {$IF NUMFIELD > 3}
      23: begin z:= AValue.x; w:= AValue.y; end;
      {$ENDIF}
      {$IF NUMFIELD > 3}
      30: begin w:= AValue.x; x:= AValue.y; end;
      31: begin w:= AValue.x; y:= AValue.y; end;
      32: begin w:= AValue.x; z:= AValue.y; end;
      33: begin w:= AValue.y; end;
      {$ENDIF}
    end;
  end;

  {$IF NUMFIELD > 2}
  function TVector.GetVec3( AIndex: Integer ): TV3;
  begin
    case AIndex of
      000:  Result:= v3( X );
      001:  Result:= v3( X, X, Y );
      002:  Result:= v3( X, X, Z );
      {$IF NUMFIELD > 3}
      003:  Result:= v3( X, X, W );
      {$ENDIF}

      010:  Result:= v3( X, Y, X );
      011:  Result:= v3( X, Y, Y );
      012:  Result:= v3( X, Y, Z );
      {$IF NUMFIELD > 3}
      013:  Result:= v3( X, Y, W );
      {$ENDIF}

      020:  Result:= v3( X, Z, X );
      021:  Result:= v3( X, Z, Y );
      022:  Result:= v3( X, Z, Z );
      {$IF NUMFIELD > 3}
      023:  Result:= v3( X, Z, W );
      {$ENDIF}

      {$IF NUMFIELD > 3}
      030:  Result:= v3( X, W, X );
      031:  Result:= v3( X, W, Y );
      032:  Result:= v3( X, W, Z );
      033:  Result:= v3( X, W, W );
      {$ENDIF}

      100:  Result:= v3( Y, X, X );
      101:  Result:= v3( Y, X, Y );
      102:  Result:= v3( Y, X, Z );
      {$IF NUMFIELD > 3}
      103:  Result:= v3( Y, X, W );
      {$ENDIF}

      110:  Result:= v3( Y, Y, X );
      111:  Result:= v3( Y );
      112:  Result:= v3( Y, Y, Z );
      {$IF NUMFIELD > 3}
      113:  Result:= v3( Y, Y, W );
      {$ENDIF}

      120:  Result:= v3( Y, Z, X );
      121:  Result:= v3( Y, Z, Y );
      122:  Result:= v3( Y, Z, Z );
      {$IF NUMFIELD > 3}
      123:  Result:= v3( Y, Z, W );
      {$ENDIF}

      {$IF NUMFIELD > 3}
      130:  Result:= v3( Y, W, X );
      131:  Result:= v3( Y, W, Y );
      132:  Result:= v3( Y, W, Z );
      133:  Result:= v3( Y, W, W );
      {$ENDIF}

      200:  Result:= v3( Z, X, X );
      201:  Result:= v3( Z, X, Y );
      202:  Result:= v3( Z, X, Z );
      {$IF NUMFIELD > 3}
      203:  Result:= v3( Z, X, W );
      {$ENDIF}

      210:  Result:= v3( Z, Y, X );
      211:  Result:= v3( Z, Y, Y );
      212:  Result:= v3( Z, Y, Z );
      {$IF NUMFIELD > 3}
      213:  Result:= v3( Z, Y, W );
      {$ENDIF}

      220:  Result:= v3( Z, Z, X );
      221:  Result:= v3( Z, Z, Y );
      222:  Result:= v3( Z );
      {$IF NUMFIELD > 3}
      223:  Result:= v3( Z, Z, W );
      {$ENDIF}

      {$IF NUMFIELD > 3}
      230:  Result:= v3( Z, W, X );
      231:  Result:= v3( Z, W, Y );
      232:  Result:= v3( Z, W, Z );
      233:  Result:= v3( Z, W, W );
      {$ENDIF}

      {$IF NUMFIELD > 3}
      300:  Result:= v3( W, X, X );
      301:  Result:= v3( W, X, Y );
      302:  Result:= v3( W, X, Z );
      303:  Result:= v3( W, X, W );

      310:  Result:= v3( W, Y, X );
      311:  Result:= v3( W, Y, Y );
      312:  Result:= v3( W, Y, Z );
      313:  Result:= v3( W, Y, W );

      320:  Result:= v3( W, Z, X );
      321:  Result:= v3( W, Z, Y );
      322:  Result:= v3( W, Z, Z );
      323:  Result:= v3( W, Z, W );

      330:  Result:= v3( W, W, X );
      331:  Result:= v3( W, W, Y );
      332:  Result:= v3( W, W, Z );
      333:  Result:= v3( W );
      {$ENDIF}

      else Result:= v3( -1 ); //THIS SHOULD NEVER HAPPEN
    end;
  end;

  procedure TVector.SetVec3( AIndex: Integer; AValue: TV3 );
  begin
    case AIndex of
      012:  begin x:= AValue.x; y:= AValue.y; z:= AValue.z; end;
      {$IF NUMFIELD > 3}
      013:  begin x:= AValue.x; y:= AValue.y; w:= AValue.z; end;
      {$ENDIF}

      021:  begin x:= AValue.x; z:= AValue.y; y:= AValue.z; end;
      {$IF NUMFIELD > 3}
      023:  begin x:= AValue.x; z:= AValue.y; w:= AValue.z; end;
      {$ENDIF}

      {$IF NUMFIELD > 3}
      031:  begin x:= AValue.x; w:= AValue.y; y:= AValue.z; end;
      032:  begin x:= AValue.x; w:= AValue.y; z:= AValue.z; end;
      {$ENDIF}

      102:  begin y:= AValue.x; x:= AValue.y; z:= AValue.z; end;
      {$IF NUMFIELD > 3}
      103:  begin y:= AValue.x; x:= AValue.y; w:= AValue.z; end;
      {$ENDIF}

      120:  begin y:= AValue.x; z:= AValue.y; x:= AValue.z; end;
      {$IF NUMFIELD > 3}
      123:  begin y:= AValue.x; z:= AValue.y; w:= AValue.z; end;
      {$ENDIF}

      {$IF NUMFIELD > 3}
      130:  begin y:= AValue.x; w:= AValue.y; x:= AValue.z; end;
      132:  begin y:= AValue.x; w:= AValue.y; z:= AValue.z; end;
      {$ENDIF}

      201:  begin z:= AValue.y; x:= AValue.z; y:= AValue.z; end;
      {$IF NUMFIELD > 3}
      203:  begin z:= AValue.y; x:= AValue.z; w:= AValue.z; end;
      {$ENDIF}

      210:  begin z:= AValue.y; y:= AValue.z; x:= AValue.z; end;
      {$IF NUMFIELD > 3}
      213:  begin z:= AValue.y; y:= AValue.z; w:= AValue.z; end;
      {$ENDIF}

      {$IF NUMFIELD > 3}
      230:  begin z:= AValue.y; w:= AValue.z; x:= AValue.z; end;
      231:  begin z:= AValue.y; w:= AValue.z; y:= AValue.z; end;
      {$ENDIF}

      {$IF NUMFIELD > 3}
      301:  begin w:= AValue.y; x:= AValue.z; y:= AValue.z; end;
      302:  begin w:= AValue.y; x:= AValue.z; z:= AValue.z; end;

      310:  begin w:= AValue.y; y:= AValue.z; x:= AValue.z; end;
      312:  begin w:= AValue.y; y:= AValue.z; z:= AValue.z; end;

      320:  begin w:= AValue.y; z:= AValue.z; x:= AValue.z; end;
      321:  begin w:= AValue.y; z:= AValue.z; y:= AValue.z; end;
      {$ENDIF}
    end;
  end;
  {$ENDIF}

  {$IF NUMFIELD > 3}
  function TVector.GetVec4( AIndex: Integer ): TV4;
  begin
    case AIndex of
      0000:  Result:= v4( X, X, X, X );
      0001:  Result:= v4( X, X, X, Y );
      0002:  Result:= v4( X, X, X, Z );
      0003:  Result:= v4( X, X, X, W );

      0010:  Result:= v4( X, X, Y, X );
      0011:  Result:= v4( X, X, Y, Y );
      0012:  Result:= v4( X, X, Y, Z );
      0013:  Result:= v4( X, X, Y, W );

      0020:  Result:= v4( X, X, Z, X );
      0021:  Result:= v4( X, X, Z, Y );
      0022:  Result:= v4( X, X, Z, Z );
      0023:  Result:= v4( X, X, Z, W );

      0030:  Result:= v4( X, X, W, X );
      0031:  Result:= v4( X, X, W, Y );
      0032:  Result:= v4( X, X, W, Z );
      0033:  Result:= v4( X, X, W, W );


      0100:  Result:= v4( X, Y, X, X );
      0101:  Result:= v4( X, Y, X, Y );
      0102:  Result:= v4( X, Y, X, Z );
      0103:  Result:= v4( X, Y, X, W );

      0110:  Result:= v4( X, Y, Y, X );
      0111:  Result:= v4( X, Y, Y, Y );
      0112:  Result:= v4( X, Y, Y, Z );
      0113:  Result:= v4( X, Y, Y, W );

      0120:  Result:= v4( X, Y, Z, X );
      0121:  Result:= v4( X, Y, Z, Y );
      0122:  Result:= v4( X, Y, Z, Z );
      0123:  Result:= v4( X, Y, Z, W );

      0130:  Result:= v4( X, Y, W, X );
      0131:  Result:= v4( X, Y, W, Y );
      0132:  Result:= v4( X, Y, W, Z );
      0133:  Result:= v4( X, Y, W, W );


      0200:  Result:= v4( X, Z, X, X );
      0201:  Result:= v4( X, Z, X, Y );
      0202:  Result:= v4( X, Z, X, Z );
      0203:  Result:= v4( X, Z, X, W );

      0210:  Result:= v4( X, Z, Y, X );
      0211:  Result:= v4( X, Z, Y, Y );
      0212:  Result:= v4( X, Z, Y, Z );
      0213:  Result:= v4( X, Z, Y, W );

      0220:  Result:= v4( X, Z, Z, X );
      0221:  Result:= v4( X, Z, Z, Y );
      0222:  Result:= v4( X, Z, Z, Z );
      0223:  Result:= v4( X, Z, Z, W );

      0230:  Result:= v4( X, Z, W, X );
      0231:  Result:= v4( X, Z, W, Y );
      0232:  Result:= v4( X, Z, W, Z );
      0233:  Result:= v4( X, Z, W, W );

      0300:  Result:= v4( X, W, X, X );
      0301:  Result:= v4( X, W, X, Y );
      0302:  Result:= v4( X, W, X, Z );
      0303:  Result:= v4( X, W, X, W );

      0310:  Result:= v4( X, W, Y, X );
      0311:  Result:= v4( X, W, Y, Y );
      0312:  Result:= v4( X, W, Y, Z );
      0313:  Result:= v4( X, W, Y, W );

      0320:  Result:= v4( X, W, Z, X );
      0321:  Result:= v4( X, W, Z, Y );
      0322:  Result:= v4( X, W, Z, Z );
      0323:  Result:= v4( X, W, Z, W );

      0330:  Result:= v4( X, W, W, X );
      0331:  Result:= v4( X, W, W, Y );
      0332:  Result:= v4( X, W, W, Z );
      0333:  Result:= v4( X, W, W, W );



      1000:  Result:= v4( Y, X, X, X );
      1001:  Result:= v4( Y, X, X, Y );
      1002:  Result:= v4( Y, X, X, Z );
      1003:  Result:= v4( Y, X, X, W );

      1010:  Result:= v4( Y, X, Y, X );
      1011:  Result:= v4( Y, X, Y, Y );
      1012:  Result:= v4( Y, X, Y, Z );
      1013:  Result:= v4( Y, X, Y, W );

      1020:  Result:= v4( Y, X, Z, X );
      1021:  Result:= v4( Y, X, Z, Y );
      1022:  Result:= v4( Y, X, Z, Z );
      1023:  Result:= v4( Y, X, Z, W );

      1030:  Result:= v4( Y, X, W, X );
      1031:  Result:= v4( Y, X, W, Y );
      1032:  Result:= v4( Y, X, W, Z );
      1033:  Result:= v4( Y, X, W, W );


      1100:  Result:= v4( Y, Y, X, X );
      1101:  Result:= v4( Y, Y, X, Y );
      1102:  Result:= v4( Y, Y, X, Z );
      1103:  Result:= v4( Y, Y, X, W );

      1110:  Result:= v4( Y, Y, Y, X );
      1111:  Result:= v4( Y, Y, Y, Y );
      1112:  Result:= v4( Y, Y, Y, Z );
      1113:  Result:= v4( Y, Y, Y, W );

      1120:  Result:= v4( Y, Y, Z, X );
      1121:  Result:= v4( Y, Y, Z, Y );
      1122:  Result:= v4( Y, Y, Z, Z );
      1123:  Result:= v4( Y, Y, Z, W );

      1130:  Result:= v4( Y, Y, W, X );
      1131:  Result:= v4( Y, Y, W, Y );
      1132:  Result:= v4( Y, Y, W, Z );
      1133:  Result:= v4( Y, Y, W, W );


      1200:  Result:= v4( Y, Z, X, X );
      1201:  Result:= v4( Y, Z, X, Y );
      1202:  Result:= v4( Y, Z, X, Z );
      1203:  Result:= v4( Y, Z, X, W );

      1210:  Result:= v4( Y, Z, Y, X );
      1211:  Result:= v4( Y, Z, Y, Y );
      1212:  Result:= v4( Y, Z, Y, Z );
      1213:  Result:= v4( Y, Z, Y, W );

      1220:  Result:= v4( Y, Z, Z, X );
      1221:  Result:= v4( Y, Z, Z, Y );
      1222:  Result:= v4( Y, Z, Z, Z );
      1223:  Result:= v4( Y, Z, Z, W );

      1230:  Result:= v4( Y, Z, W, X );
      1231:  Result:= v4( Y, Z, W, Y );
      1232:  Result:= v4( Y, Z, W, Z );
      1233:  Result:= v4( Y, Z, W, W );

      1300:  Result:= v4( Y, W, X, X );
      1301:  Result:= v4( Y, W, X, Y );
      1302:  Result:= v4( Y, W, X, Z );
      1303:  Result:= v4( Y, W, X, W );

      1310:  Result:= v4( Y, W, Y, X );
      1311:  Result:= v4( Y, W, Y, Y );
      1312:  Result:= v4( Y, W, Y, Z );
      1313:  Result:= v4( Y, W, Y, W );

      1320:  Result:= v4( Y, W, Z, X );
      1321:  Result:= v4( Y, W, Z, Y );
      1322:  Result:= v4( Y, W, Z, Z );
      1323:  Result:= v4( Y, W, Z, W );

      1330:  Result:= v4( Y, W, W, X );
      1331:  Result:= v4( Y, W, W, Y );
      1332:  Result:= v4( Y, W, W, Z );
      1333:  Result:= v4( Y, W, W, W );



      2000:  Result:= v4( Z, X, X, X );
      2001:  Result:= v4( Z, X, X, Y );
      2002:  Result:= v4( Z, X, X, Z );
      2003:  Result:= v4( Z, X, X, W );

      2010:  Result:= v4( Z, X, Y, X );
      2011:  Result:= v4( Z, X, Y, Y );
      2012:  Result:= v4( Z, X, Y, Z );
      2013:  Result:= v4( Z, X, Y, W );

      2020:  Result:= v4( Z, X, Z, X );
      2021:  Result:= v4( Z, X, Z, Y );
      2022:  Result:= v4( Z, X, Z, Z );
      2023:  Result:= v4( Z, X, Z, W );

      2030:  Result:= v4( Z, X, W, X );
      2031:  Result:= v4( Z, X, W, Y );
      2032:  Result:= v4( Z, X, W, Z );
      2033:  Result:= v4( Z, X, W, W );


      2100:  Result:= v4( Z, Y, X, X );
      2101:  Result:= v4( Z, Y, X, Y );
      2102:  Result:= v4( Z, Y, X, Z );
      2103:  Result:= v4( Z, Y, X, W );

      2110:  Result:= v4( Z, Y, Y, X );
      2111:  Result:= v4( Z, Y, Y, Y );
      2112:  Result:= v4( Z, Y, Y, Z );
      2113:  Result:= v4( Z, Y, Y, W );

      2120:  Result:= v4( Z, Y, Z, X );
      2121:  Result:= v4( Z, Y, Z, Y );
      2122:  Result:= v4( Z, Y, Z, Z );
      2123:  Result:= v4( Z, Y, Z, W );

      2130:  Result:= v4( Z, Y, W, X );
      2131:  Result:= v4( Z, Y, W, Y );
      2132:  Result:= v4( Z, Y, W, Z );
      2133:  Result:= v4( Z, Y, W, W );


      2200:  Result:= v4( Z, Z, X, X );
      2201:  Result:= v4( Z, Z, X, Y );
      2202:  Result:= v4( Z, Z, X, Z );
      2203:  Result:= v4( Z, Z, X, W );

      2210:  Result:= v4( Z, Z, Y, X );
      2211:  Result:= v4( Z, Z, Y, Y );
      2212:  Result:= v4( Z, Z, Y, Z );
      2213:  Result:= v4( Z, Z, Y, W );

      2220:  Result:= v4( Z, Z, Z, X );
      2221:  Result:= v4( Z, Z, Z, Y );
      2222:  Result:= v4( Z, Z, Z, Z );
      2223:  Result:= v4( Z, Z, Z, W );

      2230:  Result:= v4( Z, Z, W, X );
      2231:  Result:= v4( Z, Z, W, Y );
      2232:  Result:= v4( Z, Z, W, Z );
      2233:  Result:= v4( Z, Z, W, W );

      2300:  Result:= v4( Z, W, X, X );
      2301:  Result:= v4( Z, W, X, Y );
      2302:  Result:= v4( Z, W, X, Z );
      2303:  Result:= v4( Z, W, X, W );

      2310:  Result:= v4( Z, W, Y, X );
      2311:  Result:= v4( Z, W, Y, Y );
      2312:  Result:= v4( Z, W, Y, Z );
      2313:  Result:= v4( Z, W, Y, W );

      2320:  Result:= v4( Z, W, Z, X );
      2321:  Result:= v4( Z, W, Z, Y );
      2322:  Result:= v4( Z, W, Z, Z );
      2323:  Result:= v4( Z, W, Z, W );

      2330:  Result:= v4( Z, W, W, X );
      2331:  Result:= v4( Z, W, W, Y );
      2332:  Result:= v4( Z, W, W, Z );
      2333:  Result:= v4( Z, W, W, W );

      3000:  Result:= v4( W, X, X, X );
      3001:  Result:= v4( W, X, X, Y );
      3002:  Result:= v4( W, X, X, Z );
      3003:  Result:= v4( W, X, X, W );

      3010:  Result:= v4( W, X, Y, X );
      3011:  Result:= v4( W, X, Y, Y );
      3012:  Result:= v4( W, X, Y, Z );
      3013:  Result:= v4( W, X, Y, W );

      3020:  Result:= v4( W, X, Z, X );
      3021:  Result:= v4( W, X, Z, Y );
      3022:  Result:= v4( W, X, Z, Z );
      3023:  Result:= v4( W, X, Z, W );

      3030:  Result:= v4( W, X, W, X );
      3031:  Result:= v4( W, X, W, Y );
      3032:  Result:= v4( W, X, W, Z );
      3033:  Result:= v4( W, X, W, W );


      3100:  Result:= v4( W, Y, X, X );
      3101:  Result:= v4( W, Y, X, Y );
      3102:  Result:= v4( W, Y, X, Z );
      3103:  Result:= v4( W, Y, X, W );

      3110:  Result:= v4( W, Y, Y, X );
      3111:  Result:= v4( W, Y, Y, Y );
      3112:  Result:= v4( W, Y, Y, Z );
      3113:  Result:= v4( W, Y, Y, W );

      3120:  Result:= v4( W, Y, Z, X );
      3121:  Result:= v4( W, Y, Z, Y );
      3122:  Result:= v4( W, Y, Z, Z );
      3123:  Result:= v4( W, Y, Z, W );

      3130:  Result:= v4( W, Y, W, X );
      3131:  Result:= v4( W, Y, W, Y );
      3132:  Result:= v4( W, Y, W, Z );
      3133:  Result:= v4( W, Y, W, W );


      3200:  Result:= v4( W, Z, X, X );
      3201:  Result:= v4( W, Z, X, Y );
      3202:  Result:= v4( W, Z, X, Z );
      3203:  Result:= v4( W, Z, X, W );

      3210:  Result:= v4( W, Z, Y, X );
      3211:  Result:= v4( W, Z, Y, Y );
      3212:  Result:= v4( W, Z, Y, Z );
      3213:  Result:= v4( W, Z, Y, W );

      3220:  Result:= v4( W, Z, Z, X );
      3221:  Result:= v4( W, Z, Z, Y );
      3222:  Result:= v4( W, Z, Z, Z );
      3223:  Result:= v4( W, Z, Z, W );

      3230:  Result:= v4( W, Z, W, X );
      3231:  Result:= v4( W, Z, W, Y );
      3232:  Result:= v4( W, Z, W, Z );
      3233:  Result:= v4( W, Z, W, W );

      3300:  Result:= v4( W, W, X, X );
      3301:  Result:= v4( W, W, X, Y );
      3302:  Result:= v4( W, W, X, Z );
      3303:  Result:= v4( W, W, X, W );

      3310:  Result:= v4( W, W, Y, X );
      3311:  Result:= v4( W, W, Y, Y );
      3312:  Result:= v4( W, W, Y, Z );
      3313:  Result:= v4( W, W, Y, W );

      3320:  Result:= v4( W, W, Z, X );
      3321:  Result:= v4( W, W, Z, Y );
      3322:  Result:= v4( W, W, Z, Z );
      3323:  Result:= v4( W, W, Z, W );

      3330:  Result:= v4( W, W, W, X );
      3331:  Result:= v4( W, W, W, Y );
      3332:  Result:= v4( W, W, W, Z );
      3333:  Result:= v4( W, W, W, W )

      else Result:= v4( -1 ); //THIS SHOULD NEVER HAPPEN
    end;
  end;
  {$ENDIF}
{$ENDIF}

{$UNDEF TV2} {$UNDEF TV3} {$UNDEF TV4}
{$UNDEF v2} {$UNDEF v3} {$UNDEF v4}

