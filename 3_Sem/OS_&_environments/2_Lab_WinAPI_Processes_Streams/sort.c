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
#include <time.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	srand(time(0));

	unsigned int kolRepetitions = 100; //���-�� ����������
	unsigned int numElementsArray = 3800; //���-�� ��������� �������
	
	// ��������� ��������� � ������� ����� ������� ����� 0w0 !
	SYSTEMTIME TimeStart, TimeEnd, time1, time2;

	// ������������� ����� ������ ����������� ���������
    GetSystemTime(&TimeStart);

    // ������� �� ����� ����� Tstrt � ������� ������:�������:������������
    printf("����� ������ ���������� ���������: ������:�������:������������ -> %02d:%02d:%03d \n\n",
    	TimeStart.wMinute, TimeStart.wSecond, TimeStart.wMilliseconds);

    // ������������� ������� ������ ������� t1
    time1 = TimeStart;

	int array[numElementsArray];

	// ��� i �� 1 �� 100 ���������
	for (int i = 0; i < kolRepetitions; i++){
		// ��������� ������ ����� ����� ���������� ������� �� ��������� 0-10000
	    for (int j = 0; j < numElementsArray; j++) {
	    	array[j] = rand()%10000;
		}
		
		// ������������� ������ (���������� ��������� �� ��������)
		for(int i2 = 0; i2 < numElementsArray - 1; i2++) { 
			// ���������� ��� �������� ��������.
			for(int j = 0; j < numElementsArray - i2 - 1 ; j++) {  
				if(array[j] < array[j+1]) {
					int temp = array[j];
					array[j] = array[j+1] ;
					array[j+1] = temp; 
				}
	        }
		}

	}
	
	// ������������� ������� ������ ������� t2
	GetSystemTime(&time2);
	printf("����� ���������� ��������� ����� ����������: ������:�������:������������ -> %02d:%02d:%03d \n\n",
		time2.wMinute, time2.wSecond, time2.wMilliseconds);
	
	// ���������� ������� ����� ����� ����������: (t2-t1)/100 � ������� �� ����� � ��
	FILETIME fileTime1, fileTime2;
	ULARGE_INTEGER li1, li2, dif;
	// ������������� SystemTime -> FileTime
	SystemTimeToFileTime(&time1, &fileTime1);
	SystemTimeToFileTime(&time2, &fileTime2);
	// ������������� FileTime -> ULARGE_INTEGER
	li1.u.LowPart = fileTime1.dwLowDateTime;
	li1.u.HighPart = fileTime1.dwHighDateTime;
	li2.u.LowPart = fileTime2.dwLowDateTime;
	li2.u.HighPart = fileTime2.dwHighDateTime;
	// ��������� t2-t1 � ����� �� ���-�� ����������
	dif.QuadPart = (li2.QuadPart - li1.QuadPart) / 100;

	printf("��� ���-�� ��������� ������� = %d � ���-�� ���������� = %d:\n\n", kolRepetitions, numElementsArray);
	printf("������� ����� ���������� ����� ���������� = %03dms \n\n", dif.QuadPart/100);
	
	// ������������� ����� ��������� TimeEnd ���������� ��������� � ������� �� �����
	GetSystemTime(&TimeEnd);
    printf("����� ��������� ���������� ���������: ������:�������:������������ -> %02d:%02d:%03d \n\n",
    	TimeEnd.wMinute, TimeEnd.wSecond, TimeEnd.wMilliseconds);
    
    printf("\n");
    system("pause");
    
	return 0;
}