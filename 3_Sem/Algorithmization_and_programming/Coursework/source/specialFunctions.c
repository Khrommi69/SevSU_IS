
#include "../headers/specialFunctions.h"

//==============================================================================
//                            СПЕЦИАЛЬНЫЕ ФУНКЦИИ
//==============================================================================

// Установить координаты курсора
void gotoxy(int x, int y) {
    COORD coord = {x, y}; // Координаты
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Показать/скрыть курсор
void setCursor(int i) {
	CONSOLE_CURSOR_INFO tmp;
    tmp.bVisible = i; // Видимость=1/невидимость=0 курсора
    tmp.dwSize = 1; // Размер курсора
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &tmp);
}

// Вывод пунктов меню
void showMenuItems(const char *menuItems[], const int NUM_MENU_ITEMS, const char *title) {
	system("cls");
	int i;
	
	// Напечатать заглавие
	gotoxy(0, 1);
	printf("%s", title);
	
	for (i=0; i != NUM_MENU_ITEMS; i++) {
		gotoxy(0, i+3);
		printf("%s\n", menuItems[i]);
	}
}

// Меню интерактивное
// Параметры: список пунктов, кол-во пунктов, заглавие меню
int menu(const char *menuItems[], int numPunct, const char *title) {
	const int NUM_MENU_ITEMS = numPunct; // Кол-во пунктов меню
	int activeMenuItem = 0; // Активный элемент
	int ch = 0;
	
	setCursor(0); // удалить курсор
	
	while (ch != 13) {
		// Eсли Esc, то вернуть номер последнего пункта меню
		if (ch == 27) {
			setCursor(1);
			system("cls");
			return NUM_MENU_ITEMS-1;
		}
		
		showMenuItems(menuItems, NUM_MENU_ITEMS, title); // Показать пункты меню
		gotoxy(0, activeMenuItem+3);
		
		// Выделить текущий пункт ярко жёлтым цветом
		SetBacklightYellow;
		printf("->%s", menuItems[activeMenuItem]);
		
		ch = getch();
		// так как у стрелок первый код 224 и только второй 72 или 80, то делаем 2 getch
		if (ch == 224)
			ch = getch();
		
		switch (ch) {
			case 81: activeMenuItem++; break; // page down
			case 80: activeMenuItem++; break; // стрелка вниз
			case 73: activeMenuItem--; break; // page up
			case 72: activeMenuItem--; break; // стрелка вверх
		}
		
		// Переход по пунктам меню с 1 на последний и на оборот
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

// Вы уверены в своём выборе?
int yesOrNo(const char *title) {
	const char *yesORno [] = {
		" Да",
		" Нет"
	};
	int kol_selections = 2;
	return menu(yesORno, kol_selections, title);
}