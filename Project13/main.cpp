#include <iostream>
#include <stdexcept>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void scale(double factor) = 0; 
    virtual double area() const = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("Ошибка: Радиус должен быть положительным.");
        }
    }

    void scale(double factor) override {
        if (factor < 0) {
            throw invalid_argument("Ошибка: Масштабирование на отрицательное значение невозможно.");
        }
        radius *= factor; 
    }

    double area() const override {
        return 3.14 * radius * radius; 
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        if (s <= 0) {
            throw invalid_argument("Ошибка: Сторона должна быть положительной.");
        }
    }

    void scale(double factor) override {
        if (factor < 0) {
            throw invalid_argument("Ошибка: Масштабирование на отрицательное значение невозможно.");
        }
        side *= factor; 
    }

    double area() const override {
        return side * side; 
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        double radius, side;

        
        cout << "Введите радиус круга: ";
        cin >> radius;
        Circle circle(radius);

        
        cout << "Введите сторону квадрата: ";
        cin >> side;
        Square square(side);

        cout << "Площадь круга: " << circle.area() << endl;
        cout << "Площадь квадрата: " << square.area() << endl;

        double scaleFactor;
        cout << "Введите коэффициент масштабирования для круга: ";
        cin >> scaleFactor;
        circle.scale(scaleFactor);
        cout << "Новая площадь круга: " << circle.area() << endl;

        cout << "Введите коэффициент масштабирования для квадрата: ";
        cin >> scaleFactor;
        square.scale(scaleFactor);
        cout << "Новая площадь квадрата: " << square.area() << endl;

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}