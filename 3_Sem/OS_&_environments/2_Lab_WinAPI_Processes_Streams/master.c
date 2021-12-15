#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	SYSTEMTIME Time;
	printf("\nMASTER: ������������!\n\n");

	// ���� � �������� ��������� ��������� ������ ������������ ��� ��, �� ��-��...
	char cmd[256];
	if (argc!=1) {
		strcpy(cmd, argv[1]);
	} else {
		strcpy(cmd, "sort.exe");
	}
	
	int procId = GetCurrentProcessId(); // ����� ������������� ����������� ��������
	sprintf(cmd+strlen(cmd), " %d", procId); // cmd+�������������
	printf("������ ��������: %s\n", cmd);
	fflush(stdout); // �������� ����� ������
	Sleep(3000); //����� 3 ���

	STARTUPINFO si; // lpStartupInfo
	memset(&si, 0, sizeof(si)); // ���������� � info ������� ����� 0
	si.cb = sizeof(si); // ������ ���� ��������, ����� ������ ����� ��������

	PROCESS_INFORMATION pi; // lpProcessInformation

	//=============================================--1--=============================================

	si.lpTitle = "Process: 1.1; Prioritet: IDLE_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // ��� ����������
					   	cmd,   // ���������� ������
					   	NULL,  // �������� ������� ��������
					   	NULL,  // �������� ������� ������
					   	FALSE, // ������������ ������������ (�� �����������)
					   	CREATE_NEW_CONSOLE | IDLE_PRIORITY_CLASS, // ����� ����������
					   	NULL, // ��������� ����� ��������� ������������� ��������
					   	NULL, // ������� ����� ������������� �������� ����� ������������ ����������� ���������
					   	&si,
					   	&pi) ) {
		printf("Master: 1.1 ������� Sort �� �������\a\n");
	}

	si.lpTitle = "Process: 1.2; Prioritet: NORMAL_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // ��� ����������
					   	cmd,   // ���������� ������
					   	NULL,  // �������� ������� ��������
					   	NULL,  // �������� ������� ������
					   	FALSE, // ������������ ������������ (�� �����������)
					   	CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, // ����� ����������
					   	NULL, // ��������� ����� ��������� ������������� ��������
					   	NULL, // ������� ����� ������������� �������� ����� ������������ ����������� ���������
					   	&si,
					   	&pi) ) {
		printf("Master: 1.2 ������� Sort �� �������\a\n");
	}

	//pi->hProcess = ���������� �������� ������ ���������� ��������
	WaitForSingleObject(pi.hProcess, INFINITE);

	GetSystemTime(&Time);
	printf("����� ���������� ��������� ����� ������ ���� ���������: ������:�������:������������ -> %02d:%02d:%03d \n\n",
    	Time.wMinute, Time.wSecond, Time.wMilliseconds);

	//=============================================--2--=============================================

	si.lpTitle = "Process: 2.1; Prioritet: IDLE_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // ��� ����������
					   	cmd,   // ���������� ������
					   	NULL,  // �������� ������� ��������
					   	NULL,  // �������� ������� ������
					   	FALSE, // ������������ ������������ (�� �����������)
					   	CREATE_NEW_CONSOLE | IDLE_PRIORITY_CLASS, // ����� ����������
					   	NULL, // ��������� ����� ��������� ������������� ��������
					   	NULL, // ������� ����� ������������� �������� ����� ������������ ����������� ���������
					   	&si,
					   	&pi) ) {
		printf("Master: 2.1 ������� Sort �� �������\a\n");
	}

	si.lpTitle = "Process: 2.2; Prioritet: HIGH_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // ��� ����������
					   	cmd,   // ���������� ������
					   	NULL,  // �������� ������� ��������
					   	NULL,  // �������� ������� ������
					   	FALSE, // ������������ ������������ (�� �����������)
					   	CREATE_NEW_CONSOLE | HIGH_PRIORITY_CLASS, // ����� ����������
					   	NULL, // ��������� ����� ��������� ������������� ��������
					   	NULL, // ������� ����� ������������� �������� ����� ������������ ����������� ���������
					   	&si,
					   	&pi) ) {
		printf("Master: 2.2 ������� Sort �� �������\a\n");
	}

	//pi->hProcess = ���������� �������� ������ ���������� ��������
	WaitForSingleObject(pi.hProcess, INFINITE);

	GetSystemTime(&Time);
	printf("����� ���������� ��������� ����� ������ ���� ���������: ������:�������:������������ -> %02d:%02d:%03d \n\n",
    	Time.wMinute, Time.wSecond, Time.wMilliseconds);

	//=============================================--3--=============================================

	si.lpTitle = "Process: 3.1; Prioritet: NORMAL_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // ��� ����������
					   	cmd,   // ���������� ������
					   	NULL,  // �������� ������� ��������
					   	NULL,  // �������� ������� ������
					   	FALSE, // ������������ ������������ (�� �����������)
					   	CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, // ����� ����������
					   	NULL, // ��������� ����� ��������� ������������� ��������
					   	NULL, // ������� ����� ������������� �������� ����� ������������ ����������� ���������
					   	&si,
					   	&pi) ) {
		printf("Master: 3.1 ������� Sort �� �������\a\n");
	}

	si.lpTitle = "Process: 3.2; Prioritet: NORMAL_PRIORITY_CLASS";

	if (!CreateProcess (NULL,  // ��� ����������
					   	cmd,   // ���������� ������
					   	NULL,  // �������� ������� ��������
					   	NULL,  // �������� ������� ������
					   	FALSE, // ������������ ������������ (�� �����������)
					   	CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, // ����� ����������
					   	NULL, // ��������� ����� ��������� ������������� ��������
					   	NULL, // ������� ����� ������������� �������� ����� ������������ ����������� ���������
					   	&si,
					   	&pi) ) {
		printf("Master: 3.2 ������� Sort �� �������\a\n");
	}

	//pi->hProcess = ���������� �������� ������ ���������� ��������
	WaitForSingleObject(pi.hProcess, INFINITE);

	GetSystemTime(&Time);
	printf("����� ���������� ��������� ����� ������� ���� ���������: ������:�������:������������ -> %02d:%02d:%03d \n\n",
    	Time.wMinute, Time.wSecond, Time.wMilliseconds);

	system("pause");
	
	return 0;
}