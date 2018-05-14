{ include.inc }

{ TMat2, TDMat2 }
{$DEFINE FLOATTYPE}
{$DEFINE NUMFIELD:=2}
{$DEFINE TMATRIX:= TMat2}
{$DEFINE TVECTOR:= TVec2}
{$DEFINE FIELDTYPE:= Float}
{$INCLUDE p3d.math.matrix.type.inc}
{$DEFINE TMATRIX:= TDMat2}
{$DEFINE TVECTOR:= TDVec2}
{$DEFINE FIELDTYPE:= Double}
{$INCLUDE p3d.math.matrix.type.inc}
{$UNDEF FLOATTYPE}
{$DEFINE TMATRIX:= TIMat2}
{$DEFINE TVECTOR:= TIVec2}
{$DEFINE FIELDTYPE:= Int}
{$INCLUDE p3d.math.matrix.type.inc}

{ TMat3, TDMat3 }
{$DEFINE FLOATTYPE}
{$DEFINE NUMFIELD:=3}
{$DEFINE TMATRIX:= TMat3}
{$DEFINE TVECTOR:= TVec3}
{$DEFINE FIELDTYPE:= Float}
{$INCLUDE p3d.math.matrix.type.inc}
{$DEFINE TMATRIX:= TDMat3}
{$DEFINE TVECTOR:= TDVec3}
{$DEFINE FIELDTYPE:= Double}
{$INCLUDE p3d.math.matrix.type.inc}
{$UNDEF FLOATTYPE}
{$DEFINE TMATRIX:= TIMat3}
{$DEFINE TVECTOR:= TIVec3}
{$DEFINE FIELDTYPE:= Int}
{$INCLUDE p3d.math.matrix.type.inc}

{ TMat4, TDMat4 }
{$DEFINE FLOATTYPE}
{$DEFINE NUMFIELD:=4}
{$DEFINE TMATRIX:= TMat4}
{$DEFINE TVECTOR:= TVec4}
{$DEFINE FIELDTYPE:= Float}
{$INCLUDE p3d.math.matrix.type.inc}
{$DEFINE TMATRIX:= TDMat4}
{$DEFINE TVECTOR:= TDVec4}
{$DEFINE FIELDTYPE:= Double}
{$INCLUDE p3d.math.matrix.type.inc}
{$UNDEF FLOATTYPE}
{$DEFINE TMATRIX:= TIMat4}
{$DEFINE TVECTOR:= TIVec4}
{$DEFINE FIELDTYPE:= Int}
{$INCLUDE p3d.math.matrix.type.inc}

{$UNDEF TMATRIX}
{$UNDEF TVECTOR}
{$UNDEF NUMFIELD}

{$INCLUDE p3d.math.matrix.constructors.float.inc}
{$INCLUDE p3d.math.matrix.constructors.double.inc}
{$INCLUDE p3d.math.matrix.constructors.int.inc}
{$DEFINE FIELDTYPE:= Float}
{$INCLUDE p3d.math.matrix.functions.inc}
{$DEFINE FIELDTYPE:= Double}
{$INCLUDE p3d.math.matrix.functions.inc}

