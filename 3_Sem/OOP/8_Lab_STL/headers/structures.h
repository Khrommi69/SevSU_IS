#ifndef TEST_STRUCTURES_H
#define TEST_STRUCTURES_H


#include <iostream>
#include <windows.h>
#include <deque>
#include <iomanip>
#include <fstream>
#include <algorithm>


//==============================================================================
//                                —“–” “”–€
//==============================================================================
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


#endif //TEST_STRUCTURES_H