#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void getIntersection(const Shape& other) const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    double x, y;
public:
    Circle(double r, double xPos, double yPos) : radius(r), x(xPos), y(yPos) {
        if (r <= 0) throw invalid_argument("Ошибка: радиус круга должен быть положительным.");
    }

    void getIntersection(const Shape& other) const override {
        cout << "Нахождение пересечения круга с радиусом " << radius << " и центром (" << x << ", " << y << ")." << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    double x, y;
public:
    Rectangle(double w, double h, double xPos, double yPos) : width(w), height(h), x(xPos), y(yPos) {
        if (w <= 0 || h <= 0) throw invalid_argument("Ошибка: ширина и высота прямоугольника должны быть положительными.");
    }

    void getIntersection(const Shape& other) const override {
        cout << "Нахождение пересечения прямоугольника с шириной " << width << " и высотой " << height << " с верхним левым углом (" << x << ", " << y << ")." << endl;
    }
};

class Polygon : public Shape {
private:
    vector<pair<double, double>> vertices;
public:
    Polygon(const vector<pair<double, double>>& verts) : vertices(verts) {
        if (verts.size() < 3) throw invalid_argument("Ошибка: многоугольник должен иметь как минимум 3 вершины.");
    }

    void getIntersection(const Shape& other) const override {
        cout << "Нахождение пересечения многоугольника с " << vertices.size() << " вершинами." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите фигуру (1 - Круг, 2 - Прямоугольник, 3 - Многоугольник, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double radius, x, y;
                cout << "Введите радиус круга: ";
                cin >> radius;
                cout << "Введите координаты центра (x, y): ";
                cin >> x >> y;
                Circle circle(radius, x, y);
                circle.getIntersection(circle);
            }
            else if (choice == 2) {
                double width, height, x, y;
                cout << "Введите ширину и высоту прямоугольника: ";
                cin >> width >> height;
                cout << "Введите координаты верхнего левого угла (x, y): ";
                cin >> x >> y;
                Rectangle rectangle(width, height, x, y);
                rectangle.getIntersection(rectangle);
            }
            else if (choice == 3) {
                int numVertices;
                cout << "Введите количество вершин многоугольника: ";
                cin >> numVertices;
                vector<pair<double, double>> vertices;
                for (int i = 0; i < numVertices; ++i) {
                    double x, y;
                    cout << "Введите координаты вершины " << (i + 1) << " (x, y): ";
                    cin >> x >> y;
                    vertices.emplace_back(x, y);
                }
                Polygon polygon(vertices);
                polygon.getIntersection(polygon);
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