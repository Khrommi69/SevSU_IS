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
#define PRODUCT_NAME_MAX_LEN 50 // ������������ ����� ������������ ������
#define PRODUCT_CODE_MAX_LEN 20 // ������������ ����� ���� ������ (�������)
#define RECEIPT_MAX_LEN 20      // ������������ ����� ����

//==============================================================================
//                                ���������
//==============================================================================
typedef struct when {
    UI day;
    UI month;
    UI year;
}When;

typedef struct info {
    UI num_shop;                                     // ����� ��������
    UI num_section;                                 // ����� ������
    char num_receipt[RECEIPT_MAX_LEN + 1];         // ����� ����
    char product_name[PRODUCT_NAME_MAX_LEN + 1];  // ������������ ������
    char product_code[PRODUCT_CODE_MAX_LEN + 1]; // ������� ������
    UL product_price;                           // ���� ������
    UI  product_quantity;                      // ���������� ������
    When date;                                // ���� �������
}Info;

typedef struct element {
    Info data; //������
    struct element *next;
    struct element *previous;
}Element;

#endif //TEST_STRUCTURES_H