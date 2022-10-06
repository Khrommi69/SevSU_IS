#include "busstop.h"
#include "route.h"
#include "passenger.h"
#include "random.h"

Entity* BusstopBuilder::build()
{
    Busstop* busstop = new Busstop();
    busstop->position = position;
    busstop->passengerBuilder = passengerBuilder;
    busstop->parentRoute = parentRoute;
    busstop->id = idCounter++;
    busstop->spawnEnable = spawnEnable;
    busstop->lowSpawnTime = lowSpawnTime;
    busstop->highSpawnTime = highSpawnTime;
    busstop->spawnTimer = 0.0;
    busstop->currentSpawnTime = rnd(lowSpawnTime, highSpawnTime);
    return busstop;
}

BusstopBuilder* BusstopBuilder::setPosition(double pos)
{
    position = pos;
    return this;
}

BusstopBuilder* BusstopBuilder::setPassengerBuilder(Builder* builder)
{
    passengerBuilder = builder;
    return this;
}

BusstopBuilder* BusstopBuilder::setParentRoute(Entity* route)
{
    parentRoute = route;
    return this;
}

BusstopBuilder* BusstopBuilder::setSpawnEnable(bool flag)
{
    spawnEnable = flag;
    return this;
}

BusstopBuilder* BusstopBuilder::setLowSpawnTime(double time)
{
    lowSpawnTime = time;
    return this;
}

BusstopBuilder* BusstopBuilder::setHighSpawnTime(double time)
{
    highSpawnTime = time;
    return this;
}

void Busstop::tick(double delta)
{
    Route* route = (Route*)parentRoute;
    if (spawnEnable) {
        spawnTimer += delta;
        if (spawnTimer > currentSpawnTime) {
            // сбрасываем таймер
            currentSpawnTime = rnd(lowSpawnTime, highSpawnTime);
            spawnTimer = 0.0;
            // генерируем нового пассажира
            int selfIndex = route->getBusstopIndex(this);
            // пассажиру надо будет проехать случайно число остановок (не более 2/3 от всего количества остановок)
            int passCount = 1 + rnd(min(route->getBusstopCount() - selfIndex - 1, 2 * route->getBusstopCount() / 3));
            Entity* target = route->getBusstop(selfIndex + passCount);
            // проверка на ошибочную генерацию пункта назначения
            if (target == this) {
                throw "same busstop!";
            }
            spawnPassenger(target);
        }
    }
    // удаляем прибывших пассажиров со сбором статистики по ним
    for (int i = 0; i < arrivalPassengers.size(); i++) {
        Passenger* passenger = (Passenger*)arrivalPassengers[i];
        // удаляем пассажира только когда высадка полностью завершилась
        if (passenger->isBoardingEnded()) {
            despawnPassenger(passenger);
            i--;
        }
    }
}

int Busstop::getId()
{
    return id;
}

double Busstop::getPosition()
{
    return position;
}

void Busstop::setParentRoute(Entity* route)
{
    parentRoute = route;
}

Entity* Busstop::getParentRoute()
{
    return parentRoute;
}

void Busstop::setPassengerBuilder(Builder* builder)
{
    passengerBuilder = builder;
}

Builder* Busstop::getPassengerBuilder()
{
    return passengerBuilder;
}

bool Busstop::haveWaiters()
{
    return waitingPassengers.size() > 0;
}

vector<Entity*>* Busstop::getWaitingPassengers()
{
    return &waitingPassengers;
}

void Busstop::addArrival(Entity* passenger)
{
    arrivalPassengers.push_back(passenger);
}

void Busstop::spawnPassenger(Entity* targetBusstop)
{
    // создаем пассажира при помощи билдера
    Passenger* passenger = (Passenger*)passengerBuilder->build();
    // задаем начальную остановку
    passenger->setStartBusstop(this);
    // задаем конечную для него остановку
    passenger->setTargetBusstop(targetBusstop);
    // добавлем в массив ожидающих пассажиров на остановке
    waitingPassengers.push_back(passenger);
}

void Busstop::despawnPassenger(Entity* passenger)
{
    // удаление пассажира аналогично удалению автобуса
    auto ptrItem = find(arrivalPassengers.begin(), arrivalPassengers.end(), passenger);
    if (ptrItem != arrivalPassengers.end()) {
        Entity* entity = *ptrItem;
        // сбор статистики по пассажиру
        Passenger* passenger = (Passenger*)entity;
        Route* route = (Route*)parentRoute;
        if (route->getStatcollector()) {
            route->getStatcollector()->addTripTime(passenger->getTripTime());
            route->getStatcollector()->addTotalTime(passenger->getTotalTime());
        }
        delete entity;
        arrivalPassengers.erase(ptrItem);
    }
}
