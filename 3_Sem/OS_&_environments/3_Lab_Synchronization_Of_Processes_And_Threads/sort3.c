//  << SORT3.c >>

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define N 95 // по варианту N = 95

//заполнить массив целыми числами из диапазона 0-100
void setArray(int *arr) {
	srand(time(NULL));
	for (int i = 0; i < N; i++)
        arr[i] = rand() % 101;
}

//отсортировать массив методом вставки по возрастанию
void sortArray(int *arr) {
	int counter = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i; (j > 0) && (arr[j-1] > arr[j]); j--) {
			counter++;
			int tmp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = tmp;
		}
	}
}

//вывести массив на экран
void showArray(int *arr, char const *string) {
	for (int i = 0; i < N; i++) {
		printf("%s: A[%2d] = %3d;\n", string, i+1, arr[i]);
	}
}

//=====MAIN=====
int main(int argc, char const *argv[]) {
	// если в качестве аргумента коммандной строки нет ничего то программа завершается
	if (argc != 2) return 1;

	//создаем массив целых чисел размером N (95)
	int arr[N];

	//заполнить массив целыми числами из диапазона 0-100
	setArray(arr);

	//отсортировать массив методом вставки по возрастанию
	sortArray(arr);

	//вывести массив на экран
	showArray(arr, argv[1]);

	// system("pause");
	return 0;
}