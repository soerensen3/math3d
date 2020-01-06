{ p3dmath_matrix_names.inc }

{$IF FIELDTYPE=Float}
  {$DEFINE TM2:= TMat2}
  {$DEFINE m2:= mat2}
  {$DEFINE TM3:= TMat3}
  {$DEFINE m3:= mat3}
  {$DEFINE TM4:= TMat4}
  {$DEFINE m4:= mat4}
{$ENDIF}
{$IF FIELDTYPE=Double}
  {$DEFINE TM2:= TDMat2}
  {$DEFINE m2:= dmat2}
  {$DEFINE TM3:= TDMat3}
  {$DEFINE m3:= dmat3}
  {$DEFINE TM4:= TDMat4}
  {$DEFINE m4:= dmat4}
{$ENDIF}
{$IF FIELDTYPE=Int}
  {$DEFINE TM2:= TIMat2}
  {$DEFINE m2:= imat2}
  {$DEFINE TM3:= TIMat3}
  {$DEFINE m3:= imat3}
  {$DEFINE TM4:= TIMat4}
  {$DEFINE m4:= imat4}
{$ENDIF}
