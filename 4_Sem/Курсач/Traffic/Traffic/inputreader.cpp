#include "inputreader.h"

#include <iostream>
#include <fstream>

ExperimentInputData read(const char* filename)
{
    ExperimentInputData result;

    // открываем файл для чтения
    ifstream f(filename);
    char buf[64];
    if (f) {
        // читаем до конца файла
        while (!f.eof()) {
            // считываем название параметра
            f >> buf;
            // проверяем, какой параметр считали
            if (strcmp(buf, "busVelocity") == 0) {
                f >> result.busVelocity;
            }
            if (strcmp(buf, "busstopWaitingTime") == 0) {
                f >> result.busstopWaitingTime;
            }
            if (strcmp(buf, "seatLimit") == 0) {
                f >> result.seatLimit;
            }
            if (strcmp(buf, "busCount") == 0) {
                f >> result.busCount;
            }
            if (strcmp(buf, "boardingTime") == 0) {
                f >> result.boardingTime;
            }
            if (strcmp(buf, "initPassengersLowCount") == 0) {
                f >> result.initPassengersLowCount;
            }
            if (strcmp(buf, "initPassengersHighCount") == 0) {
                f >> result.initPassengersHighCount;
            }
            if (strcmp(buf, "passengerLowSpawnTime") == 0) {
                f >> result.passengerLowSpawnTime;
            }
            if (strcmp(buf, "passengerHighSpawnTime") == 0) {
                f >> result.passengerHighSpawnTime;
            }
            if (strcmp(buf, "busstops") == 0) {
                int busstopCount;
                f >> busstopCount;
                for (int i = 0; i < busstopCount; i++) {
                    double pos;
                    f >> pos;
                    result.busstops.push_back(pos);
                }
            }
            if (strcmp(buf, "dt") == 0) {
                f >> result.dt;
            }
            if (strcmp(buf, "modelingTime") == 0) {
                f >> result.modelingTime;
            }
        }

        f.close();
    }
    else {
        // если файл не найден
        throw "file not found!";
    }

    return result;
}
