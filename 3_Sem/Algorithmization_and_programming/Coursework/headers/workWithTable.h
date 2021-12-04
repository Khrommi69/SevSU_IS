#ifndef TEST_WORKWITHTABLE_H
#define TEST_WORKWITHTABLE_H

#include "structures.h"
#include "specialFunctions.h"
#include "setData.h"

//==============================================================================
//                            "�������" �������
//                                ���������
//==============================================================================

Info setInfo(Element *head); // ���� ����������
void addNewElement(Element **head, Info info); // �������� ������� � �������
int getNumElements(Element *head); // ����� ���������� ��������� �������
void showTable(Element *head); // ������������ �������
Element *selectElement(Element *head); // ������� ��������� �� ��������� �������
void correctRecord(Element *elem); // ������� � ��������������� ������
void deleteElement(Element **head); // ������� ������� � �������
void deleteTable(Element **head); // ������� ��� �������� �������
Element *searchElement(Element *head); // ���� ������� �� ������ ����
void showOneElement(Element *head); // ������� ���� �� ����� ��������
void sortTableAscending(Element **head); // ��������� ������� �� ����������� (1..2..3..4....)
void sortTableDescending(Element **head); // ��������� ������� �� �������� (....69..54..3..1)
void determineTurnoverForEachStore(Element *head); // ���������� ������������ ��� ������� ��������

#endif //TEST_WORKWITHTABLE_H