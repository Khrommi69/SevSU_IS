#include <stdio.h>
#include <windows.h>
#include <time.h>

#define N_buf 9
#define N     600

#define USE_SEMAPHORE

int arr[N_buf];

DWORD WINAPI Generate_numbers_and_put_to_buffer (LPVOID p) {

    #ifdef USE_SEMAPHORE
        HANDLE sem;
        sem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "My_Semen");
    #endif

    srand(time(NULL));
    int random_num = rand()%399;

    for (int i = 0; i < N; i++) {
        #ifdef USE_SEMAPHORE
            WaitForSingleObject(sem, INFINITE);
        #endif
        arr[i % N_buf] = random_num + i;
    }

}

DWORD WINAPI Read_data_and_show_on_the_screen (LPVOID p) {
    
    #ifdef USE_SEMAPHORE
        HANDLE sem;
        sem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "My_Semen");
    #endif

    for (int i = 0; i < N; i++) {
        printf ("%d    ", arr[i % N_buf]);
        #ifdef USE_SEMAPHORE
            ReleaseSemaphore(sem, 1, NULL);
        #endif
        if ((i % N_buf) == 8) {
            printf ("\n");
            Sleep(40);
        }
    }
    printf ("\n");

}

int main() {

    HANDLE th[2], sem;

    #ifdef USE_SEMAPHORE
        sem = CreateSemaphore(NULL, N_buf, N_buf, "My_Semen");
    #endif

    // 1 НАПИСАТЬ ПРОГРАММУ, СОДЕРЖАЩУЮ ДВА ПОТОКА

    // CreateThread(дескриптор защиты, начальный размер стека, функция потока, параметр потока, флаги создания, идентификатор потока);
    // При успехе вернет дескриптор нового потока, в противном случае NULL

    // Первый поток генерирует последовательность чисел и помещает их в кольцевой* буфер из Nbuf элементов (с
    // проверкой на свободное место в буфере с использованием механизма семафоров)
    th[0] = CreateThread(NULL, 0, Generate_numbers_and_put_to_buffer, NULL, 0, NULL);
    // Второй считывает данные из буфера и выводит их на экран
    th[1] = CreateThread(NULL, 0, Read_data_and_show_on_the_screen, NULL, 0, NULL);

    // Ждать завершения работы этих потоков
    WaitForMultipleObjects(2, th, TRUE, INFINITE);

    #ifdef USE_SEMAPHORE
        // Закрыть дескрипторы семафоров
        CloseHandle(sem);
    #endif

    system("pause");
    return 0;
}