#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	srand(time(0));

	unsigned int kolRepetitions = 100; //кол-во повторений
	unsigned int numElementsArray = 3800; //кол-во элементов массива
	
	// объявляем перменные в которых будем хранить время 0w0 !
	SYSTEMTIME TimeStart, TimeEnd, time1, time2;

	// Зафиксировать время начала выполенения программы
    GetSystemTime(&TimeStart);

    // Вывести на экран время Tstrt в формате минуты:секунды:миллисекунды
    printf("Время начала выполнения программы: минуты:секунды:миллисекунды -> %02d:%02d:%03d \n\n",
    	TimeStart.wMinute, TimeStart.wSecond, TimeStart.wMilliseconds);

    // Зафиксировать текущий момент времени t1
    time1 = TimeStart;

	int array[numElementsArray];

	// Для i от 1 до 100 повторять
	int i, i2, j, temp;
	for (i = 0; i < kolRepetitions; i++){
		// Заполнить массив целых чисел случайными числами из диапазона 0-10000
	    for (j = 0; j < numElementsArray; j++) {
	    	array[j] = rand()%10000;
		}
		
		// Отсортировать массив (сортировка Выбора по убыванию)
		int max;
		for (i2 = 0; i2 < numElementsArray-1; i2++) {
			for (max = i2, j = i2+1; j < numElementsArray; j++) {
				if (array[j] > array[max]) {
					max = j;
				}
				temp = array[max];
				array[max] = array[i2];
				array[i2] = temp;
			}
		}
	}
	
	// Зафиксировать текущий момент времени t2
	GetSystemTime(&time2);
	printf("Время выполнения программы после сортировок: минуты:секунды:миллисекунды -> %02d:%02d:%03d \n\n",
		time2.wMinute, time2.wSecond, time2.wMilliseconds);
	
	// Определить среднее вермя одной сортировки: (t2-t1)/100 и вывести на экран в мс
	FILETIME fileTime1, fileTime2;
	ULARGE_INTEGER li1, li2, dif;
	// Преобразовать SystemTime -> FileTime
	SystemTimeToFileTime(&time1, &fileTime1);
	SystemTimeToFileTime(&time2, &fileTime2);
	// Преобразовать FileTime -> ULARGE_INTEGER
	li1.u.LowPart = fileTime1.dwLowDateTime;
	li1.u.HighPart = fileTime1.dwHighDateTime;
	li2.u.LowPart = fileTime2.dwLowDateTime;
	li2.u.HighPart = fileTime2.dwHighDateTime;
	// Вычитание t2-t1 и делим на кол-во сортировок
	dif.QuadPart = (li2.QuadPart - li1.QuadPart) / 100;

	printf("Для кол-ва элементов массива = %d и кол-ву сортировок = %d:\n\n", kolRepetitions, numElementsArray);
	printf("среднее время выполнения одной сортировки = %03dms \n\n", dif.QuadPart/100);
	
	// Зафиксировать время окончания TimeEnd выполнения программы и вывести на экран
	GetSystemTime(&TimeEnd);
    printf("Время окончания выполнения программы: минуты:секунды:миллисекунды -> %02d:%02d:%03d \n\n",
    	TimeEnd.wMinute, TimeEnd.wSecond, TimeEnd.wMilliseconds);
    
    printf("\n\n");

    system("pause");
    
	return 0;
}