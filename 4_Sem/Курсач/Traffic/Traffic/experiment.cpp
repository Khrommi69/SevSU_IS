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

	// �������� � ������ ��������
	busBuilder.setPosition(0.0);
	// � ��������� ����� �������� (���� ������ ����� - ���������, �� ���� false)
	busBuilder.setTransit(true);
	// �������� ��������
	busBuilder.setVelocity(inputData.busVelocity);
	// �������� ��������� �� ���������
	busBuilder.setStopTimeLimit(inputData.busstopWaitingTime);
	// ���������� ���� � ��������
	busBuilder.setPassengersLimit(inputData.seatLimit);

	route.setBusBuilder(&busBuilder);
	// ���������� ��������� �� ��������
	route.setBusCount(inputData.busCount);

	route.setStatcollector(&statcollector);
	// ����� �������/������� ���������
	passengerBuilder.setBoardingTimeLimit(inputData.boardingTime);

	busstopBuilder.setParentRoute(&route);
	busstopBuilder.setPassengerBuilder(&passengerBuilder);
	busstopBuilder.setHighSpawnTime(inputData.passengerLowSpawnTime);
	busstopBuilder.setLowSpawnTime(inputData.passengerHighSpawnTime);
	busstopBuilder.setSpawnEnable(true);

	// �������� ��������� �� ��������
	for (int i = 0; i < inputData.busstops.size() - 1; i++) {
		route.getBusstopArray()->push_back((Busstop*)busstopBuilder
			.setPosition(inputData.busstops[i])->build());
	}
	// �� �������� ��������� �� ���������� ���������
	route.getBusstopArray()->push_back((Busstop*)busstopBuilder
		.setPosition(inputData.busstops[inputData.busstops.size() - 1])->setSpawnEnable(false)->build());
	// ���������� ����� ����� ��������
	route.setLength(inputData.busstops[inputData.busstops.size() - 1]);

	// ���������� ��������� �������� ���������� ���������� �� ����������
	for (int i = 0; i < route.getBusstopCount() - 1; i++) {
		// ���������� ����� ����������
		int count = rnd(inputData.initPassengersLowCount, inputData.initPassengersHighCount);
		Busstop* busstop = (Busstop*)route.getBusstopArray()->at(i);
		for (int j = 0; j < count; j++) {
			// ��������� ���� ����� �������� �������� ����� ��������� (�� ����� 2/3 �� ����� ���������� ���������)
			int passCount = 1 + rnd(min(route.getBusstopCount() - i - 1, 2 * route.getBusstopCount() / 3));
			Entity* target = route.getBusstop(i + passCount);
			// ��������� ��������� �� ���������
			busstop->spawnPassenger(target);
		}
	}

	// ������� �������������
	for (double t = 0.0; t < inputData.modelingTime; t += inputData.dt) {
		route.tick(inputData.dt);
	}

	// ��������� ���������� ������������
	result.missedBusstops = statcollector.getAvgMessedStopsCount();
	result.tripTime = statcollector.getAvgTripTime();
	result.totalTime = statcollector.getAvgTotalTime();
	for (auto i : statcollector.getBusStat()) {
		result.busLoad.insert(pair<int, double>(i.first, i.second * 100.0));
	}
	result.allBusLoad = statcollector.getAvgAllBusLoad() * 100.0;

	end = clock();

	// ��������� ����� ���������� ������������
	result.time = ((double)end - start) / ((double)CLOCKS_PER_SEC);

    return result;
}
