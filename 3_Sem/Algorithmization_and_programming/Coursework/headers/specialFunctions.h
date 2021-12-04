#ifndef TEST_SPECIALFUNCTIONS_H
#define TEST_SPECIALFUNCTIONS_H

#include "structures.h"

//==============================================================================
//                            ����������� �������
//                                ���������
//==============================================================================

void gotoxy(int x, int y); // ���������� ���������� �������
void setCursor(int i); // ��������/������ ������
void showMenuItems(const char *menuItems[], const int NUM_MENU_ITEMS, const char *title); // ����� ������� ����
int menu(const char *menuItems[], int numPunct, const char *title); // ���� �������������
																	// ���������: ������ �������, ���-�� �������, �������� ����
int yesOrNo(const char *title); // �� ������� � ���� ������?


#endif //TEST_SPECIALFUNCTIONS_H