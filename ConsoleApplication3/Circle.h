#pragma once
#include "Shape.h"
#include <stdexcept>
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        if (r < 0) {
            throw std::invalid_argument("Радиус не может быть отрицательным.");
        }
        radius = r;
    }

    double area() const override {
        return 3.14 * radius * radius;
    }
};