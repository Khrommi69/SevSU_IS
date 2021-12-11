#include "../headers/functions.h"

// ���������� ��� ���?
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


// ���� ���������� �� ����� ��������
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


// ����� ����� �������
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


// �������� ���������� � ��������
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


// �������� ���� ������
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


// �������� ��������� � ��������� ������
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


// ������� ���� �� �������
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