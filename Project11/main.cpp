#include <iostream>
#include <stdexcept>

using namespace std;

class Vehicle {
public:
    virtual double fuelEfficiency() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    double distance;
    double fuel;

public:
    Car(double d, double f) : distance(d), fuel(f) {
        if (d <= 0 || f <= 0) {
            throw invalid_argument("������: ���������� � ������ ������� ������ ���� ��������������.");
        }
    }

    double fuelEfficiency() const override {
        return distance / fuel;
    }
};

class Truck : public Vehicle {
private:
    double distance; 
    double fuel;    

public:
    Truck(double d, double f) : distance(d), fuel(f) {
        if (d <= 0 || f <= 0) {
            throw invalid_argument("������: ���������� � ������ ������� ������ ���� ��������������.");
        }
    }

    double fuelEfficiency() const override {
        return distance / fuel; 
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    double distance, fuel;
    char vehicleType;

    cout << "������� ��� ������������� �������� (c ��� ����������, t ��� ���������): ";
    cin >> vehicleType;

    try {
        if (vehicleType == 'c') {
            cout << "������� ���������� (��) � ������ ������� (�): ";
            cin >> distance >> fuel;
            Car car(distance, fuel);
            cout << "������������� ������� ����������: " << car.fuelEfficiency() << " ��/�" << endl;
        }
        else if (vehicleType == 't') {
            cout << "������� ���������� (��) � ������ ������� (�): ";
            cin >> distance >> fuel;
            Truck truck(distance, fuel);
            cout << "������������� ������� ���������: " << truck.fuelEfficiency() << " ��/�" << endl;
        }
        else {
            throw invalid_argument("������: �������� ��� ������������� ��������.");
        }
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}