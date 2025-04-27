#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void scale(double factor) = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("Некорректный радиус для круга. Радиус должен быть положительным.");
        }
    }

    void scale(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("Некорректный коэффициент масштабирования. Он должен быть положительным.");
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
            throw invalid_argument("Некорректная сторона для квадрата. Сторона должна быть положительной.");
        }
    }

    void scale(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("Некорректный коэффициент масштабирования. Он должен быть положительным.");
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
                throw invalid_argument("Некорректные стороны для многоугольника. Все стороны должны быть положительными.");
            }
        }
    }

    void scale(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("Некорректный коэффициент масштабирования. Он должен быть положительным.");
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
    setlocale(LC_ALL, "ru");
    string input;
    double value;

    cout << "Введите тип фигуры (круг/квадрат/многоугольник): ";
    cin >> input;

    Shape* shape;

    if (input == "круг") {
        cout << "Введите радиус круга: ";
        cin >> value;
        try {
            shape = new Circle(value);
            cout << "Введите коэффициент масштабирования: ";
            cin >> value;
            shape->scale(value);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "квадрат") {
        cout << "Введите сторону квадрата: ";
        cin >> value;
        try {
            shape = new Square(value);
            cout << "Введите коэффициент масштабирования: ";
            cin >> value;
            shape->scale(value);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "многоугольник") {
        int numSides;
        cout << "Введите количество сторон многоугольника: ";
        cin >> numSides;
        vector<double> sides(numSides);
        cout << "Введите длины сторон: ";
        for (int i = 0; i < numSides; ++i) {
            cin >> sides[i];
        }
        try {
            shape = new Polygon(sides);
            cout << "Введите коэффициент масштабирования: ";
            cin >> value;
            shape->scale(value);
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