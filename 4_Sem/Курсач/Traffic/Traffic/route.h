#pragma once

#include "entity.h"
#include "builder.h"
#include "statcollector.h"

#include <vector>

using namespace std;

class Route : public Entity {

protected:
	// ����� �������� (��)
	double length;
	// ������ ���������, ������� ��������� �� ��������
	vector<Entity*> busArray;
	// ���������� ��������� �� �������� (N)
	int busCount;
	// ������ �� ������ ���������
	Builder* busBuilder;
	// ������ ���������� ���������
	vector<Entity*> busstopArray;
	// ������� ����������
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

	// ���������� ����� ���������
	int getBusstopIndex(Entity* busstop);
	// ���������� ��������� �� ��������
	int getBusstopCount();
	// ��������� �� ������
	Entity* getBusstop(int index);

	void despawnBus(Entity* ptr);
	void spawnBus();

};