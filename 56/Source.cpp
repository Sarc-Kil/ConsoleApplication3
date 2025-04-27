#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual vector<pair<double, double>> getVertices() = 0;
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0 ||
            sideA + sideB <= sideC ||
            sideA + sideC <= sideB ||
            sideB + sideC <= sideA) {
            throw invalid_argument("Ошибка: Некорректные параметры для треугольника.");
        }
    }

    vector<pair<double, double>> getVertices() override {
        return { {0, 0}, {a, 0}, {a / 2, (sqrt(3) / 2) * a} };
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double sideLength) : side(sideLength) {
        if (sideLength <= 0) {
            throw invalid_argument("Ошибка: Некорректные параметры для квадрата.");
        }
    }

    vector<pair<double, double>> getVertices() override {
        return { {0, 0}, {side, 0}, {side, side}, {0, side} };
    }
};

class Pentagon : public Shape {
private:
    double side;

public:
    Pentagon(double sideLength) : side(sideLength) {
        if (sideLength <= 0) {
            throw invalid_argument("Ошибка: Некорректные параметры для пятиугольника.");
        }
    }

    vector<pair<double, double>> getVertices() override {
        return {
            {0, 0},
            {side, 0},
            {1.5 * side, (sqrt(5) - 1) * side / 2},
            {side / 2, (sqrt(5) - 1) * side},
            {-0.5 * side, (sqrt(5) - 1) * side / 2}
        };
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип фигуры (треугольник/квадрат/пятиугольник): ";
    cin >> input;

    Shape* shape = nullptr;

    if (input == "треугольник") {
        double a, b, c;
        cout << "Введите длины сторон треугольника: ";
        cin >> a >> b >> c;
        try {
            shape = new Triangle(a, b, c);
            auto vertices = shape->getVertices();
            cout << "Вершины треугольника: ";
            for (const auto& vertex : vertices) {
                cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            cout << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "квадрат") {
        double side;
        cout << "Введите длину стороны квадрата: ";
        cin >> side;
        try {
            shape = new Square(side);
            auto vertices = shape->getVertices();
            cout << "Вершины квадрата: ";
            for (const auto& vertex : vertices) {
                cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            cout << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "пятиугольник") {
        double side;
        cout << "Введите длину стороны пятиугольника: ";
        cin >> side;
        try {
            shape = new Pentagon(side);
            auto vertices = shape->getVertices();
            cout << "Вершины пятиугольника: ";
            for (const auto& vertex : vertices) {
                cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            cout << endl;
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