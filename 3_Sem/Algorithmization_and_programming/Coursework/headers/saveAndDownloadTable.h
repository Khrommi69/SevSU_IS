#ifndef TEST_SAVEANDDOWNLOADTABLE_H
#define TEST_SAVEANDDOWNLOADTABLE_H

#include "structures.h"
#include "specialFunctions.h"
#include "setData.h"
#include "workWithTable.h"

//==============================================================================
//                    ������� ���������� � �������� �������
//                                ���������
//==============================================================================

void readTable(Element **head); // ������� ������� �� �����
void saveTable(Element *head); // ��������� ������� � ����

void readTableBIN(Element **head); // ������� ������� �� ��������� �����
void saveTableBIN(Element *head); // ��������� ������� � �������� ����

void autoDownloudTableBin(Element **head); //�������������� �������� ���������� ���������� � ������� .bin (�������������� ����)
void autoSaveTableBin(Element *head); //�������������� ���������� ������� � ������� .bin (�������������� ����)

#endif //TEST_SAVEANDDOWNLOADTABLE_H