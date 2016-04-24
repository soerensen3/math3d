{$INCLUDE p3dmath_vector_functions.inc}
//Operator for adding two vectors.
operator + ( a, b: TVector ) c: TVector; inline;
//Operator for adding one vector and a float.
operator + ( a: TVector; b: Float ) c: TVector; inline;
//Operator for subtracting two vectors.
operator - ( a, b: TVector ) c: TVector; inline;
//Operator for subtracting one vector and a float.
operator - ( a: TVector; b: Float ) c: TVector; inline;
//Operator for multiplying two vectors component-wise.
operator * ( a, b: TVector ) c: TVector; inline;
//Operator for calculating a dot product of two vectors.
operator * ( a, b: TVector ) c: Float; inline;
//Operator for scaling a vector using a scalar (float).
operator * ( a: TVector; s: Float ) c: TVector; inline;
//Operator for scaling a vector using a scalar (float).
operator * ( s: Float; b: TVector ) c: TVector; inline;
//Operator for dividing two vectors component-wise.
operator / ( a, b: TVector ) c: TVector; inline;
//Operator for scaling a vector using a scalar (float). This is the same as multiplying by -s
operator / ( a: TVector; s: Float ) c: TVector; inline;
//Operator for negating a vector.
operator - ( a: TVector ) c: TVector; inline;
//Operator for comparing two vectors.
operator = ( a, b: TVector ) c: Boolean; inline;
