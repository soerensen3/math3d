{ p3dmath_matrix_operators.inc }

{$IFDEF INTERFACE}
//@abbr`class operator for multiplying a matrix with a FieldType`. All values are affected.
class operator * ( a: TMatrix; b: FieldType ) c: TMatrix; inline;
//@abbr`class operator for multiplying two matrices`. If you multiply two transformations, the right value is the transformation applied first.
class operator * ( a: TMatrix; b: TMatrix ) c: TMatrix; //inline; // right first - left last

//@abbr`class operator for transforming a vec using a matrix`. The operation is Pre-Multiply in this order.
class operator * ( a: TVector; b: TMatrix ) c: TVector; inline; // PRE-Multiply
//@abbr`class operator for transforming a vec using a matrix`. The operation is Post-Multiply in this order.
class operator * ( a: TMatrix; b: TVector ) c: TVector; //inline; // POST-Multiply
//@abbr`class operator for comparing two matrices`.
class operator = ( a: TMatrix; b: TMatrix ) c: Boolean; inline;

class operator + ( a: TMatrix; b: TMatrix ) c: TMatrix; inline;
class operator - ( a: TMatrix; b: TMatrix ) c: TMatrix; inline;


{$IFDEF FLOATTYPE}
//@abbr`Operator for calculating the inverse of a matrix`.
class operator - ( a: TMatrix ) b: TMatrix; inline;
{$ENDIF}


{$ENDIF}

{$IFDEF IMPLEMENTATION}

{$IFDEF FLOATTYPE}
class operator TMatrix.-(a: TMatrix) b: TMatrix;
begin
  b:= a.Inverted;
end;
{$ENDIF}

class operator TMatrix.*(a: TMatrix; b: FieldType)c: TMatrix;
var
  i: Integer;
begin
  for i:= 0 to ( NUMFIELD * NUMFIELD ) - 1 do
    a._m[ i ]:= a._m[ i ] * b;
  c:= a;
end;

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TMatrix. * ( a: TMatrix; b: TMatrix ) c: TMatrix; //inline;
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
class operator TMatrix.*( a: TMatrix; b: TVector ) c: TVector;
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
class operator TMatrix.*( a: TVector; b: TMatrix ) c: TVector;
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

class operator TMatrix.=(a: TMatrix; b: TMatrix)c: Boolean;
begin
  Result:= CompareMem( @a.m, @b.m, SizeOf( a.m ));
end;

class operator TMatrix.+ ( a: TMatrix; b: TMatrix ) c: TMatrix; inline;
var
  i: Integer;
begin
  for i:= 0 to Count - 1 do
    Result[ i ]:= a[ i ] + b[ i ];
end;

class operator TMatrix.- ( a: TMatrix; b: TMatrix ) c: TMatrix; inline;
var
  i: Integer;
begin
  for i:= 0 to Count - 1 do
    Result[ i ]:= a[ i ] - b[ i ];
end;


{$ENDIF}

