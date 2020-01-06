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
type
    { gListEnumerator }

    generic gListEnumerator < T > = class
      private type
        TMoveNext = function ( var AIndex: Integer; out AItem: T ): Boolean of object;
      private
        FCurrent: T;
        FCurrentIdx: Integer;
        FMoveNext: TMoveNext;

      public
        constructor Create( AStartIndex: Integer; AMoveNext: TMoveNext );
        function MoveNext: Boolean;
        property Current: T read FCurrent;
        property CurrentIdx: Integer read FCurrentIdx;
    end;

    { gItemList }
    TItemListOnChangeAction = ( actAdd, actDelete, actClear, actAssignBefore, actAssignAfter, actSet );
    TItemListOnChangeEvent = procedure ( Sender: TPersistent; ItemIndex: Integer; Action: TItemListOnChangeAction ) of object;

    generic gItemList < T > = class ( TAutoClassMultiContainer )
      type
        TItemList = specialize gItemList < T >;
        TItemListOnChangeEvent = procedure ( Sender: TItemList; ItemIndex: Integer; Action: TItemListOnChangeAction ) of object;
        TItemListOnSetEvent = function ( Sender: TObject; ItemIndex: Integer; AValue: T ): Boolean of object;

        TItemArray = array [ 0..( MAXINT shr 8 )] of T;
        pItemArray = ^TItemArray;
        TListEnumerator = specialize gListEnumerator < T >;

      private
        FItems: pItemArray;
        FCount: Integer;
        FCapacity: Integer;
        FGrowth: Integer;
        FOnChange: TItemListOnChangeEvent;
        FOnSet: TItemListOnSetEvent;
        FSizeLimit: Integer;

        function GetItem( Index: Integer ): T;
        procedure SetCapacity( const Value: Integer );
        procedure SetCount( AValue: Integer );
        procedure SetGrowth( const Value: Integer );
        procedure SetItem( Index: Integer; const AValue: T );
        procedure Grow;
        procedure Shrink;
        function MoveNext( var AIndex: Integer; out AItem: T ): Boolean;

      protected
        function GetItemSize: Integer;

      public
        constructor Create; virtual;
        destructor Destroy; override;

        function Add( Item: T ): Integer; overload;
        function AddArray( Items: array of T ): Integer; overload;
        procedure Delete( Index: Integer ); overload;
        procedure Remove( Item: T );
        procedure Clear;
        function PtrTo( Index: Integer ): Pointer;
        function Ptr: Pointer;
        procedure AssignTo( Dest: TItemList ); reintroduce;
        function GetEnumerator(): TListEnumerator;
        function IndexOf( Item: T ): Integer;
        procedure SaveToStream( AStream: TStream );
        procedure LoadFromStream( AStream: TStream );
        procedure LoadFromStream( AStream: TStream; ACount: Integer );
        procedure AppendFromStream( AStream: TStream );
        //function GetAsString( const MaxItems: Integer = 100 ): String;

        property Items[ Index: Integer ]: T read GetItem write SetItem; default;
        property Count: Integer read FCount write SetCount;
        property Capacity: Integer read FCapacity write SetCapacity;
        property Growth: Integer read FGrowth write SetGrowth;
        property SizeLimit: Integer read FSizeLimit;
        property OnChange: TItemListOnChangeEvent read FOnChange write FOnChange;
        property OnSet: TItemListOnSetEvent read FOnSet write FOnSet;
    end;

{$ENDIF}


{$IFDEF IMPLEMENTATION}

function gItemList.Add( Item: T ): Integer;
begin
  if ( FCount = FCapacity ) then
    Grow;

  FItems^[ FCount ]:= Item;
  Result:= FCount;

  Inc( FCount );
  if ( Assigned( OnChange )) then
    OnChange( Self, Result, actAdd );
end;

function gItemList.AddArray( Items: array of T ): Integer;
var
  i: Integer;
begin
  Result:= Count;
  for i:= Low( Items ) to High( Items ) do
    Add( Items[ I ]);
end;

procedure gItemList.AssignTo( Dest: TItemList );
begin
  if ( Assigned( Dest.OnChange )) then
    Dest.OnChange( Self, -1, actAssignBefore );
  Dest.Count:= Count;
  Move( FItems^, Dest.FItems^, SizeOf( T ) * Count );
  if ( Assigned( Dest.OnChange )) then
    Dest.OnChange( Self, -1, actAssignAfter );
end;

function gItemList.GetEnumerator(): TListEnumerator;
begin
  Result:= TListEnumerator.Create( -1, @MoveNext );
end;

function gItemList.IndexOf( Item: T ): Integer;
var
  i: Integer;
begin
  Result:= -1;
  for i:= 0 to Count - 1 do
    if ( Item = Items[ i ]) then
      begin
        Result:= i;
        break;
      end;
end;

procedure gItemList.SaveToStream( AStream: TStream );
begin
  AStream.WriteBuffer( Count, SizeOf( Integer ));
  AStream.WriteBuffer( FItems^[ 0 ], SizeOf( T ) * Count );
end;

procedure gItemList.LoadFromStream( AStream: TStream );
var
  Size: Integer;
begin
  AStream.ReadBuffer( Size, SizeOf( Integer ));
  Count:= Size;
  AStream.ReadBuffer( FItems^[ 0 ], SizeOf( T ) * Count );
end;

procedure gItemList.LoadFromStream(AStream: TStream; ACount: Integer);
begin
  Count:= ACount;
  AStream.ReadBuffer( FItems^[ 0 ], SizeOf( T ) * ACount );
end;

procedure gItemList.AppendFromStream( AStream: TStream );
var
  OldCount: Integer;
  NewCount: Cardinal;
begin
  OldCount:= Count;
  NewCount:= AStream.ReadDWord;
  Count:= OldCount + NewCount;
  AStream.ReadBuffer( FItems^[ OldCount ], SizeOf( T ) * NewCount );
end;

{function gItemList.GetAsString(const MaxItems: Integer): String;
var
  i: Integer;
begin
  Result:= '';
  for i:= 0 to Min( MaxItems, Count ) - 1 do
    Result+= ', ' + Items[ i ].ToString;
  Result:= '[' + Copy( Result, 3, Length( Result ) - 2 ) + ']';
end;}

procedure gItemList.Clear;
begin
  if ( Assigned( OnChange )) then
    OnChange( Self, -1, actClear );

  FreeMem( FItems );
  FCount:= 0;
  FCapacity:= 0;
  FItems:= nil;
end;

constructor gItemList.Create;
begin
  inherited Create;
  FItems:= nil;
  FCount:= 0;
  FCapacity:= 0;
  FGrowth:= 256;
  FSizeLimit:= SizeOf( TItemArray ) div SizeOf( T );
end;

procedure gItemList.Delete( Index: Integer );
var
  i: Integer;
begin
  if ( Assigned( OnChange )) then
    OnChange( Self, Index, actDelete );

  Move( FItems^[ Index + 1 ], FItems^[ Index ], SizeOf( T ) * ( Count - 1 - Index )); //Move does a check for overlapping regions

  //for i:= Index to Count - 2 do
  //  FItems[ i ]:= FItems[ i + 1 ];
  FCount:= FCount - 1;
end;

procedure gItemList.Remove( Item: T );
var
  Index: Integer;
begin
  Index:= IndexOf( Item );
  if ( Index > -1 ) then
    Delete( Index );
end;

destructor gItemList.Destroy;
begin
  FreeMem( FItems );
  inherited;
end;

function gItemList.GetItem( Index: Integer ): T;
begin
  if (( Index >= 0 ) and ( Index < FCount )) then
    Result:= FItems^[ Index ];
end;

procedure gItemList.Grow;
begin
  FCapacity:= FCapacity + FGrowth;
  ReallocMem( FItems, FCapacity * SizeOf( T ));
end;

function gItemList.PtrTo(Index: Integer): Pointer;
begin
  if ( Count > Index ) then
    Result:= @FItems[ Index ]
  else
    Result:= nil;
end;

procedure gItemList.SetCount(AValue: Integer);
begin
  FCount:= AValue;
  while ( FCapacity < FCount ) do
    Grow;
  while ( FCapacity > FCount + FGrowth ) do
    Shrink;
end;

procedure gItemList.SetCapacity( const Value: Integer );
begin
  FCapacity:= Value;
  if ( FCapacity < FCount ) then
    FCapacity:= FCount;
  ReallocMem( FItems, FCapacity * SizeOf( T ));
end;

procedure gItemList.SetGrowth(const Value: Integer);
begin
  FGrowth:= Math.Max( 16, Value ); // Minimum Value 16
end;

procedure gItemList.SetItem( Index: Integer; const AValue: T );
begin
  if ( Assigned( OnSet ) and ( not OnSet( Self, Index, AValue ))) then
    exit;

  if ( Assigned( OnChange )) then
    OnChange( Self, Index, actSet );

  FItems^[ Index ]:= AValue;
end;

procedure gItemList.Shrink;
begin
  FCapacity:= Math.Max( 0, FCapacity - FGrowth );
  ReallocMem( FItems, FCapacity * SizeOf( T ));
end;

function gItemList.Ptr: Pointer;
begin
  Result:= FItems;
end;

function gItemList.GetItemSize: Integer;
begin
  Result:= SizeOf( T );
end;

function gItemList.MoveNext( var AIndex: Integer; out AItem: T ): Boolean;
begin
  Inc( AIndex );
  Result:= AIndex < Count;
  if ( Result ) then
    AItem:= Items[ AIndex ]
  else
    AItem:= default( T );
end;


{ TListEnumerator }

constructor gListEnumerator.Create( AStartIndex: Integer; AMoveNext: TMoveNext );
begin
  inherited Create;
  FillByte( FCurrent, SizeOf( FCurrent ), 0 );
  FCurrentIdx:= AStartIndex;
  FMoveNext:= AMoveNext;
end;

function gListEnumerator.MoveNext: Boolean;
begin
  Result:= FMoveNext( FCurrentIdx, FCurrent );
end;

{$ENDIF IMPLEMENTATION}
