#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Square.h"
#include "Shape.h"
#include <string>
using namespace std;
class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {

        if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
            throw runtime_error("Ошибка: Некорректные параметры треугольника.");
        }
    }

    void draw() const override {
        cout << "Рисуем треугольник со сторонами: " << a << ", " << b << ", " << c << endl;
    }
};