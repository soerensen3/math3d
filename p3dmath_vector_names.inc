{ p3dmath_vector_names.inc }
{$IF FIELDTYPE = Float}
  {$IF DEFINED( NUMFIELD )}
    {$IF NUMFIELD = 2}
      {$DEFINE TVECTOR:= TVec2}
      {$DEFINE VECTOR:= vec2}
    {$ENDIF}
    {$IF NUMFIELD = 3}
      {$DEFINE TVECTOR:= TVec3}
      {$DEFINE VECTOR:= vec3}
    {$ENDIF}
    {$IF NUMFIELD = 4}
      {$DEFINE TVECTOR:= TVec4}
      {$DEFINE VECTOR:= vec4}
    {$ENDIF}
  {$ENDIF}
  {$DEFINE TV2:= TVec2}
  {$DEFINE v2:= vec2}
  {$DEFINE TV3:= TVec3}
  {$DEFINE v3:= vec3}
  {$DEFINE TV4:= TVec4}
  {$DEFINE v4:= vec4}
{$ENDIF}
{$IF FIELDTYPE = Double}
  {$IF DEFINED( NUMFIELD )}
    {$IF NUMFIELD = 2}
      {$DEFINE TVECTOR:= TDVec2}
      {$DEFINE VECTOR:= dvec2}
    {$ENDIF}
    {$IF NUMFIELD = 3}
      {$DEFINE TVECTOR:= TDVec3}
      {$DEFINE VECTOR:= dvec3}
    {$ENDIF}
    {$IF NUMFIELD = 4}
      {$DEFINE TVECTOR:= TDVec4}
      {$DEFINE VECTOR:= dvec4}
    {$ENDIF}
  {$ENDIF}
  {$DEFINE TV2:= TDVec2}
  {$DEFINE v2:= dvec2}
  {$DEFINE TV3:= TDVec3}
  {$DEFINE v3:= dvec3}
  {$DEFINE TV4:= TDVec4}
  {$DEFINE v4:= dvec4}
{$ENDIF}
{$IF FIELDTYPE = Int}
  {$IF DEFINED( NUMFIELD )}
    {$IF NUMFIELD = 2}
      {$DEFINE TVECTOR:= TIVec2}
      {$DEFINE VECTOR:= ivec2}
    {$ENDIF}
    {$IF NUMFIELD = 3}
      {$DEFINE TVECTOR:= TIVec3}
      {$DEFINE VECTOR:= ivec3}
    {$ENDIF}
    {$IF NUMFIELD = 4}
      {$DEFINE TVECTOR:= TIVec4}
      {$DEFINE VECTOR:= ivec4}
    {$ENDIF}
  {$ENDIF}
  {$DEFINE TV2:= TIVec2}
  {$DEFINE v2:= ivec2}
  {$DEFINE TV3:= TIVec3}
  {$DEFINE v3:= ivec3}
  {$DEFINE TV4:= TIVec4}
  {$DEFINE v4:= ivec4}
{$ENDIF}

