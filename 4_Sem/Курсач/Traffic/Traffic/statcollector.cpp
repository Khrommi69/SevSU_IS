#include "statcollector.h"

void Statcollector::addMissedStops(int ms)
{
	missedStopsCount.push_back(ms);
}

void Statcollector::addTripTime(double t)
{
	tripTime.push_back(t);
}

void Statcollector::addTotalTime(double t)
{
	totalTime.push_back(t);
}

void Statcollector::addBusLoad(int id, double load)
{
	if (busLoad.find(id) == busLoad.end()) {
		busLoad.insert(pair<int, vector<double>>(id, {}));
	}
	busLoad[id].push_back(load);
}

double Statcollector::getAvgMessedStopsCount()
{
	return getAvg(&missedStopsCount);
}

double Statcollector::getAvgTripTime()
{
	return getAvg(&tripTime);
}

double Statcollector::getAvgTotalTime()
{
	return getAvg(&totalTime);
}

double Statcollector::getAvgBusLoad(int id)
{
	if (busLoad.find(id) == busLoad.end()) {
		return 0.0;
	}
	return getAvg(&busLoad[id]);
}

double Statcollector::getAvgAllBusLoad()
{
	double result = 0.0;
	int count = 0;
	for (auto i : busLoad) {
		result += getAvgBusLoad(i.first);
		count++;
	}
	if (count > 0) {
		result = result / (double)count;
	}
	return result;
}

map<int, double> Statcollector::getBusStat()
{
	map<int, double> result;
	for (auto i : busLoad) {
		result.insert(pair<int, double>(i.first, getAvg(&i.second)));
	}
	return result;
}
