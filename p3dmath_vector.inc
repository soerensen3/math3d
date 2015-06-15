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
TVector = packed object
  private
    {@exclude} procedure SetCoord( AIndex: Integer; AValue: Float );
    {@exclude} function GetCoord( AIndex: Integer ): Float;

  protected
    {@exclude}
    FCoord: array[ 0..NUMFIELD-1 ] of Float;

  public
    {@abbr`Calculate the length of the current vector`.}
    function GetDist: Float;
    {@abbr`Normalizes the current vector`.
    The vector will be returned in the function's result additionally.
    @br@br
    For returning a normalized vector without
    changing the current one use the @link`p3dMath.normalize` function}
    function Normalize: TVector;

    {$IF NUMFIELD>2}
    {@abbr`Calculate the cross product of the current vector and v`.}
    function CrossProduct( v: TVector ): TVector;
    {$ENDIF}
    {@abbr`Calculate the dot product of the current vector and v`.}
    function DotProduct( v: TVector ): Float;
    {@abbr`Determines the biggest component (X, Y, Z, W)`.
    The result is the index of the biggest component which can be used with @bold`Coord`@br
    @code` s:= v.Coord[ v.GetBiggestComp ]; `}
    function GetBiggestComp: Integer;

//    function RotateRad( Axis: TVec3; Angle: Float ): TVector;
//    function RotateDeg( Axis: TVec3; Angle: Float ): TVector;
//      function Transform( Matrix: TMatrix ): TVector;

    {@abbr`Negates the current vector without altering it`.
    The result is only returned without altering the original vector.
    This is exivalent to @code`v2:= -v;``}
    function Invert: TVector;
    {@abbr`Function to get access to the first element (@bold`X`) of the vector`.
    The result is a pointer to the data of a vector. It can be used when passing to
    opengl for example. This is equivalent to
    @code`ptr:= @@v.Coord[ 0 ];`}
    function Ptr: PFloat;
//      function Mirror( Plane: pPlane ): TVector;

    {@abbr`Compares two vectors and returns if their field values are equal`.
    The result is a boolean and is True if the vectors are equal.}
    function Compare( v: TVector ): Boolean;


    property Coord[ Index: Integer ]: Float read GetCoord write SetCoord; default;
    {@abbr`This will generate a string with the vector's separated with comma (and a space)`. It can
    be used for debugging or printing the values of a vector on screen.
    The string is returned in the function's result}
    function ToString( const Digits: Integer = 8 ): String;
    procedure FromString( S: String );

  published
    property X: Float index 0 read FCoord[ 0 ] write SetCoord;
    property R: Float index 0 read FCoord[ 0 ] write SetCoord;
    property S: Float index 0 read FCoord[ 0 ] write SetCoord;
    {$IF NUMFIELD>1}
    property Y: Float index 1 read FCoord[ 1 ] write SetCoord;
    property G: Float index 1 read FCoord[ 1 ] write SetCoord;
    property T: Float index 1 read FCoord[ 1 ] write SetCoord;
    {$ENDIF}

  published
    {$IF NUMFIELD>2}
    //This field will only exist from TVec3 on.
    property Z: Float index 2 read FCoord[ 2 ] write SetCoord;
    //This field will only exist from TVec3 on.
    property B: Float index 2 read FCoord[ 2 ] write SetCoord;
    //This field will only exist from TVec3 on.
    property P: Float index 2 read FCoord[ 2 ] write SetCoord;

    {$ENDIF}
  published
    {$IF NUMFIELD>3}
    //This field will only exist from TVec4 on.
    property W: Float index 3 read FCoord[ 3 ] write SetCoord;
    //This field will only exist from TVec4 on.
    property A: Float index 3 read FCoord[ 3 ] write SetCoord;
    //This field will only exist from TVec4 on.
    property Q: Float index 3 read FCoord[ 3 ] write SetCoord;
    {$ENDIF}
    {$INCLUDE p3dmath_vector_swizzle.inc}
end;

{$UNDEF INTERFACE}
{$ENDIF}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
{$IFDEF CONSTRUCTOR}
function Vector(
  {$IF NUMFIELD = 1}
  x: TYPEX;
  {$ELSEIF NUMFIELD = 2}
    {$IFDEF TYPEY}x{$ELSE}xy{$ENDIF}: TYPEX
    {$IFDEF TYPEY }
      ;y: TYPEY
    {$ENDIF}
  {$ELSEIF NUMFIELD = 3}
    {$IFDEF TYPEY}x
    {$ELSE}
      {$IFDEF TYPEZ}xy
      {$ELSE}xyz
      {$ENDIF}
    {$ENDIF}
    : TYPEX
    {$IFDEF TYPEY}
     {$IFDEF TYPEZ};y{$ELSE};yz{$ENDIF}: TYPEY
    {$ENDIF}
    {$IFDEF TYPEZ}
     ;z: TYPEZ
    {$ENDIF}
  {$ELSEIF NUMFIELD = 4}
    {$IFDEF TYPEY}x
    {$ELSE}
      {$IFDEF TYPEZ}xy
      {$ELSE}
        {$IFDEF TYPEW}xyz
        {$ELSE}xyzw
        {$ENDIF}
      {$ENDIF}
    {$ENDIF}
    : TYPEX

    {$IFDEF TYPEY}
      {$IFDEF TYPEZ};y
      {$ELSE}
        {$IFDEF TYPEW}
          ;yz
        {$ELSE}
          ;yzw
        {$ENDIF}
      {$ENDIF}
    : TYPEY
    {$ENDIF}

    {$IFDEF TYPEZ}
      {$IFDEF TYPEW};z{$ELSE};zw{$ENDIF}: TYPEZ
    {$ENDIF}

    {$IFDEF TYPEW}
      ;w: TYPEW
    {$ENDIF}
  {$ENDIF}
  ): TVector; overload; inline;

  {$IFDEF _IMPLEMENTATION}
  begin
    {$IF NUMFIELD=1}
    Result.x:= x;
    {$ELSEIF NUMFIELD=2}
      {$IFDEF TYPEY}
        Result.x:= x;
      {$ELSE}
        {$IF TYPEX = Float}
          Result.x:= xy;
          Result.y:= xy;
        {$ELSE}
          Result.x:= xy.x;
          Result.y:= xy.y;
        {$ENDIF}
      {$ENDIF}
      {$IFDEF TYPEY }
        Result.y:= y;
      {$ENDIF}
    {$ELSEIF NUMFIELD = 3}
      {$IFDEF TYPEY}
        Result.x:= x;
      {$ELSE}
        {$IFDEF TYPEZ}
          Result.x:= xy.x;
          Result.y:= xy.y;
        {$ELSE}
          {$IF TYPEX = Float}
            Result.x:= xyz;
            Result.y:= xyz;
            Result.z:= xyz;
          {$ELSE}
            Result.x:= xyz.x;
            Result.y:= xyz.y;
            Result.z:= xyz.z;
          {$ENDIF}
        {$ENDIF}
      {$ENDIF}
      {$IFDEF TYPEY}
        {$IFDEF TYPEZ}
          Result.y:= y;
        {$ELSE}
          Result.y:= yz.x;
          Result.z:= yz.y;
        {$ENDIF}
      {$ENDIF}
      {$IFDEF TYPEZ }
        Result.z:= z;
      {$ENDIF}
    {$ELSEIF NUMFIELD = 4}
      {$IFDEF TYPEY}
        Result.x:= x;
      {$ELSE}
        {$IFDEF TYPEZ}
          Result.x:= xy.x;
          Result.y:= xy.y;
        {$ELSE}
          {$IFDEF TYPEW}
            Result.x:= xyz.x;
            Result.y:= xyz.y;
            Result.z:= xyz.z;
          {$ELSE}
            {$IF TYPEX = Float}
              Result.x:= xyzw;
              Result.y:= xyzw;
              Result.z:= xyzw;
              Result.w:= 1.0;
            {$ELSE}
              Result.x:= xyzw.x;
              Result.y:= xyzw.y;
              Result.z:= xyzw.z;
              Result.w:= xyzw.w;
            {$ENDIF}
          {$ENDIF}
        {$ENDIF}
      {$ENDIF}

      {$IFDEF TYPEY}
        {$IFDEF TYPEZ};
          Result.y:= y;
        {$ELSE}
          {$IFDEF TYPEW}
            Result.y:= yz.x;
            Result.z:= yz.y;
          {$ELSE}
            Result.y:= yzw.x;
            Result.z:= yzw.y;
            Result.w:= yzw.z;
          {$ENDIF}
        {$ENDIF}
      {$ENDIF}

      {$IFDEF TYPEZ}
        {$IFDEF TYPEW};
          Result.z:= z;
        {$ELSE};
          Result.z:= zw.x;
          Result.w:= zw.y;
        {$ENDIF}
      {$ENDIF}

      {$IFDEF TYPEW}
        Result.w:= w;
      {$ENDIF}
    {$ENDIF}
  end;
  {$ENDIF}

  {$UNDEF TYPEX}
  {$UNDEF TYPEY}
  {$UNDEF TYPEZ}
  {$UNDEF TYPEW}
  {$WARNINGS ON}
{$ENDIF}

{$IFDEF HELPERFUNCT}

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

{$UNDEF HELPERFUNCT}
{$ENDIF}


{$IFDEF IMPLEMENTATION}

{ TVector }

procedure TVector.SetCoord(AIndex: Integer; AValue: Float);
begin
  FCoord[ AIndex ]:= AValue;
  //TODO: ONCHANGE EVENT
end;

function TVector.GetCoord( AIndex: Integer ): Float;
begin
  Result:= FCoord[ AIndex ];
end;

function TVector.GetDist: Float;
begin
  Result:= sqrt( sqr( x )
         {$IF NUMFIELD>1}
         + sqr( y )
         {$ENDIF}
         {$IF NUMFIELD>2}
         + sqr( z )
         {$ENDIF}
         {$IF NUMFIELD>3}
         + sqr( w )
         {$ENDIF}
         );
end;

function TVector.Normalize: TVector;
var
  len: Float;
begin
  len:= GetDist;
  if ( len > 0 ) then
    Self /= len;
  Result:= Self;
end;

{$IF NUMFIELD>2}
{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
function TVector.CrossProduct(v: TVector): TVector;
begin
  Result.x:= y * v.z - z * v.y;
  Result.y:= z * v.x - x * v.z;
  Result.z:= x * v.y - y * v.x;
  {$IF NUMFIELD=4}
  Result.w:= 1;
  {$ENDIF}
end;
{$ENDIF}
{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
function TVector.DotProduct(v: TVector): Float;
begin
  Result:= x * v.x
          {$IF NUMFIELD>1}
           + y * v.y
          {$ENDIF}
          {$IF NUMFIELD>2}
           + z * v.z
          {$ENDIF}
          ;
end;
{$WARNINGS ON}

function TVector.GetBiggestComp: Integer;
var
  i: Integer;
begin
  Result:= 0;
  for i:= 0 to NUMFIELD - 1 do
    if ( Abs( FCoord[ i ]) > Abs( FCoord[ Result ])) then
      Result:= i;
end;
(*
{$IF NUMFIELD = 3}
function TVector.RotateRad(Axis: TVec3; Angle: Float): TVector;
begin
  Result:= VecTransform( Self, Mat4Rot( Axis, Angle ));
end;

function TVector.RotateDeg(Axis: TVec3; Angle: Float): TVector;
begin
  Result:= VecTransform( Self, Mat4Rot( Axis, deg2rad * Angle ));
end;
{$ENDIF}
*)

function TVector.Invert: TVector;
begin
  x:= -x;
  {$IF NUMFIELD > 1}
  y:= -y;
  {$ENDIF}
  {$IF NUMFIELD > 2}
  z:= -z;
  {$ENDIF}
  {$IF NUMFIELD > 3}
  w:= -w;
  {$ENDIF}
  Result:= Self;
end;

function TVector.Ptr: PFloat;
begin
  Result:= @FCoord[ 0 ];
end;

{$INCLUDE p3dmath_vector_swizzle.inc}


function TVector.ToString( const Digits: Integer = 8 ): String;
var
  str: String;
begin
  {$IF NUMFIELD = 2}
  str:= StringReplace( '%.#f,%.#f', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ X, Y ]);
  {$ENDIF}
  {$IF NUMFIELD = 3}
  str:= StringReplace( '%.#f, %.#f, %.#f', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ X, Y, Z ]);
  {$ENDIF}
  {$IF NUMFIELD = 4}
  str:= StringReplace( '%.#f, %.#f, %.#f, %.#f', '#', IntToStr( Digits ), [ rfReplaceAll ]);
  Result:= Format( str, [ X, Y, Z, W ]);
  {$ENDIF}
end;

procedure TVector.FromString( S: String );
  function GetWordCount: Integer;
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

  function GetWord( n: Integer ): String;
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
begin
  n:= GetWordCount();

  if ( n <> exp_wc ) then
    raise Exception.Create( Format( 'Error while converting string ''%s'' to TVec%d. Wrong number of values given: %d.', [ S, exp_wc, n ]));
  for i:= 1 to n do
    Coord[ i - 1 ]:= StrToFloat( GetWord( i ));
end;

function TVector.Compare(v: TVector): Boolean;
begin
  Result:= ( v.x = x )
       {$IF NUMFIELD > 2}
       and ( v.y = y )
       {$ENDIF}
       {$IF NUMFIELD > 2}
       and ( v.z = z )
       {$ENDIF}
       {$IF NUMFIELD > 3}
       and ( v.w = w )
       {$ENDIF}
       ;
end;

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
operator+(a: TVector; b: Float)c: TVector;
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
operator-(a: TVector; b: Float)c: TVector;
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

operator*(a, b: TVector) c : Float;
begin
  Result:= a.DotProduct( b );
end;

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
operator*(a: TVector; s: Float)c: TVector;
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
operator*(s: Float; b: TVector)c: TVector;
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
operator/(a: TVector; s: Float)c: TVector;
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

operator-(a: TVector)c: TVector;
begin
  c:= a * -1;
end;

operator=(a, b: TVector)c: Boolean;
begin
  c:= a.Compare( b );
end;

{$INCLUDE p3dmath_vector_functions.inc}

{$UNDEF IMPLEMENTATION}
{$ENDIF}
