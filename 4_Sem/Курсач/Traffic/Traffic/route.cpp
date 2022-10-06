#include "route.h"
#include "bus.h"

Route::~Route()
{
    // очищаем память из-под ресурсов
    for (Entity* bus : busArray) {
        delete bus;
    }
    for (Entity* busstop : busstopArray) {
        delete busstop;
    }
}

void Route::tick(double delta)
{
    // ищем автобусы с отметкой для удаления и удаляем их
    for (Entity* busEntity : busArray) {
        Bus* bus = (Bus*)busEntity;
        if (bus->isNeedToDelete()) {
            despawnBus(bus);
        }
    }
    //  добавляем автобусы, если на маршруте их меньше, чем надо
    while (busArray.size() < busCount) {
        spawnBus();
    }
    // вызывваем "тик" для каждого автобуса
    for (Entity* bus : busArray) {
        bus->tick(delta);
    }
    // и для каждой остановки
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
    // удаление автобуса
    // найдем его в массиве атобусов
    auto ptrItem = find(busArray.begin(), busArray.end(), ptr);
    if (ptrItem != busArray.end()) {
        // удаляем данные
        Entity* entity = *ptrItem;
        // перед удалением собираем статистику
        Bus* bus = (Bus*)entity;
        // генерируем ошибку, если удаляется автобус, из которого вышли не все пассажиры
        if (bus->getPassengerCount() > 0) {
            throw "passenger on the bus!";
        }
        if (getStatcollector()) {
            getStatcollector()->
                addMissedStops((int)bus->getPassedBusstops()->size() - (int)bus->getVisitedBusstops()->size());
        }
        delete entity;
        // удаляем элемент из массива
        busArray.erase(ptrItem);
    }   
}

void Route::spawnBus()
{
    // добавляем в массив автобусов новый, созданный при помощи билдера
    Entity* newBus = busBuilder->build();
    // задаем текущий маршрут родительским для нового автобуса
    ((Bus*)newBus)->setParentRoute(this);
    busArray.push_back(newBus);
}
