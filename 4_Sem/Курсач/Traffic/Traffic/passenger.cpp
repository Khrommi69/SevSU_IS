#include "passenger.h"

void Passenger::tick(double delta)
{
	// увеличиваем счетчик всего времени
	totalTime += delta;
	// если в пути
	if (onTrip) {
		// увеличиваем время в пути на шаг моделирования
		tripTimer += delta;
	}
	// если осуществляется посадка/высадка
	if (isBoarding) {
		// увеличиваем таймер
		boardingTimer += delta;
		// если время посадки/высадки прошло
		if (boardingTimer > boardingTimeLimit) {
			// завершаем посадку/высадку
			isBoarding = false;
			// меняем статус "в пути" на обратный (ждет - в пути - сошел)
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
