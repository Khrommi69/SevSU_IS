#ifndef TEST_WORKWITHTABLE_H
#define TEST_WORKWITHTABLE_H

#include "structures.h"
#include "specialFunctions.h"
#include "setData.h"

//==============================================================================
//                            "ГЛАВНЫЕ" ФУНКЦИИ
//                                ПРОТОТИПЫ
//==============================================================================

Info setInfo(Element *head); // Ввод информации
void addNewElement(Element **head, Info info); // Добавить элемент в таблицу
int getNumElements(Element *head); // Взять количество элементов таблицы
void showTable(Element *head); // Демонстрация таблицы
Element *selectElement(Element *head); // Вернуть указатель на выбранный элемент
void correctRecord(Element *elem); // Выбрать и скорректировать запись
void deleteElement(Element **head); // Удалить элемент в таблице
void deleteTable(Element **head); // Удалить все элементы таблицы
Element *searchElement(Element *head); // Ищем элемент по номеру чека
void showOneElement(Element *head); // Вывести инфу об одном элементе
void sortTableAscending(Element **head); // Сортируем таблицу по возрастанию (1..2..3..4....)
void sortTableDescending(Element **head); // Сортируем таблицу по убыванию (....69..54..3..1)
void determineTurnoverForEachStore(Element *head); // Определить товарооборот для каждого магазина

#endif //TEST_WORKWITHTABLE_H