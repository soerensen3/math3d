{$IFDEF INTERFACE}
type
  //@abbr`Quaternions can be used instead of or together with matrices for transforming the view`.
  TQuaternion = object( TVector )
    // Using TVector instead of TVec4 as descendent so it can be easily
    // replaced with double vectors for higher precision if necessary in the future
    public
      property a: Float read FCoord[ 0 ] write FCoord[ 0 ];
      property b: Float read FCoord[ 1 ] write FCoord[ 1 ];
      property c: Float read FCoord[ 2 ] write FCoord[ 2 ];
      property d: Float read FCoord[ 3 ] write FCoord[ 3 ];

      function Conj: TQuaternion;
  end;

//Multiplies two quaternions.
operator * ( q1, q2: TQuaternion ) q : TQuaternion;
//Transforms a vector using a quaternion.
operator * ( a: TQuaternion; b: TVector ) c: TVector;
//Inverts a quaternion.
operator - ( a: TQuaternion ) b: TQuaternion;

function quat( vec: TVector ): TQuaternion;
function quat( a, b, c, d: Float ): TQuaternion;

{$ENDIF}
{$IFDEF IMPLEMENTATION}
{ TQuaternion }

function TQuaternion.Conj: TQuaternion;
begin
  Result.a:= a;
  Result.b:= -b;
  Result.c:= -c;
  Result.d:= -d;
end;

operator*(q1, q2: TQuaternion)q: TQuaternion;
begin
  q.a:=   q1.a * q2.a
        - q1.b * q2.b
        - q1.c * q2.c
        - q1.d * q2.d;
  q.b:=   q1.a * q2.b
        + q1.b * q2.a
        + q1.c * q2.d
        - q1.d * q2.c;
  q.c:=   q1.a * q2.c
        - q1.b * q2.d
        + q1.c * q2.a
        + q1.d * q2.b;
  q.d:=   q1.a * q2.d
        + q1.b * q2.c
        - q1.c * q2.b
        + q1.d * q2.a;
end;

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator * ( a: TQuaternion; b: TVec4 ) c: TVec4;
var
  a00, a01, a02, a03,
  a11, a12, a13, a22,
  a23, a33: Float;
begin
  a00:= a[0] * a[0];
  a01:= a[0] * a[1];
  a02:= a[0] * a[2];
  a03:= a[0] * a[3];
  a11:= a[1] * a[1];
  a12:= a[1] * a[2];
  a13:= a[1] * a[3];
  a22:= a[2] * a[2];
  a23:= a[2] * a[3];
  a33:= a[3] * a[3];

  c[0]:= b.x * ( +a00 + a11 - a22 - a33 )
        + 2 * ( a12 * b.y + a13 * b.z + a02 * b.z - a03 * b.y );
  c[1]:= b.y * ( +a00 - a11 + a22 - a33 )
        + 2 * ( a12 * b.x + a23 * b.z + a03 * b.x - a01 * b.z );
  c[2]:= b.z * ( +a00 - a11 - a22 + a33 )
        + 2 * ( a13 * b.x + a23 * b.y - a02 * b.x + a01 * b.y );

  c[3]:= 1;
end;
{$WARNINGS ON}

{$HINTS OFF} // Omit hints about the function result variable not being initialized
operator -( a: TQuaternion ) b: TQuaternion;
var
  len: Single;
begin
  len:= a.GetDist;
  len:= len * len;
  if ( len = 0.0 ) then
    FillByte( b, SizeOf( b ), 0 )
  else
    b:= quat( TVector( a.Conj()) * ( 1.0 / len ));
end;

function quat(vec: TVec4): TQuaternion;
begin
  Result.a:= vec.x;
  Result.b:= vec.y;
  Result.c:= vec.z;
  Result.d:= vec.w;
end;

function quat(a, b, c, d: Float): TQuaternion;
begin
  Result.a:= a;
  Result.b:= b;
  Result.c:= c;
  Result.d:= d;
end;


{$WARNINGS ON}

{$ENDIF}
