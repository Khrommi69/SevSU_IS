#pragma once

#include <vector>
#include <map>

using namespace std;

class Statcollector {

protected:
	// массив со значениями количества пропущенных остановок
	vector<int> missedStopsCount;
	// массив со значениями времени в пути
	vector<double> tripTime;
	// массив со значениями общего времени проезда для пассажира (ожидание + дорога)
	vector<double> totalTime;
	// массив значений загруженности по id автобуса
	map<int, vector<double>> busLoad;

	// общая функция для вычисления среднего арифмпетического по значениям массива
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

	// полчениче числа среднего количества пропускаемых остановок
	double getAvgMessedStopsCount();
	// получение среднего времени в пути
	double getAvgTripTime();
	// получение среднего общего времени
	double getAvgTotalTime();
	// средний процент загруженности автобуса с указанным id
	double getAvgBusLoad(int id);
	// процент загруженности всех автобусов
	double getAvgAllBusLoad();
	// получение среднего процента загруженности с id автобусов
	map<int, double> getBusStat();
};