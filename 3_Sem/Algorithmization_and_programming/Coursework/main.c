// ���������� � ������� ������� ������������ �� ���������� ������: ����� ��������; ����� ������; ����� ����; ������������ ������; ������� ������;
// ���� ������; ���������� ������; ���� �������. ��������� ��������� �����������
// ������ ������������� �� ������� ��������, �.�. ����� �����, ���������� ��
// ������� ���� ������� � ������ �������� (������ �������� ������ �� ����������
// ���������). ����������� ����� ��������� ���������.

#include "headers/structures.h"
#include "headers/specialFunctions.h"
#include "headers/workWithTable.h"
#include "headers/setData.h"
#include "headers/saveAndDownloadTable.h"

//==============================================================================
//                                MAIN
//==============================================================================
int main() {
    // ��������� �������� �����
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // ������ ��� ������� ������-�������, ����� ������
    SetConsoleTitle("������ �� �����");
    system("color B0");
    system ("mode con cols=161 lines=30");

	Element *head = NULL;

    const char *firstMenu[] = {
		" C������� ������� �������", 
		" �������� ������� �� ���������� �����",
		" �������� ������� �� ��������� �����",
		" �������� ��������������",
		" ���������� ��� �������",
		" �����"
	};
    switch (menu(firstMenu, 6, " �������� ������ ���������� �������� �������:") + 1) {
    	case 1: {
			do {
				addNewElement(&head, setInfo(head));
			} while (yesOrNo(" ���������� ���������� ���������?") == 0);
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
		" C������� �������", 
		" �������� �������",
		" ���������� ����� ������ � �������",
		" �������� ������",
		" �������� �������",
		" ������������� ������ � �������",
		" ���������� ������� (�� ���������)",
		" ����� ������ � �������",
		" ���������� ������� � �����",
		" ������ ������ �� �����",
		" ���������� ����� ������������� �� ������� ��������",
		" �����"
	};
	const int NUM_MENU_ITEMS = 12; // ���-�� ������� ����
    
    while (1) {
    	switch (menu(menuItems, NUM_MENU_ITEMS, " ������� ����:") + 1) {
    	
    	// ��������: ����� � ������������ ��������,
    	case 1: {
    		if (yesOrNo(" ����� ������ �������?") == 1) break;

    		// ���� ������� ��� ����
    		if (head) {
    			const char *optionsForCreatingTable[] = {
	    			" ������� ������� ������� ��� ���������� � ��������� �����",
	    			" ��������� ������� �������, ����� ������� �����",
	    			" �������� �������� � ������������ �������",
	    			" ���� �����, �� ���� ��������� ����� �������"
    			};
    			UI exit = 0;
    			switch (menu(optionsForCreatingTable, 4, " � ��� ��� ���� �������! �������� ��������:")) {
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
    			if (exit == 1) break; //����� �� "case 1"
			}
			
			// ���� ���������
			do {
				addNewElement(&head, setInfo(head));
			} while (yesOrNo(" ���������� ���������� ���������?") == 0);
			break;
		}
		

		case 2: {
			if (yesOrNo(" ����� �������� �������?") == 1) break;
			showTable(head);
			break;
		}
		

		case 3: {
			if (yesOrNo(" ����� ��������� ����� ������?") == 1) break;
			addNewElement(&head, setInfo(head));
			break;
		}
		

		case 4: {
			if (yesOrNo(" ����� ������� ������?") == 1) break;
			deleteElement(&head);
			break;
		}
		

		case 5: {
			if (yesOrNo(" ����� ������� �������?") == 1) break;
			deleteTable(&head);
			break;
		}
		

		case 6: {
			if (yesOrNo(" ����� ������������ ������ � �������?") == 1) break;
			correctRecord(selectElement(head));
			break;
		}

		
		case 7: {
			if (yesOrNo(" ����� ��������� ������?") == 1) break;
			if (head != NULL) {
				const char *ascendingOrDescending[] = {
					" �� �����������",
					" �� ��������"
				};
				if(menu(ascendingOrDescending, 2, " ��� ���������?") == 0) {
					sortTableAscending(&head);
				}
				else {
					sortTableDescending(&head);
				}
			  	system("cls");
			  	printf("\n\n ���������� ������� ���������!\n\n ");
				system("pause");
			}
			else {
				system("cls");
				printf("\n\n\a ������� ���, ����������� ������! \n\n");
				system("pause");
			}
			break;
		}

		
		case 8: {
			if (yesOrNo(" ����� ���� ������ � �������?") == 1) break;
			if (head != NULL) {
				showOneElement(searchElement(head));
			}
			else {
				system("cls");
				printf("\n\n\a � ������� �� ���! ��� ������ ���������? \n\n");
				system("pause");
			}
			break;
		}

		
		case 9: {
			if (yesOrNo(" ����� ��������� ������� � ����?") == 1) break;
			const char *where[] = {
    				" � ����������",
    				" � ��������",
    			};
			if (menu(where, 2, " � ����� ���� ��������� �������?") == 0) {
				saveTable(head);
			}
			else {
				saveTableBIN(head);
			}
			break;
		}
		

		case 10: {
			if (yesOrNo(" ����� ������ ������� �� �����?") == 1) break;
			// ���� ������� ��� ����������
			if (head != NULL) {
				const char *tableAlreadyExists[] = {
    				" ������� ������� ������� ��� ���������� � ������� ����� �� ���������� �����",
    				" ��������� ������� �������, ����� ������� ����� �� �����",
    				" ���� �����, ��������� ��������� ������� �� �����"
    			};
				UI exit = 0;
				switch (menu(tableAlreadyExists, 3, " � ��� ��� ���� �������! �������� ��������:")) {
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
				if (exit == 1) break; //����� �� "case 9"
			}

			// ���� �� ������� ���, �� ����� � ������
			const char *where[] = {
    				" �� ����������",
    				" �� ���������",
    			};
			if (menu(where, 2, " �� ������ ����� ������ �������?") == 0) {
				readTable(&head);
			}
			else{
				readTableBIN(&head);
			}
			break;
		}
		

		case 11: {
			if (yesOrNo(" ����� ���������� ����������?") == 1) break;
			determineTurnoverForEachStore(head);
			break;
		}
		

		case 12: {
			if (yesOrNo(" �� ����� ������� �� ��� ������?") == 1) break;

			//�������������� ���������� ������� � ������� .bin (�������������� ����)
    		autoSaveTableBin(head);

			deleteTable(&head);
			return 0;
		}
	} //switch
	} //while(1)
}


/*
GetStdHandle(STD_OUTPUT_HANDLE) ��� ���� ����� ������ �������������� � ����� �������
*/