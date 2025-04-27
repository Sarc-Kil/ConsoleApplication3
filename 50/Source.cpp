#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void rotate(double angle) = 0;
};

class Circle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("Ошибка: Некорректный угол для вращения круга. Угол должен быть в диапазоне от 0 до 360.");
        }
        cout << "Круг вращен на " << angle << " градусов." << endl;
    }
};

class Square : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("Ошибка: Некорректный угол для вращения квадрата. Угол должен быть в диапазоне от 0 до 360.");
        }
        cout << "Квадрат вращен на " << angle << " градусов." << endl;
    }
};

class Triangle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("Ошибка: Некорректный угол для вращения треугольника. Угол должен быть в диапазоне от 0 до 360.");
        }
        cout << "Треугольник вращен на " << angle << " градусов." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double angle;

    cout << "Введите тип фигуры (круг/квадрат/треугольник): ";
    cin >> input;

    Shape* shape = nullptr;

    if (input == "круг") {
        shape = new Circle();
    }
    else if (input == "квадрат") {
        shape = new Square();
    }
    else if (input == "треугольник") {
        shape = new Triangle();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите угол вращения (0-360): ";
    cin >> angle;

    try {
        shape->rotate(angle);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete shape;
    return 0;
}