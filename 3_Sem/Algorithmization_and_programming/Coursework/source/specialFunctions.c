
#include "../headers/specialFunctions.h"

//==============================================================================
//                            ����������� �������
//==============================================================================

// ���������� ���������� �������
void gotoxy(int x, int y) {
    COORD coord = {x, y}; // ����������
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ��������/������ ������
void setCursor(int i) {
	CONSOLE_CURSOR_INFO tmp;
    tmp.bVisible = i; // ���������=1/�����������=0 �������
    tmp.dwSize = 1; // ������ �������
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &tmp);
}

// ����� ������� ����
void showMenuItems(const char *menuItems[], const int NUM_MENU_ITEMS, const char *title) {
	system("cls");
	int i;
	
	// ���������� ��������
	gotoxy(0, 1);
	printf("%s", title);
	
	for (i=0; i != NUM_MENU_ITEMS; i++) {
		gotoxy(0, i+3);
		printf("%s\n", menuItems[i]);
	}
}

// ���� �������������
// ���������: ������ �������, ���-�� �������, �������� ����
int menu(const char *menuItems[], int numPunct, const char *title) {
	const int NUM_MENU_ITEMS = numPunct; // ���-�� ������� ����
	int activeMenuItem = 0; // �������� �������
	int ch = 0;
	
	setCursor(0); // ������� ������
	
	while (ch != 13) {
		// E��� Esc, �� ������� ����� ���������� ������ ����
		if (ch == 27) {
			setCursor(1);
			system("cls");
			return NUM_MENU_ITEMS-1;
		}
		
		showMenuItems(menuItems, NUM_MENU_ITEMS, title); // �������� ������ ����
		gotoxy(0, activeMenuItem+3);
		
		// �������� ������� ����� ���� ����� ������
		SetBacklightYellow;
		printf("->%s", menuItems[activeMenuItem]);
		
		ch = getch();
		// ��� ��� � ������� ������ ��� 224 � ������ ������ 72 ��� 80, �� ������ 2 getch
		if (ch == 224)
			ch = getch();
		
		switch (ch) {
			case 81: activeMenuItem++; break; // page down
			case 80: activeMenuItem++; break; // ������� ����
			case 73: activeMenuItem--; break; // page up
			case 72: activeMenuItem--; break; // ������� �����
		}
		
		// ������� �� ������� ���� � 1 �� ��������� � �� ������
		if (activeMenuItem < 0)
			activeMenuItem = NUM_MENU_ITEMS-1;
		if (activeMenuItem > NUM_MENU_ITEMS-1)
			activeMenuItem = 0;
		
		SetBacklightOff;
	}
	
	setCursor(1);
	system("cls");
	return activeMenuItem;
}

// �� ������� � ���� ������?
int yesOrNo(const char *title) {
	const char *yesORno [] = {
		" ��",
		" ���"
	};
	int kol_selections = 2;
	return menu(yesORno, kol_selections, title);
}