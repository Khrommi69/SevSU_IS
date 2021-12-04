// Информация о продаже товаров подготовлена по следующему макету: номер магазина; номер секции; номер чека; наименование товара; артикул товара;
// цена товара; количество товара; дата продажи. Составить программу определения
// объема товарооборота по каждому магазину, т.е. общую сумму, вырученную от
// продажи всех товаров в данном магазине (данные содержат записи по нескольким
// магазинам). Разработать форму выходного документа.

#include "headers/structures.h"
#include "headers/specialFunctions.h"
#include "headers/workWithTable.h"
#include "headers/setData.h"
#include "headers/saveAndDownloadTable.h"

//==============================================================================
//                                MAIN
//==============================================================================
int main() {
    // Поддержка русского языка
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Ставим фон консоли светло-голубым, текст черный
    SetConsoleTitle("ДАННЫЕ ИЗ КАССЫ");
    system("color B0");
    system ("mode con cols=161 lines=30");

	Element *head = NULL;

    const char *firstMenu[] = {
		" Cоздание таблицы вручную", 
		" Загрузка таблицы из текстового файла",
		" Загрузка таблицы из бинарного файла",
		" Загрузка автосохранения",
		" Продолжить без таблицы",
		" Выход"
	};
    switch (menu(firstMenu, 6, " Выберите способ первичного создания таблицы:") + 1) {
    	case 1: {
			do {
				addNewElement(&head, setInfo(head));
			} while (yesOrNo(" Продолжаем добавление элементов?") == 0);
    		break;
    	}

    	case 2: {
    		readTable(&head);
    		break;
    	}

    	case 3: {
			readTableBIN(&head);
    		break;
    	}
    	
    	case 4: {
    		autoDownloudTableBin(&head);
    		break;
    	}
    	
    	case 5: {
    		break;
    	}
    	
    	case 6: {
    		return 0;
    	}
    }


    const char *menuItems[] = {
		" Cоздание таблицы", 
		" Просмотр таблицы",
		" Добавление новой записи в таблицу",
		" Удаление записи",
		" Удаление таблицы",
		" Корректировка записи в таблице",
		" Сортировка таблицы (по №магазина)",
		" Поиск записи в таблице",
		" Сохранение таблицы в файле",
		" Чтение данных из файла",
		" Определить объём товарооборота по каждому магазину",
		" Выход"
	};
	const int NUM_MENU_ITEMS = 12; // Кол-во пунктов меню
    
    while (1) {
    	switch (menu(menuItems, NUM_MENU_ITEMS, " ГЛАВНОЕ МЕНЮ:") + 1) {
    	
    	// проверки: зайти с существующей таблицей,
    	case 1: {
    		if (yesOrNo(" Точно создаём таблицу?") == 1) break;

    		// Если таблица уже есть
    		if (head) {
    			const char *optionsForCreatingTable[] = {
	    			" Удалить текущую таблицу без сохранения и создавать новую",
	    			" Сохранить текущую таблицу, затем создать новую",
	    			" Добавить элементы в существующую таблицу",
	    			" Хочу выйти, не хочу создавать новую таблицу"
    			};
    			UI exit = 0;
    			switch (menu(optionsForCreatingTable, 4, " У вас уже есть таблица! Выберите действие:")) {
    				case 0: {
    					deleteTable(&head);
    					break;
    				}
    				case 1: {
    					saveTable(head);
    					deleteTable(&head);
    					break;
    				}
    				case 2: {
    					break;
    				}
    				case 3: {
    					exit = 1;
    					break;
    				}
    			}
    			if (exit == 1) break; //выход из "case 1"
			}
			
			// Ввод элементов
			do {
				addNewElement(&head, setInfo(head));
			} while (yesOrNo(" Продолжаем добавление элементов?") == 0);
			break;
		}
		

		case 2: {
			if (yesOrNo(" Точно показать таблицу?") == 1) break;
			showTable(head);
			break;
		}
		

		case 3: {
			if (yesOrNo(" Точно добавляем новую запись?") == 1) break;
			addNewElement(&head, setInfo(head));
			break;
		}
		

		case 4: {
			if (yesOrNo(" Точно удаляем запись?") == 1) break;
			deleteElement(&head);
			break;
		}
		

		case 5: {
			if (yesOrNo(" Точно удаляем таблицу?") == 1) break;
			deleteTable(&head);
			break;
		}
		

		case 6: {
			if (yesOrNo(" Точно корректируем запись в таблице?") == 1) break;
			correctRecord(selectElement(head));
			break;
		}

		
		case 7: {
			if (yesOrNo(" Точно сортируем записи?") == 1) break;
			if (head != NULL) {
				const char *ascendingOrDescending[] = {
					" По возрастанию",
					" По убыванию"
				};
				if(menu(ascendingOrDescending, 2, " Как сортируем?") == 0) {
					sortTableAscending(&head);
				}
				else {
					sortTableDescending(&head);
				}
			  	system("cls");
			  	printf("\n\n Сортировка успешно завершена!\n\n ");
				system("pause");
			}
			else {
				system("cls");
				printf("\n\n\a Записей нет, сортировать нечего! \n\n");
				system("pause");
			}
			break;
		}

		
		case 8: {
			if (yesOrNo(" Точно ищем запись в таблице?") == 1) break;
			if (head != NULL) {
				showOneElement(searchElement(head));
			}
			else {
				system("cls");
				printf("\n\n\a А таблицы то нет! Где искать собрались? \n\n");
				system("pause");
			}
			break;
		}

		
		case 9: {
			if (yesOrNo(" Точно сохраняем таблицу в файл?") == 1) break;
			const char *where[] = {
    				" В текстовоый",
    				" В бинарный",
    			};
			if (menu(where, 2, " В какой файл сохраняем таблицу?") == 0) {
				saveTable(head);
			}
			else {
				saveTableBIN(head);
			}
			break;
		}
		

		case 10: {
			if (yesOrNo(" Точно читаем таблицу из файла?") == 1) break;
			// Если таблица уже существует
			if (head != NULL) {
				const char *tableAlreadyExists[] = {
    				" Удалить текущую таблицу без сохранения и считать новую из текстового файла",
    				" Сохранить текущую таблицу, затем считать новую из файла",
    				" Хочу выйти, передумал считывать таблицу из файла"
    			};
				UI exit = 0;
				switch (menu(tableAlreadyExists, 3, " У вас уже есть таблица! Выберите действие:")) {
					case 0: {
						deleteTable(&head);
						break;
					}
					case 1: {
						saveTable(head);
						deleteTable(&head);
						break;
					}
					case 2: {
						exit = 1;
						break;
					}
				}
				if (exit == 1) break; //выход из "case 9"
			}

			// Если же таблицы нет, то смело её читаем
			const char *where[] = {
    				" Из текстового",
    				" Из бинарного",
    			};
			if (menu(where, 2, " Из какого файла читаем таблицу?") == 0) {
				readTable(&head);
			}
			else{
				readTableBIN(&head);
			}
			break;
		}
		

		case 11: {
			if (yesOrNo(" Точно определяем товароборт?") == 1) break;
			determineTurnoverForEachStore(head);
			break;
		}
		

		case 12: {
			if (yesOrNo(" Вы точно сделали всё что хотели?") == 1) break;

			//Автоматическое сохранение таблицы в формате .bin (типизированный файл)
    		autoSaveTableBin(head);

			deleteTable(&head);
			return 0;
		}
	} //switch
	} //while(1)
}


/*
GetStdHandle(STD_OUTPUT_HANDLE) для того чтобы курсор устанавливался в нашей консоли
*/