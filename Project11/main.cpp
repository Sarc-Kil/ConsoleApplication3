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
            throw invalid_argument("Ошибка: Расстояние и расход топлива должны быть положительными.");
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
            throw invalid_argument("Ошибка: Расстояние и расход топлива должны быть положительными.");
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

    cout << "Введите тип транспортного средства (c для автомобиля, t для грузовика): ";
    cin >> vehicleType;

    try {
        if (vehicleType == 'c') {
            cout << "Введите расстояние (км) и расход топлива (л): ";
            cin >> distance >> fuel;
            Car car(distance, fuel);
            cout << "Эффективность топлива автомобиля: " << car.fuelEfficiency() << " км/л" << endl;
        }
        else if (vehicleType == 't') {
            cout << "Введите расстояние (км) и расход топлива (л): ";
            cin >> distance >> fuel;
            Truck truck(distance, fuel);
            cout << "Эффективность топлива грузовика: " << truck.fuelEfficiency() << " км/л" << endl;
        }
        else {
            throw invalid_argument("Ошибка: Неверный тип транспортного средства.");
        }
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}