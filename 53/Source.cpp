#include <iostream>
#include <stdexcept>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("Ошибка: Некорректный радиус круга.");
        }
    }

    double getArea() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw invalid_argument("Ошибка: Некорректные параметры прямоугольника.");
        }
    }

    double getArea() override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {
        if (b <= 0 || h <= 0) {
            throw invalid_argument("Ошибка: Некорректные параметры треугольника.");
        }
    }

    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип фигуры (круг/прямоугольник/треугольник): ";
    cin >> input;

    Shape* shape = nullptr;

    if (input == "круг") {
        double radius;
        cout << "Введите радиус круга: ";
        cin >> radius;
        try {
            shape = new Circle(radius);
            cout << "Площадь круга: " << shape->getArea() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "прямоугольник") {
        double width, height;
        cout << "Введите ширину и высоту прямоугольника: ";
        cin >> width >> height;
        try {
            shape = new Rectangle(width, height);
            cout << "Площадь прямоугольника: " << shape->getArea() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "треугольник") {
        double base, height;
        cout << "Введите основание и высоту треугольника: ";
        cin >> base >> height;
        try {
            shape = new Triangle(base, height);
            cout << "Площадь треугольника: " << shape->getArea() << endl;
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