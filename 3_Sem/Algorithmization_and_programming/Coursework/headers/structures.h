#ifndef TEST_STRUCTURES_H
#define TEST_STRUCTURES_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define SetBacklightYellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
#define SetBacklightOff SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176);
#define UI unsigned int
#define UL unsigned long
#define PRODUCT_NAME_MAX_LEN 50 // Максимальная длина наименования товара
#define PRODUCT_CODE_MAX_LEN 20 // Максимальная длина кода товара (артикул)
#define RECEIPT_MAX_LEN 20      // Максимальная длина чека

//==============================================================================
//                                СТРУКТУРЫ
//==============================================================================
typedef struct when {
    UI day;
    UI month;
    UI year;
}When;

typedef struct info {
    UI num_shop;                                     // Номер магазина
    UI num_section;                                 // Номер секции
    char num_receipt[RECEIPT_MAX_LEN + 1];         // Номер чека
    char product_name[PRODUCT_NAME_MAX_LEN + 1];  // Наименование товара
    char product_code[PRODUCT_CODE_MAX_LEN + 1]; // Артикул товара
    UL product_price;                           // Цена товара
    UI  product_quantity;                      // Количество товара
    When date;                                // Дата продажи
}Info;

typedef struct element {
    Info data; //данные
    struct element *next;
    struct element *previous;
}Element;

#endif //TEST_STRUCTURES_H