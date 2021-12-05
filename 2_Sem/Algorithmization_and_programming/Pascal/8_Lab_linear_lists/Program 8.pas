Program lab_8;
Uses Crt;
Type
    Anketa = record
      n,gr,kold,oklad:integer;
      fio,ss:string[20];
      gender:char;
    end;
    Ukaz=^pole;
    pole = record
      d:anketa;
      next:Ukaz;
    end;
    File_name=string;
    

//Удаление таблицы
//===================================
procedure deleteTABL(var left:Ukaz);
Var temp:ukaz;
begin
  while left <> nil do
  begin
    temp:=left;
    left:=left^.next;
    dispose(temp);
  end
end;


//Создание таблицы
//===========================================================
Procedure createNEW (var right,left:Ukaz);
Var A:anketa;
    NewE:Ukaz;
Begin
  deleteTABL(left); //процедура удаления старой таблицы
  
  Writeln('=========================================');
  Writeln('Выполняется процедура создания списка');
  Writeln('(+ очистка пред. таблицы если она имеется)');
  Writeln('=========================================');
  
  Write('Введите фамилию и инициалы (* - выход): '); readln(A.fio);
  if A.fio = '*' then exit;
  Write('Введите год рождения: ');                   readln(A.gr);
  Write('Введите пол (м/ж): ');                      readln(A.gender);
  Write('Введите семейное состояние: ');             readln(A.ss);
  Write('Введите количество детей: ');               readln(A.kold);
  Write('Введите оклад: ');                          readln(A.oklad);
  
  New(NewE);
  NewE^.d.Fio:=A.Fio;
  NewE^.d.gr:=A.gr;
  NewE^.d.gender:=A.gender;
  NewE^.d.ss:=A.ss;
  NewE^.d.kold:=A.kold;
  NewE^.d.oklad:=A.oklad;
  NewE^.Next:=nil;
  Right:=NewE;     //Right - указатель начала таблицы
  Left:=NewE;     //Left - указатель конца таблицы
  
  While true do
  begin
    writeln();
    writeln('======= Ввод следующей строки =======');
    writeln();
    Write('Введите фамилию и инициалы (* - выход): '); readln(A.fio);
    if A.fio = '*' then exit;
    Write('Введите год рождения: ');                   readln(A.gr);
    Write('Введите пол (м/ж): ');                      readln(A.gender);
    Write('Введите семейное состояние: ');             readln(A.ss);
    Write('Введите количество детей: ');               readln(A.kold);
    Write('Введите оклад: ');                          readln(A.oklad);
    
    New(NewE);
    NewE^.d.Fio:=A.Fio;
    NewE^.d.gr:=A.gr;
    NewE^.d.gender:=A.gender;
    NewE^.d.ss:=A.ss;
    NewE^.d.kold:=A.kold;
    NewE^.d.oklad:=A.oklad;
    NewE^.Next:=nil;
    Right^.Next:=NewE;
    Right:=NewE 
  end;
end;


//Добавить в конец таблицы один элемент
//===========================================================
Procedure Dobav (Var left,right:ukaz);
Var A:anketa;
    newE:Ukaz;
Begin
  Writeln('=========================================');
  Writeln('Выполняется процедура добавления элемента');
  Writeln('=========================================');
  Write('Введите фамилию и инициалы (* - выход): '); readln(A.fio);
  if A.fio = '*' then exit; 
  Write('Введите год рождения: ');                   readln(A.gr);
  Write('Введите пол (м/ж): ');                      readln(A.gender);
  Write('Введите семейное состояние: ');             readln(A.ss);
  Write('Введите количество детей: ');               readln(A.kold);
  Write('Введите оклад: ');                          readln(A.oklad);
  
  New(NewE);
  NewE^.d.Fio:=A.Fio;
  NewE^.d.gr:=A.gr;
  NewE^.d.gender:=A.gender;
  NewE^.d.ss:=A.ss;
  NewE^.d.kold:=A.kold;
  NewE^.d.oklad:=A.oklad;
  NewE^.Next:=nil;
  If Left=Nil Then      {Если добавляется первый элемент, то}
    Left:=NewE          {инициализировать указатель головы}
  Else
    begin
    Right:=Left;
    while (right^.next<>nil) do
      right:=right^.next;
    right^.next:=NewE;
    right:=NewE;
    end;
    Writeln('Нажмите "Enter" для продолжения'); readln;
end;


//Удалить первый элемент таблицы
//===========================================================
Procedure Delete_1(Var left,right:ukaz);
Var temp:ukaz;
Begin
  Writeln('Исключение первого элемента таблицы');
  If left<>nil then
  begin
    Temp:=left;
    left:=Left^.next;
    Dispose(Temp);
    //если удалили последний элемент
    If Left=nil then right:=nil;
  end
  else
    Writeln('--------ERROR: таблица пуста--------');
  Writeln('Нажмите "Enter" для продолжения'); readln;
end;


//МОЯ ПРОЦЕДУРА
//Удаление последнего элемента таблицы
//===========================================================
Procedure Delete_last (Var Left:ukaz);
Var Temp:ukaz;
Begin
  Writeln('Исключение последнего элемента таблицы');
  if left=nil then
  begin
    Writeln('--------ERROR: таблица пуста--------');
    Writeln('Нажмите "Enter" для продолжения'); readln; Exit;
  end;
  if left^.next=nil then
  begin
    Dispose(Left);
    Left:=nil;
    Writeln('Нажмите "Enter" для продолжения'); readln; Exit;
  end;
  temp:=left;
  while (temp^.next^.next) <> nil do temp:=temp^.next;
  Dispose(temp^.next);
  Temp^.next:=nil;
  Writeln('Нажмите "Enter" для продолжения'); readln;
end;


//Показать таблицу
//===========================================================
Procedure Show_tabl(const left:ukaz);
Var k:integer;
    temp:ukaz;
Begin
  if left=nil then
  begin
    writeln();
    writeln('=========================================');
    writeln('         ERROR: Таблица пуста            ');
    writeln('=========================================');
    writeln();
  end
  else
  begin
    k:=1; Temp:=Left;
    writeln();
    writeln('=================================================================================');
    writeln('                                     ТАБЛИЦА                                     ');
    writeln('=================================================================================');
    writeln();
    writeln(
        '№':4,                ' | ',
        'ФИО':20,     ' | ',
        'Г.р.':5,       ' | ',
        'Пол':3,   ' | ',
        'Семейное состояние':20,      ' | ',
        'Дети':4,     ' | ',
        'Оклад':7
        );
    writeln('---------------------------------------------------------------------------------');
    While Temp <> nil do
    begin
      writeln(
        k:4,                ' | ',
        Temp^.d.Fio:20,     ' | ',
        Temp^.d.gr:5,       ' | ',
        Temp^.d.gender:3,   ' | ',
        Temp^.d.ss:20,      ' | ',
        Temp^.d.kold:4,     ' | ',
        Temp^.d.oklad:7
        );
        Temp:=Temp^.Next; inc(k);
    end;
  end;
  Writeln('Нажмите "Enter" для продолжения'); readln;
end;


//Сохранить таблицу
//===========================================================
Procedure Save(const FN:file_name; var Left:ukaz);
var temp:ukaz;
    f: file of anketa;
Begin
  assign(f,FN);
  rewrite(f);
  
  Temp:=left;
  while Temp <> nil do
  begin
    write(f, Temp^.d);
    Temp := Temp^.next;
  end;
  
  close(f);
  
  writeln();
  writeln('===================================================');
  writeln('   Таблица была сохранена и может быть загружена   ');
  writeln('===================================================');
  writeln();
  Writeln('Нажмите "Enter" для продолжения'); readln;
end;


//Загрузить таблицу
//===========================================================
Procedure download(const FN:file_name; var Left:ukaz);
Var t,temp:Ukaz;
    f: file of anketa;
Begin
  deleteTABL(left);
  assign(f,FN);
  reset(f);
  
  new(Left);
  Temp:=left;
  
  while not eof(f) do
  begin
    t := temp;
    read(f, temp^.d);
    new(temp^.next);
    temp := temp^.next;
  end;
  
  if left <> temp then
    dispose(t^.next)
  else
    dispose(left);
    close(f);  
  
  writeln();
  writeln('===================================================');
  writeln(' Таблица была загружена и может быть использована  ');
  writeln('===================================================');
  writeln();
  Writeln('Нажмите "Enter" для продолжения'); readln;
end;


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Var key:byte;
    NewE,Left,Right,Temp:Ukaz;
    A:anketa;
    Filename:File_name;

{============== Основная программа ==============}
BEGIN
  Right:=Nil; Left:=Nil;
//......................................\\
  FileName:='C:\PABCWork.NET\lab_8.txt';
//......................................\\
  while true do
  begin
    ClrScr;
    writeln();
    writeln('=========================================');
    writeln('Выберите действие:');
    writeln('1 - Создание таблицы (+ удаление старой)');
    writeln('2 - Добавление элемента в таблицу');
    writeln('3 - Удалить первого');
    writeln('4 - Удалить последнего'); //МОЁ
    writeln('5 - Показать таблицу');
    writeln('6 - Сохранить таблицу в файл');
    writeln('7 - Выгрузить таблицу из файла');
    writeln('8 - Выход из программы');
    
    write('Ввод: -> '); readln(key);
    case key of
      1: begin ClrScr; CreateNEW(right,left); end;
      2: begin ClrScr; Dobav(left,right); end;
      3: begin ClrScr; Delete_1(left,right); end;
      4: begin ClrScr; Delete_last(left); end;
      5: begin ClrScr; Show_tabl(left);  end;
      6: begin ClrScr; Save(FileName,left); end;
      7: begin ClrScr; download(FileName,left); end;
      8: Exit;
      else writeln('(!) Неверная команда!');
    end;
  end;
END.