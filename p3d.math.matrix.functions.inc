{ p3dmath_matrix_functions.inc }

{$INCLUDE p3dmath_matrix_names.inc}
{$INCLUDE p3dmath_vector_names.inc}

function mat3rotate(Axis: TV3; Angle: FieldType): TM3;
{$IFDEF IMPLEMENTATION}
var
   co, si, ico: FieldType;
   nsi: TV3;
begin
    Axis.Normalize;
    // now convert this to a 3x3 matrix
    co:= cos( Angle );
    si:= sin( Angle );

    ico:= ( 1.0 - co );
    nsi[ 0 ]:= Axis[ 0 ] * si;
    nsi[ 1 ]:= Axis[ 1 ] * si;
    nsi[ 2 ]:= Axis[ 2 ] * si;

    Result._00:= (( Axis[ 0 ] * Axis[ 0 ]) * ico ) + co;
    Result._01:= (( Axis[ 0 ] * Axis[ 1 ]) * ico ) + nsi[ 2 ];
    Result._02:= (( Axis[ 0 ] * Axis[ 2 ]) * ico ) - nsi[ 1 ];
    Result._10:= (( Axis[ 0 ] * Axis[ 1 ]) * ico ) - nsi[ 2 ];
    Result._11:= (( Axis[ 1 ] * Axis[ 1 ]) * ico ) + co;
    Result._12:= (( Axis[ 1 ] * Axis[ 2 ]) * ico ) + nsi[ 0 ];
    Result._20:= (( Axis[ 0 ] * Axis[ 2 ]) * ico ) + nsi[ 1 ];
    Result._21:= (( Axis[ 1 ] * Axis[ 2 ]) * ico ) - nsi[ 0 ];
    Result._22:= (( Axis[ 2 ] * Axis[ 2 ]) * ico ) + co;
end;
{$ENDIF}

{>>$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
function mat4rotate(Axis: TV3; Angle: FieldType ): TM4;
{$IFDEF IMPLEMENTATION}
begin
   Axis.Normalize;
   Result:= m4( mat3rotate( Axis, Angle ));
end;
{$ENDIF}
{$WARNINGS ON}

function mat2determinant( M: TM2 ): FieldType;
{$IFDEF IMPLEMENTATION}
begin
  Result:=
    M._00 * M._11 -
    M._01 * M._10;
end;
{$ENDIF}

function mat3determinant( M: TM3 ): FieldType;
{$IFDEF IMPLEMENTATION}
begin
  Result:=
    M._10 * ( M._02 * M._21 - M._22 * M._01 ) +
    M._11 * ( M._00 * M._22 - M._20 * M._02 ) +
    M._12 * ( M._01 * M._20 - M._21 * M._00 );
end;
{$ENDIF}

function mat4determinant(Mat: TM4): FieldType;
{$IFDEF IMPLEMENTATION}
  function MatrixDet( const a1, a2, a3, b1, b2, b3, c1, c2, c3: FieldType ): FieldType;
  begin
    Result:= a1 * ( b2 * c3 - b3 * c2 )
           - b1 * ( a2 * c3 - a3 * c2 )
           + c1 * ( a2 * b3 - a3 * b2 );
  end;

begin
  Result:= Mat._00 * MatrixDet( Mat.m[ 5 ], Mat.m[ 9 ], Mat.m[ 13 ],
                                Mat.m[ 6 ], Mat.m[ 10 ], Mat.m[ 14 ],
                                Mat.m[ 7 ], Mat.m[ 11 ], Mat.m[ 15 ])

         - Mat._01 * MatrixDet( Mat.m[ 4 ], Mat.m[ 8 ], Mat.m[ 12 ],
                                Mat.m[ 6 ], Mat.m[ 10 ], Mat.m[ 14 ],
                                Mat.m[ 7 ], Mat.m[ 11 ], Mat.m[ 15 ])

         + Mat._02 * MatrixDet( Mat.m[ 4 ], Mat.m[ 8 ], Mat.m[ 12 ],
                                Mat.m[ 5 ], Mat.m[ 9 ], Mat.m[ 13 ],
                                Mat.m[ 7 ], Mat.m[ 11 ], Mat.m[ 15 ])

         - Mat._03 * MatrixDet( Mat.m[ 4 ], Mat.m[ 8 ], Mat.m[ 12 ],
                                Mat.m[ 5 ], Mat.m[ 9 ], Mat.m[ 13 ],
                                Mat.m[ 6 ], Mat.m[ 10 ], Mat.m[ 14 ]);
end;
{$ENDIF}


function mat3normalize( M: TM3 ): TM3;
{$IFDEF IMPLEMENTATION}
begin
  Result:= m3( M[ 0 ].Normalize, M[ 1 ].Normalize, M[ 2 ].Normalize );
end;
{$ENDIF}

function mat4normalize( Mat: TM4 ): TM4;
{$IFDEF IMPLEMENTATION}
var
  d: FieldType;
  i: Integer;
begin
  d:= mat4determinant( Mat );
  if ( d > 0 ) then
  for i:= 0 to high( Mat.m ) do
    Result.m[ i ]:= Mat.m[ i ]/d;
end;
{$ENDIF}

function mat2adjoint( Mat: TM2 ): TM2;
{$IFDEF IMPLEMENTATION}
var
  m_out: TM2;
begin
  m_out._00:=  Mat._11;
  m_out._01:= -Mat._01;

  m_out._10:= -Mat._10;
  m_out._11:=  Mat._00;

  Result:= m_out;
end;
{$ENDIF}

function mat2inverse( Mat: TM2; out MatInv: TM2 ): Boolean;
{$IFDEF IMPLEMENTATION}
var
  matadj, MatOut: TM2;
  det: FieldType;
  i: Integer;
begin
  { calc adjoint }
  matadj:= mat2adjoint( Mat );

  { then determinant old matrix! }
  det:= mat2determinant( Mat );

  Result:= ( det <> 0 );

  if ( Result ) then //if (LIKELY(det != 0.0f))
    begin
      det:= 1 / det;
      for i:= 0 to 1 do
        MatOut[ i ]:= matadj[ i ] * det;
      MatInv:= MatOut;
    end
  else
    MatInv:= Mat;
end;
{$ENDIF}

function mat3adjoint( Mat: TM3 ): TM3;
{$IFDEF IMPLEMENTATION}
var
  m_out: TM3;
begin
  m_out._00:=  Mat._11 * Mat._22 - Mat._12 * Mat._21;
  m_out._01:= -Mat._01 * Mat._22 + Mat._02 * Mat._21;
  m_out._02:=  Mat._01 * Mat._12 - Mat._02 * Mat._11;

  m_out._10:= -Mat._10 * Mat._22 + Mat._12 * Mat._20;
  m_out._11:=  Mat._00 * Mat._22 - Mat._02 * Mat._20;
  m_out._12:= -Mat._00 * Mat._12 + Mat._02 * Mat._10;

  m_out._20:=  Mat._10 * Mat._21 - Mat._11 * Mat._20;
  m_out._21:= -Mat._00 * Mat._21 + Mat._01 * Mat._20;
  m_out._22:=  Mat._00 * Mat._11 - Mat._01 * Mat._10;
  Result:= m_out;
end;
{$ENDIF}

function mat3inverse( Mat: TM3; out MatInv: TM3 ): Boolean;
{$IFDEF IMPLEMENTATION}
var
  matadj, MatOut: TM3;
  det: FieldType;
  i: Integer;
begin
  { calc adjoint }
  matadj:= mat3adjoint( Mat );

  { then determinant old matrix! }
  det:= mat3determinant( Mat );

  Result:= ( det <> 0 );

  if ( Result ) then //if (LIKELY(det != 0.0f))
    begin
      det:= 1 / det;
      for i:= 0 to 2 do
        MatOut[ i ]:= matadj[ i ] * det;
      MatInv:= MatOut;
    end
  else
    MatInv:= Mat;
end;
{$ENDIF}


function mat4inverse( Mat: TM4; out MatInv: TM4 ): Boolean;
{$IFDEF IMPLEMENTATION}
  function MatrixDet( const a1, a2, a3, b1, b2, b3, c1, c2, c3: FieldType ): FieldType;
  begin
    Result:= a1 * ( b2 * c3 - b3 * c2 )
           - b1 * ( a2 * c3 - a3 * c2 )
           + c1 * ( a2 * b3 - a3 * b2 );
  end;

var
  det, a1, a2, a3, a4, b1, b2, b3, b4,
  c1, c2, c3, c4, d1, d2, d3, d4: FieldType;
begin
  det:= mat4determinant( Mat );
  if ( Abs( det ) < epsilon ) then
    Result:= False
  else
    begin
      Result:= True;
      a1:= Mat._00; b1:= Mat._01; c1:= Mat._02; d1:= Mat._03;
      a2:= Mat._10; b2:= Mat._11; c2:= Mat._12; d2:= Mat._13;
      a3:= Mat._20; b3:= Mat._21; c3:= Mat._22; d3:= Mat._23;
      a4:= Mat._30; b4:= Mat._31; c4:= Mat._32; d4:= Mat._33;
      MatInv._00:= MatrixDet(b2, b3, b4, c2, c3, c4, d2, d3, d4);
      MatInv._10:=-MatrixDet(a2, a3, a4, c2, c3, c4, d2, d3, d4);
      MatInv._20:= MatrixDet(a2, a3, a4, b2, b3, b4, d2, d3, d4);
      MatInv._30:=-MatrixDet(a2, a3, a4, b2, b3, b4, c2, c3, c4);
      MatInv._01:=-MatrixDet(b1, b3, b4, c1, c3, c4, d1, d3, d4);
      MatInv._11:= MatrixDet(a1, a3, a4, c1, c3, c4, d1, d3, d4);
      MatInv._21:=-MatrixDet(a1, a3, a4, b1, b3, b4, d1, d3, d4);
      MatInv._31:= MatrixDet(a1, a3, a4, b1, b3, b4, c1, c3, c4);
      MatInv._02:= MatrixDet(b1, b2, b4, c1, c2, c4, d1, d2, d4);
      MatInv._12:=-MatrixDet(a1, a2, a4, c1, c2, c4, d1, d2, d4);
      MatInv._22:= MatrixDet(a1, a2, a4, b1, b2, b4, d1, d2, d4);
      MatInv._32:=-MatrixDet(a1, a2, a4, b1, b2, b4, c1, c2, c4);
      MatInv._03:=-MatrixDet(b1, b2, b3, c1, c2, c3, d1, d2, d3);
      MatInv._13:= MatrixDet(a1, a2, a3, c1, c2, c3, d1, d2, d3);
      MatInv._23:=-MatrixDet(a1, a2, a3, b1, b2, b3, d1, d2, d3);
      MatInv._33:= MatrixDet(a1, a2, a3, b1, b2, b3, c1, c2, c3);

      MatInv:= MatInv * ( 1/det );
    end;
end;
{$ENDIF}


//based on mat3_to_rot_size in math_matrix.c from the blender source

procedure mat3decompose( mat: TM3; out rot: TM3; out scale: TV3 );
{$IFDEF IMPLEMENTATION}
  function mat3_is_negative( m: TM3 ): Boolean;
  begin
    Result:= ( dot( cross( m[ 0 ], m[ 1 ]), m[ 2 ]) < 0 );
  end;

var
  mat_n: TM3;
begin
  (*
  { rotation & scale are linked, we need to create the mat's
   * for these together since they are related. }

  { so scale doesn't interfere with rotation [#24291] }
  { note: this is a workaround for negative matrix not working for rotation conversion, FIXME }

  mat_n:= mat3normalize( mat );
  if ( mat3_is_negative( mat )) then
    mat_n:= mat3( -mat[ 0 ], -mat[ 1 ], -mat[ 2 ]);

  { rotation }
  { keep rot as a 3x3 matrix, the caller can convert into a quat or euler }
  rot:= mat_n;

  { scale }
  { note: mat4_to_size(ob->size, mat) fails for negative scale }
  mat3inverse( mat_n, mat_n );
  mat_sz:= mat_n * mat;

  scale:= vec3( mat_sz[ 0 ][ 0 ], mat_sz[ 1 ][ 1 ], mat_sz[ 2 ][ 2 ]);*)

  (*
  /* keep rot as a 3x3 matrix, the caller can convert into a quat or euler */
  	size[0] = normalize_v3_v3(rot[0], mat3[0]);
  	size[1] = normalize_v3_v3(rot[1], mat3[1]);
  	size[2] = normalize_v3_v3(rot[2], mat3[2]);
  	if (UNLIKELY(is_negative_m3(rot))) {
  		negate_m3(rot);
  		negate_v3(size);
  }
  *)
  scale:= max( v3( mat.Row[ 0 ].length, mat.Row[ 1 ].length, mat.Row[ 2 ].length ), epsilon );
  mat_n:= m3( mat.Row[ 0 ] / scale[ 0 ], mat.Row[ 1 ] / scale[ 1 ], mat.Row[ 2 ] / scale[ 2 ]);
  if ( mat3_is_negative( mat_n )) then
    rot:= m3( -mat_n[ 0 ], -mat_n[ 1 ], -mat_n[ 2 ])
  else
    rot:= mat_n;
end;
{$ENDIF}

procedure mat4decompose( mat: TM4; out loc: TV3; out rot: TM3; out scale: TV3 );
{$IFDEF IMPLEMENTATION}
begin
  mat3decompose( m3( mat ), rot, scale );
  loc:= mat.Row[ 3 ].xyz;
end;
{$ENDIF}

function mat2translate( Vec: TV2 ): TM2;
{$IFDEF IMPLEMENTATION}
begin
  Result.Identity;
  Result._10:= Vec.x;
  Result._11:= Vec.y;
end;
{$ENDIF}

function mat3translate( Vec: TV3 ): TM3;
{$IFDEF IMPLEMENTATION}
begin
  Result.Identity;
  Result._20:= Vec.x;
  Result._21:= Vec.y;
  Result._22:= Vec.z;
end;
{$ENDIF}

function mat4translate( Vec: TV3 ): TM4;
{$IFDEF IMPLEMENTATION}
begin
  Result.Identity;
  Result._30:= Vec.x;
  Result._31:= Vec.y;
  Result._32:= Vec.z;
end;
{$ENDIF}

function mat4translate( Vec: TV4 ): TM4;
{$IFDEF IMPLEMENTATION}
begin
  Result.Identity;
  Result._30:= Vec.x;
  Result._31:= Vec.y;
  Result._32:= Vec.z;
  Result._33:= Vec.w;
end;
{$ENDIF}

function mat2scale( Vec: TV2 ): TM2;
{$IFDEF IMPLEMENTATION}
begin
  Result.Identity;
  Result._00:= Vec.x;
  Result._11:= Vec.y;
end;
{$ENDIF}

function mat3scale( Vec: TV3 ): TM3;
{$IFDEF IMPLEMENTATION}
begin
  Result.Identity;
  Result._00:= Vec.x;
  Result._11:= Vec.y;
  Result._22:= Vec.z;
end;
{$ENDIF}

function mat4scale( Vec: TV4 ): TM4;
{$IFDEF IMPLEMENTATION}
begin
  Result.Identity;
  Result._00:= Vec.x;
  Result._11:= Vec.y;
  Result._22:= Vec.z;
  Result._33:= Vec.w;
end;
{$ENDIF}

{$WARNINGS OFF} // Omit warnings about the function result variable not being initialized
function mat4transpose(Matrix: TM4): TM4;
{$IFDEF IMPLEMENTATION}
begin
  Result._00:= Matrix._00;
  Result._10:= Matrix._01;
  Result._20:= Matrix._02;
  Result._30:= Matrix._03;

  Result._01:= Matrix._10;
  Result._11:= Matrix._11;
  Result._21:= Matrix._12;
  Result._31:= Matrix._13;

  Result._02:= Matrix._20;
  Result._12:= Matrix._21;
  Result._22:= Matrix._22;
  Result._32:= Matrix._23;

  Result._03:= Matrix._30;
  Result._13:= Matrix._31;
  Result._23:= Matrix._32;
  Result._33:= Matrix._33;
end;
{$ENDIF}


function mat3toScale( Matrix: TM3 ): TV3;
{$IFDEF IMPLEMENTATION}
begin
  Result.X:= _length( v3( Matrix._00, Matrix._01, Matrix._02 ));
  Result.Y:= _length( v3( Matrix._10, Matrix._11, Matrix._12 ));
  Result.Z:= _length( v3( Matrix._20, Matrix._21, Matrix._22 ));
end;

function unproject( x: TV3; matView, matProj: TM4; ScrWidth, ScrHeight: Integer; out Direction: TV3 ): TV3;
    {$IFDEF IMPLEMENTATION}
var
  m: TM4;
begin
  // Compute the vector of the pick ray in screen space
  Result.x:=  ((( 2.0 * x.x ) / ScrWidth ) - 1 ) / matProj._00;
  Result.y:= -((( 2.0 * x.y ) / ScrHeight ) - 1 ) / matProj._11;
  Result.z:= -1.0; //TODO: Check if left or righthanded

  // Get the inverse view matrix

  m:= -matView;

  // Transform the screen space pick ray into 3D space
  Direction.x:= Result.x * m._00 + Result.y * m._10 + Result.z * m._20;
  Direction.y:= Result.x * m._01 + Result.y * m._11 + Result.z * m._21;
  Direction.z:= Result.x * m._02 + Result.y * m._12 + Result.z * m._22;
  Direction.Normalize;
  Result.x:= m._30;
  Result.y:= m._31;
  Result.z:= m._32;
end;
    {$ENDIF}
{$ENDIF}

