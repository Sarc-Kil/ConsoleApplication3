#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Shape {
public:
    virtual string getColor() const = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    string color;

public:
    Circle(const string& color) : color(color) {
        if (color.empty()) {
            throw invalid_argument("Ошибка: Цвет круга не может быть пустым.");
        }
    }

    string getColor() const override {
        return color;
    }
};

class Square : public Shape {
private:
    string color;

public:
    Square(const string& color) : color(color) {
        if (color.empty()) {
            throw invalid_argument("Ошибка: Цвет квадрата не может быть пустым.");
        }
    }

    string getColor() const override {
        return color;
    }
};

class Triangle : public Shape {
private:
    string color;

public:
    Triangle(const string& color) : color(color) {
        if (color.empty()) {
            throw invalid_argument("Ошибка: Цвет треугольника не может быть пустым.");
        }
    }

    string getColor() const override {
        return color;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    string shapeType;
    while (true) {
        cout << "Введите тип фигуры (circle, square, triangle, exit): ";
        cin >> shapeType;

        if (shapeType == "exit") {
            cout << "Выход из программы." << endl;
            break;
        }

        try {
            string color;
            cout << "Введите цвет фигуры: ";
            cin >> ws; 
            getline(cin, color);

            if (shapeType == "circle") {
                Circle circle(color);
                cout << "Цвет круга: " << circle.getColor() << endl;
            }
            else if (shapeType == "square") {
                Square square(color);
                cout << "Цвет квадрата: " << square.getColor() << endl;
            }
            else if (shapeType == "triangle") {
                Triangle triangle(color);
                cout << "Цвет треугольника: " << triangle.getColor() << endl;
            }
            else {
                cout << "Ошибка: Неизвестный тип фигуры." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}