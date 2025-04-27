#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Shape.h"
#include "Triangle.h"
#include <string>
using namespace std;
class Square : public Shape {
private:
    double side;

public:
    Square(double sideLength) : side(sideLength) {

        if (side <= 0) {
            throw runtime_error("������: ������������ ��������� ��������.");
        }
    }

    void draw() const override {
        cout << "������ ������� �� ��������: " << side << endl;
    }
};