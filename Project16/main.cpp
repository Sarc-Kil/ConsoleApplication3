#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Shape {
public:
    virtual void rotate(double angle) = 0; 
    virtual ~Shape() {}
};

class Triangle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("Ошибка: Угол должен быть в диапазоне от 0 до 360 градусов.");
        }
        cout << "Треугольник повернут на " << angle << " градусов." << endl;
    }
};

class Rectangle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("Ошибка: Угол должен быть в диапазоне от 0 до 360 градусов.");
        }
        cout << "Прямоугольник повернут на " << angle << " градусов." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        Triangle triangle;
        Rectangle rectangle;

        double angle;

        cout << "Введите угол поворота для треугольника: ";
        cin >> angle;
        triangle.rotate(angle);

        cout << "Введите угол поворота для прямоугольника: ";
        cin >> angle;
        rectangle.rotate(angle);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}