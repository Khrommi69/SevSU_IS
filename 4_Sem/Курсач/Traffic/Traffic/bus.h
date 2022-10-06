#pragma once

#include "entity.h"
#include "builder.h"

#include <vector>

using namespace std;

// ����� ����������� ����� (� ��������� - �������)
class Bus : public Entity {

protected:
	
	int id;
	// ���������� �������� �� ������ �������� (��)
	double position;
	// �������� �������� (��/�)
	double velocity;
	// ����, ������������, �������� ������� ��� �����
	bool inTransit;
	// ������ �� �������, �� �������� �������� �������
	Entity* parentRoute;
	// ����, ������������, ��� ������� �������� ��������
	bool needToDelete;
	// ������ ���������, ���� ������� ������� ������� (� ��� ����� ���������� ��)
	vector<Entity*> passedBusstops;
	// ������ �������� �� ��������� � ��������
	double stopTimeLimit;
	// ������� ������� ���������
	double stopTimer;
	// ������ ���������, �� ������� ������� ��������������
	vector<Entity*> visitedBusstops;
	// ������ ����������
	vector<Entity*> passengers;
	// ��������� ������ ������� ���������� �����
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

	// ������� ��� �������� ���������� ���������� � ��������
	int getPassengerCount();
	// ���������� ��������� ���� � ��������
	int getFreeSeatCount();
	// ���� �� ����-�� �� �������� ����� �� ��������� ���������
	bool needToGetOff(Entity* busstop);
	// ����� �� ��������� �������� � ��������
	bool sitOnTheBus(Entity* passenger);

	friend class BusBuilder;

};

// ������� ������ ��� �������� ��������
class BusBuilder : public Builder {
protected:
	double position = 0.0;
	double velocity = 0.0;
	bool inTransit = false;
	bool needToDelete = false;
	int idCounter = 0;
	double stopTimeLimit = 0.0;
	// ������ ���������� ���� � ��������. �� �������� � ������ ��������,
	// ����� ��� ������� ������� ������� ���������� � ��������
	int passengersLimit = 0;

public:
	BusBuilder* setPosition(double pos);
	BusBuilder* setVelocity(double vel);
	BusBuilder* setTransit(bool t);
	BusBuilder* setStopTimeLimit(double stl);
	BusBuilder* setPassengersLimit(int pl);
	virtual Entity* build();

};
