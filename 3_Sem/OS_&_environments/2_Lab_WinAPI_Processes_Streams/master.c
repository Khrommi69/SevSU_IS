#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	SYSTEMTIME Time;
	printf("\nMASTER: Здравствуйте!\n\n");

	// Если в качестве аргумента командной строки передовалось что то, то то-то...
	char cmd[256];
	if (argc!=1) {
		strcpy(cmd, argv[1]);
	} else {
		strcpy(cmd, "sort.exe");
	}
	
	int procId = GetCurrentProcessId(); // Взять идентификатор вызывающего процесса
	sprintf(cmd+strlen(cmd), " %d", procId); // cmd+идентификатор
	printf("Мастер стартует: %s\n", cmd);
	fflush(stdout); // Очистить буфер вывода
	Sleep(3000); //спать 3 сек

	STARTUPINFO si; // lpStartupInfo
	memset(&si, 0, sizeof(si)); // Заполнение в info каждого байта 0
	si.cb = sizeof(si); // должно быть записано, какой размер имеет стуктура

	PROCESS_INFORMATION pi; // lpProcessInformation

	//=============================================--1--=============================================

	si.lpTitle = "Process: 1.1; Prioritet: IDLE_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // имя приложения
					   	cmd,   // коммандная строка
					   	NULL,  // атрибуты доступа процесса
					   	NULL,  // атрибуты доступа потока
					   	FALSE, // наследование дескрипторов (не наследовать)
					   	CREATE_NEW_CONSOLE | IDLE_PRIORITY_CLASS, // класс приоритета
					   	NULL, // наследует среду окружения родительского процесса
					   	NULL, // текущая папка родительского процесса будет унаследована порождаемым процессом
					   	&si,
					   	&pi) ) {
		printf("Master: 1.1 Процесс Sort не запущен\a\n");
	}

	si.lpTitle = "Process: 1.2; Prioritet: NORMAL_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // имя приложения
					   	cmd,   // коммандная строка
					   	NULL,  // атрибуты доступа процесса
					   	NULL,  // атрибуты доступа потока
					   	FALSE, // наследование дескрипторов (не наследовать)
					   	CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, // класс приоритета
					   	NULL, // наследует среду окружения родительского процесса
					   	NULL, // текущая папка родительского процесса будет унаследована порождаемым процессом
					   	&si,
					   	&pi) ) {
		printf("Master: 1.2 Процесс Sort не запущен\a\n");
	}

	//pi->hProcess = Дескриптор главного потока созданного процесса
	WaitForSingleObject(pi.hProcess, INFINITE);

	GetSystemTime(&Time);
	printf("Время выполнения программы после второй пары процессов: минуты:секунды:миллисекунды -> %02d:%02d:%03d \n\n",
    	Time.wMinute, Time.wSecond, Time.wMilliseconds);

	//=============================================--2--=============================================

	si.lpTitle = "Process: 2.1; Prioritet: IDLE_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // имя приложения
					   	cmd,   // коммандная строка
					   	NULL,  // атрибуты доступа процесса
					   	NULL,  // атрибуты доступа потока
					   	FALSE, // наследование дескрипторов (не наследовать)
					   	CREATE_NEW_CONSOLE | IDLE_PRIORITY_CLASS, // класс приоритета
					   	NULL, // наследует среду окружения родительского процесса
					   	NULL, // текущая папка родительского процесса будет унаследована порождаемым процессом
					   	&si,
					   	&pi) ) {
		printf("Master: 2.1 Процесс Sort не запущен\a\n");
	}

	si.lpTitle = "Process: 2.2; Prioritet: HIGH_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // имя приложения
					   	cmd,   // коммандная строка
					   	NULL,  // атрибуты доступа процесса
					   	NULL,  // атрибуты доступа потока
					   	FALSE, // наследование дескрипторов (не наследовать)
					   	CREATE_NEW_CONSOLE | HIGH_PRIORITY_CLASS, // класс приоритета
					   	NULL, // наследует среду окружения родительского процесса
					   	NULL, // текущая папка родительского процесса будет унаследована порождаемым процессом
					   	&si,
					   	&pi) ) {
		printf("Master: 2.2 Процесс Sort не запущен\a\n");
	}

	//pi->hProcess = Дескриптор главного потока созданного процесса
	WaitForSingleObject(pi.hProcess, INFINITE);

	GetSystemTime(&Time);
	printf("Время выполнения программы после второй пары процессов: минуты:секунды:миллисекунды -> %02d:%02d:%03d \n\n",
    	Time.wMinute, Time.wSecond, Time.wMilliseconds);

	//=============================================--3--=============================================

	si.lpTitle = "Process: 3.1; Prioritet: NORMAL_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // имя приложения
					   	cmd,   // коммандная строка
					   	NULL,  // атрибуты доступа процесса
					   	NULL,  // атрибуты доступа потока
					   	FALSE, // наследование дескрипторов (не наследовать)
					   	CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, // класс приоритета
					   	NULL, // наследует среду окружения родительского процесса
					   	NULL, // текущая папка родительского процесса будет унаследована порождаемым процессом
					   	&si,
					   	&pi) ) {
		printf("Master: 3.1 Процесс Sort не запущен\a\n");
	}

	si.lpTitle = "Process: 3.2; Prioritet: NORMAL_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // имя приложения
					   	cmd,   // коммандная строка
					   	NULL,  // атрибуты доступа процесса
					   	NULL,  // атрибуты доступа потока
					   	FALSE, // наследование дескрипторов (не наследовать)
					   	CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, // класс приоритета
					   	NULL, // наследует среду окружения родительского процесса
					   	NULL, // текущая папка родительского процесса будет унаследована порождаемым процессом
					   	&si,
					   	&pi) ) {
		printf("Master: 3.2 Процесс Sort не запущен\a\n");
	}

	//pi->hProcess = Дескриптор главного потока созданного процесса
	WaitForSingleObject(pi.hProcess, INFINITE);

	GetSystemTime(&Time);
	printf("Время выполнения программы после третьей пары процессов: минуты:секунды:миллисекунды -> %02d:%02d:%03d \n\n",
    	Time.wMinute, Time.wSecond, Time.wMilliseconds);

	system("pause");
	
	return 0;
}