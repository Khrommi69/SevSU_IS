#pragma once

#include "entity.h"
#include "builder.h"

#include <vector>

using namespace std;

class Busstop : public Entity {

protected:
	int id;
	// координата остановки на маршруте
	double position;
	// сслыка на маршрут, на котором находится остановка
	Entity* parentRoute;
	// массив ожидающих пассажиров
	vector<Entity*> waitingPassengers;
	// массив прибывших пассажиров
	vector<Entity*> arrivalPassengers;
	// ссылка на билдер пассажиров
	Builder* passengerBuilder;
	// разрешает появление пассажиров на остановке
	bool spawnEnable = false;
	// пассажир появляется через случайный промежуток времени между двумя данными временами
	// минимальное время появления пассажира
	double lowSpawnTime = 0.0;
	// макисмальное время появления пассажира
	double highSpawnTime = 0.0;
	// таймер появления пассажира
	double spawnTimer;
	// через это время появится пасажир
	double currentSpawnTime;

	// passenger spawn speed

public:
	virtual void tick(double delta);

	int getId();
	double getPosition();
	void setParentRoute(Entity* route);
	Entity* getParentRoute();
	void setPassengerBuilder(Builder* builder);
	Builder* getPassengerBuilder();

	// есть ли на остановке пассажиры, ожидающие автобус
	bool haveWaiters();

	vector<Entity*>* getWaitingPassengers();
	// добавление прибывшего пассажира на остановку
	void addArrival(Entity* passenger);

	// создание пассажира на остановке с заданием остановки, куда он хочет уехать
	void spawnPassenger(Entity* targetBusstop);
	void despawnPassenger(Entity* passenger);

	friend class BusstopBuilder;

};

class BusstopBuilder : public Builder {
protected:
	double position = 0.0;
	int idCounter = 0;
	Builder* passengerBuilder;
	Entity* parentRoute;
	bool spawnEnable;
	double lowSpawnTime;
	double highSpawnTime;
public:
	virtual Entity* build();

	BusstopBuilder* setPosition(double pos);
	BusstopBuilder* setPassengerBuilder(Builder* builder);
	BusstopBuilder* setParentRoute(Entity* route);
	BusstopBuilder* setSpawnEnable(bool flag);
	BusstopBuilder* setLowSpawnTime(double time);
	BusstopBuilder* setHighSpawnTime(double time);
};