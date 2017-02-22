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
  //@abbr`Quaternions can be used instead of or together with matrices for transforming the view`.
  TQuaternion = object( TVector )
    // Using TVector instead of TVec4 as descendent so it can be easily
    // replaced with double vectors for higher precision if necessary in the future
    public
      function Conj: TQuaternion;
      function GetAxisAngle: TVec4; //with XYZ as Axis and A (=W) as angle
  end;

  TRotationOrder = ( roXYZ = 0, roXZY = 1, roYXZ = 2, roYZX = 3, roZXY = 4, roZYX = 5 );

//Multiplies two quaternions.
operator * ( q1, q2: TQuaternion ) q : TQuaternion;
//Transforms a vector using a quaternion.
//operator * ( a: TQuaternion; b: TVector ) c: TVector;
operator * ( a: TQuaternion; b: TVec3 ) c: TVec3;
//Inverts a quaternion.
operator - ( a: TQuaternion ) b: TQuaternion;

function quat( vec: TVector ): TQuaternion;
function quat( x, y, z, w: Fieldtype ): TQuaternion;
function quat( mat: TMat3 ): TQuaternion;
function quatRotation( Axis: TVec3; Alpha: Float ): TQuaternion;

{$ENDIF}
{$IFDEF IMPLEMENTATION}
{ TQuaternion }

function TQuaternion.Conj: TQuaternion;
begin
  Result.w:=  w;
  Result.x:= -x;
  Result.y:= -y;
  Result.z:= -z;
end;

function TQuaternion.GetAxisAngle: TVec4;
var
  q1: TQuaternion;
  sp: Single;
begin
  q1:= Self;
  if ( q1.w > 1) then
    q1.Normalize(); // if w>1 acos and sqrt will produce errors, this cant happen if quaternion is normalised
  Result.w:= 2 * arccos( q1.w );
  sp:= sqrt( 1 - q1.w * q1.w ); // assuming quaternion normalised then w is less than 1, so term always positive.
  if ( sp < 0.001 ) then // test to avoid divide by zero, sp is always positive due to sqrt
    // if sp close to zero then direction of axis not important
    begin
      x:= q1.x; // if it is important that axis is normalised then replace with x=1; y=z=0;
      y:= q1.y;
      z:= q1.z;
    end
  else
    begin
      x:= q1.x / sp; // normalise axis
      y:= q1.y / sp;
      z:= q1.z / sp;
    end;
end;

operator*(q1, q2: TQuaternion)q: TQuaternion;
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

{
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
}

operator * ( a: TQuaternion; b: TVec3 ) c: TVec3;
var
  t0, t1, t2: Float;
begin{
  t0:= - a.x * b.x - a.y * b.y - a.z * b.z;
  t1:=   a.w * b.x + a.y * b.z - a.z * b.y;
  t2:=   a.w * b.y + a.z * b.x - a.x * b.z;
  c.z:= a.w * b.z + a.x * b.y - a.y * b.x;
  c.x:= t1;
  c.y:= t2;

  t1:= t0 * -a.x + c.x * a.w - c.y * a.z + c.z * a.y;
  t2:= t0 * -a.y + c.y * a.w - c.z * a.x + c.x * a.z;
  c.z:= t0 * -a.z + c.z * a.w - c.x * a.y + c.y * a.x;
  c.x:= t1;
  c.y:= t2;
  }
  //c:= b + 2.0 * cross( cross( b, a.xyz ) + a.w * b, a.xyz );
  {

  t0:= b.y * a.z - b.z * a.y + a.w * b.x;
  t1:= b.z * a.x - b.x * a.z + a.w * b.y;
  t2:= b.x * a.y - b.y * a.x + a.w * b.z;

  c.x:= b.x + 2.0 * ( t1 * a.z - t2 * a.y );
  c.y:= b.y + 2.0 * ( t2 * a.x - t0 * a.z );
  c.z:= b.z + 2.0 * ( t0 * a.y - t1 * a.x );}
  c:= ( a * quat( b.x, b.y, b.z, 0 ) * a.Conj ).xyz;
end;

{$WARNINGS ON}

{$HINTS OFF} // Omit hints about the function result variable not being initialized
operator -( a: TQuaternion ) b: TQuaternion;
var
  len: Single;
  f: Fieldtype;
begin
  //len:= a.GetDist;
  //len:= len * len;
  f:= dot( a, a );
  if ( f = 0.0 ) then
    FillByte( b, SizeOf( b ), 0 )
  else
    b:= quat( TVector( a.Conj()) * ( 1.0 / f ));
end;

function quat(vec: TVec4): TQuaternion;
begin
  Result.w:= vec.w;
  Result.x:= vec.x;
  Result.y:= vec.y;
  Result.z:= vec.z;
end;

function quat(x, y, z, w: Fieldtype): TQuaternion;
begin
  Result.w:= w;
  Result.x:= x;
  Result.y:= y;
  Result.z:= z;
end;

//Converted from math_rotation.c from blender
function quat( mat: TMat3 ): TQuaternion;
var
  tr, s: Double;
begin
  mat.Col[ 0 ]:= normalize( mat.Col[ 0 ]);// this is needed AND a 'normalize_qt' in the end
  mat.Col[ 1 ]:= normalize( mat.Col[ 1 ]);
  mat.Col[ 2 ]:= normalize( mat.Col[ 2 ]);

  tr:= 0.25 * (1.0 + mat.Col[0][0] + mat.Col[1][1] + mat.Col[2][2]);

  if (tr > epsilon) then
    begin
      s:= sqrt( tr );
      Result.w:= s;
      s:= 1.0 / (4.0 * s);
      Result.x:= ( mat.Col[1][2] - mat.Col[2][1]) * s;
      Result.y:= ( mat.Col[2][0] - mat.Col[0][2]) * s;
      Result.z:= ( mat.Col[0][1] - mat.Col[1][0]) * s;
    end
  else
    begin
      if (( mat.Col[0][0] > mat.Col[1][1]) AND ( mat.Col[0][0] > mat.Col[2][2])) then
        begin
  	  s:= 2.0 * sqrt( 1.0 + mat.Col[0][0] - mat.Col[1][1] - mat.Col[2][2]);
  	  Result.x:= (0.25 * s);

  	  s:= 1.0 / s;
  	  Result.w:= (mat.Col[2][1] - mat.Col[1][2]) * s;
  	  Result.y:= (mat.Col[1][0] + mat.Col[0][1]) * s;
  	  Result.z:= (mat.Col[2][0] + mat.Col[0][2]) * s;
  	end
      else if (mat.Col[1][1] > mat.Col[2][2]) then
        begin
  	  s:= 2.0 * sqrt(1.0 + mat.Col[1][1] - mat.Col[0][0] - mat.Col[2][2]);
  	  Result.y:= (0.25 * s);

  	  s:= 1.0 / s;
  	  Result.w:= (mat.Col[2][0] - mat.Col[0][2]) * s;
  	  Result.x:= (mat.Col[1][0] + mat.Col[0][1]) * s;
  	  Result.z:= (mat.Col[2][1] + mat.Col[1][2]) * s;
      end
      else
        begin
  	  s:= 2.0 * sqrt(1.0 + mat.Col[2][2] - mat.Col[0][0] - mat.Col[1][1]);
  	  Result.z:= (0.25 * s);

  	  s:= 1.0 / s;
  	  Result.w:= (mat.Col[1][0] - mat.Col[0][1]) * s;
  	  Result.x:= (mat.Col[2][0] + mat.Col[0][2]) * s;
  	  Result.y:= (mat.Col[2][1] + mat.Col[1][2]) * s;
  	end;
    end;

  Result.Normalize;
  //Result.w:= sqrt( 1 + mat._00 + mat._11 + mat._22) /2;
  //Result.x:= (mat._21 - mat._12)/( 4 * Result.w);
  //Result.y:= (mat._02 - mat._20)/( 4 * Result.w);
  //Result.z:= (mat._10 - mat._01)/( 4 * Result.w);
end;

function quatRotation( Axis: TVec3; Alpha: Float ): TQuaternion;
begin
  Result:= quat( Axis.x * sin( Alpha/2 ), Axis.y * sin( Alpha/2 ), Axis.z * sin( Alpha/2 ), cos( Alpha/2 ));
end;





{$WARNINGS ON}

{$ENDIF}
