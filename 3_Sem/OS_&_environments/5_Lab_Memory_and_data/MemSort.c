#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MEMPAGE_COUNT 1
#define MEMPAGE_SIZE 4096
#define TOTAL_MEMSIZE ((MEMPAGE_COUNT) * (MEMPAGE_SIZE))

#define MAX 32767

typedef short arr_elem_t;

void sort(arr_elem_t *arrv, size_t arrc)
{
    int i, j, step;
    arr_elem_t tmp;
    for (step = arrc/2; step > 0; step /= 2)
        for (i = step; i < arrc; i++)
        {
            tmp = arrv[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arrv[j-step])
                    arrv[j] = arrv[j-step];
                else
                    break;
            }
            arrv[j] = tmp;
        }
}

int main()
{
    // Открытие мьютекса |5.2.2.1|
    HANDLE mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "My_mutex");
    WaitForSingleObject(mutex, INFINITE);

    // Открытие общей памяти и отображение её в программе |5.2.2.2|
    HANDLE shared_mem = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "memshare");
    arr_elem_t *arr = (arr_elem_t *) MapViewOfFile(shared_mem, FILE_MAP_ALL_ACCESS, 0, 0, TOTAL_MEMSIZE);

    // Сортировка данных в памяти общего доступа, методом Шелла |5.2.2.3|
    sort(arr, TOTAL_MEMSIZE / sizeof(arr_elem_t));

    ReleaseMutex(mutex);
    UnmapViewOfFile((LPVOID) arr);
    CloseHandle(shared_mem);

    return 0;
}