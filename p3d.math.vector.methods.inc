{$IFDEF INTERFACE}
  public
    {@abbr`Determines the biggest component (X, Y, Z, W)`.
    The result is the index of the biggest component which can be used with @bold`Coord`@br
    @code` s:= v.Coord[ v.GetBiggestComp ]; `}
    function GetBiggestComp: Integer;

    {@abbr`Negates the current vector without altering it`.
    The result is only returned without altering the original vector.
    This is exivalent to @code`v2:= -v;``}
    function Invert: TVector;

    function ToString{$IFDEF FLOATTYPE}( const Digits: Integer = -1 ){$ENDIF}: String;
    function FromString( S: String ): TVector;

  {$IFDEF FloatType}

    {@abbr`Calculate the length of the current vector`.}
    function length: FieldType;
    {@abbr`Calculate the squared length of the current vector`. This is faster than GetDist as it does not calculate the square root. }
    function length_sq: FieldType;
    {@abbr`Calculate the manhattan length of the current vector`. It is calculated by summing all the fields of the vector. }
    function length_manh: FieldType;
    {@abbr`Normalizes the current vector`.
    The vector will be returned in the function's result additionally.
    @br@br
    For returning a normalized vector without
    changing the current one use the @link`p3dMath.normalize` function}
    function normalize: TVector;

    {$IF NUMFIELD>2}
    {@abbr`Calculate the cross product of the current vector and v`.}
    function cross( v: TVector ): TVector;
    {$ENDIF}
    {@abbr`Calculate the dot product of the current vector and v`.}
    function dot( v: TVector ): FieldType;
    {$IF NUMFIELD=4}
    function fade( Alpha: FieldType ): TVector;
    {$ENDIF}

  {$ENDIF}
  {$IFDEF QUATTYPE}
    function conj: TVector;
    function GetAxisAngle: TVec4; //with XYZ as Axis and A (=W) as angle
  {$ENDIF}

  {$IF NUMFIELD>1}
    property X: FieldType index 0 read FCoord[ 0 ] write SetCoord;
    property R: FieldType index 0 read FCoord[ 0 ] write SetCoord;
    property S: FieldType index 0 read FCoord[ 0 ] write SetCoord;
    property Y: FieldType index 1 read FCoord[ 1 ] write SetCoord;
    property G: FieldType index 1 read FCoord[ 1 ] write SetCoord;
    property T: FieldType index 1 read FCoord[ 1 ] write SetCoord;
  {$ENDIF}


  {$IF NUMFIELD>2}
    //This field will only exist from TVec3 on.
    property Z: FieldType index 2 read FCoord[ 2 ] write SetCoord;
    //This field will only exist from TVec3 on.
    property B: FieldType index 2 read FCoord[ 2 ] write SetCoord;
    //This field will only exist from TVec3 on.
    property P: FieldType index 2 read FCoord[ 2 ] write SetCoord;
  {$ENDIF}

  {$IF NUMFIELD>3}
    //This field will only exist from TVec4 on.
    property W: FieldType index 3 read FCoord[ 3 ] write SetCoord;
    //This field will only exist from TVec4 on.
    property A: FieldType index 3 read FCoord[ 3 ] write SetCoord;
    //This field will only exist from TVec4 on.
    property Q: FieldType index 3 read FCoord[ 3 ] write SetCoord;
  {$ENDIF}
  {$UNDEF ToStrFloat}
{$ENDIF}

{$IFDEF IMPLEMENTATION}

{$IFDEF FLOATTYPE}
  {$DEFINE ToStrFloat}
{$ENDIF}
{$IFDEF QUATTYPE}
  {$DEFINE ToStrFloat}
{$ENDIF}


function TVector.GetBiggestComp: Integer;
var
  i: Integer;
begin
  Result:= 0;
  for i:= 0 to NUMFIELD - 1 do
    if ( Abs( FCoord[ i ]) > Abs( FCoord[ Result ])) then
      Result:= i;
end;

function TVector.Invert: TVector;
var
  i: Integer;
begin
  for i:= 0 to NUMFIELD - 1 do
    FCoord[ i ]:= - FCoord[ i ];
  Result:= Self;
end;

function TVector.ToString {$IFDEF FLOATTYPE}( const Digits: Integer = -1 ){$ENDIF}: String;
var
  str: String;
  d: String;
begin
  {$IFDEF FLOATTYPE}
  if ( Digits = -1 ) then
    d:= 'g'
  else
    d:= '.' + IntToStr( Digits ) + 'f';
  {$ELSE}
  {$IFDEF INTTYPE}
  d:= 'd';
  {$ENDIF}
  {$ENDIF}

  {$IF NUMFIELD = 2}
  str:= StringReplace( '%#, %#', '#', d, [ rfReplaceAll ]);
  Result:= Format( str, [ X, Y ]);
  {$ENDIF}
  {$IF NUMFIELD = 3}
  str:= StringReplace( '%#, %#, %#', '#', d, [ rfReplaceAll ]);
  Result:= Format( str, [ X, Y, Z ]);
  {$ENDIF}
  {$IF NUMFIELD = 4}
  str:= StringReplace( '%#, %#, %#, %#', '#', d, [ rfReplaceAll ]);
  Result:= Format( str, [ X, Y, Z, W ]);
  {$ENDIF}
end;

function TVector.FromString(S: String): TVector;
  function GetWordCount: Integer; inline;
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

  function GetWord( n: Integer ): String; inline;
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
    {$IFDEF FLOATTYPE}
    Coord[ i - 1 ]:= StrToFloat( GetWord( i ));
    {$ELSE}
    {$IFDEF INTTYPE}
    Coord[ i - 1 ]:= StrToInt( GetWord( i ));
    {$ENDIF}
    {$ENDIF}
  Result:= Self;
end;

{$IFDEF FloatType}

function TVector.length: FieldType;
var
  sq: FieldType;
  i: Integer;
begin
  sq:= 0;
  for i:= 0 to NumField - 1 do
    sq+= sqr( FCoord[ i ]);
  if ( sq > epsilon ) then
    Result:= sqrt( sq )
  else
    Result:= 0;
end;

function TVector.length_sq: FieldType;
var
  sq: FieldType;
  i: Integer;
begin
  sq:= 0;
  for i:= 0 to NumField - 1 do
    sq+= sqr( FCoord[ i ]);
  Result:= sq;
end;

function TVector.length_manh: FieldType;
var
  i: Integer;
begin
  Result:= 0;
  for i:= low( FCoord ) to high( FCoord ) do
    Result += FCoord[ i ];
end;

function TVector.normalize: TVector;
var
  len: FieldType;
begin
  len:= length;
  if ( len > 0 ) then
    Self /= len;
  Result:= Self;
end;

{$IF NUMFIELD=4}
function TVector.fade( Alpha: FieldType ): TVector;
begin
  Result:= Self;
  Result.a:= a * Alpha;
end;
{$ENDIF}

{$IF NUMFIELD>2}
{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
function TVector.cross(v: TVector): TVector;
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
function TVector.dot(v: TVector): FieldType;
begin
  Result:=   x * v.x
          {$IF NUMFIELD>1}
           + y * v.y
          {$ENDIF}
          {$IF NUMFIELD>2}
           + z * v.z
          {$ENDIF}
          {$IF NUMFIELD>3}
           + w * v.w
          {$ENDIF}
          ;
end;
{$WARNINGS ON}

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

{$ENDIF}
{$IFDEF QUATTYPE}
function TQuat.conj: TVector;
begin
  Result.w:=  w;
  Result.x:= -x;
  Result.y:= -y;
  Result.z:= -z;
end;

function TQuat.GetAxisAngle: TVec4;
var
  q1: TQuat;
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

{$ENDIF}


{$ENDIF}
