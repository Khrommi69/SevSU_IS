#include <stdio.h>
#include <windows.h>
#include <string.h>

int main(int argc, char *argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	for(int i = 0; i < 3; i++) {
		
	}


	// // ���� � �������� ��������� ��������� ������ ������������ ��� ��, �� ��-��...
	// char cmd[256];
	// if (argc!=1) {
	// 	strcpy(cmd, argv[1]);
	// } else {
	// 	strcpy(cmd, "sort.exe");
	// }
	
	// int procId = GetCurrentProcessId(); // ����� ������������� ����������� ��������
	// sprintf(cmd+strlen(cmd), " %d", procId); // cmd+�������������
	// printf("������ ��������: %s\n", cmd);
	// fflush(stdout); // �������� ����� ������
	
	// STARTUPINFO strtpinfo; // ���������� � ������� ��������
	// memset(&strtpinfo, 0, sizeof(strtpinfo)); // ��������� ���� strtpinfo ������
	// strtpinfo.cb = sizeof(strtpinfo); // ������ ��������� strtpinfo = ������ �������� strtpinfo
	
	// PROCESS_INFORMATION procinfo; // ������������ �������� ����������� � �������������� ID �������� � ������

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
	// 	printf("Master: ������� Sort �� �������\n");
	// 	printf("Master: ��������� ������������ ��������� ����� �������� � ���������� ������\n");
	// }
	// WaitForSingleObject(process,INFINITE);
	
	
	// printf("\n\n� ���!\n\n");
	system("pause");
	
	return 0;
}
