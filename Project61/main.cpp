#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual void transform(double factor) = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("Ошибка: Радиус круга должен быть положительным.");
        }
    }

    void transform(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("Ошибка: Фактор трансформации должен быть положительным.");
        }
        radius *= factor; 
        cout << "Новый радиус круга: " << radius << endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        if (s <= 0) {
            throw invalid_argument("Ошибка: Сторона квадрата должна быть положительной.");
        }
    }

    void transform(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("Ошибка: Фактор трансформации должен быть положительным.");
        }
        side *= factor; 
        cout << "Новая сторона квадрата: " << side << endl;
    }
};

class Polygon : public Shape {
private:
    vector<double> sides;

public:
    Polygon(const vector<double>& s) : sides(s) {
        for (double side : sides) {
            if (side <= 0) {
                throw invalid_argument("Ошибка: Все стороны многоугольника должны быть положительными.");
            }
        }
    }

    void transform(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("Ошибка: Фактор трансформации должен быть положительным.");
        }
        for (double& side : sides) {
            side *= factor; 
        }
        cout << "Новые стороны многоугольника: ";
        for (double side : sides) {
            cout << side << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    string shapeType;
    while (true) {
        cout << "Введите тип фигуры (circle, square, polygon, exit): ";
        cin >> shapeType;

        if (shapeType == "exit") {
            cout << "Выход из программы." << endl;
            break;
        }

        try {
            if (shapeType == "circle") {
                double radius;
                cout << "Введите радиус круга: ";
                cin >> radius;
                Circle circle(radius);

                double factor;
                cout << "Введите фактор трансформации: ";
                cin >> factor;
                circle.transform(factor);
            }
            else if (shapeType == "square") {
                double side;
                cout << "Введите сторону квадрата: ";
                cin >> side;
                Square square(side);

                double factor;
                cout << "Введите фактор трансформации: ";
                cin >> factor;
                square.transform(factor);
            }
            else if (shapeType == "polygon") {
                int numSides;
                cout << "Введите количество сторон многоугольника: ";
                cin >> numSides;

                vector<double> sides(numSides);
                for (int i = 0; i < numSides; ++i) {
                    cout << "Введите длину стороны " << (i + 1) << ": ";
                    cin >> sides[i];
                }
                Polygon polygon(sides);

                double factor;
                cout << "Введите фактор трансформации: ";
                cin >> factor;
                polygon.transform(factor);
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