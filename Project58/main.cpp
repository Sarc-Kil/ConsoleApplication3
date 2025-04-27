#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double getPerimeter() const = 0; 
    virtual ~Shape() {}
};

class Triangle : public Shape {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
       
        if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
            throw invalid_argument("Ошибка: Некорректные параметры для треугольника.");
        }
    }

    double getPerimeter() const override {
        return sideA + sideB + sideC; 
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        
        if (s <= 0) {
            throw invalid_argument("Ошибка: Некорректные параметры для квадрата.");
        }
    }

    double getPerimeter() const override {
        return 4 * side; 
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        double a, b, c;

        
        cout << "Введите стороны треугольника (a b c): ";
        cin >> a >> b >> c;
        Triangle triangle(a, b, c);
        cout << "Периметр треугольника: " << triangle.getPerimeter() << endl;

        
        double side;
        cout << "Введите сторону квадрата: ";
        cin >> side;
        Square square(side);
        cout << "Периметр квадрата: " << square.getPerimeter() << endl;

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}