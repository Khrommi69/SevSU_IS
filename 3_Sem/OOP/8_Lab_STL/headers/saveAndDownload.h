#ifndef TEST_SAVEANDDOWNLOAD_H
#define TEST_SAVEANDDOWNLOAD_H

#include "structures.h"
#include "functions.h"

//==============================================================================
//                    ������� ���������� � �������� �������
//                                ���������
//==============================================================================

void saveDataBase(std::deque<Element> database); // ��������� ���� ������
std::deque<Element> downloadDataBase(std::deque<Element> database); // ��������� ���� ������

#endif //TEST_SAVEANDDOWNLOAD_H