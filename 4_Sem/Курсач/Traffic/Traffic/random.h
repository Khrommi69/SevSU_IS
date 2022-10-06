#pragma once

#include <stdlib.h>

// сброс генератора случайных чисел
void randomize();


// генерирование случайного числа от нуля до lim
template<class T>
inline T rnd(T lim)
{
	return (T)(((double)rand() / (double)RAND_MAX) * (double)lim);
}

// генерирование случайного числа от lowLim до upLim
template<class T>
inline T rnd(T lowLim, T upLim)
{
	return lowLim + rnd(upLim - lowLim);
}