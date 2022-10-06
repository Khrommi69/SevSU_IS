#pragma once

#include <vector>
#include <map>

using namespace std;

class ExperimentInputData {
public:
	// скорость движения автобуса (км/ч)
	double busVelocity;
	// время ожидания автобуса на остановке (с)
	double busstopWaitingTime;
	// количество мест в автобусе
	int seatLimit;
	// количество автобусов на маршруте
	int busCount;
	// время посадки/высадки пассажира (с)
	double boardingTime;
	// начальное число пассажиров на остановке генерируется между:
	int initPassengersLowCount;
	int initPassengersHighCount;
	// очередное пассажир на остановке появится в случайное время (с) между:
	double passengerLowSpawnTime;
	double passengerHighSpawnTime;
	// массив координат остановок на маршруте (км)
	vector<double> busstops;
	// шаг моделирования
	double dt;
	// время моделирования
	double modelingTime;
};

class ExperimentOutputData {
public:
	// среднее коичество пропускаемых остановок
	double missedBusstops;
	// среднее время пассажира в пути (c)
	double tripTime;
	// среднее время пассажира в пути с учетом времени ожидания (c)
	double totalTime;
	// средняя загруженность по автобусам (%)
	map<int, double> busLoad;
	// средня загруженность всех автобусов (%)
	double allBusLoad;
	// время выполнения эксперимента (c)
	double time;
};

// функция для проведения моделирования
ExperimentOutputData doExperiment(ExperimentInputData inputData);
