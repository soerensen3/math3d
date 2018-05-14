{ p3dmath_vector_types.inc }

{$DEFINE FLOATTYPE}
{$DEFINE TVector:=TVec2}
  {$DEFINE NUMFIELD:= 2} {$DEFINE FIELDTYPE:= Float}
  {$INCLUDE p3d.math.vector.type.inc}
{$DEFINE TVector:=TDVec2} {$DEFINE FIELDTYPE:= Double}
  {$INCLUDE p3d.math.vector.type.inc}

{$DEFINE TVector:=TVec3}
  {$DEFINE NUMFIELD:= 3} {$DEFINE FIELDTYPE:= Float}
  {$INCLUDE p3d.math.vector.type.inc}
{$DEFINE TVector:=TDVec3} {$DEFINE FIELDTYPE:= Double}
  {$INCLUDE p3d.math.vector.type.inc}

{$DEFINE TVector:=TVec4}
  {$DEFINE NUMFIELD:= 4} {$DEFINE FIELDTYPE:= Float}
  {$INCLUDE p3d.math.vector.type.inc}
{$DEFINE TVector:=TDVec4} {$DEFINE FIELDTYPE:= Double}
  {$INCLUDE p3d.math.vector.type.inc}

{$DEFINE QUATTYPE}
{$DEFINE TVector:=TQuat}
  {$DEFINE NUMFIELD:= 4} {$DEFINE FIELDTYPE:= Float}
  {$INCLUDE p3d.math.vector.type.inc}

{$UNDEF FLOATTYPE}
{$UNDEF QUATTYPE}
{$DEFINE INTTYPE}

{$DEFINE TVector:=TIVec2}
  {$DEFINE NUMFIELD:= 2} {$DEFINE FIELDTYPE:= Int}
  {$INCLUDE p3d.math.vector.type.inc}
{$DEFINE TVector:=TIVec3}
  {$DEFINE NUMFIELD:= 3} {$DEFINE FIELDTYPE:= Int}
  {$INCLUDE p3d.math.vector.type.inc}
{$DEFINE TVector:=TIVec4}
  {$DEFINE NUMFIELD:= 4} {$DEFINE FIELDTYPE:= Int}
  {$INCLUDE p3d.math.vector.type.inc}

{$UNDEF INTTYPE}
{$UNDEF TVector}

{$INCLUDE p3d.math.vector.constructors.float.inc}
{$INCLUDE p3d.math.vector.constructors.double.inc}
{$INCLUDE p3d.math.vector.constructors.int.inc}

