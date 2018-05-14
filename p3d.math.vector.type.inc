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

{$IFDEF INTERFACE }

{@abstract' @classname is a basic vector object wich can be modified with operators and functions
and which provides some methods itself.
There are provided different ways to access the fields of the vector.'
@orderedList(
@item Using Coord
@item Using @bold( x,y,z,w r,g,b,a s,t,p,q ) properties
@item Using Swizzling
)
@italic(1. Access the fields with the array @bold(Coord)) @br@br
@bold(Coord) is the default property so using @bold( v[ 0 ]) is the same as @bold( v.Coord[ 0 ] ). @br@br
@italic(2. Alternatively you can use it's properties @bold( X, Y, Z, W ).) @br@br
However you can also write @bold( R, G, B, A ) if you use the vector for color values
for example. Another alias is @bold( S, T, P, Q ) which is for texture coordinates.
So all these code lines are equivalent:
@longCode(
v.Coords[ 0 ]:= 0.0;
v[ 0 ]:= 0.0;
v.x:= 0.0;
v.r:= 0.0;
v.s:= 0.0;
)
These different type of access are only for convenience but point to one and
the same field. Except for the Coord alias everything works just like in @bold( glsl ).
@br@br
Depending on the vectors type some fields may not be availabe.@br
For @link( TVec2 ) there is only @bold( X (R, S)) and @bold( Y (G, T)) defined.@br
For @link( TVec3 ) there is only @bold( X (R, S)), @bold( Y (G, T)) and @bold( Z (B, P)) defined.@br
For @link( TVec4 ) there is @bold( X (R, S)), @bold( Y (G, T)), @bold( Z (B, P)) and @bold( W (A, Q)) defined.@br
@br@br
@italic(3. Additionally math3d supports swizzling in @bold( glsl-style ).) @br@br
This means you can write:
@longCode(
v2:= v1.xxy; // equivalent to vec3( v1.x, v1.x, v1.y )
)
Unlike @bold( glsl ) this is not yet supported:
@longCode(
var
  v1: TVec2;
  v2: TVec3;
begin
  v2:= v1.xxx; //Returns an error because v1 only has two members and cannot return a TVec3
end;
)
This is due to an internal problem of how the math3d unit is written.
In Pascal you can only forward declare classes and procedures but not objects.
So it is not possible for TVec2 to return TVec3 because it's still undefined at that stage.
There is no solution for that for now i fear.
@br@br
For more information on swizzling see this
doc: https://www.opengl.org/wiki/Data_Type_%28GLSL%29#Swizzling
}
type
  //generic TVector < FieldType > = packed object
  TVector = packed record
    private type
      PFieldType = ^FieldType;

    private
      FCoord: array[ 0..NUMFIELD-1 ] of FieldType;

      class function GetCount: Integer; static;
      {@exclude} procedure SetCoord( AIndex: Integer; AValue: FieldType );
      {@exclude} function GetCoord( AIndex: Integer ): FieldType;

    public
      //Operator for comparing two vectors.
      {$INCLUDE p3d.math.vector.operators.inc}
      {@abbr`Function to get access to the first element (@bold`X`) of the vector`.
      The result is a pointer to the data of a vector. It can be used when passing to
      opengl for example. This is equivalent to
      @code`ptr:= @@v.Coord[ 0 ];`}
      function Ptr: PFieldType;
      {@abbr`Compares two vectors and returns if their field values are equal`.
      The result is a boolean and is True if the vectors are equal.}
      function Compare( v: TVector ): Boolean;
      function Greater( v: TVector ): Boolean;
      function Less( v: TVector ): Boolean;
      function GreaterEqual( v: TVector ): Boolean;
      function LessEqual( v: TVector ): Boolean;

      property Coord[ Index: Integer ]: FieldType read GetCoord write SetCoord; default;
      {@abbr`This will generate a string with the vector's separated with comma (and a space)`. It can
      be used for debugging or printing the values of a vector on screen.
      The string is returned in the function's result}
      procedure LoadFromStream( S: TStream );
      procedure SaveToStream( S: TStream );

      {$INCLUDE p3d.math.vector.methods.inc}

    public
      class property Count: Integer read GetCount;


      {$INCLUDE p3d.math.vector.swizzle.inc}
  end;

  {$INCLUDE p3d.math.vector.functions.inc}

{$ENDIF}
{$IFDEF IMPLEMENTATION}

  {$INCLUDE p3d.math.vector.functions.inc}
  {$INCLUDE p3d.math.vector.operators.inc}

{ TVector }

  {$INCLUDE p3d.math.vector.swizzle.inc}

procedure TVector.SetCoord(AIndex: Integer; AValue: FieldType);
begin
  FCoord[ AIndex ]:= AValue;
  //TODO: ONCHANGE EVENT
end;

function TVector.GetCoord(AIndex: Integer): FieldType;
begin
  Result:= FCoord[ AIndex ];
end;

class function TVector.GetCount: Integer;
begin
  Result:= NUMFIELD;
end;

function TVector.Ptr: PFieldType;
begin
  Result:= @FCoord[ 0 ];
end;

procedure TVector.LoadFromStream(S: TStream);
begin
  S.Read( FCoord[ 0 ], SizeOf( FCoord ));
end;

procedure TVector.SaveToStream(S: TStream);
begin
  S.Write( FCoord[ 0 ], SizeOf( FCoord ));
end;

function TVector.Compare(v: TVector): Boolean;
var
  i: Integer;
begin
  Result:= True;
  for i:= 0 to NUMFIELD - 1 do
    if ( FCoord[ i ] <> v.FCoord[ i ]) then
      begin
        Result:= False;
        break;
      end;
end;

function TVector.Greater(v: TVector): Boolean;
var
  i: Integer;
begin
  Result:= True;
  for i:= 0 to NUMFIELD - 1 do
    if ( FCoord[ i ] < v.FCoord[ i ]) then
      begin
        Result:= False;
        break;
      end;
end;

function TVector.Less(v: TVector): Boolean;
var
  i: Integer;
begin
  Result:= True;
  for i:= 0 to NUMFIELD - 1 do
    if ( FCoord[ i ] >= v.FCoord[ i ]) then
      begin
        Result:= False;
        break;
      end;
end;

function TVector.GreaterEqual(v: TVector): Boolean;
var
  i: Integer;
begin
  Result:= True;
  for i:= 0 to NUMFIELD - 1 do
    if ( FCoord[ i ] < v.FCoord[ i ]) then
      begin
        Result:= False;
        break;
      end;
end;

function TVector.LessEqual(v: TVector): Boolean;
var
  i: Integer;
begin
  Result:= True;
  for i:= 0 to NUMFIELD - 1 do
    if ( FCoord[ i ] > v.FCoord[ i ]) then
      begin
        Result:= False;
        break;
      end;
end;

{$INCLUDE p3d.math.vector.methods.inc}

{
{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator+(a, b: TVector)c: TVector;
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
operator+(a: TVector; b: FieldType)c: TVector;
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
operator-(a, b: TVector)c: TVector;
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
operator-(a: TVector; b: FieldType)c: TVector;
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

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator*(a, b: TVector )c: TVector;
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

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator*(a: TVector; s: FieldType)c: TVector;
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
operator*(s: FieldType; b: TVector)c: TVector;
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
operator/(a, b: TVector)c: TVector;
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
operator/(a: TVector; s: FieldType)c: TVector;
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

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
operator div(a, b: TVector)c: TVector;
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
operator div(a: TVector; s: FieldType)c: TVector;
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

operator mod(a, b: TVector)c: TVector;
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


operator mod(a: TVector; s: FieldType)c: TVector;
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

operator-(a: TVector)c: TVector;
begin
  c:= a * -1;
end;

operator=(a, b: TVector)c: Boolean;
begin
  c:= a.Compare( b );
end;

{$INCLUDE p3dmath_vector_functions.inc}
}
{$ENDIF}
