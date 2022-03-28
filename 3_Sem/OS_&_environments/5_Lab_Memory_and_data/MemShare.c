#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MEMPAGE_COUNT 1
#define MEMPAGE_SIZE 4096
#define TOTAL_MEMSIZE ((MEMPAGE_COUNT) * (MEMPAGE_SIZE))

#define MAX 32767

typedef short arr_elem_t;

/* Заполнить массив случайными данными */
void fill_array (arr_elem_t * arrv, size_t arrc)
{
    for (size_t i = 0; i < arrc; i++)
        arrv[i] = rand() % MAX;
}

int main()
{
	// Создание Мютекса и Процесса |5.2.1.1|
	// CreateMutex(Атрибут безопасности, флаг начального владельца, имя объекта)
    HANDLE mutex = CreateMutex(NULL, TRUE, "My_mutex");
    STARTUPINFO si; PROCESS_INFORMATION pi;
    memset(&si, 0, sizeof(STARTUPINFO)); memset(&pi, 0, sizeof(PROCESS_INFORMATION));
    si.cb = sizeof(STARTUPINFO); si.lpTitle = "MemSorter";
    // CreateProcess(имя приложения, командная строка, атрибуты доступа процесса, атрибуты доступа потока, наследование дескрипторов,
    // флаги, параметры среды, текущая папка процесса, структура стартовых полей, возвращаемые значения
    CreateProcess(NULL, "MemSort.exe", 0, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

    // Выделение участка виртуальной памяти |5.2.1.2|
    DWORD old_sec_attrs;
    // VirtualAlloc(адрес области памяти, необходимый размер, режим выделения, уровень защиты)
    // Если в качестве первого аргумента функции передать значение NULL, то ОС
	// самостоятельно определит подходящий адрес выделяемой области.
    // Если необходимо выделить (а не просто зарезервировать) память, в качестве третьего
    // аргумента необходимо указатьзначение МЕМ_СОММIТ
    LPVOID base_address = VirtualAlloc(NULL, TOTAL_MEMSIZE, MEM_COMMIT, PAGE_READWRITE);
    arr_elem_t *arr = (arr_elem_t *) base_address;

	// Заполнение памяти |5.2.1.3|
    fill_array (arr, TOTAL_MEMSIZE / sizeof(arr_elem_t));

    // Изменение прав доступа к памяти |5.2.1.4|
    // VirtualProtect(начальный адресс, размер памяти, новые атрибуты, старые атрибуты безопасности)
    VirtualProtect(base_address, TOTAL_MEMSIZE, PAGE_READONLY, &old_sec_attrs);

	// Создание памяти общего доступа |5.2.1.5|
	// CreateFileMapping(дескриптор файла, структура атрибутов безопасности, устанавливает защиту, старшие 32 бита
	// 64-битного размера файла, младшие 32 бита 64-битного размера файла, имя объекта отображения файла на память);
    HANDLE file_map = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, TOTAL_MEMSIZE, "memshare");
    // Отображение файла в адресное пространство программы
    // MapViewOfFile(дескриптор объекта отображения файла на память, тип доступа, старшие 32 бита 64-битной стартовой позиции
    // младшие 32 бита 64-битной стартовой позиции, количество байт, которое следует отобразить);
    LPVOID view = MapViewOfFile(file_map, FILE_MAP_ALL_ACCESS, 0, 0, TOTAL_MEMSIZE);

    // Копирование в файл из Виртуальной памяти |5.2.1.6|
    // CopyMemory(указатель на адрес памяти для использования, указатель на адрес памяти из которого
    // будут копироваться данные, число копируемых байтов)
    CopyMemory(view, base_address, TOTAL_MEMSIZE);

    // Освобождение мьютекса и ожидание завершения процесса |5.2.1.7|
    ReleaseMutex(mutex);
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Изменение прав доступа к памяти |5.2.1.8|
    // VirtualProtect(начальный адресс, размер памяти, новые атрибуты, старые атрибуты безопасности)
    VirtualProtect(base_address, TOTAL_MEMSIZE, PAGE_READWRITE, &old_sec_attrs);

    // Копирование данных из памяти общего доступа в память, выделенную с помощью VirtualAlloc |5.2.1.9|
    // CopyMemory(base_address, view, TOTAL_MEMSIZE);

    // Печать данных на экран |5.2.1.10|
    for (size_t i = 0; i < TOTAL_MEMSIZE / sizeof(arr_elem_t); i++)
        printf("%d ", (int) arr[i]);
    printf("\r\n");

    // Освобождение памяти и Выход |5.2.1.11 & 5.2.1.12|
    VirtualFree(base_address, TOTAL_MEMSIZE, MEM_RELEASE);
    UnmapViewOfFile(view);
    CloseHandle(file_map);
    
    system("pause");
	return 0;
}