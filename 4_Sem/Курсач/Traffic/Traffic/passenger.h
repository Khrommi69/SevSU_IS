#pragma once

#include "entity.h"
#include "builder.h"

class Passenger : public Entity {

protected:
	int id;
	// ��������� ��������� (� ������� �������� ������� � �������)
	Entity* startBusstop = nullptr;
	// ������� ��������� (���� ��������� ���� ��������)
	Entity* targetBusstop = nullptr;
	// ������� ������� � ����
	double tripTimer = 0.0;
	// ������� ����� ������� (�������� + �������)
	double totalTime = 0.0;
	// ������� ������� �������/�������
	double boardingTimer = 0.0;
	// ���� ����, ��� �������� ��������� � ����
	bool onTrip = false;
	// ���� ����, ��� �������� �������/�������
	bool isBoarding = false;
	// ����� �������/������� ���������
	double boardingTimeLimit;

public:

	virtual void tick(double delta);

	int getId();

	void setStartBusstop(Entity* busstop);
	Entity* getStartBusstop();
	void setTargetBusstop(Entity* busstop);
	Entity* getTargetBusstop();

	// ����� ������������ ��� ������� � �������. ������ ������������� - �������
	// ����� ���������, ��� �������� ��������� � ����
	// ������ ������������� - �������, ���������, ��� �������� ������� � ����� ����������
	void startBoarding();
	bool isBoardingEnded();
	bool isOnTrip();

	double getTripTime();
	double getTotalTime();

	friend class PassengerBuilder;

};

class PassengerBuilder : public Builder {

protected:
	int idCounter = 0;
	double boardingTimeLimit;

public:
	virtual Entity* build();

	PassengerBuilder* setBoardingTimeLimit(double boardingTime);
};
