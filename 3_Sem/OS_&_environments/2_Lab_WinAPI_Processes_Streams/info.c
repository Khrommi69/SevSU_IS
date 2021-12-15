������� � ��� ������� �������� ���������
����� � ������� ��������������� � ������������� ������������� �������

� �� Windows ���������� ��������� ������ ����������� ���������:
HIGH_PRIORITY_CLASS - 2
IDLE_PRIORITY_CLASS - 4
NORMAL_PRIORITY_CLASS - 3 - (�� �����, ���� �������� �� (4))
REALTIME_PRIORITY_CLASS - 1 ����� ������� ��������� ���������

� �������� ���� ������������� � ���������� (���������� ��� ���������� ��������� �� ������� ��������)

� ������� ��������� ������� WaitForSingleObject ����� ���������� ��������� �������� ��������
�������� ���������� WaitForSingleObject � ����������, ��������� �� ���������� ������������� ���������� ������� � ���������� ���������.
���������� �������� ��������� � ���������� ��������� �����, ����� ������� ��������� ���� ������.
WaitForSingleObject(���������� ������� ����,  ����� ��������);

BOOL WINAPI CreateProcessW( LPCWSTR lpApplicationName  -  ��� ����������,
							LPWSTR lpCommandLine  -  ��������� ������,
							LPSECURITY_ATTRIBUTES lpProcessAttributes  -  �������� ������� ��������,
							LPSECURITY_ATTRIBUTES lpThreadAttributes  -  �������� ������� ������,
							BOOL bInheritHandles  -  ������������ ������������,
							DWORD dwCreationFlags  -  �����,
							LPVOID lpEnvironment  -  ��������� �����,
							LPCWSTR lpCurrentDirectory  -  ������� ����� ��������,
							LPSTARTUPINFO lpStartupInfo  -  ��������� ��������� �����,
							LPPROCESS_INFORMATION lpProcessInformation  -  ������������ ��������
							);

LPCWSTR �������� "������� ��������� �� ���������� ������"
LPWSTR � ��������� �� UNICODE ������

LPSECURITY_ATTRIBUTES - ��� ��������� �� ��������� SECURITY_ATTRIBUTES
typedef struct _SECURITY_ATTRIBUTES {
	DWORD  nLength;              // ����� ������, � ������, ���� ���������
	LPVOID lpSecurityDescriptor; // ��������� �� ���������� ������������ ��� ������� ��������������� ���������� ��� �������������.
	                             // ���� NULL, �� � �������� ����� ������ ���������� ������������ �� ��������� ����������� ��������.
	BOOL   bInheritHandle;       // ����������, ����� �� ������������ ���������� ������������� ��� �������� ������ ��������.
	                             // ���� ����� TRUE, ����� ������� ��������� ����������.
} SECURITY_ATTRIBUTES;

DWORD � 32-������ ����������� �����. �������: unsigned long int...
LPVOID - ��� ���������. ��� ���� ��� ��������� (P �� Pointer) �� ��� ������ (VOID), �� ��� � ������� (L - �� Long)

��������� �� ��������� SECURITY_ATTRIBUTES ������������ ��� �������� � ����������� ������� ���� � ���������� ������ Win32 API,
������� ���������� ���������� �������.

LpStartupInfo � ��������� �� ��������� STARTUPINFO, ������� ������������� ������� ����� ���������, ������� ����,
����������� ����������� � ������� ��� �������� ���� ��� ������ ��������.

LPPROCESS_INFORMATION lpProcessInformation � ���������, ���������� ������ � �������� �������� � �������: struct PROCESS_INFORMATION
��������� PROCESS_INFORMATION �������� ���������� � ����� ��������� �������� � ��� ������ ��� ������ ������� CreateProcess
typedef struct _PROCESS_INFORMATION {
	HANDLE hProcess;    // ���������� ���������� ��������
	HANDLE hThread;     // ���������� �������� ������ ���������� ��������
	DWORD  dwProcessId; // ������������� ��������
	DWORD  dwThreadId;  // ������������� ������
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;


���� ������ ����� ��������� lpApplicationName ������ NULL, ��� ������
��������� ����� ���������� ������ ���, ������� � ��������� ������
lpCommandLine. ���� ������� ����������������, ���������, ��-������, � �����
���������� ������������� ����������� ���������� "���"

���� ��������� lpProcessAttributes � lpThreadAttributes ����������� � NULL,
������������ ������� ����� �������

������ �������� ������� � ������� ��������� ��������� dwCreationFlags,
��� �������� "����������" ����� ���������� ��������, �� ��� ������� ������
�������� ����� �����, ��������, ��������� ������� � ���������� ������ ���
�� ������ ����� ���������� ��������.

�������� lpEnvironment � ��������� �� ����� � ����������� �����; ���� ����
�������� ����� NULL, ����������� ������� ��������� ����� ��������� ������������� ��������

���� �������� lpCurrentDirectory ���������� � NULL, �� ������� ����� ������������� ��������
����� ������������ ����������� ���������.

�������� lpStartupInfo � ��������� �� ��������� STARTUPINFO, ���� �������
���������� ����� �������� ������ ��������
struct STARTUPINFO {
	DWORD cb; //������ ���������
	LPSTR lpReserved; //NULL
	LPSTR lpDesktop; //��� "�������� �����"
	LPSTR lpTitle; //��������� �������
	DWORD dwX; //����� ������� ����
	DWORD dwY; //������ ����
	DWORD dwXSize; //������ ������ ����������� ����
	DWORD dwYSize; //������ ������ ����������� ����
	DWORD dwXCountChars; //������ ������
	DWORD dwYCountChars; // �������
	DWORD dwFillAttribute; //���� ������ (� ���������� ����������)
	DWORD dwFlags; //���� ���������� ����������� ����
	WORD wShowWindow; //������ ����������� ����
	WORD cbReserved2; //NULL
	LPBYTE lpReserved2; //NULL
	HANDLE hStdInput; //����������� �����������
	HANDLE hStdOutput; //������� �����/������
	HANDLE hStdError; //������ ������
};

LPSTR. ��������� �� ������, ������������� ����� ��� 8-��������� Windows (ANSI) ��������
LPBYTE-��� ��������� �� ������ ������.
HANDLE - ����������, �.�. �����, � ������� �������� ����� ���������������� ������.

���� dwFlags ������ ������������� � STARTF_USESHOWWINDOW, ��� ���������
������ ������ ����������� ����. �������� SW_SHOWNORMAL � ���� wShowWindow
��������� Windows �������������� ���������� ������ � ��������� ������������ ����, � SW_SHOWMINIMIZED ��������, ��� ���������� ����������� � "���������" ����

lpProcessInformation � ��������� �� ���������
PROCESS_INFORMATION, � ������� ������������ �������� ����������� � �������������� ������������ �������� � ������:
struct PROCESS_INFORMATION {
	HANDLE hProcess; //���������� ������ ��������
	HANDLE hThread; //���������� �������� ������
	DWORD dwProcessId; //������������� ������ ��������
	DWORD dwThreadId; //������������� �������� ������
};

������������� ��������� �������:
BOOL WINAPI TerminateProcess(HANDLE hProcess, UINT fuExitCode);
� �������� ������� ��������� ���� ������� ������������ ���������� ��������,
������� ������������ � ���� hProcess ��������� PROCESS_INFORMATION. ������
�������� fuExitCode � ��� ��������.

������� ����� ���� �������� � "�������" ������� ������� ExitProcess():
VOID WINAPI ExitProcess(UINT fuExitCode);

int procId = GetCurrentProcessId(); // ����� ������������� ����������� ��������


//====================================================================================================================================

��� �������� ������ ������������ ������� CreateThread():
HANDLE WINAPI CreateThread(
LPSECURITY_ATTRIBUTES lpThreadAttributes, //�������� �������
DWORD dwStackSize, //������ ����� ������
LPTHREAD_START_ROUTINE lpStartAddress, //������� ������
LPVOID lpParameter, //�������� �������
DWORD dwCreationFlags, //��������� ������
LPDWORD lpThreadId); //������������� ������

��� ���������� ���������� ������ ����� ����� ������� ������� ExitThread():
VOID WINAPI ExitThread(DWORD dwExitCode);

����� ����������� ����� ����� ��������� THREAD_PRIORITY_NORMAL.
��������� ������� GetThreadPriority � SetThreadPriority ����� �������� �������
� ���������� ��������� ��������� ���������� ������

THREAD_PRIORITY_NORMAL 0
THREAD_PRIORITY_ABOVE_NORMAL +1
THREAD_PRIORITY_BELOW_NORMAL -1
THREAD_PRIORITY_HIGHEST +2
THREAD_PRIORITY_LOWEST -2
THREAD_PRIORITY_IDLE
"������������� ������� ������� ���������� ������ ������ 1 ��� ������� ���������� ��������: IDLE_PRIORITY_CLASS,
NORMAL_PRIORITY_CLASS, ��� HIGH_PRIORITY_CLASS, � ������� �������
���������� ������ 16 ��� ������ ���������� �������� REALTIME_PRIORITY_CLASS"
THREAD_PRIORITY_TIME_CRITICAL
"������������� ������� �������
���������� ������ 15 ��� ������� ���������� ��������: IDLE_PRIORITY_CLASS,
NORMAL_PRIORITY_CLASS, ��� HIGH_PRIORITY_CLASS, � ������� ������� ���������� ������ 31 ��� ������ ���������� �������� REALTIME_PRIORITY_CLASS"