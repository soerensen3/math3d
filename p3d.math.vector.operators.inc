{$IFDEF INTERFACE}
  {$IFDEF QUATTYPE}
  //Multiplies two quaternions.
  class operator * ( q1, q2: TVector ) q : TVector;
  //Transforms a vector using a quaternion.
  //operator * ( a: TQuaternion; b: TVector ) c: TVector;
  class operator * ( a: TVector; b: TVec3 ) c: TVec3;
  //Inverts a quaternion.
  class operator - ( q1: TVector ) q: TVector;
  {$ELSE}
  //class Operator for multiplying two vectors component-wise.
  class operator * ( a, b: TVector ) c: TVector; inline;
  //class Operator for negating a vector.
  class operator - ( a: TVector ) c: TVector; inline;
  {$ENDIF}

  //class Operator for adding two vectors.
  class operator + ( a, b: TVector ) c: TVector; inline;
  //class Operator for adding one vector and a FieldType.
  class operator + ( a: TVector; b: FieldType ) c: TVector; inline;
  //class Operator for subtracting two vectors.
  class operator - ( a, b: TVector ) c: TVector; inline;
  //class Operator for subtracting one vector and a FieldType.
  class operator - ( a: TVector; b: FieldType ) c: TVector; inline;
  //class Operator for scaling a vector using a scalar (FieldType).
  class operator * ( a: TVector; s: FieldType ) c: TVector; inline;
  //class Operator for scaling a vector using a scalar (FieldType).
  class operator * ( s: FieldType; b: TVector ) c: TVector; inline;
  {$IFDEF FLOATTYPE}
  //class Operator for dividing two vectors component-wise.
  class operator / ( a, b: TVector ) c: TVector; inline;
  //class Operator for scaling a vector using a scalar (FieldType). This is the same as multiplying by 1/s
  class operator / ( a: TVector; s: FieldType ) c: TVector; inline;
  {$ENDIF}
  {$IFDEF INTTYPE}
  class operator * ( a: TVector; s: Float ) c: TVector; inline;
  class operator * ( a: TVector; s: Double ) c: TVector; inline;

  //class Operator for dividing two vectors component-wise. Please note that in GLSL this is done by the / class operator but due to Pascal convention is called div here.
  class operator div ( a, b: TVector ) c: TVector; inline;
  //class Operator for scaling a vector using a scalar (FieldType). Please note that in GLSL this is done by the / class operator but due to Pascal convention is called div here. This is the same as multiplying by 1/s
  class operator div ( a: TVector; s: FieldType ) c: TVector; inline;
  //class Operator for calculating the modulo of two vectors component-wise. Please note that in GLSL this is done by the mod function but due to Pascal convention is an class operator here.
  class operator mod ( a, b: TVector ) c: TVector; inline;
  //class Operator for calculating the modulo of a vector using a scalar (FieldType). Please note that in GLSL this is done by the mod function but due to Pascal convention is an class operator here.
  class operator mod ( a: TVector; s: FieldType ) c: TVector; inline;
  {$ENDIF}
  //class Operator for checking if two vectors are equal.
  class operator =(a, b: TVector) c: Boolean;
  //class Operator for checking if all components of first vector are smaller than the second vector.
  class operator <(a, b: TVector) c: Boolean;
  //class Operator for checking if all components of first vector are greater than the second vector.
  class operator >(a, b: TVector) c: Boolean;
  //class Operator for checking if all components of first vector are smaller or equal to the second vector.
  class operator <=(a, b: TVector) c: Boolean;
  //class Operator for checking if all components of first vector are greater or equal to the second vector.
  class operator >=(a, b: TVector) c: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class operator TVector.+(a, b: TVector)c: TVector;
begin
  c.x:= a.x + b.x;
  {$IF NUMFIELD > 1}
  c.y:= a.y + b.y;
  {$ENDIF}
  {$IF NUMFIELD > 2}
  c.z:= a.z + b.z;
  {$ENDIF}
  {$IF NUMFIELD > 3}
  c.w:= a.w + b.w;
  {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector.+(a: TVector; b: FieldType)c: TVector;
begin
  c.x:= a.x + b;
  {$IF NUMFIELD > 1}
  c.y:= a.y + b;
  {$ENDIF}
  {$IF NUMFIELD > 2}
  c.z:= a.z + b;
  {$ENDIF}
  {$IF NUMFIELD > 3}
  c.w:= a.w + b;
  {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector.-(a, b: TVector)c: TVector;
begin
  c.x:= a.x - b.x;
  {$IF NUMFIELD > 1}
  c.y:= a.y - b.y;
  {$ENDIF}
  {$IF NUMFIELD > 2}
  c.z:= a.z - b.z;
  {$ENDIF}
  {$IF NUMFIELD > 3}
  c.w:= a.w - b.w;
  {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector.-(a: TVector; b: FieldType)c: TVector;
begin
  c.x:= a.x - b;
  {$IF NUMFIELD > 1}
  c.y:= a.y - b;
  {$ENDIF}
  {$IF NUMFIELD > 2}
  c.z:= a.z - b;
  {$ENDIF}
  {$IF NUMFIELD > 3}
  c.w:= a.w - b;
  {$ENDIF}
end;
  {$WARNINGS ON}

  {$IFDEF QUATTYPE}
class operator TVector.*(q1, q2: TVector)q: TVector;
begin
  q.w:=   q1.w * q2.w
        - q1.x * q2.x
        - q1.y * q2.y
        - q1.z * q2.z;
  q.x:=   q1.w * q2.x
        + q1.x * q2.w
        + q1.y * q2.z
        - q1.z * q2.y;
  q.y:=   q1.w * q2.y
        - q1.x * q2.z
        + q1.y * q2.w
        + q1.z * q2.x;
  q.z:=   q1.w * q2.z
        + q1.x * q2.y
        - q1.y * q2.x
        + q1.z * q2.w;
end;


class operator TVector.* ( a: TVector; b: TVec3 ) c: TVec3;
begin
  c:= ( a * quat( b.x, b.y, b.z, 0 ) * a.Conj ).xyz;
end;

    {$WARNINGS ON}

    {$HINTS OFF} // Omit hints about the function result variable not being initialized
class operator TVector.-( q1: TVector ) q: TVector;
var
  f: Fieldtype;
begin
  f:= q1.dot( q1 );
  if ( f = 0.0 ) then
    FillByte( q, SizeOf( q ), 0 )
  else
    q:= TVector( q1 ).Conj() * ( 1.0 / f );
end;

  {$ELSE}
class operator TVector.-(a: TVector)c: TVector;
begin
  c:= a * -1;
end;

    {$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector.*(a, b: TVector )c: TVector;
begin
  c.x:= a.x * b.x;
    {$IF NUMFIELD > 1}
  c.y:= a.y * b.y;
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= a.z * b.z;
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= a.w * b.w;
    {$ENDIF}
end;
  {$ENDIF}


{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector.*(a: TVector; s: FieldType)c: TVector;
begin
  c.x:= a.x * s;
  {$IF NUMFIELD > 1}
  c.y:= a.y * s;
  {$ENDIF}
  {$IF NUMFIELD > 2}
  c.z:= a.z * s;
  {$ENDIF}
  {$IF NUMFIELD > 3}
  c.w:= a.w * s;
  {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector.*(s: FieldType; b: TVector)c: TVector;
begin
  c.x:= b.x * s;
  {$IF NUMFIELD > 1}
  c.y:= b.y * s;
  {$ENDIF}
  {$IF NUMFIELD > 2}
  c.z:= b.z * s;
  {$ENDIF}
  {$IF NUMFIELD > 3}
  c.w:= b.w * s;
  {$ENDIF}
end;

  {$IFDEF FloatType}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector./(a, b: TVector)c: TVector;
begin
  c.x:= a.x / b.x;
    {$IF NUMFIELD > 1}
  c.y:= a.y / b.y;
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= a.z / b.z;
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= a.w / b.w;
    {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector./(a: TVector; s: FieldType)c: TVector;
begin
  c.x:= a.x / s;
    {$IF NUMFIELD > 1}
  c.y:= a.y / s;
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= a.z / s;
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= a.w / s;
    {$ENDIF}
end;
    {$WARNINGS ON}
  {$ENDIF}
  {$IFDEF IntType}

class operator TVector.* ( a: TVector; s: Float ) c: TVector; inline;
begin
  c.x:= round( a.x * s );
    {$IF NUMFIELD > 1}
  c.y:= round( a.y * s );
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= round( a.z * s );
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= round( a.w * s );
    {$ENDIF}
end;

class operator TVector.* ( a: TVector; s: Double ) c: TVector; inline;
begin
  c.x:= round( a.x * s );
    {$IF NUMFIELD > 1}
  c.y:= round( a.y * s );
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= round( a.z * s );
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= round( a.w * s );
    {$ENDIF}
end;


{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector. div(a, b: TVector)c: TVector;
begin
  c.x:= a.x div b.x;
    {$IF NUMFIELD > 1}
  c.y:= a.y div b.y;
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= a.z div b.z;
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= a.w div b.w;
    {$ENDIF}
end;

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
class operator TVector. div(a: TVector; s: FieldType)c: TVector;
begin
  c.x:= a.x div s;
    {$IF NUMFIELD > 1}
  c.y:= a.y div s;
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= a.z div s;
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= a.w div s;
    {$ENDIF}
end;

class operator TVector. mod(a, b: TVector)c: TVector;
begin
  c.x:= a.x mod b.x;
    {$IF NUMFIELD > 1}
  c.y:= a.y mod b.y;
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= a.z mod b.z;
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= a.w mod b.w;
    {$ENDIF}
end;


class operator TVector. mod(a: TVector; s: FieldType)c: TVector;
begin
  c.x:= a.x mod s;
    {$IF NUMFIELD > 1}
  c.y:= a.y mod s;
    {$ENDIF}
    {$IF NUMFIELD > 2}
  c.z:= a.z mod s;
    {$ENDIF}
    {$IF NUMFIELD > 3}
  c.w:= a.w mod s;
    {$ENDIF}
end;

{$WARNINGS ON}
  {$ENDIF}


class operator TVector.=(a, b: TVector)c: Boolean;
begin
  c:= a.Compare( b );
end;

class operator TVector.<(a, b: TVector)c: Boolean;
begin
  c:= a.Less( b );
end;

class operator TVector.>(a, b: TVector)c: Boolean;
begin
  c:= a.Greater( b );
end;

class operator TVector.<=(a, b: TVector)c: Boolean;
begin
  c:= a.LessEqual( b );
end;

class operator TVector.>=(a, b: TVector)c: Boolean;
begin
  c:= a.GreaterEqual( b );
end;

{$ENDIF}
