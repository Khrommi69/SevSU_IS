#include "experiment.h"
#include "route.h"
#include "bus.h"
#include "busstop.h"
#include "passenger.h"
#include "random.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ExperimentOutputData doExperiment(ExperimentInputData inputData)
{

	clock_t start, end;
	start = clock();

    ExperimentOutputData result;

	Route route;
	BusBuilder busBuilder;
	BusstopBuilder busstopBuilder;
	Statcollector statcollector;
	PassengerBuilder passengerBuilder;

	// начинаем с начала маршрута
	busBuilder.setPosition(0.0);
	// в начальное точке движемся (если первая точка - остановка, то надо false)
	busBuilder.setTransit(true);
	// скорость автобуса
	busBuilder.setVelocity(inputData.busVelocity);
	// ожидание пассажира на остановке
	busBuilder.setStopTimeLimit(inputData.busstopWaitingTime);
	// количество мест в автобусе
	busBuilder.setPassengersLimit(inputData.seatLimit);

	route.setBusBuilder(&busBuilder);
	// количество автобусов на маршруте
	route.setBusCount(inputData.busCount);

	route.setStatcollector(&statcollector);
	// время посадки/высадки пассажира
	passengerBuilder.setBoardingTimeLimit(inputData.boardingTime);

	busstopBuilder.setParentRoute(&route);
	busstopBuilder.setPassengerBuilder(&passengerBuilder);
	busstopBuilder.setHighSpawnTime(inputData.passengerLowSpawnTime);
	busstopBuilder.setLowSpawnTime(inputData.passengerHighSpawnTime);
	busstopBuilder.setSpawnEnable(true);

	// создание остановок на маршруте
	for (int i = 0; i < inputData.busstops.size() - 1; i++) {
		route.getBusstopArray()->push_back((Busstop*)busstopBuilder
			.setPosition(inputData.busstops[i])->build());
	}
	// на конечной остановке не появляются пассажиры
	route.getBusstopArray()->push_back((Busstop*)busstopBuilder
		.setPosition(inputData.busstops[inputData.busstops.size() - 1])->setSpawnEnable(false)->build());
	// определяем общую длину маршрута
	route.setLength(inputData.busstops[inputData.busstops.size() - 1]);

	// изначально размещаем некоторе количество пассажиров на остановках
	for (int i = 0; i < route.getBusstopCount() - 1; i++) {
		// генерируем число пассажиров
		int count = rnd(inputData.initPassengersLowCount, inputData.initPassengersHighCount);
		Busstop* busstop = (Busstop*)route.getBusstopArray()->at(i);
		for (int j = 0; j < count; j++) {
			// пассажиру надо будет проехать случайно число остановок (не более 2/3 от всего количества остановок)
			int passCount = 1 + rnd(min(route.getBusstopCount() - i - 1, 2 * route.getBusstopCount() / 3));
			Entity* target = route.getBusstop(i + passCount);
			// размещаем пассажира на остановке
			busstop->spawnPassenger(target);
		}
	}

	// процесс моделирования
	for (double t = 0.0; t < inputData.modelingTime; t += inputData.dt) {
		route.tick(inputData.dt);
	}

	// сохраняем результаты эксперимента
	result.missedBusstops = statcollector.getAvgMessedStopsCount();
	result.tripTime = statcollector.getAvgTripTime();
	result.totalTime = statcollector.getAvgTotalTime();
	for (auto i : statcollector.getBusStat()) {
		result.busLoad.insert(pair<int, double>(i.first, i.second * 100.0));
	}
	result.allBusLoad = statcollector.getAvgAllBusLoad() * 100.0;

	end = clock();

	// вычисляем время проведения эксперимента
	result.time = ((double)end - start) / ((double)CLOCKS_PER_SEC);

    return result;
}
