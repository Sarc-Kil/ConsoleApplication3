#include <iostream>
#include <stdexcept>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        if (r <= 0) throw invalid_argument("Радиус должен быть положительным.");
        radius = r;
    }
    double getArea() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Ширина и высота должны быть положительными.");
        width = w;
        height = h;
    }
    double getArea() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) {
        if (b <= 0 || h <= 0) throw invalid_argument("Основание и высота должны быть положительными.");
        base = b;
        height = h;
    }
    double getArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите фигуру (1 - Круг, 2 - Прямоугольник, 3 - Треугольник, 0 - Выход): ";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double radius;
                cout << "Введите радиус круга: ";
                cin >> radius;
                Circle circle(radius);
                cout << "Площадь круга: " << circle.getArea() << endl;
            }
            else if (choice == 2) {
                double width, height;
                cout << "Введите ширину и высоту прямоугольника: ";
                cin >> width >> height;
                Rectangle rectangle(width, height);
                cout << "Площадь прямоугольника: " << rectangle.getArea() << endl;
            }
            else if (choice == 3) {
                double base, height;
                cout << "Введите основание и высоту треугольника: ";
                cin >> base >> height;
                Triangle triangle(base, height);
                cout << "Площадь треугольника: " << triangle.getArea() << endl;
            }
            else {
                cout << "Некорректный выбор." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}