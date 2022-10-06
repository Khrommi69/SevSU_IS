#pragma once

#include "entity.h"
#include "builder.h"

#include <vector>

using namespace std;

class Busstop : public Entity {

protected:
	int id;
	// ���������� ��������� �� ��������
	double position;
	// ������ �� �������, �� ������� ��������� ���������
	Entity* parentRoute;
	// ������ ��������� ����������
	vector<Entity*> waitingPassengers;
	// ������ ��������� ����������
	vector<Entity*> arrivalPassengers;
	// ������ �� ������ ����������
	Builder* passengerBuilder;
	// ��������� ��������� ���������� �� ���������
	bool spawnEnable = false;
	// �������� ���������� ����� ��������� ���������� ������� ����� ����� ������� ���������
	// ����������� ����� ��������� ���������
	double lowSpawnTime = 0.0;
	// ������������ ����� ��������� ���������
	double highSpawnTime = 0.0;
	// ������ ��������� ���������
	double spawnTimer;
	// ����� ��� ����� �������� �������
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

	// ���� �� �� ��������� ���������, ��������� �������
	bool haveWaiters();

	vector<Entity*>* getWaitingPassengers();
	// ���������� ���������� ��������� �� ���������
	void addArrival(Entity* passenger);

	// �������� ��������� �� ��������� � �������� ���������, ���� �� ����� ������
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