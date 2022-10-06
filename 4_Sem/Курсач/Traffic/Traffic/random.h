#pragma once

#include <stdlib.h>

// ����� ���������� ��������� �����
void randomize();


// ������������� ���������� ����� �� ���� �� lim
template<class T>
inline T rnd(T lim)
{
	return (T)(((double)rand() / (double)RAND_MAX) * (double)lim);
}

// ������������� ���������� ����� �� lowLim �� upLim
template<class T>
inline T rnd(T lowLim, T upLim)
{
	return lowLim + rnd(upLim - lowLim);
}