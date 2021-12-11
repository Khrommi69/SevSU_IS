#ifndef TEST_SAVEANDDOWNLOAD_H
#define TEST_SAVEANDDOWNLOAD_H

#include "structures.h"
#include "functions.h"

//==============================================================================
//                    ФУНКЦИИ СОХРАНЕНИЯ И ЗАГРУЗКИ ТАБЛИЦЫ
//                                ПРОТОТИПЫ
//==============================================================================

void saveDataBase(std::deque<Element> database); // Сохранить базу данных
std::deque<Element> downloadDataBase(std::deque<Element> database); // Загрузить базу данных

#endif //TEST_SAVEANDDOWNLOAD_H