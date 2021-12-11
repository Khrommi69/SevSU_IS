#include "../headers/functions.h"

// Продолжить или нет?
bool continueOrNot() {
	char ch;
	while(1) {
		system("cls");
		std::cout << "Продолжаем действие? y/n или д/н" << std::endl;
		std::cout << " -> "; std::cin >> ch;
		if ((ch == 'y') || (ch == 'д')) {
			return true;
		}
		else if ((ch == 'n') || (ch == 'н')) {
			return false;
		}
		std::cout << "\a";
	}
}


// Ввод информации об одном студенте
Element setData() {
	Element temp;
	system("cls");
	std::cout << "Введите имя, фамилию и отчество студента:" << std::endl;
	std::cout << " -> "; std::cin >> temp.fio.name;
	std::cout << " -> "; std::cin >> temp.fio.surname;
	std::cout << " -> "; std::cin >> temp.fio.patronymic;
	std::cout << std::endl;
	std::cout << "Введите оценки по ООП, АиП, ОСИСУ и Выш.мату:" << std::endl;
	std::cout << " -> "; std::cin >> temp.marks.OOP;
	std::cout << " -> "; std::cin >> temp.marks.AIP;
	std::cout << " -> "; std::cin >> temp.marks.OSIS;
	std::cout << " -> "; std::cin >> temp.marks.math;
	std::cout << std::endl;
	std::cout << "Введите название группы:" << std::endl;
	std::cout << " -> "; std::cin >> temp.group;
	std::cout << std::endl;
	std::cout << "Введите номер курса:" << std::endl;
	std::cout << " -> "; std::cin >> temp.course;
	return temp;
}


// Вывод шапки таблицы
void headerDataBase() {
	std::cout << "База данных:" << std::endl << std::endl;
	std::cout << "\t" << std::left;
	std::cout << std::setw(10) << "ИМЯ" << " | ";
	std::cout << std::setw(20) << "ФАМИЛИЯ" << " | ";
	std::cout << std::setw(15) << "ОТЧЕСТВО" << " | ";
	std::cout << std::setw(4) << "OOP" << " | ";
	std::cout << std::setw(4) << "AIP" << " | ";
	std::cout << std::setw(4) << "OSIS" << " | ";
	std::cout << std::setw(4) << "MATH" << " | ";
	std::cout << std::setw(15) << "ГРУППА" << " | ";
	std::cout << std::setw(4) << "КУРС" << " | " << std::endl;
	std::cout << std::setw(107) << std::setfill('x') << "\tx" << std::endl;
	std::cout << std::setfill(' ');
}


// Показать информацию о студенте
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


// Показать базу данных
void showDataBase(std::deque<Element> database) {
	if (database.empty()) {
		std::cout << "База данных пуста\a" << std::endl;
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


// Показать студентов в выбранной группе
void showSelectedGroup(std::deque<Element> database) {
	if (database.empty()) {
		std::cout << "База данных пуста\a" << std::endl;
	}
	else {
		std::string group;
		int course;
		int counter = 0;
		std::cout << "Введите группу:" << std::endl;
		std::cout << " -> "; std::cin >> group;
		std::cout << std::endl;
		std::cout << "Введите номер курса:" << std::endl;
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
			std::cout << std::endl << "Чё то мы не нашли студентов в указанной группе, с указанным курсом\a" << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	system("pause");
}


// Средний балл по группам
void averageScoreByGroup(std::deque<Element> database) {
	if (database.empty()) {
		std::cout << "База данных пуста\a" << std::endl << std::endl << std::endl;
		system("pause");
		return;
	}

	std::sort(database.begin(), database.end(), [](const Element& el1, const Element& el2) -> bool { 
			return el1.group < el2.group;
		}
	);

	// Можно было перегрузить "<"
	// bool operator < (const Element& el1, const Element& el2) {
	// 	return el1.group < el2.group;
	// }
	// и сделать так: std::sort(database.begin(), database.end());

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
			std::cout << "\tВ группе: " << currentGroup << " средний балл" << std::endl;
			std::cout << "\tпо ООП = " << (currentOOP / counter) << std::endl;
			std::cout << "\tпо АиП = " << (currentAIP / counter) << std::endl;
			std::cout << "\tпо ОСИС = " << (currentOSIS / counter) << std::endl;
			std::cout << "\tпо выш.мату = " << (currentMATH / counter) << std::endl;
			std::cout << "\tсредний балл по всем предметам = " << (((currentOOP + currentAIP + currentOSIS + currentMATH)) / (counter*4)) << std::endl << std::endl;
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