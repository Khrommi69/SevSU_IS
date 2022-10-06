#pragma once

#include "entity.h"
#include "builder.h"
#include "statcollector.h"

#include <vector>

using namespace std;

class Route : public Entity {

protected:
	// длина маршрута (км)
	double length;
	// массив автобусов, которые находятся на маршруте
	vector<Entity*> busArray;
	// количество автобусов на маршруте (N)
	int busCount;
	// ссылка на билдер автобусов
	Builder* busBuilder;
	// массив автобусных остановок
	vector<Entity*> busstopArray;
	// сборщик статистики
	Statcollector* statcollector;


public:
	virtual ~Route();
	virtual void tick(double delta);

	void setLength(double l);
	double getLength();
	void setBusCount(int c);
	int getBusCount();
	void setBusBuilder(Builder* builder);
	Builder* getBusBuilder();
	vector<Entity*>* getBusArray();
	vector<Entity*>* getBusstopArray();
	void setStatcollector(Statcollector* sc);
	Statcollector* getStatcollector();

	// порядковый номер остановки
	int getBusstopIndex(Entity* busstop);
	// количество остановок на маршруте
	int getBusstopCount();
	// остановка по номеру
	Entity* getBusstop(int index);

	void despawnBus(Entity* ptr);
	void spawnBus();

};