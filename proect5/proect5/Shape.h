#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include "Square.h"
#include "Triangle.h"
using namespace std;
class Shape {
public:
    virtual void draw() const {
        throw runtime_error("Ошибка: Невозможно нарисовать фигуру с некорректными параметрами.");
    }

    virtual ~Shape() {}
};
