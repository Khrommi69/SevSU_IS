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
            // ���������� ������
            currentSpawnTime = rnd(lowSpawnTime, highSpawnTime);
            spawnTimer = 0.0;
            // ���������� ������ ���������
            int selfIndex = route->getBusstopIndex(this);
            // ��������� ���� ����� �������� �������� ����� ��������� (�� ����� 2/3 �� ����� ���������� ���������)
            int passCount = 1 + rnd(min(route->getBusstopCount() - selfIndex - 1, 2 * route->getBusstopCount() / 3));
            Entity* target = route->getBusstop(selfIndex + passCount);
            // �������� �� ��������� ��������� ������ ����������
            if (target == this) {
                throw "same busstop!";
            }
            spawnPassenger(target);
        }
    }
    // ������� ��������� ���������� �� ������ ���������� �� ���
    for (int i = 0; i < arrivalPassengers.size(); i++) {
        Passenger* passenger = (Passenger*)arrivalPassengers[i];
        // ������� ��������� ������ ����� ������� ��������� �����������
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
    // ������� ��������� ��� ������ �������
    Passenger* passenger = (Passenger*)passengerBuilder->build();
    // ������ ��������� ���������
    passenger->setStartBusstop(this);
    // ������ �������� ��� ���� ���������
    passenger->setTargetBusstop(targetBusstop);
    // �������� � ������ ��������� ���������� �� ���������
    waitingPassengers.push_back(passenger);
}

void Busstop::despawnPassenger(Entity* passenger)
{
    // �������� ��������� ���������� �������� ��������
    auto ptrItem = find(arrivalPassengers.begin(), arrivalPassengers.end(), passenger);
    if (ptrItem != arrivalPassengers.end()) {
        Entity* entity = *ptrItem;
        // ���� ���������� �� ���������
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
