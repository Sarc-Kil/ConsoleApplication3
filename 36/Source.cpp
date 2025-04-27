#include <iostream>
#include <stdexcept>
#include <vector>
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
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("Некорректные параметры для треугольника.");
        }
    }

    vector<pair<double, double>> getVertices() override {
        return { {0, 0}, {a, 0}, {a * (b * b - c * c) / (2 * a * a), (b * b - a * a + c * c) / (2 * b)} };
    }
};

class Pentagon : public Shape {
private:
    double side;

public:
    Pentagon(double s) : side(s) {
        if (s <= 0) {
            throw invalid_argument("Некорректный параметр для пятиугольника.");
        }
    }

    vector<pair<double, double>> getVertices() override {
        vector<pair<double, double>> vertices;
        for (int i = 0; i < 5; ++i) {
            double angle = 2 * 3.14 * i / 5;
            vertices.emplace_back(side * cos(angle), side * sin(angle));
        }
        return vertices;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double a, b, c;

    cout << "Введите тип фигуры (треугольник/пятиугольник): ";
    cin >> input;

    Shape* shape;

    if (input == "треугольник") {
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
    else if (input == "пятиугольник") {
        cout << "Введите длину стороны пятиугольника: ";
        cin >> a;
        try {
            shape = new Pentagon(a);
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