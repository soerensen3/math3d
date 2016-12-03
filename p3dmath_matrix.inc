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

//math3d_matrix.inc

{$IF NUMFIELD = 2}
  {$DEFINE MATIDENTITY:= Mat2Identity}
{$ELSEIF NUMFIELD = 3}
  {$DEFINE MATIDENTITY:= Mat3Identity}
{$ELSEIF NUMFIELD = 4}
  {$DEFINE MATIDENTITY:= Mat4Identity}
{$ENDIF}

{$IFDEF INTERFACE}
type
  {tst}
  TMatrix = packed object
    //@abbr`A Matrix which can be either 2 by 2, 3 by 3 or 4 by 4. It can be used for
    //transformations`.
    //@br@br
    //The array @link`m` is for directly accessing the fields of the matrix.
    //You can also use the properties for accessing columns and rows which consist
    //of an "_" and one number for the column and another for the row. So if you
    //want to let's say access column 0 and row 3 you use _03.
    //The array is stored in column-major order but it only matters if you pass it
    //to another API than OpenGL, like Direct 3D. You might need to transpose the matrix then.

    private
      function GetCol( index: Integer ): TVector;
      function GetIndex( index: Integer ): Float; inline;
      function GetMField( AIndex: Integer ): Float; inline;
      function GetRow( index: Integer ): TVector;
      procedure SetCol( index: Integer ; AValue: TVector );
      procedure SetIndex( index: Integer ; AValue: Float );
      procedure SetMField( AIndex: Integer; AValue: Float );
      procedure SetRow( index: Integer ; AValue: TVector );

    public
      //@abbr`Use this one dimensional array for directly accessing the fields in the matrix`.
      m: array [0..NUMFIELD*NUMFIELD-1] of Float;
      property Row [ index: Integer ] : TVector read GetRow write SetRow;
      property Col [ index: Integer ] : TVector read GetCol write SetCol; default;

      function ToString( const LineBreaks: Boolean = False; const Digits: Integer = 8 ): String;

      //@abbr`Use these properties to access the fields of matrix using column and row.
      //The first value indicates the column, the second value indicates the row.
      property _00: Float index                0  read GetMField write SetMField;
      {$IF NUMFIELD > 1 }
      property _01: Float index                1  read GetMField write SetMField;
      property _10: Float index NUMFIELD          read GetMField write SetMField;
      property _11: Float index NUMFIELD     + 1  read GetMField write SetMField;
      {$ENDIF}
      {$IF NUMFIELD > 2 }
      property _02: Float index                2  read GetMField write SetMField;
      property _12: Float index NUMFIELD     + 2  read GetMField write SetMField;
      property _20: Float index NUMFIELD * 2      read GetMField write SetMField;
      property _21: Float index NUMFIELD * 2 + 1  read GetMField write SetMField;
      property _22: Float index NUMFIELD * 2 + 2  read GetMField write SetMField;
      {$ENDIF}
      {$IF NUMFIELD > 3 }
      property _03: Float index                3  read GetMField write SetMField;
      property _13: Float index NUMFIELD     + 3  read GetMField write SetMField;
      property _23: Float index NUMFIELD * 2 + 3  read GetMField write SetMField;
      property _30: Float index NUMFIELD * 3      read GetMField write SetMField;
      property _31: Float index NUMFIELD * 3 + 1  read GetMField write SetMField;
      property _32: Float index NUMFIELD * 3 + 2  read GetMField write SetMField;
      property _33: Float index NUMFIELD * 3 + 3  read GetMField write SetMField;
      {$ENDIF}

      //This property is only provided for the use with OnChange events if needed in the future.


      property _m[ index: Integer ]: Float read GetIndex write SetIndex; //@exclude
  end;
//@abbr`Will generate a translation matrix` of the size depending on the fields of @bold`Vec`.
//If the vector has 3 fields the corresponding matrix will be 3 by 3.
function
{$IF NUMFIELD = 2}
  mat2translate
{$ELSEIF NUMFIELD = 3}
  mat3translate
{$ELSEIF NUMFIELD = 4}
  mat4translate
{$ENDIF}
  ( Vec: TVector ): TMatrix; overload;
//@abbr`Will generate a scale matrix` of the size depending on the fields of @bold`Vec`.
//If the vector has 3 fields the corresponding matrix will be 3 by 3.
function
{$IF NUMFIELD = 2}
  mat2scale
{$ELSEIF NUMFIELD = 3}
  mat3scale
{$ELSEIF NUMFIELD = 4}
  mat4scale
{$ENDIF}
  ( Vec: TVector ): TMatrix; overload;

{$IF NUMFIELD = 3}
//@abbr`Will generate a 3 by 3 rotation matrix using an axis and an angle`.
function mat3rotate( Axis: TVec3; Angle: Float ): TMatrix; overload;
function mat3determinant( M: TMatrix ): Float;
function mat3normalize( M: TMatrix ): TMatrix;
procedure mat3decompose( mat: TMat3; out rot: TMat3; out scale: TVec3 );
{$ENDIF}
{$IF NUMFIELD = 4}
//@abbr`Will generate a 4 by 4 rotation matrix using an axis and an angle`.
function mat4rotate( Axis: TVec3; Angle: Float ): TMatrix; overload;

//@abbr`Will return the determinant of a 4 by 4 matrix`.
function mat4determinant( Mat: TMatrix ): Float;
//@abbr`Will calculate the the inverse of a 4 by 4 matrix` and store the result in @bold`MatInv`.
//If the inverse could be calculated the function will return True.
function mat4inverse( Mat: TMatrix; out MatInv: TMatrix ): Boolean;
//@abbr`Will return the the transpose of a 4 by 4 matrix` which means it will swap
//colums and rows.
function mat4transpose( Matrix: TMatrix ): TMatrix;

procedure mat4decompose( mat: TMat4; out loc: TVec3; out rot: TMat3; out scale: TVec3 );

{function MatrixMirror( Plane: TPlane ): TMatrix;}
{function MatrixCubeMap( Face: Cardinal ): TMatrix;}

{$ENDIF}

//@abbr`Operator for multiplying a matrix with a float`. All values are affected.
operator * ( a: TMatrix; b: Float ) c: TMatrix; inline;
//@abbr`Operator for multiplying two matrices`. If you multiply two transformations, the right value is the transformation applied first.
operator * ( a: TMatrix; b: TMatrix ) c: TMatrix; //inline; // right first - left last

//@abbr`Operator for transforming a vec using a matrix`. The operation is Pre-Multiply in this order.
operator * ( a: TVector; b: TMatrix ) c: TVector; inline; // PRE-Multiply
//@abbr`Operator for transforming a vec using a matrix`. The operation is Post-Multiply in this order.
operator * ( a: TMatrix; b: TVector ) c: TVector; //inline; // POST-Multiply
//@abbr`Operator for comparing two matrices`.
operator = ( a: TMatrix; b: TMatrix ) c: Boolean; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator*(a: TMatrix; b: Float)c: TMatrix;
var
  i: Integer;
begin
  for i:= 0 to 15 do
    a._m[ i ]:= a._m[ i ] * b;
  c:= a;
end;

(*
{$IF NUMFIELD=4}
operator * ( a: TVector; b: TMatrix ) c: TVector; inline;
begin
  c:= VecTransform( a, b );
end;

operator*(a: TMatrix; b: TVector)c: TVector; inline;
begin
  c:= VecTransform( b, a );
end;
{$ENDIF}
*)

{ TMatrix }

function TMatrix.GetCol( index: Integer ): TVector;
begin
  {$IF NUMFIELD = 2}
  Result:= vec2( m[ index + 0 ], m[ index + 2 ]);
  {$ELSEIF NUMFIELD = 3}
  Result:= vec3( m[ index + 0 ], m[ index + 3 ], m[ index + 6 ]);
  {$ELSEIF NUMFIELD = 4}
  Result:= vec4( m[ index + 0 ], m[ index + 4 ], m[ index + 8 ], m[ index + 12 ]);
  {$ENDIF}
end;

function TMatrix.GetIndex( index: Integer ): Float;
begin
  Result:= m[ index ];
end;

function TMatrix.GetMField(AIndex: Integer): Float;
begin
  Result:= m[ AIndex ];
end;

function TMatrix.GetRow( index: Integer ): TVector;
var
  offset: Integer;
begin
  {$IF NUMFIELD = 2}
  offset:= 2 * index;
  Result:= vec2( m[ offset + 0 ], m[ offset + 1 ]);
  {$ELSEIF NUMFIELD = 3}
  offset:= 3 * index;
  Result:= vec3( m[ offset + 0 ], m[ offset + 1 ], m[ offset + 2 ]);
  {$ELSEIF NUMFIELD = 4}
  offset:= 4 * index;
  Result:= vec4( m[ offset + 0 ], m[ offset + 1 ], m[ offset + 2 ], m[ offset + 3 ]);
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
  m[ index + 4 ]:= AValue.Y;
  m[ index + 8 ]:= AValue.Z;
  m[ index + 12 ]:= AValue.W;
  {$ENDIF}
end;

procedure TMatrix.SetIndex( index: Integer ; AValue: Float);
begin
  m[ index ]:= AValue;
end;

procedure TMatrix.SetMField(AIndex: Integer; AValue: Float);
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
  str:= StringReplace( '%.#f,%.#f, %s%.#f,%.#f', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ _00, _01, lb, _10, _11 ]);
  {$ENDIF}
  {$IF NUMFIELD = 3}
  str:= StringReplace( '%.#f, %.#f, %.#f, %s%.#f, %.#f, %.#f, %s%.#f, %.#f, %.#f, %s%.#f, %.#f, %.#f', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ _00, _01, _02, lb, _10, _11, _12, lb, _20, _21, _22 ]);
  {$ENDIF}
  {$IF NUMFIELD = 4}
  str:= StringReplace( '%.#f, %.#f, %.#f, %.#f, %s%.#f, %.#f, %.#f, %.#f, %s%.#f, %.#f, %.#f, %.#f, %s%.#f, %.#f, %.#f, %.#f', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ _00, _01, _02, _03, lb, _10, _11, _12, _13, lb, _20, _21, _22, _23, lb, _30, _31, _32, _33 ]);
  {$ENDIF}
end;


{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator * ( a: TMatrix; b: TMatrix ) c: TMatrix; //inline;
begin
  c._00:= b._00 * a._00
        {$IF NUMFIELD > 1}
        + b._01 * a._10
        {$ENDIF}
        {$IF NUMFIELD > 2}
        + b._02 * a._20
        {$ENDIF}
        {$IF NUMFIELD > 3}
        + b._03 * a._30
        {$ENDIF}
        ;
  {$IF NUMFIELD > 1}
  c._01:= b._00 * a._01
        + b._01 * a._11
        {$IF NUMFIELD > 2}
        + b._02 * a._21
        {$ENDIF}
        {$IF NUMFIELD > 3}
        + b._03 * a._31
        {$ENDIF}
        ;

  c._10:= b._10 * a._00
        + b._11 * a._10
        {$IF NUMFIELD > 2}
        + b._12 * a._20
        {$ENDIF}
        {$IF NUMFIELD > 3}
        + b._13 * a._30
        {$ENDIF}
        ;

  c._11:= b._10 * a._01
        + b._11 * a._11
        {$IF NUMFIELD > 2}
        + b._12 * a._21
        {$ENDIF}
        {$IF NUMFIELD > 3}
        + b._13 * a._31
        {$ENDIF}
        ;
  {$ENDIF}

  {$IF NUMFIELD > 2}
  c._02:= b._00 * a._02
        + b._01 * a._12
        + b._02 * a._22
        {$IF NUMFIELD > 3}
        + b._03 * a._32
        {$ENDIF}
        ;

  c._12:= b._10 * a._02
        + b._11 * a._12
        + b._12 * a._22
        {$IF NUMFIELD > 3}
        + b._13 * a._32
        {$ENDIF}
        ;

  c._20:= b._20 * a._00
        + b._21 * a._10
        + b._22 * a._20
        {$IF NUMFIELD > 3}
        + b._23 * a._30
        {$ENDIF}
        ;

  c._21:= b._20 * a._01
        + b._21 * a._11
        + b._22 * a._21
          {$IF NUMFIELD > 3}
        + b._23 * a._31
          {$ENDIF}
        ;

  c._22:= b._20 * a._02
        + b._21 * a._12
        + b._22 * a._22
          {$IF NUMFIELD > 3}
        + b._23 * a._32
          {$ENDIF}
        ;
  {$ENDIF}

  {$IF NUMFIELD > 3}
  c._03:= b._00 * a._03
        + b._01 * a._13
        + b._02 * a._23
        + b._03 * a._33;

  c._13:= b._10 * a._03
        + b._11 * a._13
        + b._12 * a._23
        + b._13 * a._33;

  c._23:= b._20 * a._03
        + b._21 * a._13
        + b._22 * a._23
        + b._23 * a._33;

  c._30:= b._30 * a._00
        + b._31 * a._10
        + b._32 * a._20
        + b._33 * a._30;

  c._31:= b._30 * a._01
        + b._31 * a._11
        + b._32 * a._21
        + b._33 * a._31;

  c._32:= b._30 * a._02
        + b._31 * a._12
        + b._32 * a._22
        + b._33 * a._32;

  c._33:= b._30 * a._03
        + b._31 * a._13
        + b._32 * a._23
        + b._33 * a._33;
  {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator*( a: TMatrix; b: TVector ) c: TVector;
begin
  Result.x:= ( b.x * a._00 )
           {$IF NUMFIELD > 1}
           + ( b.y * a._10 )
           {$ENDIF}
           {$IF NUMFIELD > 2}
           + ( b.z * a._20 )
           {$ENDIF}
           {$IF NUMFIELD > 3}
           + ( b.w * a._30 )
           {$ENDIF}
           ;

  {$IF NUMFIELD > 1}
  Result.y:= ( b.x * a._01 )
           + ( b.y * a._11 )
           {$IF NUMFIELD > 2}
           + ( b.z * a._21 )
           {$ENDIF}
           {$IF NUMFIELD > 3}
           + ( b.w * a._31 )
           {$ENDIF}
           ;
  {$ENDIF}

  {$IF NUMFIELD > 2}
  Result.z:= ( b.x * a._02 )
           + ( b.y * a._12 )
           + ( b.z * a._22 )
           {$IF NUMFIELD > 3}
           + ( b.w * a._32 )
           {$ENDIF}
           ;
  {$ENDIF}

  {$IF NUMFIELD > 3}
  Result.w:= ( b.x * a._03 )
           + ( b.y * a._13 )
           + ( b.z * a._23 )
           + ( b.w * a._33 );
  {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator*( a: TVector; b: TMatrix ) c: TVector;
begin
  Result.x:= ( b._00 * a.x )
           {$IF NUMFIELD > 1}
           + ( b._01 * a.y )
           {$ENDIF}
           {$IF NUMFIELD > 2}
           + ( b._02 * a.z )
           {$ENDIF}
           {$IF NUMFIELD > 3}
           + ( b._03 * a.w )
           {$ENDIF}
           ;

  {$IF NUMFIELD > 1}
  Result.y:= ( b._10 * a.x )
           + ( b._11 * a.y )
           {$IF NUMFIELD > 2}
           + ( b._12 * a.z )
           {$ENDIF}
           {$IF NUMFIELD > 3}
           + ( b._13 * a.w )
           {$ENDIF}
           ;
  {$ENDIF}

  {$IF NUMFIELD > 2}
  Result.z:= ( b._20 * a.x )
           + ( b._21 * a.y )
           + ( b._22 * a.z )
           {$IF NUMFIELD > 3}
           + ( b._23 * a.w )
           {$ENDIF}
           ;
  {$ENDIF}

  {$IF NUMFIELD > 3}
  Result.w:= ( b._30 * a.x )
           + ( b._31 * a.y )
           + ( b._32 * a.z )
           + ( b._33 * a.w );
  {$ENDIF}
end;
{$WARNINGS ON}

operator=(a: TMatrix; b: TMatrix)c: Boolean;
begin
  Result:= CompareMem( @a.m, @b.m, SizeOf( a.m ));
end;


function
{$IF NUMFIELD = 2}
  mat2translate
{$ELSEIF NUMFIELD = 3}
  mat3translate
{$ELSEIF NUMFIELD = 4}
  mat4translate
{$ENDIF}
  ( Vec: TVector ): TMatrix;
begin
  Result:= MatIdentity;
  {$IFDEF COLUMN_MAJOR_ORDER}
    {$IF NUMFIELD = 2}
  Result._00:= Vec.x;
  Result._11:= Vec.y;
    {$ELSEIF NUMFIELD = 3}
  Result._02:= Vec.x;
  Result._12:= Vec.y;
  Result._22:= Vec.z;
    {$ELSEIF NUMFIELD = 4}
  Result._03:= Vec.x;
  Result._13:= Vec.y;
  Result._23:= Vec.z;
  Result._33:= Vec.w;
    {$ENDIF}
  {$ELSE}
    {$IF NUMFIELD = 2}
  Result._10:= Vec.x;
  Result._11:= Vec.y;
    {$ELSEIF NUMFIELD = 3}
  Result._20:= Vec.x;
  Result._21:= Vec.y;
  Result._22:= Vec.z;
    {$ELSEIF NUMFIELD = 4}
  Result._30:= Vec.x;
  Result._31:= Vec.y;
  Result._32:= Vec.z;
  Result._33:= Vec.w;
    {$ENDIF}
  {$ENDIF}
end;

function
{$IF NUMFIELD = 2}
  mat2scale
{$ELSEIF NUMFIELD = 3}
  mat3scale
{$ELSEIF NUMFIELD = 4}
  mat4scale
{$ENDIF}
  ( Vec: TVector ): TMatrix;
begin
  Result:= MatIdentity;
  {$IF NUMFIELD = 2}
    Result._00:= Vec.x;
    Result._11:= Vec.y;
  {$ELSEIF NUMFIELD = 3}
    Result._00:= Vec.x;
    Result._11:= Vec.y;
    Result._22:= Vec.z;
  {$ELSEIF NUMFIELD = 4}
    Result._00:= Vec.x;
    Result._11:= Vec.y;
    Result._22:= Vec.z;
    Result._33:= Vec.w;
  {$ENDIF}
end;

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
{$IF NUMFIELD = 3}
function mat3rotate(Axis: TVec3; Angle: Float): TMat3;
var
   cosine, sine, one_minus_cosine : Extended;
begin
   SinCos(Angle, Sine, Cosine);
   one_minus_cosine:=1 - cosine;
   Axis.Normalize;

   {$IFDEF COLUMN_MAJOR_ORDER}
   Result._00:= (one_minus_cosine * Sqr(Axis.x)) + Cosine;
   Result._10:= (one_minus_cosine * Axis.x * Axis.y) - (Axis.z * Sine);
   Result._20:= (one_minus_cosine * Axis.z * Axis.x) + (Axis.y * Sine);

   Result._01:= (one_minus_cosine * Axis.x * Axis.y) + (Axis.z * Sine);
   Result._11:= (one_minus_cosine * Sqr(Axis.y)) + Cosine;
   Result._21:= (one_minus_cosine * Axis.y * Axis.z) - (Axis.x * Sine);

   Result._02:= (one_minus_cosine * Axis.z * Axis.x) - (Axis.y * Sine);
   Result._12:= (one_minus_cosine * Axis.y * Axis.z) + (Axis.x * Sine);
   Result._22:= (one_minus_cosine * Sqr(Axis.z)) + Cosine;
   {$ELSE}
   Result._00:= (one_minus_cosine * Sqr(Axis.x)) + Cosine;
   Result._01:= (one_minus_cosine * Axis.x * Axis.y) - (Axis.z * Sine);
   Result._02:= (one_minus_cosine * Axis.z * Axis.x) + (Axis.y * Sine);

   Result._10:= (one_minus_cosine * Axis.x * Axis.y) + (Axis.z * Sine);
   Result._11:= (one_minus_cosine * Sqr(Axis.y)) + Cosine;
   Result._12:= (one_minus_cosine * Axis.y * Axis.z) - (Axis.x * Sine);

   Result._20:= (one_minus_cosine * Axis.z * Axis.x) - (Axis.y * Sine);
   Result._21:= (one_minus_cosine * Axis.y * Axis.z) + (Axis.x * Sine);
   Result._22:= (one_minus_cosine * Sqr(Axis.z)) + Cosine;
   {$ENDIF}
end;

function mat3determinant( M: TMatrix ): Float;
begin
  Result:=
    M._10 * ( M._02 * M._21 - M._22 * M._01 ) +
    M._11 * ( M._00 * M._22 - M._20 * M._02 ) +
    M._12 * ( M._01 * M._20 - M._21 * M._00 );
end;

function mat3normalize( M: TMatrix ): TMatrix;
begin
  Result:= mat3( M[ 0 ].Normalize, m[ 1 ].Normalize, m[ 2 ].Normalize );
end;

{
var
  d: Float;
  i: Integer;
begin
  d:= mat3determinant( M );
  if ( d > 0 ) then
    for i:= 0 to high( M.m ) do
      Result.m[ i ]:= M.m[ i ]/d
  else
    Result:= M;
end;
}
function mat3adjoint( Mat: TMat3 ): TMat3;
var
  m_out: TMat3;
begin
  m_out._00:=  Mat._11 * Mat._22 - Mat._12 * Mat._21;
  m_out._01:= -Mat._01 * Mat._22 + Mat._02 * Mat._21;
  m_out._02:=  Mat._01 * Mat._12 - Mat._02 * Mat._11;

  m_out._10:= -Mat._10 * Mat._22 + Mat._12 * Mat._20;
  m_out._11:=  Mat._00 * Mat._22 - Mat._02 * Mat._20;
  m_out._12:= -Mat._00 * Mat._12 + Mat._02 * Mat._10;

  m_out._20:=  Mat._10 * Mat._21 - Mat._11 * Mat._20;
  m_out._21:= -Mat._00 * Mat._21 + Mat._01 * Mat._20;
  m_out._22:=  Mat._00 * Mat._11 - Mat._01 * Mat._10;
  Result:= m_out;
end;

function mat3inverse( Mat: TMat3; out MatInv: TMat3 ): Boolean;
var
  matadj, MatOut: TMat3;
  det: Float;
  i: Integer;
begin
  { calc adjoint }
  matadj:= mat3adjoint( Mat );

  { then determinant old matrix! }
  det:= mat3determinant( Mat );

  Result:= ( det <> 0 );

  if ( Result ) then //if (LIKELY(det != 0.0f))
    begin
      det:= 1 / det;
      for i:= 0 to 3 do
        MatOut[ i ]:= matadj[ i ] * det;
      MatInv:= MatOut;
    end
  else
    MatInv:= Mat;
end;

//based on mat3_to_rot_size in math_matrix.c from the blender source

procedure mat3decompose( mat: TMat3; out rot: TMat3; out scale: TVec3 );
  function mat3_is_negative( m: TMat3 ): Boolean;
  begin
    Result:= ( dot( cross( mat[ 0 ], mat[ 1 ]), mat[ 2 ]) < 0 );
  end;

var
  mat_n, mat_sz: TMat3;
begin
  { rotation & scale are linked, we need to create the mat's
   * for these together since they are related. }

  { so scale doesn't interfere with rotation [#24291] }
  { note: this is a workaround for negative matrix not working for rotation conversion, FIXME }

  mat_n:= mat3normalize( mat );
  if ( mat3_is_negative( mat )) then
    mat_n:= mat3( -mat[ 0 ], -mat[ 1 ], -mat[ 2 ]);

  { rotation }
  { keep rot as a 3x3 matrix, the caller can convert into a quat or euler }
  rot:= mat_n;

  { scale }
  { note: mat4_to_size(ob->size, mat) fails for negative scale }
  mat3inverse( mat_n, mat_n );
  mat_sz:= mat_n * mat;

  scale:= vec3( mat_sz[ 0 ][ 0 ], mat_sz[ 1 ][ 1 ], mat_sz[ 2 ][ 2 ]);
end;
{$ENDIF}
{$IF NUMFIELD = 4}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
function mat4rotate(Axis: TVec3; Angle: Float ): TMatrix;
var
   cosine, sine, one_minus_cosine : Extended;
begin
   SinCos(Angle, Sine, Cosine);
   one_minus_cosine:=1 - cosine;
   Axis.Normalize;

   {$IFDEF COLUMN_MAJOR_ORDER}
   Result._00:= (one_minus_cosine * Sqr(Axis.x)) + Cosine;
   Result._10:= (one_minus_cosine * Axis.x * Axis.y) - (Axis.z * Sine);
   Result._20:= (one_minus_cosine * Axis.z * Axis.x) + (Axis.y * Sine);
   Result._30:= 0;

   Result._01:= (one_minus_cosine * Axis.x * Axis.y) + (Axis.z * Sine);
   Result._11:= (one_minus_cosine * Sqr(Axis.y)) + Cosine;
   Result._21:= (one_minus_cosine * Axis.y * Axis.z) - (Axis.x * Sine);
   Result._31:= 0;

   Result._02:= (one_minus_cosine * Axis.z * Axis.x) - (Axis.y * Sine);
   Result._12:= (one_minus_cosine * Axis.y * Axis.z) + (Axis.x * Sine);
   Result._22:= (one_minus_cosine * Sqr(Axis.z)) + Cosine;
   Result._32:= 0;

   Result._03:= 0;
   Result._13:= 0;
   Result._23:= 0;
   Result._33:= 1;
   {$ELSE}
   Result._00:= (one_minus_cosine * Sqr(Axis.x)) + Cosine;
   Result._01:= (one_minus_cosine * Axis.x * Axis.y) - (Axis.z * Sine);
   Result._02:= (one_minus_cosine * Axis.z * Axis.x) + (Axis.y * Sine);
   Result._03:= 0;

   Result._10:= (one_minus_cosine * Axis.x * Axis.y) + (Axis.z * Sine);
   Result._11:= (one_minus_cosine * Sqr(Axis.y)) + Cosine;
   Result._12:= (one_minus_cosine * Axis.y * Axis.z) - (Axis.x * Sine);
   Result._13:= 0;

   Result._20:= (one_minus_cosine * Axis.z * Axis.x) - (Axis.y * Sine);
   Result._21:= (one_minus_cosine * Axis.y * Axis.z) + (Axis.x * Sine);
   Result._22:= (one_minus_cosine * Sqr(Axis.z)) + Cosine;
   Result._23:= 0;

   Result._30:= 0;
   Result._31:= 0;
   Result._32:= 0;
   Result._33:= 1;
   {$ENDIF}
end;
{$WARNINGS ON}
function MatrixDet( const a1, a2, a3, b1, b2, b3, c1, c2, c3: Float ): Float;
begin
  Result:= a1 * ( b2 * c3 - b3 * c2 )
         - b1 * ( a2 * c3 - a3 * c2 )
         + c1 * ( a2 * b3 - a3 * b2 );
end;

function mat4determinant(Mat: TMatrix): Float;
begin
  Result:= Mat._00 * MatrixDet( Mat.m[ 5 ], Mat.m[ 9 ], Mat.m[ 13 ],
                                Mat.m[ 6 ], Mat.m[ 10 ], Mat.m[ 14 ],
                                Mat.m[ 7 ], Mat.m[ 11 ], Mat.m[ 15 ])

         - Mat._01 * MatrixDet( Mat.m[ 4 ], Mat.m[ 8 ], Mat.m[ 12 ],
                                Mat.m[ 6 ], Mat.m[ 10 ], Mat.m[ 14 ],
                                Mat.m[ 7 ], Mat.m[ 11 ], Mat.m[ 15 ])

         + Mat._02 * MatrixDet( Mat.m[ 4 ], Mat.m[ 8 ], Mat.m[ 12 ],
                                Mat.m[ 5 ], Mat.m[ 9 ], Mat.m[ 13 ],
                                Mat.m[ 7 ], Mat.m[ 11 ], Mat.m[ 15 ])

         - Mat._03 * MatrixDet( Mat.m[ 4 ], Mat.m[ 8 ], Mat.m[ 12 ],
                                Mat.m[ 5 ], Mat.m[ 9 ], Mat.m[ 13 ],
                                Mat.m[ 6 ], Mat.m[ 10 ], Mat.m[ 14 ]);
end;

function mat4normalize( Mat: TMatrix ): TMatrix;
var
  d: Float;
  i: Integer;
begin
  d:= mat4determinant( Mat );
  if ( d > 0 ) then
  for i:= 0 to high( Mat.m ) do
    Result.m[ i ]:= Mat.m[ i ]/d;
end;

{
function Determinant2x2( a1, a2, b1, b2: Float ): Float; inline;
begin
  Result:= a1 * b2 - b1 * a2;
end;

function Determinant3x3( a1, a2, a3,
                         b1, b2, b3,
                         c1, c2, c3: Float ): Float; inline;
begin
  Result:= a1 * Determinant2x2( b2, b3, c2, c3 ) - b1 * Determinant2x2( a2, a3, c2, c3 ) + c1 * Determinant2x2( a2, a3, b2, b3 );
end;

function mat4inverse( Mat: TMatrix; out MatInv: TMatrix ): Boolean;
var
  L_Det: Float;
begin
  MatInv._00:=  Determinant3x3( Mat._11, Mat._21, Mat._31, Mat._12, Mat._22, Mat._32, Mat._13, Mat._23, Mat._33 );
  MatInv._10:= -Determinant3x3( Mat._10, Mat._20, Mat._30, Mat._12, Mat._22, Mat._32, Mat._13, Mat._23, Mat._33 );
  MatInv._20:=  Determinant3x3( Mat._10, Mat._20, Mat._30, Mat._11, Mat._21, Mat._31, Mat._13, Mat._23, Mat._33 );
  MatInv._30:= -Determinant3x3( Mat._10, Mat._20, Mat._30, Mat._11, Mat._21, Mat._31, Mat._12, Mat._22, Mat._32 );

  MatInv._01:= -Determinant3x3( Mat._01, Mat._21, Mat._31, Mat._03, Mat._22, Mat._32, Mat._03, Mat._23, Mat._33 );
  MatInv._11:=  Determinant3x3( Mat._00, Mat._20, Mat._30, Mat._03, Mat._22, Mat._32, Mat._03, Mat._23, Mat._33 );
  MatInv._21:= -Determinant3x3( Mat._00, Mat._20, Mat._30, Mat._01, Mat._21, Mat._31, Mat._03, Mat._23, Mat._33 );
  MatInv._31:=  Determinant3x3( Mat._00, Mat._20, Mat._30, Mat._01, Mat._21, Mat._31, Mat._03, Mat._22, Mat._32 );

  MatInv._02:=  Determinant3x3( Mat._01, Mat._11, Mat._31, Mat._03, Mat._12, Mat._32, Mat._03, Mat._13, Mat._33 );
  MatInv._12:= -Determinant3x3( Mat._00, Mat._10, Mat._30, Mat._03, Mat._12, Mat._32, Mat._03, Mat._13, Mat._33 );
  MatInv._22:=  Determinant3x3( Mat._00, Mat._10, Mat._30, Mat._01, Mat._11, Mat._31, Mat._03, Mat._13, Mat._33 );
  MatInv._32:= -Determinant3x3( Mat._00, Mat._10, Mat._30, Mat._01, Mat._11, Mat._31, Mat._03, Mat._12, Mat._32 );

  MatInv._03:= -Determinant3x3( Mat._01, Mat._11, Mat._21, Mat._03, Mat._12, Mat._22, Mat._03, Mat._13, Mat._23 );
  MatInv._13:=  Determinant3x3( Mat._00, Mat._10, Mat._20, Mat._03, Mat._12, Mat._22, Mat._03, Mat._13, Mat._23 );
  MatInv._23:= -Determinant3x3( Mat._00, Mat._10, Mat._20, Mat._01, Mat._11, Mat._21, Mat._03, Mat._13, Mat._23 );
  MatInv._33:=  Determinant3x3( Mat._00, Mat._10, Mat._20, Mat._01, Mat._11, Mat._21, Mat._03, Mat._12, Mat._22 );

  L_Det:= ( Mat._00 * MatInv._00 ) + ( Mat._01 * MatInv._10 ) + ( Mat._02 * MatInv._20 ) + ( Mat._03 * MatInv._30 );

  // Hier evntl. L_Det auf 0 prüfen, in diesem Fall ist die Matrix singular und kann nicht invertiert werden.
  Result:= L_Det > 0;
  if ( Result ) then
    L_Det:= 1.0 / L_Det;
  MatInv:= MatInv * L_Det;
end;
}



function mat4inverse( Mat: TMatrix; out MatInv: TMatrix ): Boolean;
var
  det, a1, a2, a3, a4, b1, b2, b3, b4,
  c1, c2, c3, c4, d1, d2, d3, d4: Float;
begin
  det:= mat4determinant( Mat );
  if ( Abs( det ) < epsilon ) then
    Result:= False
  else
    begin
      Result:= True;
      a1:= Mat._00; b1:= Mat._01; c1:= Mat._02; d1:= Mat._03;
      a2:= Mat._10; b2:= Mat._11; c2:= Mat._12; d2:= Mat._13;
      a3:= Mat._20; b3:= Mat._21; c3:= Mat._22; d3:= Mat._23;
      a4:= Mat._30; b4:= Mat._31; c4:= Mat._32; d4:= Mat._33;
      MatInv._00:= MatrixDet(b2, b3, b4, c2, c3, c4, d2, d3, d4);
      MatInv._10:=-MatrixDet(a2, a3, a4, c2, c3, c4, d2, d3, d4);
      MatInv._20:= MatrixDet(a2, a3, a4, b2, b3, b4, d2, d3, d4);
      MatInv._30:=-MatrixDet(a2, a3, a4, b2, b3, b4, c2, c3, c4);
      MatInv._01:=-MatrixDet(b1, b3, b4, c1, c3, c4, d1, d3, d4);
      MatInv._11:= MatrixDet(a1, a3, a4, c1, c3, c4, d1, d3, d4);
      MatInv._21:=-MatrixDet(a1, a3, a4, b1, b3, b4, d1, d3, d4);
      MatInv._31:= MatrixDet(a1, a3, a4, b1, b3, b4, c1, c3, c4);
      MatInv._02:= MatrixDet(b1, b2, b4, c1, c2, c4, d1, d2, d4);
      MatInv._12:=-MatrixDet(a1, a2, a4, c1, c2, c4, d1, d2, d4);
      MatInv._22:= MatrixDet(a1, a2, a4, b1, b2, b4, d1, d2, d4);
      MatInv._32:=-MatrixDet(a1, a2, a4, b1, b2, b4, c1, c2, c4);
      MatInv._03:=-MatrixDet(b1, b2, b3, c1, c2, c3, d1, d2, d3);
      MatInv._13:= MatrixDet(a1, a2, a3, c1, c2, c3, d1, d2, d3);
      MatInv._23:=-MatrixDet(a1, a2, a3, b1, b2, b3, d1, d2, d3);
      MatInv._33:= MatrixDet(a1, a2, a3, b1, b2, b3, c1, c2, c3);

      MatInv:= MatInv * ( 1/det );
    end;
end;

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
function mat4transpose(Matrix: TMatrix): TMatrix;
begin
  Result._00:= Matrix._00;
  Result._10:= Matrix._01;
  Result._20:= Matrix._02;
  Result._30:= Matrix._03;

  Result._01:= Matrix._10;
  Result._11:= Matrix._11;
  Result._21:= Matrix._12;
  Result._31:= Matrix._13;

  Result._02:= Matrix._20;
  Result._12:= Matrix._21;
  Result._22:= Matrix._22;
  Result._32:= Matrix._23;

  Result._03:= Matrix._30;
  Result._13:= Matrix._31;
  Result._23:= Matrix._32;
  Result._33:= Matrix._33;
end;

procedure mat4decompose( mat: TMat4; out loc: TVec3; out rot: TMat3; out scale: TVec3 );
begin
  mat3decompose( mat3( mat ), rot, scale );
  loc:= mat.Row[ 3 ].xyz;
end;

{$WARNINGS ON}



{$ENDIF}

{$ENDIF}

