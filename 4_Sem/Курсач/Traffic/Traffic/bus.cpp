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
	// управление жизненным циклом пассажиров
	// пока они едут в автобусе, либо заходят/выходят, за них "отвечает" автобус
	for (Entity* passengerEntity : passengers) {
		if (passengerEntity) {
			delete passengerEntity;
		}
	}
}

void Bus::tick(double delta)
{
	Route* route = (Route*)parentRoute;
	// сбор статистики по загруженности
	if (route->getStatcollector()) {
		route->getStatcollector()->addBusLoad(id, 1.0 - (double)getFreeSeatCount() / (double)passengers.size());
	}
	// пока пассажир в автобусе, за его моделирование "отвечает" автобус
	for (Entity* passenger : passengers) {
		if (passenger) {
			passenger->tick(delta);
		}
	}
	if (inTransit) {
		// с течением времени изменяем координату автобуса
		// в соответствии с его скоростью и прошедшим временем
		position += velocity * (delta / 3600.0); // delta в секуднах переводим в часы

		// просматриваем информацию по каждой остановке
		for (Entity* busstopEntity : *route->getBusstopArray()) {
			Busstop* busstop = (Busstop*)busstopEntity;
			// смотрим по координатам - проехал ли остановку?
			if (position > busstop->getPosition()) {
				// если остановка не в списке пройденных
				if (find(passedBusstops.begin(), passedBusstops.end(), busstop) == passedBusstops.end()) {
					// добавляем в список пройденных
					passedBusstops.push_back(busstop);

					// останавливаемся на остановке если надо кому-то выйти на ней,
					// либо если есть свободные места и на остановке ожидает пассажир
					if (needToGetOff(busstop) ||
						(getFreeSeatCount() > 0 && busstop->haveWaiters())) {
						// добавляем остановку в список остановок, на которых автобус останавливался
						visitedBusstops.push_back(busstop);
						// обнуляем таймер остановки
						stopTimer = 0.0;
						// задаем состояние автобуска как "не в движении" (на остановке)
						inTransit = false;
					}
				}
			}
		}
	}
	else {
		// увеличиваем таймер остановки на интервал моделирования
		stopTimer += delta;
		// контроль высадки, затем посадки
		// флаг, показывающий, что идет процесс посадки/высадки
		bool boardingFlag = false;
		// проверяем, осуществляется ли в данный момент посадка/высадка
		for (Entity* passengerEntity : passengers) {
			if (passengerEntity) {
				Passenger* passenger = (Passenger*)passengerEntity;
				boardingFlag |= !passenger->isBoardingEnded();
			}
		}
		// если никто не садится/выходит, проверяем, кому надо выйти
		if (!boardingFlag) {
			// получаем текущую остановку
			Busstop* currentBusstop = (Busstop*)visitedBusstops[visitedBusstops.size() - 1];
			if (currentBusstop) {
				// освобождаем места в автобусе
				for (int i = 0; i < passengers.size(); i++) {
					Passenger* passenger = (Passenger*)passengers[i];
					if (passenger) {
						if (passenger->isBoardingEnded() && !passenger->isOnTrip()) {
							passengers[i] = nullptr;
						}
					}
				}
				// ищем пассажира, которому надо выйти на текущей остановке
				for (Entity* passengerEntity : passengers) {
					if (passengerEntity) {
						Passenger* passenger = (Passenger*)passengerEntity;
						if (passenger->getTargetBusstop() == currentBusstop) {
							// запускаем процесс высадки
							passenger->startBoarding();
							boardingFlag = true;
							// добавляем в список прибывших
							currentBusstop->addArrival(passenger);
							break;
						}
					}
				}
				// если все, кто хотел, вышли из автобуса, начинаем посадку
				if (!boardingFlag && (getFreeSeatCount() > 0)) {
					if (currentBusstop->haveWaiters()) {
						// начинаем процесс посадки у первого пассажира в очереди на остановке
						Passenger* passenger = (Passenger*)(*currentBusstop->getWaitingPassengers())[0];
						// удаляем с остановки
						currentBusstop->getWaitingPassengers()->erase(currentBusstop->getWaitingPassengers()->begin());
						// сажаем пассажира на свободное место
						passengers[getFreeSitIndex()] = passenger;
						// запускаем процесс посадки
						passenger->startBoarding();
						boardingFlag = true;
					}
				}
			}
		}
		
		// когда посадка/высадка завершена и вышел предел ожидания, автобус движется дальше
		if (!boardingFlag && (stopTimer > stopTimeLimit)) {
			// задаем состояние автобуса как "в движении"
			inTransit = true;
		}
	}
	if (inTransit) {
		// проверка делается, когда автобус отъехал от последней остановки
		// проверка на выход за пределы маршрута и деспавн автобуса
		if (position > route->getLength()) {
			// помечаем автобус для удаления с маршрута
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
	// делаем все места свободными
	for (int i = 0; i < passengersLimit; i++) {
		(*bus->getPassengers())[i] = nullptr;
	}
	return bus;
}
