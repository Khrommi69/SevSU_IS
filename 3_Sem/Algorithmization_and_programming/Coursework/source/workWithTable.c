
#include "../headers/workWithTable.h"

//==============================================================================
//                            "ГЛАВНЫЕ" ФУНКЦИИ
//==============================================================================

//Ввод информации
Info setInfo(Element *head) {
	Info info;
	info.num_shop = setNumShop();
	info.num_section = setNumSection();
	setNumReceipt(info.num_receipt, head);
	setProductName(info.product_name);
	setProductCode(info.product_code);
	info.product_price = setProductPrice();
	info.product_quantity = setProductQuantity();
	info.date = setDate();
	return info;
}

// Добавить элемент в таблицу
void addNewElement(Element **head, Info info) {
	Element *temp = (Element*)malloc(sizeof(Element));
	temp->data = info;
	temp->next = NULL;
	temp->previous = NULL;
	
	// Если таблица пуста
	if (*head == NULL) {
		*head = temp;
	} else {
		Element *p = *head;
		while(p->next != NULL)
            p = p->next;
        p->next = temp;
        temp->previous = p;
	}
}

// Взять количество элементов таблицы
int getNumElements(Element *head) {
	int num = 0;
	while(head != NULL) {
		num++;
		head = head->next;
	}
	return num;
}

// Демонстрация таблицы
void showTable(Element *head) {
	setCursor(0);
	system("cls");
	if (head == NULL) {
		printf("\n\n\a ТАБЛИЦА ПУСТА! \n\n ");
		setCursor(1);
		system("pause");
		return;
	}

	int ch = 0;
	int i;
	const int numElemToShow = 10;
	const int numElementsOnTable = getNumElements(head);
	Element *temp;

	while(ch != 27) {
		system("cls");
		printf("================================================================================================================================================================ \n");
		printf("                                                                                                                                                                 \n");
		printf("                                                       Навигация: стрелочками вверх/вниз; Esc - выход                                                            \n");
		printf("                                                                                                                                                                 \n");
		printf("================================================================================================================================================================ \n");
		printf(" #МАГ  | #СЕК |      НОМЕР ЧЕКА      |                НАИМЕНОВАНИЕ ТОВАРА                 |    АРТИКУЛ ТОВАРА    | ЦЕНА ТОВАРА | КОЛ-ВО ТОВАРА |  ДАТА ПРОДАЖИ   \n");
		printf("================================================================================================================================================================ \n");
		temp = head;
		for (i=0; i != numElemToShow; i++) {
			if (temp != NULL) {
				printf(" %-5d | %-4d | %s |", temp->data.num_shop, temp->data.num_section, temp->data.num_receipt);
				printf(" %-50s | %-20s | %-11d |", temp->data.product_name, temp->data.product_code, temp->data.product_price);
				printf(" %-13d | %-2d / %-2d / %-4d\n", temp->data.product_quantity, temp->data.date.day, temp->data.date.month, temp->data.date.year);
				printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
				temp = temp->next;
			}
		}

		do {
			ch = getch();
			if (ch == 27) break;
			if (ch == 224) break;
		} while (1);

		if (ch == 224) ch = getch(); // так как у стрелок первый код 224 и только второй 72 или 80, то делаем 2 getch

		if (numElementsOnTable > numElemToShow) {
			switch (ch) {
				// 81 - page down; 80 - стрелка вниз
				case 81: {
					if (head->next != NULL)
					if (head->next->next != NULL)
					if (head->next->next->next != NULL)
					if (head->next->next->next->next != NULL)
					if (head->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next != NULL)
					if (head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next != NULL) {
						head = head->next->next->next->next->next->next->next->next->next->next;
						break;
					}
					printf("\a");
					break;
				}
				case 80: {
					if (head->next->next->next->next->next->next->next->next->next->next != NULL)
						head = head->next;
					else 
						printf("\a");
					break;
				}
				// 73 - page up; 72 - стрелка вверх
				case 73: {
					if (head->previous != NULL)
					if (head->previous->previous != NULL)
					if (head->previous->previous->previous != NULL)
					if (head->previous->previous->previous->previous != NULL)
					if (head->previous->previous->previous->previous->previous != NULL)
					if (head->previous->previous->previous->previous->previous->previous != NULL)
					if (head->previous->previous->previous->previous->previous->previous->previous != NULL)
					if (head->previous->previous->previous->previous->previous->previous->previous->previous != NULL)
					if (head->previous->previous->previous->previous->previous->previous->previous->previous->previous != NULL)
					if (head->previous->previous->previous->previous->previous->previous->previous->previous->previous->previous != NULL){
						head = head->previous->previous->previous->previous->previous->previous->previous->previous->previous->previous;
						break;
					}
					printf("\a");
					break;
				}
				case 72: {
					if (head->previous != NULL)
						head = head->previous;
					else 
						printf("\a");
					break;
				}
			}
		}
		else {
			switch (ch) {
				case 81: case 80: case 73: case 72: printf("\a");
			}
		}
	}
	setCursor(1);
}

// Вернуть указатель на выбранный элемент
Element *selectElement(Element *head) {
	SetBacklightOff;
	system("cls");
	if (head == NULL) {
		printf("\n\n\a ТАБЛИЧКИ НЕТ! \n\n\n ");
		system("pause");
		return NULL;
	}

	int ch = 0;

	while(ch != 13) {
		system("cls");
		printf("================================================================================================================================================================ \n");
		printf("                                                                                                                                                                 \n");
		printf("                                                                 ДЛЯ ВЫБОРА ЗАПИСИ НУЖНО:                                                                        \n");
		printf("                               С помощью стрелок вверх/вниз выбрать строку, с которой будем работать (Enter - подтверждение выбора)                              \n");
		printf("                                                если передумали обрабатывать запись нажмите \"Esc\" для выхода                                                   \n");
		printf("                                                                                                                                                                 \n");
		printf("================================================================================================================================================================ \n");
		printf(" #МАГ  | #СЕК |      НОМЕР ЧЕКА      |                НАИМЕНОВАНИЕ ТОВАРА                 |    АРТИКУЛ ТОВАРА    | ЦЕНА ТОВАРА | КОЛ-ВО ТОВАРА |  ДАТА ПРОДАЖИ   \n");
		printf("================================================================================================================================================================ \n");
		SetBacklightYellow;
		printf(" %-5d | %-4d | %s |", head->data.num_shop, head->data.num_section, head->data.num_receipt);
		printf(" %-50s | %-20s | %-11d |", head->data.product_name, head->data.product_code, head->data.product_price);
		printf(" %-13d | %-2d / %-2d / %-4d\n", head->data.product_quantity, head->data.date.day, head->data.date.month, head->data.date.year);
		SetBacklightOff;
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");

		do {
			ch = getch();
			if (ch == 13) break; //Enter
			if (ch == 224) { ch = getch(); break;}
			if (ch == 27) return NULL; //Esc
		} while (1);

		switch (ch) {
			// 81 - page down; 80 - стрелка вниз
			case 81:
			case 80: {
				if (head->next != NULL)
					head = head->next;
				else 
					printf("\a");
				break;
			}
			// 73 - page up; 72 - стрелка вверх
			case 73:
			case 72: {
				if (head->previous != NULL)
					head = head->previous;
				else 
					printf("\a");
				break;
			}
		}
	}
	return head;
}

// Выбрать и скорректировать запись
void correctRecord(Element *elem) {
	SetBacklightOff;
	system("cls");

	if (elem == NULL) {
		return;
	}

	int ch = 0;
	const int numRecords = 8;
	int selectedRecord = 1;

	while(ch != 13) {
		system("cls");
		printf("================================================================================================================================================================ \n");
		printf("                                                                                                                                                                 \n");
		printf("                                                              ДЛЯ КОРРЕКТИРОВКИ ЗАПИСИ НУЖНО:                                                                    \n");
		printf("                                   С помощью стрелок влево/вправо выбрать корректируемую запись (Enter - подтверждение выбора)                                   \n");
		printf("                                               если передумали корректировать запись нажмите \"Esc\" для выхода                                                  \n");
		printf("                                                                                                                                                                 \n");
		printf("================================================================================================================================================================ \n");
		printf(" #МАГ  | #СЕК |      НОМЕР ЧЕКА      |                НАИМЕНОВАНИЕ ТОВАРА                 |    АРТИКУЛ ТОВАРА    | ЦЕНА ТОВАРА | КОЛ-ВО ТОВАРА |  ДАТА ПРОДАЖИ   \n");
		printf("================================================================================================================================================================ \n");
		printf(" %-5d | %-4d | %s |", elem->data.num_shop, elem->data.num_section, elem->data.num_receipt);
		printf(" %-50s | %-20s | %-11d |", elem->data.product_name, elem->data.product_code, elem->data.product_price);
		printf(" %-13d | %-2d / %-2d / %-4d\n", elem->data.product_quantity, elem->data.date.day, elem->data.date.month, elem->data.date.year);
		SetBacklightYellow;
		switch(selectedRecord) {
			case 1: {
				gotoxy(1, 9);
				printf("%-5d", elem->data.num_shop);
				break;
			}
			case 2: {
				gotoxy(9, 9);
				printf("%-4d", elem->data.num_section);
				break;
			}
			case 3: {
				gotoxy(16, 9);
				printf("%-20s", elem->data.num_receipt);
				break;
			}
			case 4: {
				gotoxy(39, 9);
				printf("%-50s", elem->data.product_name);
				break;
			}
			case 5: {
				gotoxy(92, 9);
				printf("%-20s", elem->data.product_code);
				break;
			}
			case 6: {
				gotoxy(115, 9);
				printf("%-11d", elem->data.product_price);
				break;
			}
			case 7: {
				gotoxy(129, 9);
				printf("%-13d", elem->data.product_quantity);
				break;
			}
			case 8: {
				gotoxy(145, 9);
				printf("%-2d / %-2d / %-4d", elem->data.date.day, elem->data.date.month, elem->data.date.year);
				break;
			}
		}
		SetBacklightOff;
		printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");

		do {
			ch = getch();
			if (ch == 13) break; //Enter
			if (ch == 224) { ch = getch(); break;}
			if (ch == 27) return; //Esc
		} while (1);

		switch (ch) {
			// <-ЛЕВО  |  ПРАВО->
			case 77: { // 77 - стрелка вправо
				selectedRecord++;
				if (selectedRecord > numRecords)
					selectedRecord = 1;
				break;
			}
			case 75: { // 75 - стрелка влево
				selectedRecord--;
				if (selectedRecord < 1)
					selectedRecord = numRecords;
				break;
			}
		}
	}

	switch(selectedRecord) {
		case 1: {
			elem->data.num_shop = setNumShop();
			break;
		}
		case 2: {
			elem->data.num_section = setNumSection();
			break;
		}
		case 3: {
			setNumReceipt(elem->data.num_receipt, elem);
			break;
		}
		case 4: {
			setProductName(elem->data.product_name);
			break;
		}
		case 5: {
			setProductCode(elem->data.product_code);
			break;
		}
		case 6: {
			elem->data.product_price = setProductPrice();
			break;
		}
		case 7: {
			elem->data.product_quantity = setProductQuantity();
			break;
		}
		case 8: {
			elem->data.date = setDate();
			break;
		}
	}
}

// Удалить элемент в таблице
void deleteElement(Element **head) {
	system("cls");
	if ((*head) == NULL) {
		printf("\n\n\a Таблицы нет, удалять нечего! \n\n\n ");
		system("pause");
		return;
	}

	Element *deletedElem = *head;
	deletedElem = selectElement(deletedElem);
	while(1) {
		// Если это head
		if (deletedElem == (*head)) {
			if((*head)->next != NULL){
				*head = (*head)->next;
				(*head)->previous = NULL;
				
				//чистим память
				deletedElem->next = NULL;
				deletedElem->previous = NULL;
			}
			free(deletedElem);
			break;
		}

		// Если элемент последний
		if (deletedElem->next == NULL){
			deletedElem->previous->next = NULL;
			//чистим память
			deletedElem->next = NULL;
			deletedElem->previous = NULL;
			free(deletedElem);
			break;
		}

		// Если элемент не первый и не последний
		deletedElem->previous->next = deletedElem->next;
		deletedElem->next->previous = deletedElem->previous;
		//чистим память
		deletedElem->next = NULL;
		deletedElem->previous = NULL;
		free(deletedElem);
		break;
	}
	printf("\n\n Запись удалена успешно! \n\n");
	system("pause");
}

// Удалить все элементы таблицы
void deleteTable(Element **head) {
	if ((*head) == NULL) {
		system("cls");
		// printf("\n\n\a Таблицы нет, поэтому удалять её ненадо! \n\n\n ");
		// system("pause");
		return;
	}

	Element *temp;
	while((*head) != NULL) {
		temp = (*head);
		*head = (*head)->next;
		if ((*head) != NULL)
			(*head)->previous = NULL;

		// чистим память
		temp->next = NULL;
		free(temp);
	}
}

// Ищем элемент по номеру чека
Element *searchElement(Element *head) {
	int i, kol;
	char searchableNumReceipt[21];
	while(1) {
		i = 0;
		kol = 0;
		SetBacklightOff;
		system("cls");
		printf("\n Вы должны ввести номер чека в искомой записи, чтобы мы нашли для вас запись\n");
		printf("\n Введите номер чека:\n");
		printf("\n (данные: 20 чисел)");
		gotoxy(21 ,3);
		SetBacklightYellow;
		fflush(stdin);
		gets(searchableNumReceipt);
		while(searchableNumReceipt[i]) {
			// если число увеличиваем счетчик
			if ((searchableNumReceipt[i] == '1') || (searchableNumReceipt[i] == '2') || (searchableNumReceipt[i] == '3') || 
				(searchableNumReceipt[i] == '4') || (searchableNumReceipt[i] == '5') || (searchableNumReceipt[i] == '6') || 
				(searchableNumReceipt[i] == '7') || (searchableNumReceipt[i] == '8') || (searchableNumReceipt[i] == '9') || (searchableNumReceipt[i] == '0')) {
				kol++;
			}
			i++;
		}
		if (strlen(searchableNumReceipt) == kol) {
			if (strlen(searchableNumReceipt) == 20) {
				SetBacklightOff;
				break;
			}
		}
		SetBacklightOff;
		printf("\a");
		const char *numReceiptNotFound[] = {
			" Повторить попытку ввода",
			" Выйти"
		};
		if (menu(numReceiptNotFound, 2, " Запись не найдена") == 1) return NULL;
	}

	while (head != NULL) {
		if (strcmp(searchableNumReceipt, head->data.num_receipt) == 0) {
			return head;
		}
		head = head->next;
	}
	system("cls");
	printf("\n\n Запись не найдена\n\n\a ");
	system("pause");
	return NULL;
}

// Вывести инфу об одном элементе
void showOneElement(Element *head) {
	if (head == NULL) {
		return;
	}

	unsigned long long sum = ((head->data.product_price) * (head->data.product_quantity));

	system("cls");
	printf(" ___________________________________________________________________________ \n");	
	printf("|                                                                           |\n");	
	printf("|                               Чек номер:                                  |\n");
	printf("|                           %s                            |                  \n", head->data.num_receipt);
	printf("|___________________________________________________________________________|\n");	
	printf("|                                                                           |\n");	
	printf("|   Номер магазина:                                                   %5d |  \n", head->data.num_shop);	
	printf("|   Номер секции:                                                      %4d | \n", head->data.num_section);	
	printf("|   Наименование товара: %50s |\n", head->data.product_name);	
	printf("|   Артикул товара:                                    %20s |                \n", head->data.product_code);
	printf("|   Цена товара:                                            %10d Руб. |      \n", head->data.product_price);	
	printf("|   Количество товара:                                            %5d шт. |  \n", head->data.product_quantity);
	printf("|                                                                           |\n");	
	printf("|   Итоговая сумма:                                %19llu Руб. |             \n", sum);	
	printf("|                                                                           |\n");	
	printf("|---------------------------------------------------------------------------|\n");	
	printf("|                                %-2d/%-2d/%d                                 |\n", head->data.date.day, head->data.date.month, head->data.date.year);	
	printf("|___________________________________________________________________________|\n\n\n\n");	
	
	system("pause");
}

// Сортируем таблицу по возрастанию (1..2..3..4....)
void sortTableAscending(Element **head) {
	Element *temp = *head;
	if (temp->next == NULL) {
  		return;
	}

	UI num_shop;
	UI num_section;
	char num_receipt[RECEIPT_MAX_LEN + 1];
	char product_name[PRODUCT_NAME_MAX_LEN + 1];
	char product_code[PRODUCT_CODE_MAX_LEN + 1];
	UL product_price;
	UI product_quantity;
	UI day;
	UI month;
	UI year;

	Element *buf;
	UI numTemp = 0;
	UI kolElementsInTable = getNumElements(temp);
	
	UI i;
	for (i = kolElementsInTable; i > 1; i--) {
		numTemp = 1;
		temp = (*head);
    	while(numTemp < i) {
	    	if (temp->data.num_shop > temp->next->data.num_shop) {
				num_shop = temp->data.num_shop;
				num_section = temp->data.num_section;
				strcpy(num_receipt, temp->data.num_receipt);
				strcpy(product_name, temp->data.product_name);
				strcpy(product_code, temp->data.product_code);
				product_price = temp->data.product_price;
				product_quantity = temp->data.product_quantity;
				day = temp->data.date.day;
				month = temp->data.date.month;
				year = temp->data.date.year;

	   			temp->data.num_shop = temp->next->data.num_shop;
	   			temp->data.num_section = temp->next->data.num_section;
	   			strcpy(temp->data.num_receipt, temp->next->data.num_receipt);
	   			strcpy(temp->data.product_name, temp->next->data.product_name);
	   			strcpy(temp->data.product_code, temp->next->data.product_code);
	   			temp->data.product_price = temp->next->data.product_price;
	   			temp->data.product_quantity = temp->next->data.product_quantity;
	   			temp->data.date.day = temp->next->data.date.day;
	   			temp->data.date.month = temp->next->data.date.month;
	   			temp->data.date.year = temp->next->data.date.year;

	   			temp->next->data.num_shop = num_shop;
				temp->next->data.num_section = num_section;
				strcpy(temp->next->data.num_receipt, num_receipt);
	   			strcpy(temp->next->data.product_name, product_name);
	   			strcpy(temp->next->data.product_code, product_code);
	   			temp->next->data.product_price = product_price;
	   			temp->next->data.product_quantity = product_quantity;
	   			temp->next->data.date.day = day;
	   			temp->next->data.date.month = month;
	   			temp->next->data.date.year = year;
	    	}
	    	numTemp++;
	    	temp = temp->next;
    	}
  	}
  	temp = temp->previous;
  	(*head) = temp;
}

// Сортируем таблицу по убыванию (....69..54..3..1)
void sortTableDescending(Element **head) {
	Element *temp = *head;
	if (temp->next == NULL) {
  		return;
	}

	UI num_shop;
	UI num_section;
	char num_receipt[RECEIPT_MAX_LEN + 1];
	char product_name[PRODUCT_NAME_MAX_LEN + 1];
	char product_code[PRODUCT_CODE_MAX_LEN + 1];
	UL product_price;
	UI product_quantity;
	UI day;
	UI month;
	UI year;

	Element *buf;
	UI numTemp = 0;
	UI kolElementsInTable = getNumElements(temp);
	
	UI i;
	for (i = kolElementsInTable; i > 1; i--) {
		numTemp = 1;
		temp = (*head);
    	while(numTemp < i) {
	    	if (temp->data.num_shop < temp->next->data.num_shop) {
				num_shop = temp->data.num_shop;
				num_section = temp->data.num_section;
				strcpy(num_receipt, temp->data.num_receipt);
				strcpy(product_name, temp->data.product_name);
				strcpy(product_code, temp->data.product_code);
				product_price = temp->data.product_price;
				product_quantity = temp->data.product_quantity;
				day = temp->data.date.day;
				month = temp->data.date.month;
				year = temp->data.date.year;

	   			temp->data.num_shop = temp->next->data.num_shop;
	   			temp->data.num_section = temp->next->data.num_section;
	   			strcpy(temp->data.num_receipt, temp->next->data.num_receipt);
	   			strcpy(temp->data.product_name, temp->next->data.product_name);
	   			strcpy(temp->data.product_code, temp->next->data.product_code);
	   			temp->data.product_price = temp->next->data.product_price;
	   			temp->data.product_quantity = temp->next->data.product_quantity;
	   			temp->data.date.day = temp->next->data.date.day;
	   			temp->data.date.month = temp->next->data.date.month;
	   			temp->data.date.year = temp->next->data.date.year;

	   			temp->next->data.num_shop = num_shop;
				temp->next->data.num_section = num_section;
				strcpy(temp->next->data.num_receipt, num_receipt);
	   			strcpy(temp->next->data.product_name, product_name);
	   			strcpy(temp->next->data.product_code, product_code);
	   			temp->next->data.product_price = product_price;
	   			temp->next->data.product_quantity = product_quantity;
	   			temp->next->data.date.day = day;
	   			temp->next->data.date.month = month;
	   			temp->next->data.date.year = year;
	    	}
	    	numTemp++;
	    	temp = temp->next;
    	}
  	}
  	temp = temp->previous;
  	(*head) = temp;
}

// Определить товарооборот для каждого магазина
void determineTurnoverForEachStore(Element *head) {
	system("cls");
	if (head == NULL) {
		printf("\a\n\n Таблицы нет, товарооборот не может быть определен!\n\n ");
		system("pause");
		return;
	}
	
	//=========================================================================================
	FILE *fdownload;
	// переменная флаг - "сохраняем файл или нет"
	int saveOrNo = 0;
	if (yesOrNo(" Сделаем вывод товраооборота в каждом магазине в текстовый файл?") == 0) {
		// Вводим путь к файлу сохранения
		int exitFromWhile = 0;
		int lenBuf = 0;

		//Ввод пути к файлу где будем сохранять
		char buf[255];
		do {
			memset(buf, 0, sizeof(buf));
			system("cls");
			SetBacklightOff;
			printf("\n Введите путь к файлу вывода:\n\n");
			printf(" (например: \"D:\\coursework\\turnover\\turnover1.txt\")");
			gotoxy(30, 1);
			SetBacklightYellow;
			fflush(stdin);
			gets(buf);
			SetBacklightOff;

			// проверить текстовый файл или нет, и если нет то повторяем попитку ввода
			lenBuf = strlen(buf);
			if (lenBuf > 4) {
				if (((buf[lenBuf-4] == '.') && (buf[lenBuf-3] == 't') && (buf[lenBuf-2] == 'x') && (buf[lenBuf-1] == 't')) == 0) {
					printf("\a");
					continue;
				}
			}
			else {
				printf("\a");
				continue;
			}

			//Если файл уже существует перезаписать его?
			if ((fdownload = fopen(buf, "r")) != NULL) {
				const char *overwrite[] = {
					" Да, давай перезапишем",
					" Неа, повторим попытку ввода",
					" Я хочу выйти, передумал делать вывод в текстовый файл"
				};
				fclose(fdownload);
				switch(menu(overwrite, 3, " Указанный файл уже существует. Перезапишем его?")) {
					case 0: {
						//выходим из ввода 
						fdownload = fopen(buf, "w");
						saveOrNo = 1;
						exitFromWhile = 1;
						break;
					}
					case 1: {
						exitFromWhile = 2;
						break;
					}
					case 2: {
						exitFromWhile = 1;
					}
				}
				if (exitFromWhile == 1) break;
				if (exitFromWhile == 2) continue;
			}

			if ((fdownload = fopen(buf, "w")) != NULL) {
				saveOrNo = 1;
				exitFromWhile = 1;
			}
			else {
				printf("\a");
				const char *error[] = {
					" Повторить попытку ввода",
					" Я хочу выйти, передумал делать вывод в текстовый файл"
				};
				if (menu(error, 2, " Не удалось получить доступ к файлу!") == 1) {
					exitFromWhile = 1;
				}
			}
		} while (exitFromWhile != 1); 
	} //делаем вывод товраооборота в каждом магазине в текстовый файл?

	//=========================================================================================
	//отсортируем список но не черз функцию, потому что функция меняет оригинальный список
	while(1) {
		Element *firstElem = head;
		if (head->next == NULL) {
	  		break;
		}

		UI num_shop;
		UI num_section;
		char num_receipt[RECEIPT_MAX_LEN + 1];
		char product_name[PRODUCT_NAME_MAX_LEN + 1];
		char product_code[PRODUCT_CODE_MAX_LEN + 1];
		UL product_price;
		UI product_quantity;
		UI day;
		UI month;
		UI year;

		Element *buf;
		UI numTemp = 0;
		UI kolElementsInTable = getNumElements(head);
		
		UI i;
		for (i = kolElementsInTable; i > 1; i--) {
			numTemp = 1;
			head = firstElem;
	    	while(numTemp < i) {
		    	if (head->data.num_shop > head->next->data.num_shop) {
					num_shop = head->data.num_shop;
					num_section = head->data.num_section;
					strcpy(num_receipt, head->data.num_receipt);
					strcpy(product_name, head->data.product_name);
					strcpy(product_code, head->data.product_code);
					product_price = head->data.product_price;
					product_quantity = head->data.product_quantity;
					day = head->data.date.day;
					month = head->data.date.month;
					year = head->data.date.year;

		   			head->data.num_shop = head->next->data.num_shop;
		   			head->data.num_section = head->next->data.num_section;
		   			strcpy(head->data.num_receipt, head->next->data.num_receipt);
		   			strcpy(head->data.product_name, head->next->data.product_name);
		   			strcpy(head->data.product_code, head->next->data.product_code);
		   			head->data.product_price = head->next->data.product_price;
		   			head->data.product_quantity = head->next->data.product_quantity;
		   			head->data.date.day = head->next->data.date.day;
		   			head->data.date.month = head->next->data.date.month;
		   			head->data.date.year = head->next->data.date.year;

		   			head->next->data.num_shop = num_shop;
					head->next->data.num_section = num_section;
					strcpy(head->next->data.num_receipt, num_receipt);
		   			strcpy(head->next->data.product_name, product_name);
		   			strcpy(head->next->data.product_code, product_code);
		   			head->next->data.product_price = product_price;
		   			head->next->data.product_quantity = product_quantity;
		   			head->next->data.date.day = day;
		   			head->next->data.date.month = month;
		   			head->next->data.date.year = year;
		    	}
		    	numTemp++;
		    	head = head->next;
	    	}
	  	}
	  	head = head->previous;
	  	break;
	}

	//=========================================================================================
	printf("\n");
	UI lastnumShop = head->data.num_shop; // последний магазин
	unsigned long long turnoverSum = 0; // счетчик суммы товарооборота

	char numberSTR[25];
	char massage[80];
	if(saveOrNo == 1) {
		memset(massage, 0, sizeof(massage));
		strcat(massage, "\n Товарооборот по каждому магазину, который есть в таблице:\n\n");
		fputs(massage, fdownload);
	}

	printf("\n\n Товарооборот по каждому магазину, который есть в таблице:\n\n");
	//Выводим на экран (и в файл если saveOrNo == 1) инфу о товарообороте в каждом магазине
	while(head != NULL) {
		if (head->data.num_shop == lastnumShop) {
			//копим сумму товарооборота по одному магазину
			turnoverSum += (head->data.product_price * head->data.product_quantity);
		}
		else {
			//вывод в консоль
			printf(" В магазине №%d сумма товарооборота = %llu;\n", lastnumShop, turnoverSum);
			//запись в файл
			if(saveOrNo == 1) {
				memset(massage, 0, sizeof(massage));
				strcat(massage, " В магазине №");
				memset(numberSTR, 0, sizeof(numberSTR));
				itoa(lastnumShop, numberSTR, 10);
				strcat(massage, numberSTR);
				strcat(massage, " сумма товарооборота = ");
				memset(numberSTR, 0, sizeof(numberSTR));
				itoa(turnoverSum, numberSTR, 10);
				strcat(massage, numberSTR);
				strcat(massage, ";\n");
				fputs(massage, fdownload);
			}

			turnoverSum = 0; // обнуляем сумму для нового магазина
			turnoverSum += (head->data.product_price * head->data.product_quantity);
			lastnumShop = head->data.num_shop;
		}
		head = head->next;
	}
	//вывод в консоль
	printf(" В магазине №%d сумма товарооборота = %llu;\n", lastnumShop, turnoverSum);
	//запись в файл
	if(saveOrNo == 1) {
		memset(massage, 0, sizeof(massage));
		strcat(massage, " В магазине №");
		memset(numberSTR, 0, sizeof(numberSTR));
		itoa(lastnumShop, numberSTR, 10);
		strcat(massage, numberSTR);
		strcat(massage, " сумма товарооборота = ");
		memset(numberSTR, 0, sizeof(numberSTR));
		itoa(turnoverSum, numberSTR, 10);
		strcat(massage, numberSTR);
		strcat(massage, ";\n");
		fputs(massage, fdownload);

		//и не забываем закрыть файл если он был
		fclose(fdownload);
	}
	printf("\n ");
	system("pause");	
}