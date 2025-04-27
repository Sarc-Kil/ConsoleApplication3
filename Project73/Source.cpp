#include <iostream>
#include <stdexcept>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void getDimensions() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Ошибка: радиус круга должен быть положительным.");
    }

    void getDimensions() const override {
        cout << "Круг: радиус = " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Ошибка: ширина и высота прямоугольника должны быть положительными.");
    }

    void getDimensions() const override {
        cout << "Прямоугольник: ширина = " << width << ", высота = " << height << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {
        if (b <= 0 || h <= 0) throw invalid_argument("Ошибка: основание и высота треугольника должны быть положительными.");
    }

    void getDimensions() const override {
        cout << "Треугольник: основание = " << base << ", высота = " << height << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите фигуру (1 - Круг, 2 - Прямоугольник, 3 - Треугольник, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double radius;
                cout << "Введите радиус круга: ";
                cin >> radius;
                Circle circle(radius);
                circle.getDimensions();
            }
            else if (choice == 2) {
                double width, height;
                cout << "Введите ширину и высоту прямоугольника: ";
                cin >> width >> height;
                Rectangle rectangle(width, height);
                rectangle.getDimensions();
            }
            else if (choice == 3) {
                double base, height;
                cout << "Введите основание и высоту треугольника: ";
                cin >> base >> height;
                Triangle triangle(base, height);
                triangle.getDimensions();
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