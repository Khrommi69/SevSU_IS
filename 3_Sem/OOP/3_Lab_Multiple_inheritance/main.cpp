#include <iostream>
#include <windows.h>
#include <string>

#define UI unsigned int

using namespace std;

class Car {
    string brand;
    UI power;
    UI speed;
public:
    Car() { power = speed = 0; brand = "0"; cout << "����������� Car �� �����." << endl; }
    Car(string _brand, UI _power, UI _speed) { brand = _brand; power = _power; speed = _speed; cout << "����������� Car" << endl; }
    ~Car() { cout << "���������� Car" << endl; }

    void set_car(string _brand, UI _power, UI _speed) { brand = _brand; power = _power; speed = _speed; }
    void show_car() { cout << "����� - " << brand << ", �������� - " << power << ", �������� - " << speed << endl; }
};

class Vehicle {
    UI tonnage;
    string type;
public:
    Vehicle() { tonnage = 0; type = "0"; cout << "����������� Vehicle �� �����." << endl; }
    Vehicle(UI _tonnage, string _type) { tonnage = _tonnage; type = _type; cout << "����������� Vehicle" << endl; }
    ~Vehicle() { cout << "���������� Vehicle" << endl; }

    void set_vehicle(UI _tonnage, string _type) { tonnage = _tonnage; type = _type; }
    void show_vehicle() { cout << "��� - " << type << ", ������ - " << tonnage << endl; }
};

class Truck : public Car, public Vehicle {
public:
    Truck() : Car(), Vehicle() { cout << "����������� Truck �� �����." << endl; }
    Truck(string _brand, UI _power, UI _speed, UI _tonnage, string _type) : Car(_brand, _power, _speed), Vehicle(_tonnage, _type) { cout << "����������� Truck" << endl; }
    ~Truck() { cout << "���������� Truck" << endl; }

    void set_truck(string _brand, UI _power, UI _speed, UI _tonnage, string _type) { set_car(_brand, _power, _speed); set_vehicle(_tonnage, _type); }
    void show_truck() { show_car(); show_vehicle(); }
    UI sum_parameters(UI _power, UI _speed, UI _tonnage);
};

UI Truck::sum_parameters(UI _power, UI _speed, UI _tonnage){
    return _power+_speed+_tonnage;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Car *car_obj = new Car;
    car_obj->show_car();
    string _brand = "Mercedes-Benz";
    UI _power = 8000;
    UI _speed = 234;
    car_obj->set_car(_brand, _power, _speed);
    car_obj->show_car();
    car_obj->set_car("�����", 8600, 100);
    car_obj->show_car();
    delete car_obj;
    cout << endl;

    UI _tonnage = 12;
    string _type = "������-��������������";
    Vehicle *vehicle_obj = new Vehicle(_tonnage, _type);
    vehicle_obj->show_vehicle();
    delete vehicle_obj;
    cout << endl;

    Truck *truck_obj = new Truck("Hyundai", 15600, 80, 40, "������-��������������");
    truck_obj->show_truck();
    cout << "��������� �� ������ ������: " << endl;
    cout << "power: " << _power << ", speed: " << _speed << ", tonnage: " << _tonnage << endl;
    cout << "����� ����������: " << truck_obj->sum_parameters(_power, _speed, _tonnage) << endl << endl;
    _brand = "Volvo FMX";
    _power = 14000;
    _speed = 120;
    _tonnage = 32;
    _type = "������-��������������";
    truck_obj->set_truck(_brand, _power, _speed, _tonnage, _type);
    truck_obj->show_truck();
    delete truck_obj;
    cout << endl;
    
    system("pause");
    return 0;
}
