#include "experiment.h"
#include "inputreader.h"
#include "outputwriter.h"
#include "random.h"

#include <iostream>

using namespace std;

bool doCalculations(ExperimentInputData& inp, ExperimentOutputData& out) {
	bool result = false;
	try {
		// осуществляем вычисления
		printf_s("calculating...\n");
		out = doExperiment(inp);
		printf_s("done in %.4f second(s)\n", out.time);
		result = true;
	}
	catch (...) {
		
	}
	return result;
}

void print_time(double sec) {
	int h = (int)sec / 3600;
	sec -= h * 3600.0;
	int m = (int)sec / 60;
	sec -= m * 60.0;
	printf_s("%i h %i m %f sec", h, m, sec);
}

int main() {
	int result = 0;
	// сбрасываем генератор случайных чисел
	randomize();
	// входные и выходные данные для моделирования
	ExperimentInputData inp;
	ExperimentOutputData out;
	int option = 0;
	bool haveResults = false;
	char inpfile[256];
	char outfile[256];
	do {
		// печатаем меню
		printf_s("\n\nchoose option:\n");
		printf_s("[1] - enter data from this,\n");
		printf_s("[2] - enter data from file,\n");
		printf_s("[3] - show results,\n");
		printf_s("[4] - save result to file,\n");
		printf_s("[5] - exit.\n");
		cin >> option;
		// очищаем экран
		system("cls");
		int busstopCount;
		double busstopPosition;
		switch (option) {
		case 1:
			result = 0;
			printf_s("enter input data.\n");
			printf_s("bus velocity (km/h): ");
			cin >> inp.busVelocity;
			printf_s("busstop waiting time (sec): ");
			cin >> inp.busstopWaitingTime;
			printf_s("seat limit: ");
			cin >> inp.seatLimit;
			printf_s("bus count: ");
			cin >> inp.busCount;
			printf_s("boarding time (sec): ");
			cin >> inp.boardingTime;
			printf_s("init passengers low count: ");
			cin >> inp.initPassengersLowCount;
			printf_s("init passengers high count: ");
			cin >> inp.initPassengersHighCount;
			printf_s("passenger low spawn time (sec): ");
			cin >> inp.passengerLowSpawnTime;
			printf_s("passenger high spawn time (sec): ");
			cin >> inp.passengerHighSpawnTime;
			printf_s("busstop count: ");
			cin >> busstopCount;
			inp.busstops.clear();
			for (int i = 0; i < busstopCount; i++) {
				printf_s("busstop #%i position (km): ", i);
				cin >> busstopPosition;
				inp.busstops.push_back(busstopPosition);
			}
			printf_s("modeling time step (sec): ");
			cin >> inp.dt;
			printf_s("total modeling time (sec): ");
			cin >> inp.modelingTime;
			if (!doCalculations(inp, out)) { // если произошла ошибка во время расчетов
				result = -2;
				printf_s("error while calculating...\n");
				haveResults = false;
			}
			else {
				haveResults = true;
			}
			break;
		case 2:
			result = 0;
			printf_s("enter input data filename: ");
			cin >> inpfile;
			try {
				printf_s("reading from '%s'...\n", inpfile);
				inp = read(inpfile);
			}
			catch (...) {
				// ошибка чтения входного файла
				result = -1;
				printf_s("error while file opening...\n");
			}
			// нет ошибок чтения, значит считаем
			if (result == 0) {
				if (!doCalculations(inp, out)) { // если произошла ошибка во время расчетов
					result = -2;
					printf_s("error while calculating...\n");
					haveResults = false;
				}
				else {
					haveResults = true;
				}
			}
			break;
		case 3:
			if (haveResults) {
				// печатаем результаты в консоли

				// пишем исходные данные
				printf_s( "INPUT DATA:\n");
				printf_s( "bus velocity: %.2f km/h\n", inp.busVelocity);
				printf_s( "busstop waiting time: %.2f sec\n", inp.busstopWaitingTime);
				printf_s( "bus seat count: %i\n", inp.seatLimit);
				printf_s( "bus count limit: %d\n", inp.busCount);
				printf_s( "boarding time: %.2f sec\n", inp.boardingTime);
				printf_s( "init busstop passenger count between %i and %i\n", inp.initPassengersLowCount, inp.initPassengersHighCount);
				printf_s( "passenger spawn time between ");
				print_time(inp.passengerLowSpawnTime);
				printf_s( " and ");
				print_time(inp.passengerHighSpawnTime);
				printf_s( "\n");
				printf_s( "busstops (%i):\n", (int)inp.busstops.size());
				for (int i = 0; i < inp.busstops.size(); i++) {
					printf_s( "%.2f km, ", inp.busstops[i]);
				}
				printf_s( "\n");
				printf_s( "route length: %.2f km\n", inp.busstops[inp.busstops.size() - 1]);
				printf_s( "modeling time: ");
				print_time(inp.modelingTime);
				printf_s( "\n");
				printf_s( "dt = %.2f sec\n", inp.dt);
				// пишем результаты
				printf_s( "\nmodeling ends in: %.4f sec\n\n", out.time);
				printf_s( "RESULTS:\n");
				printf_s( "average missed stops count: %f\n", out.missedBusstops);
				printf_s( "average passenger trip time: ");
				print_time(out.tripTime);
				printf_s( " (%f sec)\n", out.tripTime);
				printf_s( "average passenger total time: ");
				print_time(out.totalTime);
				printf_s( " (%f sec)\n", out.totalTime);
				printf_s( "bus load by id:\n");
				for (auto i : out.busLoad) {
					printf_s( "#%d: %.2f%%\n", i.first, i.second);
				}
				printf_s( "all bus load is: %.2f%%\n", out.allBusLoad);
			}
			else {
				printf_s("there is not any modeling results. please enter input data.\n");
			}
			break;
		case 4:
			if (haveResults) {
				printf_s("enter output file name: ");
				cin >> outfile;
				// сохраняем результаты вычислений в файл
				write(outfile, inp, out);
				printf("result saved into '%s'\n", outfile);
			}
			else {
				printf_s("there is not any modeling results. please enter input data.\n");
			}
			break;
		case 5:
			break;
		default:
			printf_s("wrong option!\n");
		}
	} while (option != 5);

	system("pause");

	return result;

}