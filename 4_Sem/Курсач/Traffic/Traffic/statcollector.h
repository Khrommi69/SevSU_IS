#pragma once

#include <vector>
#include <map>

using namespace std;

class Statcollector {

protected:
	// ������ �� ���������� ���������� ����������� ���������
	vector<int> missedStopsCount;
	// ������ �� ���������� ������� � ����
	vector<double> tripTime;
	// ������ �� ���������� ������ ������� ������� ��� ��������� (�������� + ������)
	vector<double> totalTime;
	// ������ �������� ������������� �� id ��������
	map<int, vector<double>> busLoad;

	// ����� ������� ��� ���������� �������� ���������������� �� ��������� �������
	template<class T>
	double getAvg(vector<T>* v) {
		if (v->size() == 0) {
			return 0.0;
		}
		double sum = 0.0;
		for (T val: *v) {
			sum += (double)val;
		}
		return sum / (double)v->size();
	}

public:
	void addMissedStops(int ms);
	void addTripTime(double t);
	void addTotalTime(double t);
	void addBusLoad(int id, double load);

	// ��������� ����� �������� ���������� ������������ ���������
	double getAvgMessedStopsCount();
	// ��������� �������� ������� � ����
	double getAvgTripTime();
	// ��������� �������� ������ �������
	double getAvgTotalTime();
	// ������� ������� ������������� �������� � ��������� id
	double getAvgBusLoad(int id);
	// ������� ������������� ���� ���������
	double getAvgAllBusLoad();
	// ��������� �������� �������� ������������� � id ���������
	map<int, double> getBusStat();
};