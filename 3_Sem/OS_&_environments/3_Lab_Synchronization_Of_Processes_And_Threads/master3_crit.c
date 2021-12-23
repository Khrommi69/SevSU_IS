//мьютексы и крит.секции нужны для синхронизации потоков (и процессов - мьютексы)

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define N 95 // по варианту N = 95
#define COL_THREAD 3 //кол-во создаваемых потоков по варианту

CRITICAL_SECTION c = { 0 }; //Критическая секция

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



DWORD WINAPI Sort (LPVOID p) {
    int arr[N];
    setArray(arr);
    sortArray(arr);

    EnterCriticalSection(&c);

    showArray(arr, (char *) p);

    LeaveCriticalSection(&c);

    return 0;
}


int main () {
    char tmp[COL_THREAD][1024];
    DWORD th[COL_THREAD];
    HANDLE hth[COL_THREAD];

    InitializeCriticalSection(&c);

    for (int i = 0; i < COL_THREAD; i++) {
        sprintf(tmp[i], "Thr%d", i + 1);
        hth[i] = CreateThread(NULL, 0, Sort, (LPVOID) (tmp + i), CREATE_SUSPENDED, &th[i]);
    }

    for (int i = 0; i < COL_THREAD; i++) ResumeThread(hth[i]);

    WaitForMultipleObjects(COL_THREAD, hth, TRUE, INFINITE); //ожидаем все потоки

    DeleteCriticalSection(&c);

    system("pause");
    return 0;
}