#pragma once

#include <vector>
#include <map>

using namespace std;

class ExperimentInputData {
public:
	// �������� �������� �������� (��/�)
	double busVelocity;
	// ����� �������� �������� �� ��������� (�)
	double busstopWaitingTime;
	// ���������� ���� � ��������
	int seatLimit;
	// ���������� ��������� �� ��������
	int busCount;
	// ����� �������/������� ��������� (�)
	double boardingTime;
	// ��������� ����� ���������� �� ��������� ������������ �����:
	int initPassengersLowCount;
	int initPassengersHighCount;
	// ��������� �������� �� ��������� �������� � ��������� ����� (�) �����:
	double passengerLowSpawnTime;
	double passengerHighSpawnTime;
	// ������ ��������� ��������� �� �������� (��)
	vector<double> busstops;
	// ��� �������������
	double dt;
	// ����� �������������
	double modelingTime;
};

class ExperimentOutputData {
public:
	// ������� ��������� ������������ ���������
	double missedBusstops;
	// ������� ����� ��������� � ���� (c)
	double tripTime;
	// ������� ����� ��������� � ���� � ������ ������� �������� (c)
	double totalTime;
	// ������� ������������� �� ��������� (%)
	map<int, double> busLoad;
	// ������ ������������� ���� ��������� (%)
	double allBusLoad;
	// ����� ���������� ������������ (c)
	double time;
};

// ������� ��� ���������� �������������
ExperimentOutputData doExperiment(ExperimentInputData inputData);
