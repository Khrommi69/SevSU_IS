// ��� �������
//typedef union _ULARGE_INTEGER {
//  struct {
//    DWORD LowPart;
//    DWORD HighPart;
//  } DUMMYSTRUCTNAME;
//  struct {
//    DWORD LowPart;
//    DWORD HighPart;
//  } u;
//  ULONGLONG QuadPart;
//} ULARGE_INTEGER;
//
//typedef struct _FILETIME {
//  DWORD dwLowDateTime;
//  DWORD dwHighDateTime;
//} FILETIME, *PFILETIME, *LPFILETIME;

#include <stdio.h>
#include <windows.h>

int main() {
	unsigned int kol = 100; //���-�� ����������
	unsigned int N = 3800; //���-�� ��������� �������
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	SYSTEMTIME Tstrt, Tend, st1, st2;
	// ������������� ����� ������ Tstrt ���������� ���������
    GetSystemTime(&Tstrt);
    // ������� �� ����� ����� Tstrt � ������� ������:�������:������������
    printf("����� ������ ���������� ���������: %d:%d:%d \n", Tstrt.wMinute, Tstrt.wSecond, Tstrt.wMilliseconds);
    // ������������� ������� ������ ������� t1
    st1 = Tstrt;

	int k=0;
	int i, arr[N], j, max, temp;
	
	for (; k<kol; k++){
		// ��������� ������ ����� ����� ���������� ������� �� ��������� 0-10000
	    srand(time(NULL));
	    for (i=0; i<N; i++) {
	    	arr[i] = rand()%10000;
		}
		
		// ������������� ������ (���������� ������� ������ �� ��������)
		for (i=0; i<N-1; i++) {
			for (max = i, j=i+1; j<N; j++) {
				if (arr[j] > arr[max]) {
					max = j;
				}
			temp = arr[max];
			arr[max] = arr[i];
			arr[i] = temp;
			}
		}
	}
	
	// ������������� ������� ������ ������� t2
	GetSystemTime(&st2);
	printf("����� ���������� ��������� ����� ����������: %d:%d:%d \n", st2.wMinute, st2.wSecond, st2.wMilliseconds);
	
	// ���������� ������� ����� ����� ����������: (t2-t1)/100 � ������� �� ����� � ��
	FILETIME ft1, ft2;
	ULARGE_INTEGER li1, li2, dif;
	// ������������� SystemTime -> FileTime
	SystemTimeToFileTime(&st1, &ft1);
	SystemTimeToFileTime(&st2, &ft2);
	// ������������� FileTime -> ULARGE_INTEGER
	li1.u.LowPart = ft1.dwLowDateTime;
	li1.u.HighPart = ft1.dwHighDateTime;
	li2.u.LowPart = ft2.dwLowDateTime;
	li2.u.HighPart = ft2.dwHighDateTime;
	// ��������� t2-t1 � ����� �� ���-�� ����������
	dif.QuadPart = (li2.QuadPart - li1.QuadPart)/kol;
	printf("��� ���-�� ��������� ������� = %d � ���-�� ���������� = %d:\n", kol, N);
	printf("������� ����� ���������� ����� ����������: %dms \n", dif.QuadPart/10000);
	
	// ������������� ����� ��������� Tend ���������� ��������� � ������� �� �����
	GetSystemTime(&Tend);
    printf("����� ��������� ���������� ���������: %d:%d:%d \n", Tend.wMinute, Tend.wSecond, Tend.wMilliseconds);
    
    printf("\n");
    system("pause");
    
	return 0;
}
