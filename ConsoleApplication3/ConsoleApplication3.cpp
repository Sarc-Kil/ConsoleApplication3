#include <iostream>
#include <stdexcept>
#include <cmath>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        double radius;
        cout << "Введите радиус круга: ";
        cin >> radius;
        Shape* circle = new Circle(radius);
        cout << "Площадь круга: " << circle->area() << endl;
        delete circle;

        double width, height;
        cout << "Введите ширину прямоугольника: ";
        cin >> width;
        cout << "Введите высоту прямоугольника: ";
        cin >> height;
        Shape* rectangle = new Rectangle(height, width);
        cout << "Площадь прямоугольника: " << rectangle->area() << endl;
        delete rectangle;


    }
    catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}