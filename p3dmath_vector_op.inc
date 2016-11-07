//Operator for adding two vectors.
operator + ( a, b: TVector ) c: TVector; inline;
//Operator for adding one vector and a FieldType.
operator + ( a: TVector; b: FieldType ) c: TVector; inline;
//Operator for subtracting two vectors.
operator - ( a, b: TVector ) c: TVector; inline;
//Operator for subtracting one vector and a FieldType.
operator - ( a: TVector; b: FieldType ) c: TVector; inline;
//Operator for multiplying two vectors component-wise.
operator * ( a, b: TVector ) c: TVector; inline;
//Operator for scaling a vector using a scalar (FieldType).
operator * ( a: TVector; s: FieldType ) c: TVector; inline;
//Operator for scaling a vector using a scalar (FieldType).
operator * ( s: FieldType; b: TVector ) c: TVector; inline;
{$IFDEF FLOATTYPE}
//Operator for dividing two vectors component-wise.
operator / ( a, b: TVector ) c: TVector; inline;
//Operator for scaling a vector using a scalar (FieldType). This is the same as multiplying by 1/s
operator / ( a: TVector; s: FieldType ) c: TVector; inline;
{$ENDIF}
{$IFDEF INTTYPE}
//Operator for dividing two vectors component-wise. Please note that in GLSL this is done by the / operator but due to Pascal convention is called div here.
operator div ( a, b: TVector ) c: TVector; inline;
//Operator for scaling a vector using a scalar (FieldType). Please note that in GLSL this is done by the / operator but due to Pascal convention is called div here. This is the same as multiplying by 1/s
operator div ( a: TVector; s: FieldType ) c: TVector; inline;
//Operator for calculating the modulo of two vectors component-wise. Please note that in GLSL this is done by the mod function but due to Pascal convention is an operator here.
operator mod ( a, b: TVector ) c: TVector; inline;
//Operator for calculating the modulo of a vector using a scalar (FieldType). Please note that in GLSL this is done by the mod function but due to Pascal convention is an operator here.
operator mod ( a: TVector; s: FieldType ) c: TVector; inline;
{$ENDIF}
//Operator for negating a vector.
operator - ( a: TVector ) c: TVector; inline;
//Operator for comparing two vectors.
operator = ( a, b: TVector ) c: Boolean; inline;
