#include <stdio.h>
#include <windows.h>
#include <string.h>

int main(int argc, char *argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	for(int i = 0; i < 3; i++) {
		
	}


	// // Если в качестве аргумента командной строки передовалось что то, то то-то...
	// char cmd[256];
	// if (argc!=1) {
	// 	strcpy(cmd, argv[1]);
	// } else {
	// 	strcpy(cmd, "sort.exe");
	// }
	
	// int procId = GetCurrentProcessId(); // Взять идентификатор вызывающего процесса
	// sprintf(cmd+strlen(cmd), " %d", procId); // cmd+идентификатор
	// printf("Мастер стартует: %s\n", cmd);
	// fflush(stdout); // Очистить буфер вывода
	
	// STARTUPINFO strtpinfo; // Информация о запуске процесса
	// memset(&strtpinfo, 0, sizeof(strtpinfo)); // Заполнить весь strtpinfo нулями
	// strtpinfo.cb = sizeof(strtpinfo); // Размер структуры strtpinfo = размер стуркуты strtpinfo
	
	// PROCESS_INFORMATION procinfo; // Возвращаемые функцией дескрипторы и идентификаторы ID процесса и потока

	// if (!CreateProcess (NULL, 
	// 				   	cmd,
	// 				   	NULL,
	// 				   	NULL,
	// 				   	FALSE,
	// 				   	NORMAL_PRIORITY_CLASS,
	// 				   	NULL,
	// 				   	NULL,
	// 				   	&strtpinfo,
	// 				   	&procinfo)) 
	// {
	// 	printf("Master: Процесс Sort не запущен\n");
	// 	printf("Master: проверьте правильность укавзания имени процесса в коммандной строке\n");
	// }
	// WaitForSingleObject(process,INFINITE);
	
	
	// printf("\n\nЯ тут!\n\n");
	system("pause");
	
	return 0;
}
