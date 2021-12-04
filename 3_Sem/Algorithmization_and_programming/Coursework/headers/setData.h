#ifndef TEST_SETDATA_H
#define TEST_SETDATA_H

#include "structures.h"
#include "specialFunctions.h"

//==============================================================================
//                        ФУНКЦИИ ВВОДА ДАННЫХ С ПРОВЕРКАМИ
//                                   ПРОТОТИПЫ
//==============================================================================

UI setNumShop(); // Ввод номера магазина
UI setNumSection(); // Ввод номера секции
int checkingForIdenticalReceipts(Element *head, char buf[25]); // Проверка наличия одинаковых чеков
void setNumReceipt(char *buf, Element *head); // Ввод номера чека
void setProductName(char *buf); // Ввод наименования продукта
void setProductCode(char *buf); // Ввод артикула продукта
UL setProductPrice(); // Ввод цены товара
UI setProductQuantity(); // Ввод количества продуктов
When setDate(); // Ввод даты: день/месяц/год


#endif //TEST_SETDATA_H