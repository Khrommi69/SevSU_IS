Unit mod1;
interface
Type 
  rasp=record
    n,cost:integer;     //номер поезда,стоимость билета
    sO,sP:string[20];  //станция отправления/прибытия
    vO,vP:string[5];  //время отправления/прибытия
  end;

  tree=record
    data:rasp;
    left,right:^tree;
  end;
Procedure DeleteTree(var tmp:^tree);
Procedure AddElement(var root:^tree; const elem:^tree);
Procedure CreateTree (var root:^tree);
Procedure ShowTree (const root:^tree; otstup:integer);
Procedure SearchInTree(root:^tree; poezd:integer);
Procedure SaveElement(const elem:^tree; var fileP: file of rasp);
Procedure SaveTree(const root:^tree; FileName:string);
Procedure DownloadTree(var root:^tree; const FileName:string);


implementation
uses crt;

////  Удаление дерева  \\\\
Procedure DeleteTree(var tmp:^tree);
Begin
  if tmp<>nil then
  begin
    // Очистка левой и правой ветви
    DeleteTree(tmp^.left);
    DeleteTree(tmp^.right);
    // Удаление корня
    dispose(tmp);
    tmp:=nil;
  end;
End;


////  Добавить новый элемент  \\\\
Procedure AddElement(var root:^tree; const elem:^tree);
begin
  if root = nil then
  begin
    root := elem;
    EXIT;
  end;
  if root^.data.n < elem^.data.n then
    AddElement(root^.right,elem)
  else
    AddElement(root^.left,elem);
end;


////  Процедура создания дерева  \\\\
Procedure CreateTree (var root:^tree);
Var tmp:^tree; r:rasp;
Begin
  //удалить предыдущее дерево если таково было
  DeleteTree(root);
  
  Writeln('Создаём дерево');
  writeln;
  write('Введите номер поезда: ');        readln(R.n);
  write('Введите станцию отправления: '); readln(R.sO);
  write('Введите станцию прибытия: ');    readln(R.sP);
  write('Введите время отправления: ');   readln(R.vO);
  write('Введите время прибытия: ');      readln(R.vP);
  write('Введите стоимость билета: ');    readln(R.cost);
  new(tmp);
  tmp^.data:=r;
  root:=tmp;
  readkey;
    
  while true do
  begin
    clrscr; 
    write('Введите номер поезда: ');        readln(R.n);
    write('Введите станцию отправления (*-выход): '); readln(R.sO);
    if R.sO = '*' then Exit;
    write('Введите станцию прибытия: ');    readln(R.sP);
    write('Введите время отправления: ');   readln(R.vO);
    write('Введите время прибытия: ');      readln(R.vP);
    write('Введите стоимость билета: ');    readln(R.cost);
    new(tmp);
    tmp^.data:=r;
    AddElement(root,tmp);
    readkey;
  end;
End;


////  Процедура демонстрации дерева  \\\\
Procedure ShowTree (const root:^tree; otstup:integer);
begin
  if root<>nil then
  Begin
    otstup:=otstup+10;
    ShowTree(Root^.right,otstup);
    Writeln(' ':otstup, Root^.Data.n);
    Writeln(' ':otstup, Root^.Data.sO);
    Writeln(' ':otstup, Root^.Data.sP);
    Writeln(' ':otstup, Root^.Data.vO);
    Writeln(' ':otstup, Root^.Data.vP);
    Writeln(' ':otstup, Root^.Data.cost);
    ShowTree(Root^.left, otstup);
  End
end;


////  Узнать входит ли элемент в дерево  \\\\
Procedure SearchInTree(root:^tree; poezd:integer);
Var found:boolean; i:integer;
Begin
  Found:=false;
  While (root<>nil) and (not found) and (i<>1000) do
  begin
    i:=i+1;
    if root^.data.n=poezd then
      found:=true
    else
    if root^.data.n>poezd then
      root:=root^.left
    else
      root:=root^.right;
  end;
  if found=false then 
  begin
    Writeln('Я не нашёл такой поезд :('); 
    readkey;
    exit;
  end
  else 
  begin
    writeln('Поезд найден!!! :)');
    Writeln('------------------------------------------------------');
    Writeln('|    Номер поезда:      | ',root^.data.n:25,'|');
    Writeln('|  Станция отправления: | ',root^.data.sO:25,'|');
    Writeln('|  Станция прибытия:    | ',root^.data.sP:25,'|');
    Writeln('|  Время отправления:   | ',root^.data.vO:25,'|');
    Writeln('|   Время прибытия:     | ',root^.data.vP:25,'|');
    Writeln('|  Стоимость билета:    | ',root^.data.cost:25,'|');
    Writeln('------------------------------------------------------');
    Writeln;
    readkey;
  end;
end;


////  Сохранение одного элемента  \\\\
Procedure SaveElement(const elem:^tree; var fileP: file of rasp);
begin
  if elem = nil then exit;
  write(fileP, elem^.data);
  SaveElement(elem^.left, fileP);
  SaveElement(elem^.right, fileP);
end;


////  Сохранения дерева в файл  \\\\
Procedure SaveTree(const root:^tree; FileName:string);
var fileP: file of rasp;
begin
  assign(fileP, fileName);
  rewrite(fileP);
  
  SaveElement(root,fileP);
  
  close(fileP);
  writeln;
end;


////  Загрузка дерева из файла  \\\\
Procedure DownloadTree(var root:^tree; const FileName:string);
var fileP: file of rasp;
    element:^tree;
begin
  assign(fileP, fileName);
  reset(fileP);
  DeleteTree(root);
  while not eof(fileP) do
  begin
    new(element); 
    element^.right:=nil; 
    element^.left:=nil;
    read(fileP, element^.data);
    AddElement(root,element);
    element:=nil;
  end;
  close(fileP);
  writeln;
end;

  
begin
end.