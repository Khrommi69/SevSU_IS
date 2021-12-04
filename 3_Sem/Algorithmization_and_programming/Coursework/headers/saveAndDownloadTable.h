#ifndef TEST_SAVEANDDOWNLOADTABLE_H
#define TEST_SAVEANDDOWNLOADTABLE_H

#include "structures.h"
#include "specialFunctions.h"
#include "setData.h"
#include "workWithTable.h"

//==============================================================================
//                    ФУНКЦИИ СОХРАНЕНИЯ И ЗАГРУЗКИ ТАБЛИЦЫ
//                                ПРОТОТИПЫ
//==============================================================================

void readTable(Element **head); // Считать таблицу из файла
void saveTable(Element *head); // Сохранить таблицу в файл

void readTableBIN(Element **head); // Считать таблицу из бинарного файла
void saveTableBIN(Element *head); // Сохранить таблицу в бинарный файл

void autoDownloudTableBin(Element **head); //Автоматическая загрузка последнего сохранения в формате .bin (типизированный файл)
void autoSaveTableBin(Element *head); //Автоматическое сохранение таблицы в формате .bin (типизированный файл)

#endif //TEST_SAVEANDDOWNLOADTABLE_H