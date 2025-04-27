#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual double getPerimeter() const = 0;
    virtual ~Shape() {}
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("Ошибка: некорректные параметры для треугольника.");
        }
    }

    double getPerimeter() const override {
        return a + b + c;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) {
            throw invalid_argument("Ошибка: сторона квадрата должна быть положительной.");
        }
    }

    double getPerimeter() const override {
        return 4 * side;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите фигуру (1 - Треугольник, 2 - Квадрат, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double a, b, c;
                cout << "Введите стороны треугольника: ";
                cin >> a >> b >> c;
                Triangle triangle(a, b, c);
                cout << "Периметр треугольника: " << triangle.getPerimeter() << endl;
            }
            else if (choice == 2) {
                double side;
                cout << "Введите сторону квадрата: ";
                cin >> side;
                Square square(side);
                cout << "Периметр квадрата: " << square.getPerimeter() << endl;
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