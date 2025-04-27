#include <iostream>
#include <stdexcept>
#include <locale>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Ellipse : public Shape {
private:
    double semiMajorAxis;
    double semiMinorAxis;

public:
    Ellipse(double a, double b) : semiMajorAxis(a), semiMinorAxis(b) {
        if (a <= 0 || b <= 0) {
            throw invalid_argument("Некорректные параметры для эллипса. Полуоси должны быть положительными.");
        }
    }

    double getArea() override {
        return 3.14 * semiMajorAxis * semiMinorAxis;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        if (s <= 0) {
            throw invalid_argument("Некорректный параметр для квадрата. Сторона должна быть положительной.");
        }
    }

    double getArea() override {
        return side * side;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double a, b;

    cout << "Введите тип фигуры (эллипс/квадрат): ";
    cin >> input;

    Shape* shape;

    if (input == "эллипс") {
        cout << "Введите длину полуоси a: ";
        cin >> a;
        cout << "Введите длину полуоси b: ";
        cin >> b;
        try {
            shape = new Ellipse(a, b);
            cout << "Площадь эллипса: " << shape->getArea() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "квадрат") {
        cout << "Введите длину стороны квадрата: ";
        cin >> a;
        try {
            shape = new Square(a);
            cout << "Площадь квадрата: " << shape->getArea() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "Неверный ввод." << endl;
    }

    delete shape;
    return 0;
}