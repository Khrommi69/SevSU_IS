Program lab_10;
Uses crt,mod1;

Var FileName:string;
    num,otstup:integer;
    myTree:^tree;
    
////  Основная программа  \\\\
BEGIN
  FileName:='C:\PABCWork.NET\lab_9.txt';
  
  Writeln;
  Writeln('============================================');
  Writeln('  Программа работает с бинарными деревьями  ');
  Writeln('  (дерево упрорядочено по номерам поездов)  ');
  Writeln('============================================');
  Writeln;
  readkey;
  clrscr;
      
  While true do
  begin  
    Writeln;
    Writeln('1 - Создание нового дерева');
    Writeln('2 - Удаление дерева');
    Writeln('3 - Просмотр дерева');
    Writeln('4 - Узнать входит ли элемент в дерево');  //my
    Writeln('5 - Сохранить дерево');
    Writeln('6 - Загрузить дерево');
    Writeln('7 - Выход из программы');
    Writeln;
    Write('Ввод -> ');readln(num);
    ClrScr;
  case num of
    1: 
    Begin
      CreateTree(myTree);
      clrscr;
    End;
    2:
    Begin
      Writeln('Дерево было удалено');
      DeleteTree(myTree);
      readkey;
      clrscr;
    End;
    3:
    Begin
      Writeln('Выполняется просмотр дерева':50);
      Writeln('---------------------------':50);
      Writeln('|      Номер поезда       |':50);
      Writeln('|   Станция отправления   |':50);
      Writeln('|    Станция прибытия     |':50);
      Writeln('|    Время отправления    |':50);
      Writeln('|     Время прибытия      |':50);
      Writeln('|    Стоимость билета     |':50);
      Writeln('---------------------------':50);
      Writeln;
      
      ShowTree(myTree,otstup);
      
      readkey;
      ClrScr;
    end;
    4:
    Begin
      Writeln('Выполняется проверка присутствия элемента в дереве');
      Write('Введите номер искомого поезда -> '); readln(num);
      SearchInTree(myTree,num);
      ClrScr;
    end;
    5:
    Begin
      SaveTree(myTree,FileName);
      Writeln('Дерво было успешно сохранено!');
      readkey;
      ClrScr;
    end;
    6:
    Begin
      DownloadTree(myTree,FileName);
      Writeln('Дерво было успешно загружено!');
      readkey;
      ClrScr;
    end;
    7: Exit;
  end;
  end;
END.