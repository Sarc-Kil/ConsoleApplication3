#include <iostream>
#include <stdexcept>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double a, b, c;

    cout << "Введите длины сторон треугольника (a, b, c): ";
    cin >> a >> b >> c;

    try {
        Triangle triangle(a, b, c);
        triangle.draw();
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }


    double side;
    cout << "Введите длину стороны квадрата: ";
    cin >> side;

    try {
        Square square(side);
        square.draw();
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

  

    return 0;
}