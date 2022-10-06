#include "bus.h"
#include "route.h"
#include "busstop.h"
#include "passenger.h"

int Bus::getFreeSitIndex()
{
	int result = -1;
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers[i] == nullptr) {
			result = i;
			break;
		}
	}
	return result;
}

Bus::~Bus()
{
	// ���������� ��������� ������ ����������
	// ���� ��� ���� � ��������, ���� �������/�������, �� ��� "��������" �������
	for (Entity* passengerEntity : passengers) {
		if (passengerEntity) {
			delete passengerEntity;
		}
	}
}

void Bus::tick(double delta)
{
	Route* route = (Route*)parentRoute;
	// ���� ���������� �� �������������
	if (route->getStatcollector()) {
		route->getStatcollector()->addBusLoad(id, 1.0 - (double)getFreeSeatCount() / (double)passengers.size());
	}
	// ���� �������� � ��������, �� ��� ������������� "��������" �������
	for (Entity* passenger : passengers) {
		if (passenger) {
			passenger->tick(delta);
		}
	}
	if (inTransit) {
		// � �������� ������� �������� ���������� ��������
		// � ������������ � ��� ��������� � ��������� ��������
		position += velocity * (delta / 3600.0); // delta � �������� ��������� � ����

		// ������������� ���������� �� ������ ���������
		for (Entity* busstopEntity : *route->getBusstopArray()) {
			Busstop* busstop = (Busstop*)busstopEntity;
			// ������� �� ����������� - ������� �� ���������?
			if (position > busstop->getPosition()) {
				// ���� ��������� �� � ������ ����������
				if (find(passedBusstops.begin(), passedBusstops.end(), busstop) == passedBusstops.end()) {
					// ��������� � ������ ����������
					passedBusstops.push_back(busstop);

					// ��������������� �� ��������� ���� ���� ����-�� ����� �� ���,
					// ���� ���� ���� ��������� ����� � �� ��������� ������� ��������
					if (needToGetOff(busstop) ||
						(getFreeSeatCount() > 0 && busstop->haveWaiters())) {
						// ��������� ��������� � ������ ���������, �� ������� ������� ��������������
						visitedBusstops.push_back(busstop);
						// �������� ������ ���������
						stopTimer = 0.0;
						// ������ ��������� ��������� ��� "�� � ��������" (�� ���������)
						inTransit = false;
					}
				}
			}
		}
	}
	else {
		// ����������� ������ ��������� �� �������� �������������
		stopTimer += delta;
		// �������� �������, ����� �������
		// ����, ������������, ��� ���� ������� �������/�������
		bool boardingFlag = false;
		// ���������, �������������� �� � ������ ������ �������/�������
		for (Entity* passengerEntity : passengers) {
			if (passengerEntity) {
				Passenger* passenger = (Passenger*)passengerEntity;
				boardingFlag |= !passenger->isBoardingEnded();
			}
		}
		// ���� ����� �� �������/�������, ���������, ���� ���� �����
		if (!boardingFlag) {
			// �������� ������� ���������
			Busstop* currentBusstop = (Busstop*)visitedBusstops[visitedBusstops.size() - 1];
			if (currentBusstop) {
				// ����������� ����� � ��������
				for (int i = 0; i < passengers.size(); i++) {
					Passenger* passenger = (Passenger*)passengers[i];
					if (passenger) {
						if (passenger->isBoardingEnded() && !passenger->isOnTrip()) {
							passengers[i] = nullptr;
						}
					}
				}
				// ���� ���������, �������� ���� ����� �� ������� ���������
				for (Entity* passengerEntity : passengers) {
					if (passengerEntity) {
						Passenger* passenger = (Passenger*)passengerEntity;
						if (passenger->getTargetBusstop() == currentBusstop) {
							// ��������� ������� �������
							passenger->startBoarding();
							boardingFlag = true;
							// ��������� � ������ ���������
							currentBusstop->addArrival(passenger);
							break;
						}
					}
				}
				// ���� ���, ��� �����, ����� �� ��������, �������� �������
				if (!boardingFlag && (getFreeSeatCount() > 0)) {
					if (currentBusstop->haveWaiters()) {
						// �������� ������� ������� � ������� ��������� � ������� �� ���������
						Passenger* passenger = (Passenger*)(*currentBusstop->getWaitingPassengers())[0];
						// ������� � ���������
						currentBusstop->getWaitingPassengers()->erase(currentBusstop->getWaitingPassengers()->begin());
						// ������ ��������� �� ��������� �����
						passengers[getFreeSitIndex()] = passenger;
						// ��������� ������� �������
						passenger->startBoarding();
						boardingFlag = true;
					}
				}
			}
		}
		
		// ����� �������/������� ��������� � ����� ������ ��������, ������� �������� ������
		if (!boardingFlag && (stopTimer > stopTimeLimit)) {
			// ������ ��������� �������� ��� "� ��������"
			inTransit = true;
		}
	}
	if (inTransit) {
		// �������� ��������, ����� ������� ������� �� ��������� ���������
		// �������� �� ����� �� ������� �������� � ������� ��������
		if (position > route->getLength()) {
			// �������� ������� ��� �������� � ��������
			needToDelete = true;
		}
	}
}

int Bus::getId()
{
	return id;
}

bool Bus::isNeedToDelete()
{
	return needToDelete;
}

double Bus::getPosition()
{
	return position;
}

void Bus::setParentRoute(Entity* route)
{
	parentRoute = route;
}

vector<Entity*>* Bus::getPassedBusstops()
{
	return &passedBusstops;
}

vector<Entity*>* Bus::getVisitedBusstops()
{
	return &visitedBusstops;
}

bool Bus::getTransitState()
{
	return inTransit;
}

vector<Entity*>* Bus::getPassengers()
{
	return &passengers;
}

int Bus::getPassengerCount()
{
	int passengersCount = 0;
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers[i]) {
			passengersCount++;
		}
	}
	return passengersCount;
}

int Bus::getFreeSeatCount()
{
	return (int)passengers.size() - getPassengerCount();
}

bool Bus::needToGetOff(Entity* busstop)
{
	bool result = false;
	for (Entity* passengerEntity : passengers) {
		if (passengerEntity) {
			Passenger* passenger = (Passenger*)passengerEntity;
			result |= (passenger->getTargetBusstop() == busstop);
		}
	}
	return result;
}

bool Bus::sitOnTheBus(Entity* passenger)
{
	return find(passengers.begin(), passengers.end(), passenger) != passengers.end();
}

BusBuilder* BusBuilder::setPosition(double pos)
{
	position = pos;
	return this;
}

BusBuilder* BusBuilder::setVelocity(double vel)
{
	velocity = vel;
	return this;
}

BusBuilder* BusBuilder::setTransit(bool t)
{
	inTransit = t;
	return this;
}

BusBuilder* BusBuilder::setStopTimeLimit(double stl)
{
	stopTimeLimit = stl;
	return this;
}

BusBuilder* BusBuilder::setPassengersLimit(int pl)
{
	passengersLimit = pl;
	return this;
}

Entity* BusBuilder::build()
{
	Bus* bus = new Bus();
	bus->inTransit = inTransit;
	bus->velocity = velocity;
	bus->position = position;
	bus->needToDelete = needToDelete;
	bus->stopTimeLimit = stopTimeLimit;
	bus->id = idCounter++;
	bus->getPassengers()->resize(passengersLimit);
	// ������ ��� ����� ����������
	for (int i = 0; i < passengersLimit; i++) {
		(*bus->getPassengers())[i] = nullptr;
	}
	return bus;
}
