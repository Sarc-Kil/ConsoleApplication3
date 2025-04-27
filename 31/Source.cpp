#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void reflect(double angle) = 0;
};

class Circle : public Shape {
public:
    void reflect(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("Некорректный угол отражения для круга. Угол должен быть от 0 до 360.");
        }
        cout << "Круг отражен на угол " << angle << " градусов." << endl;
    }
};

class Rectangle : public Shape {
public:
    void reflect(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("Некорректный угол отражения для прямоугольника. Угол должен быть от 0 до 360.");
        }
        cout << "Прямоугольник отражен на угол " << angle << " градусов." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double angle;

    cout << "Введите тип фигуры (круг/прямоугольник): ";
    cin >> input;

    Shape* shape;

    if (input == "круг") {
        shape = new Circle();
    }
    else if (input == "прямоугольник") {
        shape = new Rectangle();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите угол отражения (0-360): ";
    cin >> angle;

    try {
        shape->reflect(angle);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete shape;
    return 0;
}