#pragma once

#include "experiment.h"

// запись результатов моделирования в файл
void write(const char* filename, const ExperimentInputData& inputData, const ExperimentOutputData& outputData);
