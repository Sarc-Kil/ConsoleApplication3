#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual string getDescription() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Ошибка: радиус круга должен быть положительным.");
    }

    string getDescription() const override {
        return "Круг с радиусом " + to_string(radius);
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw invalid_argument("Ошибка: сторона квадрата должна быть положительной.");
    }

    string getDescription() const override {
        return "Квадрат со стороной " + to_string(side);
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {
        if (b <= 0 || h <= 0) throw invalid_argument("Ошибка: основание и высота треугольника должны быть положительными.");
    }

    string getDescription() const override {
        return "Треугольник с основанием " + to_string(base) + " и высотой " + to_string(height);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите фигуру (1 - Круг, 2 - Квадрат, 3 - Треугольник, 0 - Выход): ";
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
                cout << circle.getDescription() << endl;
            }
            else if (choice == 2) {
                double side;
                cout << "Введите сторону квадрата: ";
                cin >> side;
                Square square(side);
                cout << square.getDescription() << endl;
            }
            else if (choice == 3) {
                double base, height;
                cout << "Введите основание и высоту треугольника: ";
                cin >> base >> height;
                Triangle triangle(base, height);
                cout << triangle.getDescription() << endl;
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