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

{$IFDEF FLOATTYPE}

//@abbr`This return a normalized vector leaving the original vector untouched`.
function normalize( x: TVector ): TVector; overload;
    {$IFDEF IMPLEMENTATION}
begin
  Result:= x;
  Result.normalize;
end;
    {$ENDIF}

    {$IF NUMFIELD>2}
//@abbr`This will return the cross product of two vectors`.
function cross ( x: TVector; y: TVector ): TVector; overload;
       {$IFDEF IMPLEMENTATION}
begin
  Result:= x.cross( y );
end;
       {$ENDIF}

    {$ENDIF}
//@abbr`This will return the dot product of two vectors`.
function dot( x: TVector; y: TVector ): FieldType; overload;
    {$IFDEF IMPLEMENTATION}
begin
  Result:= x.dot( y );
end;
    {$ENDIF}


    {$IFDEF QUATTYPE}
      function quatrotate( Axis: TVec3; Alpha: FieldType ): TVector;
      {$IFDEF IMPLEMENTATION}
      begin
        Result:= quat( Axis.x * sin( Alpha/2 ), Axis.y * sin( Alpha/2 ), Axis.z * sin( Alpha/2 ), cos( Alpha/2 ));
      end;
      {$ENDIF}
    {$ELSE}

function project( x: TVector; Normal: TVector ): TVector;
       {$IFDEF IMPLEMENTATION}
begin
  Result:= dot( x, Normal ) / dot( Normal, Normal ) * Normal;
end;
       {$ENDIF}

//@abbr`Computes the direction of a refracted ray` if i specifies the normalized(!)
//direction of the incoming ray and n specifies the normalized(!) normal vector
//of the interface of two optical media (e.g. air and water). The vector n
//should point to the side from where i is coming, i.e. the dot product of n and
//i should be negative. The floating-point number r is the ratio of the
//refractive index of the medium from where the ray comes to the refractive index
//of the medium on the other side of the surface. Thus, if a ray comes from air
//(refractive index about 1.0) and hits the surface of water (refractive index 1.33),
//then the ratio r is 1.0 / 1.33 = 0.75.
{
function refract( i, n: TVector; r: Fieldtype ): TVector; overload;
       {$IFDEF IMPLEMENTATION}
var
  d: Fieldtype;
begin
  d:= 1.0 - r * r * (1.0 - dot(n, i) * dot(n, i));
  if ( d < 0.0 ) then
    Result:= vector( 0 ) // total internal reflection
  else
    Result:= r * i - ( r * dot( n, i ) + sqrt( d )) * n;
end;
       {$ENDIF}}

//@abbr`Will reflect an input vector using a normal vector.` For a given incident vector I and surface normal N reflect returns the reflection direction calculated as I - 2.0 * dot(N, I) * N.
//N should be normalized in order to achieve the desired result.
function reflect( i, n: TVector ): TVector; overload;
       {$IFDEF IMPLEMENTATION}
begin
  Result:= I - 2.0 * dot(N, I) * N;
end;
       {$ENDIF}

//@abbr`Returns the distance between the two points p0 and p1`.
function distance( p0, p1: TVector ): Fieldtype; overload;
       {$IFDEF IMPLEMENTATION}
begin
  Result:= ( p1 - p0 ).length;
end;
       {$ENDIF}

//@abbr`Generate a step function by comparing two values`.
{function step( edge, x: TVector ): TVector; overload;
       {$IFDEF IMPLEMENTATION}
begin
  Result:= TVector( x < edge );
end;}

//@abbr`Will make a gradient between two edges`.
function smoothstep( edge0, edge1, x: TVector ): TVector; overload;
       {$IFDEF IMPLEMENTATION}
var
  t: TVector;
begin
   t:= clamp(( x - edge0 ) / ( edge1 - edge0 ), 0, 1 );
   Result:= t * t * ( - 2 * t + 3 );
end;
       {$ENDIF}


       {$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
       {$IF NUMFIELD = 4}

(*//@abbr`This will unproject a vector using world, view and projection matrix`. It will return the unprojected vector and the direction it is pointing to.
function unproject( x: TVector; matWorld, matView, matProj: TMat4; Width, Height: Integer; out vDirection: TVector ): TVector;
  {$IFDEF IMPLEMENTATION}
var
  m: TMatrix;
begin
  // Compute the vector of the pick ray in screen space
  Result.x:=  ((( 2.0 * x.x ) / Width ) - 1 ) / matProj._00;
  Result.y:= -((( 2.0 * x.y ) / Height ) - 1 ) / matProj._11;
  Result.z:= -1.0; //TODO: Check if left or righthanded

  // Get the inverse view matrix

  mat4inverse( matView * matWorld, m );

  // Transform the screen space pick ray into 3D space
  vDirection.x:= Result.x * m._00 + Result.y * m._10 + Result.z * m._20;
  vDirection.y:= Result.x * m._01 + Result.y * m._11 + Result.z * m._21;
  vDirection.z:= Result.x * m._02 + Result.y * m._12 + Result.z * m._22;
  vDirection.Normalize;
  Result.x:= m._30;
  Result.y:= m._31;
  Result.z:= m._32;
end;
  {$ENDIF}
  *)
       {$ENDIF}
  {$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a value equal to the nearest integer that is less than or equal to x`.
function floor( x: TVector ): TVector; overload;
  {$IFDEF IMPLEMENTATION}
begin
  Result.x:= floor( x.x );
    {$IF NUMFIELD > 1}
  Result.y:= floor( x.y );
    {$ENDIF}
    {$IF NUMFIELD > 2}
  Result.z:= floor( x.z );
    {$ENDIF}
    {$IF NUMFIELD > 3}
  Result.w:= floor( x.w );
    {$ENDIF}
end;
  {$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a value equal to the nearest integer that is greater than or equal to x`.
  function ceil( x: TVector ): TVector; overload;
  {$IFDEF IMPLEMENTATION}
begin
  Result.x:= ceil( x.x );
    {$IF NUMFIELD > 1}
  Result.y:= ceil( x.y );
    {$ENDIF}
    {$IF NUMFIELD > 2}
  Result.z:= ceil( x.z );
    {$ENDIF}
    {$IF NUMFIELD > 3}
  Result.w:= ceil( x.w );
    {$ENDIF}
end;
  {$ENDIF}


{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns a value equal to the nearest integer to x`.
function round( x: TVector ): TVector; overload;
  {$IFDEF IMPLEMENTATION}
begin
  Result.x:= round( x.x );
    {$IF NUMFIELD > 1}
  Result.y:= round( x.y );
    {$ENDIF}
    {$IF NUMFIELD > 2}
  Result.z:= round( x.z );
    {$ENDIF}
    {$IF NUMFIELD > 3}
  Result.w:= round( x.w );
    {$ENDIF}
end;
  {$ENDIF}
  {$WARNINGS ON}

//@abbr`Returns the length of the vector`. It's not called length because it would
//override the function Length from system, which is invisible then.
function _length( p: TVector ): Fieldtype; overload;
  {$IFDEF IMPLEMENTATION}
begin
  Result:= p.length;
end;
  {$ENDIF}

//@abbr`Returns the length of the vector`. It's not called length because it would
//override the function Length from system, which is invisible then.
function length_sq( p: TVector ): Fieldtype; overload;
  {$IFDEF IMPLEMENTATION}
begin
  Result:= p.length_sq;
end;
  {$ENDIF}

  {$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns the fractional part of x`.
function fract( x: TVector ): TVector; overload;
  {$IFDEF IMPLEMENTATION}
begin
  Result.x:= frac( x.x );
    {$IF NUMFIELD > 1}
  Result.y:= frac( x.y );
    {$ENDIF}
    {$IF NUMFIELD > 2}
  Result.z:= frac( x.z );
    {$ENDIF}
    {$IF NUMFIELD > 3}
  Result.w:= frac( x.w );
    {$ENDIF}
end;
  {$ENDIF}

  {$WARNINGS ON}

{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will return the bigger components of two vectors`. It works component-wise.
function max( x: TVector; y: TVector ): TVector; overload;
{$IFDEF IMPLEMENTATION}
begin
  Result.x:= max( x.x, y.x );
  {$IF NUMFIELD > 1}
  Result.y:= max( x.y, y.y );
  {$ENDIF}
  {$IF NUMFIELD > 2}
  Result.z:= max( x.z, y.z );
  {$ENDIF}
  {$IF NUMFIELD > 3}
  Result.w:= max( x.w, y.w );
  {$ENDIF}
end;
{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will return the smaller components of two vectors`. It works component-wise.
function min( x: TVector; y: TVector ): TVector; overload;
{$IFDEF IMPLEMENTATION}
begin
  Result.x:= min( x.x, y.x );
  {$IF NUMFIELD > 1}
  Result.y:= min( x.y, y.y );
  {$ENDIF}
  {$IF NUMFIELD > 2}
  Result.z:= min( x.z, y.z );
  {$ENDIF}
  {$IF NUMFIELD > 3}
  Result.w:= min( x.w, y.w );
  {$ENDIF}
end;
{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will return the bigger components of one vector and a scalar`. It works component-wise.
function max( x: TVector; s: FieldType ): TVector; overload;
{$IFDEF IMPLEMENTATION}
begin
  Result.x:= max( x.x, s );
  {$IF NUMFIELD > 1}
  Result.y:= max( x.y, s );
  {$ENDIF}
  {$IF NUMFIELD > 2}
  Result.z:= max( x.z, s );
  {$ENDIF}
  {$IF NUMFIELD > 3}
  Result.w:= max( x.w, s );
  {$ENDIF}
end;
{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Will return the smaller components of one vector and a scalar`. It works component-wise.
function min( x: TVector; s: Fieldtype ): TVector; overload;
{$IFDEF IMPLEMENTATION}
begin
  Result.x:= min( x.x, s );
  {$IF NUMFIELD > 1}
  Result.y:= min( x.y, s );
  {$ENDIF}
  {$IF NUMFIELD > 2}
  Result.z:= min( x.z, s );
  {$ENDIF}
  {$IF NUMFIELD > 3}
  Result.w:= min( x.w, s );
  {$ENDIF}
end;
{$ENDIF}
{$WARNINGS ON}

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x, minVal, maxVal: TVector ): TVector; overload;
{$IFDEF IMPLEMENTATION}
begin
  Result:= min( max( x, minVal ), maxVal );
end;
{$ENDIF}


{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns x if x >= 0; otherwise, it returns -x`.
function abs( x: TVector ): TVector; overload;
{$IFDEF IMPLEMENTATION}
begin
  Result.x:= abs( x.x );
  {$IF NUMFIELD > 1}
  Result.y:= abs( x.y );
  {$ENDIF}
  {$IF NUMFIELD > 2}
  Result.z:= abs( x.z );
  {$ENDIF}
  {$IF NUMFIELD > 3}
  Result.w:= abs( x.w );
  {$ENDIF}
end;
{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized

//@abbr`Returns the value of x constrained to the range minVal to maxVal`. The returned value is computed as min(max(x, minVal), maxVal).
function clamp( x: TVector; minVal, maxVal: Fieldtype ): TVector; overload;
{$IFDEF IMPLEMENTATION}
begin
  Result.x:= min( max( x.x, minVal ), maxVal );
  {$IF NUMFIELD > 1}
  Result.y:= min( max( x.y, minVal ), maxVal );
  {$ENDIF}
  {$IF NUMFIELD > 2}
  Result.z:= min( max( x.z, minVal ), maxVal );
  {$ENDIF}
  {$IF NUMFIELD > 3}
  Result.w:= min( max( x.w, minVal ), maxVal );
  {$ENDIF}
end;
{$ENDIF}

//TODO: Write Doc
function mix( x, y: TVector; a: Double ): TVector;
{$IFDEF IMPLEMENTATION}
begin
  {$IFDEF FLOATTYPE}
  Result:= x * ( 1 - a) + y * a;
  {$ENDIF}
  {$IFDEF INTTYPE}
  //Result:= round( x * ( 1 - a ) + y * a );
  {$ENDIF}
end;
{$ENDIF}

