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

  {$IFDEF IMPLEMENTATION}
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
