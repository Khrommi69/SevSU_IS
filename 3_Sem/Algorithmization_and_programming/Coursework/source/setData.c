
#include "../headers/setData.h"

//==============================================================================
//                        ������� ����� ������ � ����������
//==============================================================================

// ���� ������ ��������
UI setNumShop() {
	UI numShop;
	char buf[255];
	int i, kol;
	while(1){
		i = 0;
		kol = 0;
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ������� ����� ��������:\n\n");
		printf(" (������: ����� �� 1 �� 50�)");
		gotoxy(25 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// ���� ����� ����������� �������
				if ((buf[i] == '1') || (buf[i] == '2') || (buf[i] == '3') || (buf[i] == '4') || 
					(buf[i] == '5') || (buf[i] == '6') || (buf[i] == '7') || (buf[i] == '8') || (buf[i] == '9') || (buf[i] == '0')) {
					kol++;
				}
				i++;
			}
			if (strlen(buf) == kol) {
				numShop = atoi(buf);
				if ((numShop > 0) && (numShop < 50001)) {
					SetBacklightOff;
					return numShop;
				}
				else {
					printf("\a");
					break;
				}
			}
			else {
				printf("\a");
				break;
			}
		}
	}
}

// ���� ������ ������
UI setNumSection() {
	UI numSection;
	char buf[255];
	int i, kol;
	while(1) {
		i = 0;
		kol = 0;
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ������� ����� ������:\n\n");
		printf(" (������: ����� �� 1 �� 1�)");
		gotoxy(23 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// ���� ����� ����������� �������
				if ((buf[i] == '1') || (buf[i] == '2') || (buf[i] == '3') || (buf[i] == '4') || 
					(buf[i] == '5') || (buf[i] == '6') || (buf[i] == '7') || (buf[i] == '8') || (buf[i] == '9') || (buf[i] == '0')) {
					kol++;
				}
				i++;
			}
			if (strlen(buf) == kol) {
				numSection = atoi(buf);
				if ((numSection > 0) && (numSection < 1001)) {
					SetBacklightOff;
					return numSection;
				}
				else {
					printf("\a");
					break;
				}
			}
			else {
				printf("\a");
				break;
			}
		}
	}
}

// �������� ������� ���������� �����
int checkingForIdenticalReceipts(Element *head, char buf[25]){
	system("cls");
	char num_receipt[22];
	int i;
	int mismatch;
	int kol;
	while (head != NULL) {
		kol = 0;
		memset(num_receipt, 0, sizeof(num_receipt));
		strcpy(num_receipt, head->data.num_receipt);
		for (i=0; i<20; i++) {
			if (num_receipt[i] == buf[i]) {
				mismatch = 1;
			}
			else {
				mismatch = 0;
			}
			kol += mismatch;
		}
		if (kol == 20){
			printf("\n\a\n ������! ����� ��� ��� ����!\n\n ");
			system("pause");
			return 1;
		}
		head = head->next;
	}
	return 0;
}

//���� ����� ����
void setNumReceipt(char *buf, Element *head) {
	int i, kol;
	while(1) {
		i = 0;
		kol = 0;
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ������� ����� ����:\n\n");
		printf(" (������: 20 �����)");
		gotoxy(21 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		SetBacklightOff;
		while(1) {
			while(buf[i]) {
				// ���� ����� ����������� �������
				if ((buf[i] == '1') || (buf[i] == '2') || (buf[i] == '3') || (buf[i] == '4') || 
					(buf[i] == '5') || (buf[i] == '6') || (buf[i] == '7') || (buf[i] == '8') || (buf[i] == '9') || (buf[i] == '0')) {
					kol++;
				}
				i++;
			}
			if (strlen(buf) == kol) {
				if (strlen(buf) == 20) {
					// ���� ������ ���� ��� ��� � �������
					if (checkingForIdenticalReceipts(head, buf) == 0) {
						return;
					}
					else {
						break;
					}
				}
				else {
					printf("\a");
					break;
				}
			}
			else {
				printf("\a");
				break;
			}
		}
	}
}

//���� ������������ ��������
void setProductName(char *buf) {
	while(1) {
		memset(buf, 0, sizeof(buf));
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ������� ������������ ������:\n\n");
		printf(" (������: ����� �� 50 ��������)");
		gotoxy(30 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		if ((strlen(buf) < 51) && (strlen(buf) > 0)) {
			SetBacklightOff;
			break;
		}
		else {
			printf("\a");
		}
	}
}

//���� �������� ��������
void setProductCode(char *buf) {
	while(1) {
		memset(buf, 0, sizeof(buf));
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ������� ������� ������:\n\n");
		printf(" (������: ����� �� 20 ��������)");
		gotoxy(25 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		if ((strlen(buf) < 21) && (strlen(buf) > 0)) {
			SetBacklightOff;
			break;
		}
		else {
			printf("\a");
		}
	}
}

// ���� ���� ������
UL setProductPrice() {
	UL numSection;
	char buf[255];
	int i, kol;
	while(1) {
		i = 0;
		kol = 0;
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ������� ���� ������:\n\n");
		printf(" (������: ����� ����� �� 1 �� 1����.)");
		gotoxy(22 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// ���� ����� ����������� �������
				if ((buf[i] == '1') || (buf[i] == '2') || (buf[i] == '3') || (buf[i] == '4') || 
					(buf[i] == '5') || (buf[i] == '6') || (buf[i] == '7') || (buf[i] == '8') || (buf[i] == '9') || (buf[i] == '0')) {
					kol++;
				}
				i++;
			}
			if (strlen(buf) == kol) {
				numSection = atoi(buf);
				if ((numSection > 0) && (numSection < 1000000001)) {
					SetBacklightOff;
					return numSection;
				}
				else {
					printf("\a");
					break;
				}
			}
			else {
				printf("\a");
				break;
			}
		}
	}
}

// ���� ���������� ���������
UI setProductQuantity() {
	UI productQuantity;
	char buf[255];
	int i, kol;
	while(1){
		i = 0;
		kol = 0;
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ������� ���������� �������:\n\n");
		printf(" (������: ����� �� 1 �� 50�)");
		gotoxy(29 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// ���� ����� ����������� �������
				if ((buf[i] == '1') || (buf[i] == '2') || (buf[i] == '3') || (buf[i] == '4') || 
					(buf[i] == '5') || (buf[i] == '6') || (buf[i] == '7') || (buf[i] == '8') || (buf[i] == '9') || (buf[i] == '0')) {
					kol++;
				}
				i++;
			}
			if (strlen(buf) == kol) {
				productQuantity = atoi(buf);
				if ((productQuantity > 0) && (productQuantity < 50001)) {
					SetBacklightOff;
					return productQuantity;
				}
				else {
					printf("\a");
					break;
				}
			}
			else {
				printf("\a");
				break;
			}
		}
	}
}

// ���� ����
When setDate() {
	When date;
	UI i;
	int ch;

	setCursor(0);

	while(1) {
	//--------------------------------------------����
	ch = 0;
	i = 1;
	while(ch != 13) {
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ����:\n\n");
		printf(" (����������� ������� �����/���� � Enter)");
		gotoxy(7 ,1);
		SetBacklightYellow;
		printf("%d", i);
		ch = getch();
		// ��� ��� � ������� ������ ��� 224 � ������ ������ 72 ��� 80, �� ������ 2 getch
		if (ch == 224) ch = getch();
		switch (ch) {
			case 81: i--; break; // page down
			case 80: i--; break; // ������� ����
			case 73: i++; break; // page up
			case 72: i++; break; // ������� �����
		}
		
		// ������� �� ������� ���� � 1 �� ��������� � �� ������
		if (i < 1)  i = 31;
		if (i > 31) i = 1;
	}
	date.day = i;

	//--------------------------------------------�����
	ch = 0;
	i = 1;
	char *month[] = {"������", "�������", "����", "������", "���", "����", "����", "������",
					"��������", "�������", "������", "�������"};
	while(ch != 13) {
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n �����:\n\n");
		printf(" (����������� ������� �����/���� � Enter)");
		gotoxy(8 ,1);
		SetBacklightYellow;
		printf("%s", month[i-1]);
		ch = getch();
		// ��� ��� � ������� ������ ��� 224 � ������ ������ 72 ��� 80, �� ������ 2 getch
		if (ch == 224) ch = getch();
		switch (ch) {
			case 81: i--; break; // page down
			case 80: i--; break; // ������� ����
			case 73: i++; break; // page up
			case 72: i++; break; // ������� �����
		}
		
		// ������� �� ������� ���� � 1 �� ��������� � �� ������
		if (i < 1)  i = 12;
		if (i > 12) i = 1;
	}
	date.month = i;

	//--------------------------------------------���
	ch = 0;
	i = 2021;
	while(ch != 13) {
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n ���:\n\n");
		printf(" (����������� ������� �����/���� � Enter)");
		gotoxy(6 ,1);
		SetBacklightYellow;
		printf("%d", i);
		ch = getch();
		// ��� ��� � ������� ������ ��� 224 � ������ ������ 72 ��� 80, �� ������ 2 getch
		if (ch == 224) ch = getch();
		switch (ch) {
			case 81: i--; break; // page down
			case 80: i--; break; // ������� ����
			case 73: i++; break; // page up
			case 72: i++; break; // ������� �����
		}
		
		// ������� �� ������� ���� � 1 �� ��������� � �� ������
		if (i < 1990)  i = 2023;
		if (i > 2023) i = 1990;
	}
	date.year = i;

	// �������� �� ���������� ����� � ������ (� ������������ ����)
	i = 0;
	switch(date.month) {
		case 4:
		case 6:
		case 9:
		case 11: {
			if (date.day == 31) {
				printf("\a");
				i = 1;
			}
			break;
		}
		case 2: {
			// ���� ��� �����������, ��
			if ((date.year % 4) == 0) {
				if (date.day > 29) {
					printf("\a");
					i = 1;
				}
			}
			// ���� ��� �� �����������, ��
			if ((date.year % 4) != 0) {
				if (date.day > 28) {
					printf("\a");
					i = 1;
				}
			}
			break;	
		}
	}
	if (i == 0)
		break;

	}//while(1)
	setCursor(1);
	SetBacklightOff;
	return date;
}