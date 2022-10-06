#pragma once

#include "entity.h"
#include "builder.h"

#include <vector>

using namespace std;

// класс маршрутного такси (в программе - автобус)
class Bus : public Entity {

protected:
	
	int id;
	// координата автобуса от начала маршрута (км)
	double position;
	// скорость автобуса (км/ч)
	double velocity;
	// флаг, показывающий, движется автобус или стоит
	bool inTransit;
	// сслыка на маршрут, по которому движется автобус
	Entity* parentRoute;
	// флаг, показывающий, что автобус подлежит удалению
	bool needToDelete;
	// массив остановок, мимо которых проехал автобус (в том числе посещенные им)
	vector<Entity*> passedBusstops;
	// предел ожидания на остановке в секундах
	double stopTimeLimit;
	// счетчик времени остановки
	double stopTimer;
	// массив остановок, на которых автобус останавливался
	vector<Entity*> visitedBusstops;
	// массив пассажиров
	vector<Entity*> passengers;
	// получение номера первого свободного места
	int getFreeSitIndex();

	// average load

public:
	virtual ~Bus();
	virtual void tick(double delta);

	int getId();
	bool isNeedToDelete();
	double getPosition();
	void setParentRoute(Entity* route);
	vector<Entity*>* getPassedBusstops();
	vector<Entity*>* getVisitedBusstops();
	bool getTransitState();
	vector<Entity*>* getPassengers();

	// функция для подсчета количества пассажиров в автобусе
	int getPassengerCount();
	// количество свободных мест в автобусе
	int getFreeSeatCount();
	// надо ли кому-то из автобуса выйти на указанной остановке
	bool needToGetOff(Entity* busstop);
	// сидит ли указанный пассажир в автобусе
	bool sitOnTheBus(Entity* passenger);

	friend class BusBuilder;

};

// паттерн билдер для создания автобуса
class BusBuilder : public Builder {
protected:
	double position = 0.0;
	double velocity = 0.0;
	bool inTransit = false;
	bool needToDelete = false;
	int idCounter = 0;
	double stopTimeLimit = 0.0;
	// задает количество мест в автобусе. не хранится в классе автобуса,
	// нужна для задания размера массива пассажиров в автобусе
	int passengersLimit = 0;

public:
	BusBuilder* setPosition(double pos);
	BusBuilder* setVelocity(double vel);
	BusBuilder* setTransit(bool t);
	BusBuilder* setStopTimeLimit(double stl);
	BusBuilder* setPassengersLimit(int pl);
	virtual Entity* build();

};
