
#include "../headers/setData.h"

//==============================================================================
//                        ФУНКЦИИ ВВОДА ДАННЫХ С ПРОВЕРКАМИ
//==============================================================================

// Ввод номера магазина
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
		printf("\n Введите номер магазина:\n\n");
		printf(" (данные: число от 1 до 50к)");
		gotoxy(25 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// если число увеличиваем счетчик
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

// Ввод номера секции
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
		printf("\n Введите номер секции:\n\n");
		printf(" (данные: число от 1 до 1к)");
		gotoxy(23 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// если число увеличиваем счетчик
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

// Проверка наличия одинаковых чеков
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
			printf("\n\a\n ОШИБКА! Такой чек уже есть!\n\n ");
			system("pause");
			return 1;
		}
		head = head->next;
	}
	return 0;
}

//Ввод номер чека
void setNumReceipt(char *buf, Element *head) {
	int i, kol;
	while(1) {
		i = 0;
		kol = 0;
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n Введите номер чека:\n\n");
		printf(" (данные: 20 чисел)");
		gotoxy(21 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		SetBacklightOff;
		while(1) {
			while(buf[i]) {
				// если число увеличиваем счетчик
				if ((buf[i] == '1') || (buf[i] == '2') || (buf[i] == '3') || (buf[i] == '4') || 
					(buf[i] == '5') || (buf[i] == '6') || (buf[i] == '7') || (buf[i] == '8') || (buf[i] == '9') || (buf[i] == '0')) {
					kol++;
				}
				i++;
			}
			if (strlen(buf) == kol) {
				if (strlen(buf) == 20) {
					// Если такого чека ещё нет в таблице
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

//Ввод наименования продукта
void setProductName(char *buf) {
	while(1) {
		memset(buf, 0, sizeof(buf));
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n Введите наименование товара:\n\n");
		printf(" (данные: любые до 50 символов)");
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

//Ввод артикула продукта
void setProductCode(char *buf) {
	while(1) {
		memset(buf, 0, sizeof(buf));
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n Введите артикул товара:\n\n");
		printf(" (данные: любые до 20 символов)");
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

// Ввод цена товара
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
		printf("\n Введите цену товара:\n\n");
		printf(" (данные: целое число от 1 до 1млрд.)");
		gotoxy(22 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// если число увеличиваем счетчик
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

// Ввод количества продуктов
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
		printf("\n Введите количество товаров:\n\n");
		printf(" (данные: число от 1 до 50к)");
		gotoxy(29 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		while(1) {
			while(buf[i]) {
				// если число увеличиваем счетчик
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

// Ввод даты
When setDate() {
	When date;
	UI i;
	int ch;

	setCursor(0);

	while(1) {
	//--------------------------------------------ДЕНЬ
	ch = 0;
	i = 1;
	while(ch != 13) {
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n День:\n\n");
		printf(" (используйте стрелки вверх/вниз и Enter)");
		gotoxy(7 ,1);
		SetBacklightYellow;
		printf("%d", i);
		ch = getch();
		// так как у стрелок первый код 224 и только второй 72 или 80, то делаем 2 getch
		if (ch == 224) ch = getch();
		switch (ch) {
			case 81: i--; break; // page down
			case 80: i--; break; // стрелка вниз
			case 73: i++; break; // page up
			case 72: i++; break; // стрелка вверх
		}
		
		// Переход по пунктам меню с 1 на последний и на оборот
		if (i < 1)  i = 31;
		if (i > 31) i = 1;
	}
	date.day = i;

	//--------------------------------------------МЕСЯЦ
	ch = 0;
	i = 1;
	char *month[] = {"январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август",
					"Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
	while(ch != 13) {
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n Месяц:\n\n");
		printf(" (используйте стрелки вверх/вниз и Enter)");
		gotoxy(8 ,1);
		SetBacklightYellow;
		printf("%s", month[i-1]);
		ch = getch();
		// так как у стрелок первый код 224 и только второй 72 или 80, то делаем 2 getch
		if (ch == 224) ch = getch();
		switch (ch) {
			case 81: i--; break; // page down
			case 80: i--; break; // стрелка вниз
			case 73: i++; break; // page up
			case 72: i++; break; // стрелка вверх
		}
		
		// Переход по пунктам меню с 1 на последний и на оборот
		if (i < 1)  i = 12;
		if (i > 12) i = 1;
	}
	date.month = i;

	//--------------------------------------------ГОД
	ch = 0;
	i = 2021;
	while(ch != 13) {
		SetBacklightOff;
		system("cls");
		gotoxy(0,0);
		printf("\n Год:\n\n");
		printf(" (используйте стрелки вверх/вниз и Enter)");
		gotoxy(6 ,1);
		SetBacklightYellow;
		printf("%d", i);
		ch = getch();
		// так как у стрелок первый код 224 и только второй 72 или 80, то делаем 2 getch
		if (ch == 224) ch = getch();
		switch (ch) {
			case 81: i--; break; // page down
			case 80: i--; break; // стрелка вниз
			case 73: i++; break; // page up
			case 72: i++; break; // стрелка вверх
		}
		
		// Переход по пунктам меню с 1 на последний и на оборот
		if (i < 1990)  i = 2023;
		if (i > 2023) i = 1990;
	}
	date.year = i;

	// Проверка на совпадение числа и месяца (и високостного года)
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
			// Если год високостный, то
			if ((date.year % 4) == 0) {
				if (date.day > 29) {
					printf("\a");
					i = 1;
				}
			}
			// Если год не високостный, то
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