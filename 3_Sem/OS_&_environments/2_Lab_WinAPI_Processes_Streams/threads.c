// LPSECURITY_ATTRIBUTES lpThreadAttributes, //атрибуты доступа
// DWORD dwStackSize, //размер стека потока
// LPTHREAD_START_ROUTINE lpStartAddress, //функция потока
// LPVOID lpParameter, //параметр функции
// DWORD dwCreationFlags, //состояние потока
// LPDWORD lpThreadId; //идентификатор потока

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
	printf(" сортировка окончена ");
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

	DWORD ti1, ti2; //идентификаторы потоков
    HANDLE th1, th2; //дескрипторы потоков


	int array[numElementsArray];
	setArray(array);

	th1 = CreateThread(NULL, 0, mass_print, &array, CREATE_SUSPENDED, &ti1); //CREATE_SUSPENDED - создать приостановленный
	th2 = CreateThread(NULL, 0, sort, &array, CREATE_SUSPENDED, &ti2); //CREATE_SUSPENDED - создать приостановленный

	SetThreadPriority(th1, THREAD_PRIORITY_TIME_CRITICAL); //печать массива
    SetThreadPriority(th2, THREAD_PRIORITY_LOWEST); //сортировка

    ResumeThread(th1);
    ResumeThread(th2);

    WaitForSingleObject(th1, INFINITE);
    WaitForSingleObject(th2, INFINITE);

	printf("\n\n");
	system("pause");
	return 0;
}