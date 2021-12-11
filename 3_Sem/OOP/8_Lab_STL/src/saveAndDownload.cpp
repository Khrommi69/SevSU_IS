#include "../headers/saveAndDownload.h"


// ��������� ���� ������
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


// ��������� ���� ������
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