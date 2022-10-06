#include "passenger.h"

void Passenger::tick(double delta)
{
	// ����������� ������� ����� �������
	totalTime += delta;
	// ���� � ����
	if (onTrip) {
		// ����������� ����� � ���� �� ��� �������������
		tripTimer += delta;
	}
	// ���� �������������� �������/�������
	if (isBoarding) {
		// ����������� ������
		boardingTimer += delta;
		// ���� ����� �������/������� ������
		if (boardingTimer > boardingTimeLimit) {
			// ��������� �������/�������
			isBoarding = false;
			// ������ ������ "� ����" �� �������� (���� - � ���� - �����)
			onTrip = !onTrip;
		}
	}
}

int Passenger::getId()
{
	return id;
}

void Passenger::setStartBusstop(Entity* busstop)
{
	startBusstop = busstop;
}

Entity* Passenger::getStartBusstop()
{
	return startBusstop;
}

void Passenger::setTargetBusstop(Entity* busstop)
{
	targetBusstop = busstop;
}

Entity* Passenger::getTargetBusstop()
{
	return targetBusstop;
}

void Passenger::startBoarding()
{
	isBoarding = true;
	boardingTimer = 0.0;
}

bool Passenger::isBoardingEnded()
{
	return !isBoarding;
}

bool Passenger::isOnTrip()
{
	return onTrip;
}

double Passenger::getTripTime()
{
	return tripTimer;
}

double Passenger::getTotalTime()
{
	return totalTime;
}

Entity* PassengerBuilder::build()
{
	Passenger* passenger = new Passenger();
	passenger->id = idCounter++;
	passenger->startBusstop = nullptr;
	passenger->targetBusstop = nullptr;
	passenger->tripTimer = 0.0;
	passenger->totalTime = 0.0;
	passenger->boardingTimer = 0.0;
	passenger->onTrip = false;
	passenger->isBoarding = false;
	passenger->boardingTimeLimit = boardingTimeLimit;
	return passenger;
}

PassengerBuilder* PassengerBuilder::setBoardingTimeLimit(double boardingTime)
{
	boardingTimeLimit = boardingTime;
	return this;
}
