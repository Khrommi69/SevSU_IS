процесс – это единица владения ресурсами
поток – единица диспетчеризации и распределения процессорного времени

В ОС Windows определены следующие классы приоритетов процессов:
HIGH_PRIORITY_CLASS - 2
IDLE_PRIORITY_CLASS - 4
NORMAL_PRIORITY_CLASS - 3 - (по умолч, если родитель не (4))
REALTIME_PRIORITY_CLASS - 1 самый высокий возможный приоритет

у процесса есть идентификатор и дескриптор (дескриптор для управления процессом из другого процесса)

с помощью системной функции WaitForSingleObject можно определить состояние текущего процесса
Основное назначение WaitForSingleObject – определить, находится ли дескриптор определенного системного объекта в сигнальном состоянии.
Дескриптор процесса переходит в сигнальное состояние тогда, когда процесс завершает свою работу.
WaitForSingleObject(дескриптор объекта ядра,  ВРЕМЯ ОЖИДАНИЯ);

BOOL WINAPI CreateProcessW( LPCWSTR lpApplicationName  -  имя приложения,
							LPWSTR lpCommandLine  -  командная строка,
							LPSECURITY_ATTRIBUTES lpProcessAttributes  -  атрибуты доступа процесса,
							LPSECURITY_ATTRIBUTES lpThreadAttributes  -  атрибуты доступа потока,
							BOOL bInheritHandles  -  наследование дескрипторов,
							DWORD dwCreationFlags  -  флаги,
							LPVOID lpEnvironment  -  параметры среды,
							LPCWSTR lpCurrentDirectory  -  текущая папка процесса,
							LPSTARTUPINFO lpStartupInfo  -  структура стартовых полей,
							LPPROCESS_INFORMATION lpProcessInformation  -  возвращаемые значения
							);

LPCWSTR означает "длинный указатель на постоянную строку"
LPWSTR – указатель на UNICODE строку

LPSECURITY_ATTRIBUTES - это указатель на структуру SECURITY_ATTRIBUTES
typedef struct _SECURITY_ATTRIBUTES {
	DWORD  nLength;              // Задаёт размер, в байтах, этой структуры
	LPVOID lpSecurityDescriptor; // Указатель на дескриптор безопасности для объекта контролирующего совместное его использование.
	                             // Если NULL, то с объектом будет связан дескриптор безопасности по умолчанию вызывающего процесса.
	BOOL   bInheritHandle;       // Определяет, будет ли возвращаемый дескриптор наследоваться при создании нового процесса.
	                             // Если равен TRUE, новый процесс наследует дескриптор.
} SECURITY_ATTRIBUTES;

DWORD — 32-битное беззнаковое целое. Аналоги: unsigned long int...
LPVOID - это указатель. При этом это указатель (P от Pointer) на что угодно (VOID), да еще и дальний (L - от Long)

Указатель на структуру SECURITY_ATTRIBUTES используется как параметр в большинстве функций ядра и управления окнами Win32 API,
которые возвращают дескриптор объекта.

LpStartupInfo – указатель на структуру STARTUPINFO, которая устанавливает оконный режим терминала, рабочий стол,
стандартные дескрипторы и внешний вид главного окна для нового процесса.

LPPROCESS_INFORMATION lpProcessInformation – указатель, получающий данные о дочернем процессе в формате: struct PROCESS_INFORMATION
Структура PROCESS_INFORMATION содержит информацию о новом созданном процессе и его потоке при вызове функции CreateProcess
typedef struct _PROCESS_INFORMATION {
	HANDLE hProcess;    // Дескриптор созданного процесса
	HANDLE hThread;     // Дескриптор главного потока созданного процесса
	DWORD  dwProcessId; // Идентификатор процесса
	DWORD  dwThreadId;  // Идентификатор потока
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;


Если вместо имени программы lpApplicationName задать NULL, под именем
программы будет пониматься первое имя, стоящее в командной строке
lpCommandLine. Этот вариант предпочтительнее, поскольку, во-первых, к имени
приложения автоматически добавляется расширение "ехе"

Если параметры lpProcessAttributes и lpThreadAttributes установлены в NULL,
используются текущие права доступа

Обычно процессы создают с нулевым значением параметра dwCreationFlags,
что означает "нормальный" режим выполнения процесса, но при задании других
значений флага можно, например, запустить процесс в отладочном режиме или
же задать класс приоритета процесса.

Параметр lpEnvironment — указатель на буфер с параметрами среды; если этот
параметр равен NULL, порождаемый процесс наследует среду окружения родительского процесса

Если параметр lpCurrentDirectory установлен в NULL, то текущая папка родительского процесса
будет унаследована порождаемым процессом.

Параметр lpStartupInfo — указатель на структуру STARTUPINFO, поля которой
определяют режим открытия нового процесса
struct STARTUPINFO {
	DWORD cb; //размер структуры
	LPSTR lpReserved; //NULL
	LPSTR lpDesktop; //имя "рабочего стола"
	LPSTR lpTitle; //заголовок консоли
	DWORD dwX; //левый верхний угол
	DWORD dwY; //нового окна
	DWORD dwXSize; //ширина нового консольного окна
	DWORD dwYSize; //высота нового консольного окна
	DWORD dwXCountChars; //размер буфера
	DWORD dwYCountChars; // консоли
	DWORD dwFillAttribute; //цвет текста (в консольном приложении)
	DWORD dwFlags; //флаг определяет разрешенные поля
	WORD wShowWindow; //способ отображения окна
	WORD cbReserved2; //NULL
	LPBYTE lpReserved2; //NULL
	HANDLE hStdInput; //дескрипторы стандартных
	HANDLE hStdOutput; //потоков ввода/вывода
	HANDLE hStdError; //потока ошибок
};

LPSTR. указатель на строку, завершающуюся нулем или 8-разрядную Windows (ANSI) символов
LPBYTE-это указатель на массив байтов.
HANDLE - дескриптор, т.е. число, с помощью которого можно идентифицировать ресурс.

Поле dwFlags обычно устанавливают в STARTF_USESHOWWINDOW, что позволяет
задать способ отображения окна. Значение SW_SHOWNORMAL в поле wShowWindow
позволяет Windows самостоятельно определить размер и положение открываемого окна, а SW_SHOWMINIMIZED означает, что приложение открывается в "свернутом" виде

lpProcessInformation — указатель на структуру
PROCESS_INFORMATION, в которой возвращается значение дескриптора и идентификатора порождаемого процесса и потока:
struct PROCESS_INFORMATION {
	HANDLE hProcess; //дескриптор нового процесса
	HANDLE hThread; //дескриптор главного потока
	DWORD dwProcessId; //идентификатор нового процесса
	DWORD dwThreadId; //идентификатор главного потока
};

принудительно завершить процесс:
BOOL WINAPI TerminateProcess(HANDLE hProcess, UINT fuExitCode);
В качестве первого параметра этой функции используется дескриптор процесса,
который возвращается в поле hProcess структуры PROCESS_INFORMATION. Второй
параметр fuExitCode — код возврата.

Процесс может быть завершен и "изнутри" вызовом функции ExitProcess():
VOID WINAPI ExitProcess(UINT fuExitCode);

int procId = GetCurrentProcessId(); // Взять идентификатор вызывающего процесса


//====================================================================================================================================

Для создания потока используется функция CreateThread():
HANDLE WINAPI CreateThread(
LPSECURITY_ATTRIBUTES lpThreadAttributes, //атрибуты доступа
DWORD dwStackSize, //размер стека потока
LPTHREAD_START_ROUTINE lpStartAddress, //функция потока
LPVOID lpParameter, //параметр функции
DWORD dwCreationFlags, //состояние потока
LPDWORD lpThreadId); //идентификатор потока

Для досрочного завершения работы поток может вызвать функцию ExitThread():
VOID WINAPI ExitThread(DWORD dwExitCode);

Вновь создаваемый поток имеет приоритет THREAD_PRIORITY_NORMAL.
Используя функции GetThreadPriority и SetThreadPriority можно получить текущий
и установить требуемый приоритет созданного потока

THREAD_PRIORITY_NORMAL 0
THREAD_PRIORITY_ABOVE_NORMAL +1
THREAD_PRIORITY_BELOW_NORMAL -1
THREAD_PRIORITY_HIGHEST +2
THREAD_PRIORITY_LOWEST -2
THREAD_PRIORITY_IDLE
"устанавливает базовый уровень приоритета потока равный 1 для классов приоритета процесса: IDLE_PRIORITY_CLASS,
NORMAL_PRIORITY_CLASS, или HIGH_PRIORITY_CLASS, и базовый уровень
приоритета потока 16 для класса приоритета процесса REALTIME_PRIORITY_CLASS"
THREAD_PRIORITY_TIME_CRITICAL
"устанавливает базовый уровень
приоритета потока 15 для классов приоритета процесса: IDLE_PRIORITY_CLASS,
NORMAL_PRIORITY_CLASS, или HIGH_PRIORITY_CLASS, и базовый уровень приоритета потока 31 для класса приоритета процесса REALTIME_PRIORITY_CLASS"