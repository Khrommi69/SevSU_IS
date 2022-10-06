#include "route.h"
#include "bus.h"

Route::~Route()
{
    // ������� ������ ��-��� ��������
    for (Entity* bus : busArray) {
        delete bus;
    }
    for (Entity* busstop : busstopArray) {
        delete busstop;
    }
}

void Route::tick(double delta)
{
    // ���� �������� � �������� ��� �������� � ������� ��
    for (Entity* busEntity : busArray) {
        Bus* bus = (Bus*)busEntity;
        if (bus->isNeedToDelete()) {
            despawnBus(bus);
        }
    }
    //  ��������� ��������, ���� �� �������� �� ������, ��� ����
    while (busArray.size() < busCount) {
        spawnBus();
    }
    // ��������� "���" ��� ������� ��������
    for (Entity* bus : busArray) {
        bus->tick(delta);
    }
    // � ��� ������ ���������
    for (Entity* busstopEntity : busstopArray) {
        busstopEntity->tick(delta);
    }
}

void Route::setLength(double l)
{
    length = l;
}

double Route::getLength()
{
    return length;
}

void Route::setBusCount(int c)
{
    busCount = c;
}

int Route::getBusCount()
{
    return busCount;
}

void Route::setBusBuilder(Builder* builder)
{
    busBuilder = builder;
}

Builder* Route::getBusBuilder()
{
    return busBuilder;
}

vector<Entity*>* Route::getBusArray()
{
    return &busArray;
}

vector<Entity*>* Route::getBusstopArray()
{
    return &busstopArray;
}

void Route::setStatcollector(Statcollector* sc)
{
    statcollector = sc;
}

Statcollector* Route::getStatcollector()
{
    return statcollector;
}

int Route::getBusstopIndex(Entity* busstop)
{
    int result = -1;
    for (int i = 0; i < busstopArray.size(); i++) {
        if (busstopArray[i] == busstop) {
            result = i;
            break;
        }
    }
    return result;
}

int Route::getBusstopCount()
{
    return (int)busstopArray.size();
}

Entity* Route::getBusstop(int index)
{
    return busstopArray[index];
}

void Route::despawnBus(Entity* ptr)
{
    // �������� ��������
    // ������ ��� � ������� ��������
    auto ptrItem = find(busArray.begin(), busArray.end(), ptr);
    if (ptrItem != busArray.end()) {
        // ������� ������
        Entity* entity = *ptrItem;
        // ����� ��������� �������� ����������
        Bus* bus = (Bus*)entity;
        // ���������� ������, ���� ��������� �������, �� �������� ����� �� ��� ���������
        if (bus->getPassengerCount() > 0) {
            throw "passenger on the bus!";
        }
        if (getStatcollector()) {
            getStatcollector()->
                addMissedStops((int)bus->getPassedBusstops()->size() - (int)bus->getVisitedBusstops()->size());
        }
        delete entity;
        // ������� ������� �� �������
        busArray.erase(ptrItem);
    }   
}

void Route::spawnBus()
{
    // ��������� � ������ ��������� �����, ��������� ��� ������ �������
    Entity* newBus = busBuilder->build();
    // ������ ������� ������� ������������ ��� ������ ��������
    ((Bus*)newBus)->setParentRoute(this);
    busArray.push_back(newBus);
}
