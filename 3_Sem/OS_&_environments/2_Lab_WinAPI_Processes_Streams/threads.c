// LPSECURITY_ATTRIBUTES lpThreadAttributes, //�������� �������
// DWORD dwStackSize, //������ ����� ������
// LPTHREAD_START_ROUTINE lpStartAddress, //������� ������
// LPVOID lpParameter, //�������� �������
// DWORD dwCreationFlags, //��������� ������
// LPDWORD lpThreadId; //������������� ������

#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

#define numElementsArray  (3800/50)


void setArray(int array[numElementsArray]) {
	for (int i = 0; i < numElementsArray; i++) {
	    	array[i] = rand()%10000;
	}
}


void sort(int array[numElementsArray]) {
	int max, j, i, temp;
	for (i = 0; i < numElementsArray-1; i++) {
		for (max = i, j = i+1; j < numElementsArray; j++) {
			if (array[j] > array[max]) {
				max = j;
			}
			temp = array[max];
			array[max] = array[i];
			array[i] = temp;
		}
	}
	printf(" ���������� �������� ");
}


void mass_print(int array[numElementsArray]) {
	for (int i = 0; i < numElementsArray; i++) {
	    	printf("%d ", array[i]);
	}
	printf("\n\n");
}


//==============================================================================
int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	DWORD ti1, ti2; //�������������� �������
    HANDLE th1, th2; //����������� �������


	int array[numElementsArray];
	setArray(array);

	th1 = CreateThread(NULL, 0, mass_print, &array, CREATE_SUSPENDED, &ti1); //CREATE_SUSPENDED - ������� ����������������
	th2 = CreateThread(NULL, 0, sort, &array, CREATE_SUSPENDED, &ti2); //CREATE_SUSPENDED - ������� ����������������

	SetThreadPriority(th1, THREAD_PRIORITY_TIME_CRITICAL); //������ �������
    SetThreadPriority(th2, THREAD_PRIORITY_LOWEST); //����������

    ResumeThread(th1);
    ResumeThread(th2);

    WaitForSingleObject(th1, INFINITE);
    WaitForSingleObject(th2, INFINITE);

	printf("\n\n");
	system("pause");
	return 0;
}