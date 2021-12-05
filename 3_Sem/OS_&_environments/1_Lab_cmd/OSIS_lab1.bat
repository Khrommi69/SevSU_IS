chcp 65001
@ECHO OFF
setlocal EnableDelayedExpansion
CLS

REM создать дерево каталогов
cd /d D:\
md OSIS_lab1
cd OSIS_lab1
md Khromenko.IS_b_20_2_o
cd Khromenko.IS_b_20_2_o
md KDA1
md KDA2
md KDA3
ECHO Создано дерево каталогов
ECHO A directory tree has been created > D:\OSIS_lab1\echo.log
tree D:\OSIS_lab1
ECHO.
ECHO. >> D:\OSIS_lab1\echo.log
pause
CLS

REM создать текстовый файл
cd KDA1
ECHO (осуществляйте ввод на английском языке пж)
ECHO Введите ФИО и группу, которые будут записаны в текстовый файл (ctrl+z - прекращение ввода):
ECHO Input FIO and grup >> D:\OSIS_lab1\echo.log
COPY CON Danil.txt

REM если файл создался, скопировать его в KDA2 иначе выход
IF NOT EXIST Danil.txt GOTO Error_and_exit
ECHO файл %Danil.txt% успешно создан! :)
ECHO file has been created >> D:\OSIS_lab1\echo.log
ECHO.
ECHO. >> D:\OSIS_lab1\echo.log
pause
CLS
COPY Danil.txt ..\KDA2

REM перейти в каталог KDA2 и переименовать файл
cd ..
cd KDA2
REN Danil.txt linaD.txt

REM файл 1 + файл 2 = файл 3 в каталоге KDA3 с именем 1 или 2 или new .doc
IF NOT EXIST linaD.txt GOTO Error_and_exit
ECHO файл Danil.txt из каталога KDA1 успешно скопирован в каталог KDA2 и переименован в linaD.txt! :)
ECHO File Danil.txt of directory KDA1 successfull copy in directory KDA2 and renamed in linaD.txt! :) >> D:\OSIS_lab1\echo.log
ECHO.
ECHO. >> D:\OSIS_lab1\echo.log
pause
CLS
cd ..
ECHO Теперь мы объединяем текст из файлов Danil.txt и linaD.txt в третий_файл - !fileName!.!EXT! c в каталоге KDA3
ECHO Now we combine the textfrom the Danil.txt and linaD.txt in the third.doc in the catalogKDA3 >> D:\OSIS_lab1\echo.log

IF NOT "%1" == "" (
SET name=%1
IF NOT "!EXT!" == "" (
COPY KDA1\Danil.txt + KDA2\linaD.txt KDA3\!name!.!EXT!
SET rasschirenie=!EXT!
) ELSE (
COPY KDA1\Danil.txt + KDA2\linaD.txt KDA3\!name!.doc
SET rasschirenie=doc
)
) ELSE (
ECHO так как при запуске bat файла не было указано имя третьего файла в переменной окружения EXT, то выбирайте
ECHO  since when the bat file was launched, the name ofthe tird file was not specifiedin the environment variable EXT, then select >> D:\OSIS_lab1\echo.log
ECHO номер 1 - имя Danil, номер 2 или вообще что угодно - имя linaD
ECHO num 1 - name Danil, num 2 or anything - name linaD >> D:\OSIS_lab1\echo.log
SET /p name="Номер: "
IF "!name!" == "1" ( SET name=Danil ) ELSE ( SET name=linaD )
COPY KDA1\Danil.txt + KDA2\linaD.txt "KDA3\!name!.!rasschirenie!"
)

IF NOT EXIST "D:\OSIS_lab1\Khromenko.IS_b_20_2_o\KDA3\!name!.!rasschirenie!" GOTO Error_and_exit
ECHO Мои поздравления! третий файл.doc успешно создан!
ECHO Congratulations! The third.doc has been created! >> D:\OSIS_lab1\echo.log
ECHO.
ECHO. >> D:\OSIS_lab1\echo.log
pause
CLS

REM перемещение файла.doc в каталог ниже уровнем
MOVE "KDA3\!name!.!rasschirenie!" "!name!.!rasschirenie!"
IF NOT EXIST "!name!.!rasschirenie!" GOTO Error_and_exit
ECHO Ура, теперь мы ещё и переместили этот файл в каталог ниже уровнем :) (Khromenko.IS_b_20_2_o)
ECHO Placed the third file below the level >> D:\OSIS_lab1\echo.log
ECHO.
ECHO. >> D:\OSIS_lab1\echo.log
pause
CLS

ECHO Давайте же прочтем что в нем находится
ECHO Let's go read file >> D:\OSIS_lab1\echo.log
ECHO.
ECHO. >> D:\OSIS_lab1\echo.log
COPY "%name%.!rasschirenie!" CON
ECHO.
ECHO. >> D:\OSIS_lab1\echo.log
ECHO удалось!
ECHO succeeded! >> D:\OSIS_lab1\echo.log
echo.
ECHO. >> D:\OSIS_lab1\echo.log
pause
CLS

ECHO теперь удалим все файлы и каталоги
ECHO let's delete files and directory >> D:\OSIS_lab1\echo.log
ECHO Удаляем? да/нет
ECHO Delete? Y/N >> D:\OSIS_lab1\echo.log
SET /p ques="Ответ: "
IF "!ques!" == "да" (
cd D:\OSIS_lab1\Khromenko.IS_b_20_2_o\KDA1
del Danil.txt
cd ..
cd KDA2
del linaD.txt
cd ..
rd KDA1
rd KDA2
rd KDA3
del "!name!.!rasschirenie!"
cd ..
rd Khromenko.IS_b_20_2_o
del echo.log
cd ..
rd OSIS_lab1
ECHO Все файлы и каталоги были удалены.
ECHO all files and directory has been deleted. >> D:\OSIS_lab1\echo.log
) ELSE (
ECHO Ладно, ничего удалять не будем
ECHO Ok, we will not delete >> D:\OSIS_lab1\echo.log
)

pause
set name =
set ques =
GOTO :EOF
:Error_and_exit
ECHO Ошибка, аварийный выход!
ECHO Ошибка, аварийный выход! >> D:\OSIS_lab1\echo.log
pause
REM удаление переменной
set name =