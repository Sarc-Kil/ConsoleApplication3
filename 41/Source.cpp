#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual double area() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("Некорректный радиус для круга. Радиус должен быть положительным.");
        }
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw invalid_argument("Некорректные параметры для прямоугольника. Ширина и высота должны быть положительными.");
        }
    }

    double area() override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("Некорректные параметры для треугольника. Стороны должны быть положительными и удовлетворять неравенству треугольника.");
        }
    }

    double area() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double a, b, c;

    cout << "Введите тип фигуры (круг/прямоугольник/треугольник): ";
    cin >> input;

    Shape* shape;

    if (input == "круг") {
        cout << "Введите радиус круга: ";
        cin >> a;
        try {
            shape = new Circle(a);
            cout << "Площадь круга: " << shape->area() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "прямоугольник") {
        cout << "Введите ширину и высоту прямоугольника: ";
        cin >> a >> b;
        try {
            shape = new Rectangle(a, b);
            cout << "Площадь прямоугольника: " << shape->area() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "треугольник") {
        cout << "Введите длины сторон треугольника: ";
        cin >> a >> b >> c;
        try {
            shape = new Triangle(a, b, c);
            cout << "Площадь треугольника: " << shape->area() << endl;
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