#pragma once

#include "entity.h"
#include "builder.h"

class Passenger : public Entity {

protected:
	int id;
	// стартовая остановка (с которой пассажир сажидся в автобус)
	Entity* startBusstop = nullptr;
	// целевая остановка (куда пассажиру надо дораться)
	Entity* targetBusstop = nullptr;
	// счетчик времени в пути
	double tripTimer = 0.0;
	// счетчик всего времени (ожидание + поездка)
	double totalTime = 0.0;
	// счетчик времени посадки/высадки
	double boardingTimer = 0.0;
	// флаг того, что пассажир находится в пути
	bool onTrip = false;
	// флаг того, что пассажир садится/выходит
	bool isBoarding = false;
	// время посадки/высадки пассажира
	double boardingTimeLimit;

public:

	virtual void tick(double delta);

	int getId();

	void setStartBusstop(Entity* busstop);
	Entity* getStartBusstop();
	void setTargetBusstop(Entity* busstop);
	Entity* getTargetBusstop();

	// метод используется для посадки и высадки. первое использование - посадка
	// далее считается, что пассажир находится в пути
	// второе использование - высадка, считается, что пассажир приехал в пункт назначения
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
