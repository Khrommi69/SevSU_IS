#ifndef TEST_SETDATA_H
#define TEST_SETDATA_H

#include "structures.h"
#include "specialFunctions.h"

//==============================================================================
//                        ������� ����� ������ � ����������
//                                   ���������
//==============================================================================

UI setNumShop(); // ���� ������ ��������
UI setNumSection(); // ���� ������ ������
int checkingForIdenticalReceipts(Element *head, char buf[25]); // �������� ������� ���������� �����
void setNumReceipt(char *buf, Element *head); // ���� ������ ����
void setProductName(char *buf); // ���� ������������ ��������
void setProductCode(char *buf); // ���� �������� ��������
UL setProductPrice(); // ���� ���� ������
UI setProductQuantity(); // ���� ���������� ���������
When setDate(); // ���� ����: ����/�����/���


#endif //TEST_SETDATA_H