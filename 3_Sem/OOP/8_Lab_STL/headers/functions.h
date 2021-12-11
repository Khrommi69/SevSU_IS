#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "structures.h"

//==============================================================================
//                                 ФУНКЦИИ
//                                ПРОТОТИПЫ
//==============================================================================

bool continueOrNot(); // Продолжить или нет?
Element setData(); // Ввод информации об одном студенте
void headerDataBase(); // Вывод шапки таблицы
void showStudent(std::deque<Element>::iterator i); // Показать информацию о студенте
void showDataBase(std::deque<Element> database); // Показать базу данных
void showSelectedGroup(std::deque<Element> database); // Показать студентов в выбранной группе
void averageScoreByGroup(std::deque<Element> database); // Средний балл по группам

#endif //TEST_FUNCTIONS_H