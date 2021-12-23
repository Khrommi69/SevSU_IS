//  << MASTER3_mtx.c >>

#include <stdio.h>
#include <windows.h>

#define COL_PRC 3 //кол-во создаваемых процессов по варианту

int main(int argc, char const *argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Создать 3 процесса Sort3 передавая в качестве параметра
	// командной строки номер процесса – N_PRC
	// Необходимо, чтобы все процессы использовали одну консоль
	// и имели класс приоритета NORMAL_PRIORITY_CLASS

	char cmd[255];

	STARTUPINFO s[COL_PRC];
	PROCESS_INFORMATION p[COL_PRC];
	
	memset(&s, 0, sizeof(s));
    memset(&p, 0, sizeof(p));

	HANDLE mtx = CreateMutex(NULL, TRUE, "MyMutexSort");  //+

    for (int i = 0; i < COL_PRC; i++) {
        s[i].cb = sizeof(STARTUPINFO); // должно быть записано, какой размер имеет стуктура
        s[i].lpTitle = calloc(sizeof(char), sprintf(cmd, "Proc%d", i + 1));
        strcpy(s[i].lpTitle, cmd);
    }

    for (int i = 0; i < COL_PRC; i++) {
    	sprintf(cmd, ".\\sort3_mtx.exe Proc_%d", i+1);
		if (!CreateProcess (NULL,  // имя приложения
						   	cmd,   // коммандная строка
						   	NULL,  // атрибуты доступа процесса
						   	NULL,  // атрибуты доступа потока
						   	FALSE, // наследование дескрипторов (не наследовать)
						   	NORMAL_PRIORITY_CLASS, // класс приоритета
						   	NULL, // наследует среду окружения родительского процесса
						   	NULL, // текущая папка родительского процесса будет унаследована порождаемым процессом
						   	&s[i],
						   	&p[i]) ) {
			printf("Master: %d Процесс Sort не запущен\a\n", i+1);
		}
	}

	ReleaseMutex(mtx); //+
    WaitForSingleObject(p[0].hProcess, INFINITE);
    WaitForSingleObject(p[1].hProcess, INFINITE);
    WaitForSingleObject(p[2].hProcess, INFINITE);

    CloseHandle(mtx); //+
    
	system("pause");
	return 0;
}