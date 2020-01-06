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

//p3dmath_matrix.inc


{{$IF FIELDTYPE = Float}
  {$IF NUMFIELD = 2}
    {$DEFINE MATIDENTITY:= Mat2Identity}
  {$ELSEIF NUMFIELD = 3}
    {$DEFINE MATIDENTITY:= Mat3Identity}
  {$ELSEIF NUMFIELD = 4}
    {$DEFINE MATIDENTITY:= Mat4Identity}
  {$ENDIF}
{$ENDIF}
{$IF FIELDTYPE = Double}
  {$IF NUMFIELD = 2}
    {$DEFINE MATIDENTITY:= DMat2Identity}
  {$ELSEIF NUMFIELD = 3}
    {$DEFINE MATIDENTITY:= DMat3Identity}
  {$ELSEIF NUMFIELD = 4}
    {$DEFINE MATIDENTITY:= DMat4Identity}
  {$ENDIF}

{$ENDIF}
{$IF FIELDTYPE = Int}
{$ENDIF}}
{$IFDEF INTERFACE}
  {$INCLUDE p3dmath_vector_names.inc}
type
  {tst}
  TMatrix = packed record
    //@abbr`A Matrix which can be either 2 by 2, 3 by 3 or 4 by 4. It can be used for
    //transformations`.
    //@br@br
    //The array @link`m` is for directly accessing the fields of the matrix.
    //You can also use the properties for accessing columns and rows which consist
    //of an "_" and one number for the column and another for the row. So if you
    //want to let's say access column 0 and row 3 you use _03.
    //The array is stored in column-major order but it only matters if you pass it
    //to another API than OpenGL, like Direct 3D. You might need to transpose the matrix then.

    private type
      PFieldType = ^FieldType;

    private
      class function GetCount: Integer; static;
      function GetCol( index: Integer ): TVector;
      function GetIndex( index: Integer ): FieldType; inline;
      function GetMField( AIndex: Integer ): FieldType; inline;
      function GetRow( index: Integer ): TVector;
      procedure SetCol( index: Integer ; AValue: TVector );
      procedure SetIndex( index: Integer ; AValue: FieldType );
      procedure SetMField( AIndex: Integer; AValue: FieldType );
      procedure SetRow( index: Integer ; AValue: TVector );

    public
      {$INCLUDE p3d.math.matrix.operators.inc}

    public
      //@abbr`Use this one dimensional array for directly accessing the fields in the matrix`.
      m: array [0..NUMFIELD*NUMFIELD-1] of FieldType;
      property Row [ index: Integer ] : TVector read GetRow write SetRow;
      property Col [ index: Integer ] : TVector read GetCol write SetCol; default;

      function Ptr: PFieldType;
      procedure Identity;

      {$IFDEF FLOATTYPE}
      function ToString( const LineBreaks: Boolean = False; const Digits: Integer = 8 ): String;
      function FromString( S: String ): TMatrix;
      function Inverted: TMatrix;
      function Inverse: Boolean;
      {$ENDIF}

      //@abbr`Use these properties to access the fields of matrix using column and row.
      //The first value indicates the column, the second value indicates the row.
      property _00: FieldType index                0  read GetMField write SetMField;
      {$IF NUMFIELD > 1 }
      property _01: FieldType index                1  read GetMField write SetMField;
      property _10: FieldType index NUMFIELD          read GetMField write SetMField;
      property _11: FieldType index NUMFIELD     + 1  read GetMField write SetMField;
      {$ENDIF}
      {$IF NUMFIELD > 2 }
      property _02: FieldType index                2  read GetMField write SetMField;
      property _12: FieldType index NUMFIELD     + 2  read GetMField write SetMField;
      property _20: FieldType index NUMFIELD * 2      read GetMField write SetMField;
      property _21: FieldType index NUMFIELD * 2 + 1  read GetMField write SetMField;
      property _22: FieldType index NUMFIELD * 2 + 2  read GetMField write SetMField;
      {$ENDIF}
      {$IF NUMFIELD > 3 }
      property _03: FieldType index                3  read GetMField write SetMField;
      property _13: FieldType index NUMFIELD     + 3  read GetMField write SetMField;
      property _23: FieldType index NUMFIELD * 2 + 3  read GetMField write SetMField;
      property _30: FieldType index NUMFIELD * 3      read GetMField write SetMField;
      property _31: FieldType index NUMFIELD * 3 + 1  read GetMField write SetMField;
      property _32: FieldType index NUMFIELD * 3 + 2  read GetMField write SetMField;
      property _33: FieldType index NUMFIELD * 3 + 3  read GetMField write SetMField;
      {$ENDIF}

      //This property is only provided for the use with OnChange events if needed in the future.

      property _m[ index: Integer ]: FieldType read GetIndex write SetIndex; //@exclude

      class property Count: Integer read GetCount;
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}

{$INCLUDE p3dmath_vector_names.inc}

{ TMatrix }

class function TMatrix.GetCount: Integer; static;
begin
  Result:= NUMFIELD;
end;

function TMatrix.GetCol( index: Integer ): TVector;
begin
  {$IF NUMFIELD = 2}
  Result:= v2( m[ index + 0 ], m[ index + 2 ]);
  {$ELSEIF NUMFIELD = 3}
  Result:= v3( m[ index + 0 ], m[ index + 3 ], m[ index + 6 ]);
  {$ELSEIF NUMFIELD = 4}
  Result:= v4( m[ index + 0 ], m[ index + 4 ], m[ index + 8 ], m[ index + 12 ]);
  {$ENDIF}
end;

function TMatrix.GetIndex( index: Integer ): FieldType;
begin
  Result:= m[ index ];
end;

function TMatrix.GetMField(AIndex: Integer): FieldType;
begin
  Result:= m[ AIndex ];
end;

function TMatrix.GetRow( index: Integer ): TVector;
var
  offset: Integer;
begin
  {$IF NUMFIELD = 2}
  offset:= 2 * index;
  Result:= v2( m[ offset + 0 ], m[ offset + 1 ]);
  {$ELSEIF NUMFIELD = 3}
  offset:= 3 * index;
  Result:= v3( m[ offset + 0 ], m[ offset + 1 ], m[ offset + 2 ]);
  {$ELSEIF NUMFIELD = 4}
  offset:= 4 * index;
  Result:= v4( m[ offset + 0 ], m[ offset + 1 ], m[ offset + 2 ], m[ offset + 3 ]);
  {$ENDIF}
end;

procedure TMatrix.SetCol( index: Integer ; AValue: TVector );
begin
  {$IF NUMFIELD = 2}
  m[ index + 0 ]:= AValue.x;
  m[ index + 2 ]:= AValue.Y;
  {$ENDIF}
  {$IF NUMFIELD = 3}
  m[ index + 0 ]:= AValue.x;
  m[ index + 3 ]:= AValue.Y;
  m[ index + 6 ]:= AValue.Z;
  {$ENDIF}
  {$IF NUMFIELD = 4}
  m[ index + 0 ]:= AValue.X;
  m[ index + 4 ]:= AValue.Y;
  m[ index + 8 ]:= AValue.Z;
  m[ index + 12 ]:= AValue.W;
  {$ENDIF}
end;

procedure TMatrix.SetIndex( index: Integer ; AValue: FieldType);
begin
  m[ index ]:= AValue;
end;

procedure TMatrix.SetMField(AIndex: Integer; AValue: FieldType);
begin
  m[ AIndex ]:= AValue;
end;

procedure TMatrix.SetRow( index: Integer ; AValue: TVector );
var
  offset: Integer;
begin
  {$IF NUMFIELD = 2}
  offset:= 2 * index;
  m[ offset + 0 ]:= AValue.x;
  m[ offset + 1 ]:= AValue.Y;
  {$ELSEIF NUMFIELD = 3}
  offset:= 3 * index;
  m[ offset + 0 ]:= AValue.X;
  m[ offset + 1 ]:= AValue.Y;
  m[ offset + 2 ]:= AValue.Z;
  {$ELSEIF NUMFIELD = 4}
  offset:= 4 * index;
  m[ offset + 0 ]:= AValue.X;
  m[ offset + 1 ]:= AValue.Y;
  m[ offset + 2 ]:= AValue.Z;
  m[ offset + 3 ]:= AValue.W;
  {$ENDIF}
end;

  {$IFDEF FLOATTYPE}

function TMatrix.ToString(const LineBreaks: Boolean; const Digits: Integer ): String;
var
  lb: String;
  str: String;
begin
  if ( LineBreaks ) then
    lb:= LineEnding
  else
    lb:= '';
    {$IF NUMFIELD = 2}
  str:= StringReplace( '[%.#f,%.#f], %s[%.#f,%.#f]', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ _00, _10, lb, _01, _11 ]);
    {$ENDIF}
    {$IF NUMFIELD = 3}
  str:= StringReplace( '[%.#f, %.#f, %.#f], %s[%.#f, %.#f, %.#f], %s[%.#f, %.#f, %.#f]', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ _00, _10, _20, lb, _01, _11, _21, lb, _02, _12, _22 ]);
    {$ENDIF}
    {$IF NUMFIELD = 4}
  str:= StringReplace( '[%.#f, %.#f, %.#f, %.#f], %s[%.#f, %.#f, %.#f, %.#f], %s[%.#f, %.#f, %.#f, %.#f], %s[%.#f, %.#f, %.#f, %.#f]', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ _00, _10, _20, _30, lb, _01, _11, _21, _31, lb, _02, _12, _22, _32, lb, _03, _13, _23, _33 ]);
    {$ENDIF}
end;

function TMatrix.FromString(S: String): TMatrix;
  function GetWordCount: Integer; inline;
  var
    c: Char;
  begin
    if ( S = '' ) then
      Result:= 0
    else
      begin
        Result:= 1;
        for c in S do
          if ( c = ',' ) then
            Inc( Result );
      end;
  end;

  function GetWord( n: Integer ): String; inline;
  var
    i: Integer;
    c: Char;
  begin
    i:= 1;
    Result:= '';
    for c in S do
      if ( c = ',' ) then
        begin
          Inc( i );
          if ( i > n ) then
            break;
        end
      else if ( i = n ) then
        Result:= Result + c;
  end;

const
  exp_wc =
    {$IF NUMFIELD = 2}
       2
    {$ELSEIF NUMFIELD = 3}
       3
    {$ELSEIF NUMFIELD = 4}
       4
    {$ENDIF}
    ;
var
  i: Integer;
  n: Integer;
  comp: TStringArray;
  val: TVector;
  s2: String;
begin
  comp:= S.Split([ ',' ], '[', ']' );
  n:= length( comp );

  if ( n <> exp_wc ) then
    raise Exception.Create( Format( 'Error while converting string ''%s'' to TMat%d. Wrong number of values given: %d.', [ S, exp_wc, n ]));
  for i:= 0 to n - 1 do begin
    s2:= Trim( comp[ i ]);
    if ( not s2.StartsWith( '[' )) then
      raise Exception.Create( Format( 'Error while converting string ''%s'' to TMat%d. "[" expected!', [ s, exp_wc ]));
    if ( not s2.EndsWith( ']' )) then
      raise Exception.Create( Format( 'Error while converting string ''%s'' to TMat%d. "]" expected!', [ s, exp_wc ]));
    s2:= Copy( s2, 2, Length( s2 ) - 2 );
    val.FromString( s2 );
    Col[ i ]:= val;
  end;
  Result:= Self;
end;

function TMatrix.Inverted: TMatrix;
begin
    {$IF NUMFIELD = 2}
  mat2inverse( Self, Result );
    {$ENDIF}
    {$IF NUMFIELD = 3}
  mat3inverse( Self, Result );
    {$ENDIF}
    {$IF NUMFIELD = 4}
  mat4inverse( Self, Result );
    {$ENDIF}
end;

function TMatrix.Inverse: Boolean;
begin
    {$IF NUMFIELD = 2}
  Result:= mat2inverse( Self, Self );
    {$ENDIF}
    {$IF NUMFIELD = 3}
  Result:= mat3inverse( Self, Self );
    {$ENDIF}
    {$IF NUMFIELD = 4}
  Result:= mat4inverse( Self, Self );
    {$ENDIF}
end;
  {$ENDIF}

function TMatrix.Ptr: PFieldType;
begin
  Result:= @m[ 0 ];
end;

procedure TMatrix.Identity;
const
  mI: TMatrix =
  {$IF NUMFIELD = 2}
  ( m: ( 1, 0, 0, 1 ));
  {$ENDIF}
  {$IF NUMFIELD = 3}
  ( m: ( 1, 0, 0, 0, 1, 0, 0, 0, 1 ));
  {$ENDIF}
  {$IF NUMFIELD = 4}
  ( m: ( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ));
  {$ENDIF}
begin
  Self:= mI;
end;

{$INCLUDE p3d.math.matrix.operators.inc}

{$ENDIF}

{$UNDEF v2} {$UNDEF v3} {$UNDEF v4}

