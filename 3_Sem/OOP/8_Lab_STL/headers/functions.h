#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "structures.h"

//==============================================================================
//                                 �������
//                                ���������
//==============================================================================

bool continueOrNot(); // ���������� ��� ���?
Element setData(); // ���� ���������� �� ����� ��������
void headerDataBase(); // ����� ����� �������
void showStudent(std::deque<Element>::iterator i); // �������� ���������� � ��������
void showDataBase(std::deque<Element> database); // �������� ���� ������
void showSelectedGroup(std::deque<Element> database); // �������� ��������� � ��������� ������
void averageScoreByGroup(std::deque<Element> database); // ������� ���� �� �������

#endif //TEST_FUNCTIONS_H