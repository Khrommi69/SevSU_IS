// ДЛЯ СПРАВКИ
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
	unsigned int kol = 100; //кол-во повторений
	unsigned int N = 3800; //кол-во элементов массива
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	SYSTEMTIME Tstrt, Tend, st1, st2;
	// Зафиксировать время начала Tstrt выполенени программы
    GetSystemTime(&Tstrt);
    // Вывести на экран время Tstrt в формате минуты:секунды:миллисекунды
    printf("Время начала выполнения программы: %d:%d:%d \n", Tstrt.wMinute, Tstrt.wSecond, Tstrt.wMilliseconds);
    // Зафиксировать текущий момент времени t1
    st1 = Tstrt;

	int k=0;
	int i, arr[N], j, max, temp;
	
	for (; k<kol; k++){
		// Заполнить массив целых чисел случайными числами из диапазона 0-10000
	    srand(time(NULL));
	    for (i=0; i<N; i++) {
	    	arr[i] = rand()%10000;
		}
		
		// Отсортировать массив (сортировка методом выбора по убыванию)
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
	
	// Зафиксировать текущий момент времени t2
	GetSystemTime(&st2);
	printf("Время выполнения программы после сортировок: %d:%d:%d \n", st2.wMinute, st2.wSecond, st2.wMilliseconds);
	
	// Определить среднее вермя одной сортировки: (t2-t1)/100 и вывести на экран в мс
	FILETIME ft1, ft2;
	ULARGE_INTEGER li1, li2, dif;
	// Преобразовать SystemTime -> FileTime
	SystemTimeToFileTime(&st1, &ft1);
	SystemTimeToFileTime(&st2, &ft2);
	// Преобразовать FileTime -> ULARGE_INTEGER
	li1.u.LowPart = ft1.dwLowDateTime;
	li1.u.HighPart = ft1.dwHighDateTime;
	li2.u.LowPart = ft2.dwLowDateTime;
	li2.u.HighPart = ft2.dwHighDateTime;
	// Вычитание t2-t1 и делим на кол-во сортировок
	dif.QuadPart = (li2.QuadPart - li1.QuadPart)/kol;
	printf("Для кол-ва элементов массива = %d и кол-ву сортировок = %d:\n", kol, N);
	printf("Среднее время выполнения одной сортировки: %dms \n", dif.QuadPart/10000);
	
	// Зафиксировать время окончания Tend выполнения программы и вывести на экран
	GetSystemTime(&Tend);
    printf("Время окончания выполнения программы: %d:%d:%d \n", Tend.wMinute, Tend.wSecond, Tend.wMilliseconds);
    
    printf("\n");
    system("pause");
    
	return 0;
}
