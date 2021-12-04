#ifndef TEST_SPECIALFUNCTIONS_H
#define TEST_SPECIALFUNCTIONS_H

#include "structures.h"

//==============================================================================
//                            СПЕЦИАЛЬНЫЕ ФУНКЦИИ
//                                ПРОТОТИПЫ
//==============================================================================

void gotoxy(int x, int y); // Установить координаты курсора
void setCursor(int i); // Показать/скрыть курсор
void showMenuItems(const char *menuItems[], const int NUM_MENU_ITEMS, const char *title); // Вывод пунктов меню
int menu(const char *menuItems[], int numPunct, const char *title); // Меню интерактивное
																	// Параметры: список пунктов, кол-во пунктов, заглавие меню
int yesOrNo(const char *title); // Вы уверены в своём выборе?


#endif //TEST_SPECIALFUNCTIONS_H