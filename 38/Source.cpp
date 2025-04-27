#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual string getColor() = 0;
};

class Circle : public Shape {
private:
    string color;

public:
    Circle(const string& c) : color(c) {
        if (c.empty()) {
            throw invalid_argument("Некорректный параметр для цвета круга. Цвет не может быть пустым.");
        }
    }

    string getColor() override {
        return color;
    }
};

class Square : public Shape {
private:
    string color;

public:
    Square(const string& c) : color(c) {
        if (c.empty()) {
            throw invalid_argument("Некорректный параметр для цвета квадрата. Цвет не может быть пустым.");
        }
    }

    string getColor() override {
        return color;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, color;

    cout << "Введите тип фигуры (круг/квадрат): ";
    cin >> input;

    Shape* shape;

    if (input == "круг") {
        cout << "Введите цвет круга: ";
        cin >> color;
        try {
            shape = new Circle(color);
            cout << "Цвет круга: " << shape->getColor() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "квадрат") {
        cout << "Введите цвет квадрата: ";
        cin >> color;
        try {
            shape = new Square(color);
            cout << "Цвет квадрата: " << shape->getColor() << endl;
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