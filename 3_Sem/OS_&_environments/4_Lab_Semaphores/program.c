#include <stdio.h>
#include <windows.h>
#include <time.h>

#define N_buf 9
#define N     600

#define USE_SEMAPHORE

int arr[N_buf];
int max = 0;
int k = 0;

DWORD WINAPI Generate_numbers_and_put_to_buffer (LPVOID p) {
    InitializeCriticalSection;

    #ifdef USE_SEMAPHORE
        HANDLE sem[3];
        sem[0] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "MySem_Free");
        sem[1] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "MySem_Full");
        sem[2] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "MySem_Bool");
    #endif

    srand(time(NULL));
    int random_num = rand()%399;

    for (int i = 0; i < N; i++) {
        #ifdef USE_SEMAPHORE
            WaitForSingleObject(sem[0], INFINITE);
            WaitForSingleObject(sem[2], INFINITE);
        #endif

        arr[i % N_buf] = random_num + i;
        k++;
        if (k>max) max = k;

        #ifdef USE_SEMAPHORE
            ReleaseSemaphore(sem[1], 1, NULL);
            ReleaseSemaphore(sem[2], 1, NULL);
        #endif
    }

}

DWORD WINAPI Read_data_and_show_on_the_screen (LPVOID p) {
    
    #ifdef USE_SEMAPHORE
        HANDLE sem[3];
        sem[0] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "MySem_Free");
        sem[1] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "MySem_Full");
        sem[2] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "MySem_Bool");
    #endif

    for (int i = 0; i < N; i++) {
        #ifdef USE_SEMAPHORE
            WaitForSingleObject(sem[1], INFINITE);
            WaitForSingleObject(sem[2], INFINITE);
        #endif

        printf ("%d    ", arr[i % N_buf]);
        k--;
        if (k>max) max = k;

        #ifdef USE_SEMAPHORE
            ReleaseSemaphore(sem[0], 1, NULL);
            ReleaseSemaphore(sem[2], 1, NULL);
        #endif
    }
    printf ("\n");

}

int main() {

    HANDLE th[2], sem[3];

    #ifdef USE_SEMAPHORE
        sem[0] = CreateSemaphore(NULL, N_buf, N_buf, "MySem_Free");
        sem[1] = CreateSemaphore(NULL, 0,     N_buf, "MySem_Full");
        sem[2] = CreateSemaphore(NULL, 1,     1,     "MySem_Bool");
    #endif

    // 1 НАПИСАТЬ ПРОГРАММУ, СОДЕРЖАЩУЮ ДВА ПОТОКА

    // CreateThread(дескриптор защиты, начальный размер стека, функция потока, параметр потока, флаги создания, идентификатор потока);
    // При успехе вернет дескриптор нового потока, в противном случае NULL

    // Первый поток генерирует последовательность чисел и помещает их в кольцевой* буфер из Nbuf элементов (с
    // проверкой на свободное место в буфере с использованием механизма семафоров)
    th[0] = CreateThread(NULL, 0, Generate_numbers_and_put_to_buffer, NULL, CREATE_SUSPENDED, NULL);
    // Второй считывает данные из буфера и выводит их на экран
    th[1] = CreateThread(NULL, 0, Read_data_and_show_on_the_screen, NULL, CREATE_SUSPENDED, NULL);

    SetThreadPriority(th[1], THREAD_PRIORITY_TIME_CRITICAL);
    SetThreadPriority(th[0], THREAD_PRIORITY_LOWEST);

    ResumeThread(th[0]);
    ResumeThread(th[1]);

    // Ждать завершения работы этих потоков
    WaitForMultipleObjects(2, th, TRUE, INFINITE);

    #ifdef USE_SEMAPHORE
        // Закрыть дескрипторы семафоров
        for (int i = 0; i < 3; i++)
            CloseHandle(sem[i]);
    #endif

        printf ("\n\n max = %d \n", max);

    system("pause");
    return 0;
}