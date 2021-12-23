//  << MASTER3_mtx.c >>

#include <stdio.h>
#include <windows.h>

#define COL_PRC 3 //���-�� ����������� ��������� �� ��������

int main(int argc, char const *argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������� 3 �������� Sort3 ��������� � �������� ���������
	// ��������� ������ ����� �������� � N_PRC
	// ����������, ����� ��� �������� ������������ ���� �������
	// � ����� ����� ���������� NORMAL_PRIORITY_CLASS

	char cmd[255];

	STARTUPINFO s[COL_PRC];
	PROCESS_INFORMATION p[COL_PRC];
	
	memset(&s, 0, sizeof(s));
    memset(&p, 0, sizeof(p));

	HANDLE mtx = CreateMutex(NULL, TRUE, "MyMutexSort");  //+

    for (int i = 0; i < COL_PRC; i++) {
        s[i].cb = sizeof(STARTUPINFO); // ������ ���� ��������, ����� ������ ����� ��������
        s[i].lpTitle = calloc(sizeof(char), sprintf(cmd, "Proc%d", i + 1));
        strcpy(s[i].lpTitle, cmd);
    }

    for (int i = 0; i < COL_PRC; i++) {
    	sprintf(cmd, ".\\sort3_mtx.exe Proc_%d", i+1);
		if (!CreateProcess (NULL,  // ��� ����������
						   	cmd,   // ���������� ������
						   	NULL,  // �������� ������� ��������
						   	NULL,  // �������� ������� ������
						   	FALSE, // ������������ ������������ (�� �����������)
						   	NORMAL_PRIORITY_CLASS, // ����� ����������
						   	NULL, // ��������� ����� ��������� ������������� ��������
						   	NULL, // ������� ����� ������������� �������� ����� ������������ ����������� ���������
						   	&s[i],
						   	&p[i]) ) {
			printf("Master: %d ������� Sort �� �������\a\n", i+1);
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