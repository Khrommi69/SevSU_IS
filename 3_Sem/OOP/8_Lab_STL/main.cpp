#include <iostream>
#include <windows.h>
#include <deque>
#include <iomanip>
#include <fstream>
#include <algorithm>

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

bool continueOrNot() {
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

Element setData() {
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

void headerDataBase() {
	std::cout << "���� ������:" << std::endl << std::endl;
	std::cout << "\t" << std::left;
	std::cout << std::setw(10) << "���" << " | ";
	std::cout << std::setw(20) << "�������" << " | ";
	std::cout << std::setw(15) << "��������" << " | ";
	std::cout << std::setw(4) << "OOP" << " | ";
	std::cout << std::setw(4) << "AIP" << " | ";
	std::cout << std::setw(4) << "OSIS" << " | ";
	std::cout << std::setw(4) << "MATH" << " | ";
	std::cout << std::setw(15) << "������" << " | ";
	std::cout << std::setw(4) << "����" << " | " << std::endl;
	std::cout << std::setw(107) << std::setfill('x') << "\tx" << std::endl;
	std::cout << std::setfill(' ');
}

void showStudent(std::deque<Element>::iterator i) {
	std::cout << "\t" << std::left;
	std::cout << std::setw(10) << (*i).fio.name << " | ";
	std::cout << std::setw(20) << (*i).fio.surname << " | ";
	std::cout << std::setw(15) << (*i).fio.patronymic << " | ";
	std::cout << std::setw(4) << (*i).marks.OOP << " | ";
	std::cout << std::setw(4) << (*i).marks.AIP << " | ";
	std::cout << std::setw(4) << (*i).marks.OSIS << " | ";
	std::cout << std::setw(4) << (*i).marks.math << " | ";
	std::cout << std::setw(15) << (*i).group << " | ";
	std::cout << std::setw(4) << (*i).course << " | " << std::endl;
}

void showDataBase(std::deque<Element> database) {
	if (database.empty()) {
		std::cout << "���� ������ �����\a" << std::endl;
	}
	else {
		headerDataBase();
		for (std::deque<Element>::iterator i = database.begin(); i != database.end(); i++) {
			showStudent(i);
		}
	}
	std::cout << std::endl << std::endl;
	system("pause");
}

void showSelectedGroup(std::deque<Element> database) {
	if (database.empty()) {
		std::cout << "���� ������ �����\a" << std::endl;
	}
	else {
		std::string group;
		int course;
		int counter = 0;
		std::cout << "������� ������:" << std::endl;
		std::cout << " -> "; std::cin >> group;
		std::cout << std::endl;
		std::cout << "������� ����� �����:" << std::endl;
		std::cout << " -> "; std::cin >> course;
		std::cout << std::endl;
		headerDataBase();
		for (std::deque<Element>::iterator i = database.begin(); i != database.end(); i++) {
			if (((*i).group == group) && ((*i).course == course)) {
				counter++;
				showStudent(i);
			}
		}
		if (counter == 0) {
			std::cout << std::endl << "׸ �� �� �� ����� ��������� � ��������� ������, � ��������� ������\a" << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	system("pause");
}

void saveDataBase(std::deque<Element> database) {
	std::string filename;
	std::cout << "������� ��� ���������� �����:" << std::endl;
	std::cout << " -> "; std::cin >> filename;
	std::cout << std::endl;

	// ������� ���� ��� ������
	std::ofstream fout(filename);

	if (!fout.is_open()) {
		std::cout << "ERROR: ������ �������� �����: \a" << filename << std::endl << std::endl;
		system("pause");
		return;
	}

	for(std::deque<Element>::iterator i = database.begin(); i != database.end(); i++) {
		fout << (*i).fio.name << std::endl;
		fout << (*i).fio.surname << std::endl;
		fout << (*i).fio.patronymic << std::endl;
		fout << (*i).marks.OOP << std::endl;
		fout << (*i).marks.AIP << std::endl;
		fout << (*i).marks.OSIS << std::endl;
		fout << (*i).marks.math << std::endl;
		fout << (*i).group << std::endl;
		fout << (*i).course << std::endl;
	}
	fout.close();

	std::cout << "���� ������ ������� ��������� � ���� " << filename << std::endl << std::endl;
	system("pause");
}

std::deque<Element> downloadDataBase(std::deque<Element> database) {
	std::string filename;
	std::cout << "������� ��� ���������� �����:" << std::endl;
	std::cout << " -> "; std::cin >> filename;
	std::cout << std::endl;

	// ������� ���� ��� ������
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		std::cout << "ERROR: ������ �������� �����: \a" << filename << std::endl << std::endl;
		system("pause");
		return database;
	}
	
	Element temp;
	while (1) {
		fin >> temp.fio.name;
		fin >> temp.fio.surname;
		fin >> temp.fio.patronymic;
		fin >> temp.marks.OOP;
		fin >> temp.marks.AIP;
		fin >> temp.marks.OSIS;
		fin >> temp.marks.math;
		fin >> temp.group;
		fin >> temp.course;
		if (fin.eof()) break;
		database.push_back( temp );
	}

	fin.close();

	std::cout << "���� ������ ������� ��������� �� ����� " << filename << std::endl << std::endl;
	system("pause");
	return database;
}

void averageScoreByGroup(std::deque<Element> database) {
	if (database.empty()) {
		std::cout << "���� ������ �����\a" << std::endl << std::endl << std::endl;
		system("pause");
		return;
	}

	std::sort(database.begin(), database.end(), [](const Element& el1, const Element& el2) -> bool { 
			return el1.group < el2.group;
		}
	);

	// ����� ���� ����������� "<"
	// bool operator < (const Element& el1, const Element& el2) {
	// 	return el1.group < el2.group;
	// }
	// � ������� ���: std::sort(database.begin(), database.end());

	std::deque<Element>::iterator i = database.begin();
	std::string currentGroup = (*i).group;
	float currentOOP = 0;
	float currentAIP = 0;
	float currentOSIS = 0;
	float currentMATH = 0;
	int counter = 0;

	while (i != database.end() + 1) {
		if ((*i).group == currentGroup) {
			std::cout << "��� = " << (*i).group << std::endl;

			counter++;
			currentOOP += (*i).marks.OOP;
			currentAIP += (*i).marks.AIP;
			currentOSIS += (*i).marks.OSIS;
			currentMATH += (*i).marks.math;
		}
		else {
			std::cout << "\t� ������: " << currentGroup << " ������� ����" << std::endl;
			std::cout << "\t�� ��� = " << (currentOOP / counter) << std::endl;
			std::cout << "\t�� ��� = " << (currentAIP / counter) << std::endl;
			std::cout << "\t�� ���� = " << (currentOSIS / counter) << std::endl;
			std::cout << "\t�� ���.���� = " << (currentMATH / counter) << std::endl;
			std::cout << "\t������� ���� �� ���� ��������� = " << (((currentOOP + currentAIP + currentOSIS + currentMATH)) / (counter*4)) << std::endl << std::endl;
			currentGroup = (*i).group;
			currentOOP = (*i).marks.OOP;
			currentAIP = (*i).marks.AIP;
			currentOSIS = (*i).marks.OSIS;
			currentMATH = (*i).marks.math;
			counter = 1;
		}
		i++;
	}
	system("pause");
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