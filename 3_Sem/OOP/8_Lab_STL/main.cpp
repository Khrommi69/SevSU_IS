#include "headers/structures.h"
#include "headers/functions.h"
#include "headers/saveAndDownload.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

    std::deque<Element> database;
	char ch;
	while (1) {
		system("cls");
		std::cout << "1 - �������� ���� ������ (���������� ��������� � ����� �������)" << std::endl;
		std::cout << "2 - �������� ���� ������ �� �����" << std::endl;
		std::cout << "3 - ��������� ���� ������ � ����" << std::endl;
		std::cout << "4 - ����� ���� ������" << std::endl;
		std::cout << "5 - ����� ���������� � ��������� ����������� ������, �����" << std::endl;
		std::cout << "6 - ���������� � ����� ���������� � ������� ����� �����" << std::endl;
		std::cout << "7 - �������� ���� ������" << std::endl;
		std::cout << "8 - �����" << std::endl;
		std::cout << " -> "; std::cin >> ch;
		system("cls");

		switch (ch) {
			case '1' : {
				do {
					database.push_back( setData() );
				} while ( continueOrNot() );
				break;
			} 

			case '2' : {
				database.clear();
				database = downloadDataBase(database);
				break;
			}

			case '3' : {
				saveDataBase(database);
				break;
			}

			case '4' : {
				showDataBase(database);
				break;
			}

			case '5' : {
				showSelectedGroup(database);
				break;
			}

			case '6' : {
				averageScoreByGroup(database);
				break;
			}

			case '7' : {
				database.clear();
				break;
			}

			case '8' : {
				database.clear();
				return 0;
			}
		}
	}
}