#include "outputwriter.h"

void print_time(FILE* file, double sec) {
	int h = (int)sec / 3600;
	sec -= h * 3600.0;
	int m = (int)sec / 60;
	sec -= m * 60.0;
	fprintf(file, "%i h %i m %f sec", h, m, sec);
}

void write(const char* filename, const ExperimentInputData& inputData, const ExperimentOutputData& outputData)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "w");
	if (file) {
		// пишем исходные данные
		fprintf(file, "INPUT DATA:\n");
		fprintf(file, "bus velocity: %.2f km/h\n", inputData.busVelocity);
		fprintf(file, "busstop waiting time: %.2f sec\n", inputData.busstopWaitingTime);
		fprintf(file, "bus seat count: %i\n", inputData.seatLimit);
		fprintf(file, "bus count limit: %d\n", inputData.busCount);
		fprintf(file, "boarding time: %.2f sec\n", inputData.boardingTime);
		fprintf(file, "init busstop passenger count between %i and %i\n", inputData.initPassengersLowCount, inputData.initPassengersHighCount);
		fprintf(file, "passenger spawn time between ");
		print_time(file, inputData.passengerLowSpawnTime);
		fprintf(file, " and ");
		print_time(file, inputData.passengerHighSpawnTime);
		fprintf(file, "\n");
		fprintf(file, "busstops (%i):\n", (int)inputData.busstops.size());
		for (int i = 0; i < inputData.busstops.size(); i++) {
			fprintf(file, "%.2f km, ", inputData.busstops[i]);
		}
		fprintf(file, "\n");
		fprintf(file, "route length: %.2f km\n", inputData.busstops[inputData.busstops.size() - 1]);
		fprintf(file, "modeling time: ");
		print_time(file, inputData.modelingTime);
		fprintf(file, "\n");
		fprintf(file, "dt = %.2f sec\n", inputData.dt);
		// пишем результаты
		fprintf(file, "\nmodeling ends in: %.4f sec\n\n", outputData.time);
		fprintf(file, "RESULTS:\n");
		fprintf(file, "average missed stops count: %f\n", outputData.missedBusstops);
		fprintf(file, "average passenger trip time: ");
		print_time(file, outputData.tripTime);
		fprintf(file, " (%f sec)\n", outputData.tripTime);
		fprintf(file, "average passenger total time: ");
		print_time(file, outputData.totalTime);
		fprintf(file, " (%f sec)\n", outputData.totalTime);
		fprintf(file, "bus load by id:\n");
		for (auto i : outputData.busLoad) {
			fprintf(file, "#%d: %.2f%%\n", i.first, i.second);
		}
		fprintf(file, "all bus load is: %.2f%%\n", outputData.allBusLoad);

		fclose(file);
	}
}
