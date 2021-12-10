#include <iostream>
#include <windows.h>
#include <deque>
#include <iomanip>

struct FIO {
	std::string name;
	std::string surname;
	std::string patronymic;
};

struct Marks {
	int OOP;
	int AIP;
	int OSIS;
	int math;
};

struct Element {
	FIO fio;
	Marks marks;
	std::string group;
	int course;
};

bool continueOrNot(){
	char ch;
	while(1) {
		system("cls");
		std::cout << "���������� ��������? y/n ��� �/�" << std::endl;
		std::cout << " -> "; std::cin >> ch;
		if ((ch == 'y') || (ch == '�')) {
			return true;
		}
		else if ((ch == 'n') || (ch == '�')) {
			return false;
		}
		std::cout << "\a";
	}
}

Element setData(){
	Element temp;
	system("cls");
	std::cout << "������� ���, ������� � �������� ��������:" << std::endl;
	std::cout << " -> "; std::cin >> temp.fio.name;
	std::cout << " -> "; std::cin >> temp.fio.surname;
	std::cout << " -> "; std::cin >> temp.fio.patronymic;
	std::cout << std::endl;
	std::cout << "������� ������ �� ���, ���, ����� � ���.����:" << std::endl;
	std::cout << " -> "; std::cin >> temp.marks.OOP;
	std::cout << " -> "; std::cin >> temp.marks.AIP;
	std::cout << " -> "; std::cin >> temp.marks.OSIS;
	std::cout << " -> "; std::cin >> temp.marks.math;
	std::cout << std::endl;
	std::cout << "������� �������� ������:" << std::endl;
	std::cout << " -> "; std::cin >> temp.group;
	std::cout << std::endl;
	std::cout << "������� ����� �����:" << std::endl;
	std::cout << " -> "; std::cin >> temp.course;
	return temp;
}

void headerDataBase(){
	std::cout << "���� ������:" << std::endl << std::endl;
	std::cout << "\t";
	std::cout << std::setw(10) << std::left << "���" << " | ";
	std::cout << std::setw(20) << std::left << "�������" << " | ";
	std::cout << std::setw(15) << std::left << "��������" << " | ";
	std::cout << std::setw(4) << std::left << "OOP" << " | ";
	std::cout << std::setw(4) << std::left << "AIP" << " | ";
	std::cout << std::setw(4) << std::left << "OSIS" << " | ";
	std::cout << std::setw(4) << std::left << "MATH" << " | ";
	std::cout << std::setw(15) << std::left << "������" << " | ";
	std::cout << std::setw(4) << std::left << "����" << " | " << std::endl;
	std::cout << std::setw(107) << std::left << std::setfill('x') << "\tx" << std::endl;

}



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
		std::cout << "3 - ����� ���� ������" << std::endl;
		std::cout << "4 - ����� ���������� � ��������� ����������� ������, �����" << std::endl;
		std::cout << "5 - ���������� � ����� ���������� � ������� ����� �����" << std::endl;
		std::cout << "6 - �������� ���� ������" << std::endl;
		std::cout << "7 - �����" << std::endl;
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
				break;
			}

			case '3' : {
				if (database.empty()) {
					std::cout << "���� ������ �����\a" << std::endl;
				}
				else {
					headerDataBase();
					for (std::deque<Element>::iterator i = database.begin(); i != database.end(); i++) {
						std::cout << "\t";
						std::cout << std::setw(10) << std::left << (*i).fio.name << " | ";
						std::cout << std::setw(20) << std::left << (*i).fio.surname << " | ";
						std::cout << std::setw(15) << std::left << (*i).fio.patronymic << " | ";
						std::cout << std::setw(4) << std::left << (*i).marks.OOP << " | ";
						std::cout << std::setw(4) << std::left << (*i).marks.AIP << " | ";
						std::cout << std::setw(4) << std::left << (*i).marks.OSIS << " | ";
						std::cout << std::setw(4) << std::left << (*i).marks.math << " | ";
						std::cout << std::setw(15) << std::left << (*i).group << " | ";
						std::cout << std::setw(4) << std::left << (*i).course << " | " << std::endl;
					}
				}
				std::cout << std::endl << std::endl;
				system("pause");
				break;
			}

			case '4' : {
				break;
			}

			case '5' : {
				break;
			}

			case '6' : {
				database.clear();
				break;
			}

			case '7' : {
				database.clear();
				return 0;
			}
		}
	}
}