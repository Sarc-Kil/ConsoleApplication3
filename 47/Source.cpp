#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void getBoundingBox(double& xMin, double& yMin, double& xMax, double& yMax) = 0;
};

class Circle : public Shape {
private:
    double centerX, centerY, radius;

public:
    Circle(double x, double y, double r) : centerX(x), centerY(y), radius(r) {
        if (r <= 0) {
            throw invalid_argument("Некорректный радиус для круга. Радиус должен быть положительным.");
        }
    }

    void getBoundingBox(double& xMin, double& yMin, double& xMax, double& yMax) override {
        xMin = centerX - radius;
        yMin = centerY - radius;
        xMax = centerX + radius;
        yMax = centerY + radius;
    }
};

class Rectangle : public Shape {
private:
    double x, y, width, height;

public:
    Rectangle(double x, double y, double w, double h) : x(x), y(y), width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw invalid_argument("Некорректные параметры для прямоугольника. Ширина и высота должны быть положительными.");
        }
    }

    void getBoundingBox(double& xMin, double& yMin, double& xMax, double& yMax) override {
        xMin = x;
        yMin = y;
        xMax = x + width;
        yMax = y + height;
    }
};

class Polygon : public Shape {
private:
    vector<pair<double, double>> vertices;

public:
    Polygon(const vector<pair<double, double>>& verts) : vertices(verts) {
        if (verts.size() < 3) {
            throw invalid_argument("Некорректные параметры для многоугольника. Должно быть не менее трех вершин.");
        }
    }

    void getBoundingBox(double& xMin, double& yMin, double& xMax, double& yMax) override {
        xMin = yMin = numeric_limits<double>::max();
        xMax = yMax = numeric_limits<double>::lowest();

        for (const auto& vertex : vertices) {
            if (vertex.first < xMin) xMin = vertex.first;
            if (vertex.first > xMax) xMax = vertex.first;
            if (vertex.second < yMin) yMin = vertex.second;
            if (vertex.second > yMax) yMax = vertex.second;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double x, y, width, height, radius;

    cout << "Введите тип фигуры (круг/прямоугольник/многоугольник): ";
    cin >> input;

    Shape* shape;

    if (input == "круг") {
        cout << "Введите координаты центра (x, y) и радиус: ";
        cin >> x >> y >> radius;
        try {
            shape = new Circle(x, y, radius);
            double xMin, yMin, xMax, yMax;
            shape->getBoundingBox(xMin, yMin, xMax, yMax);
            cout << "Границы круга: (" << xMin << ", " << yMin << "), (" << xMax << ", " << yMax << ")" << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "прямоугольник") {
        cout << "Введите координаты (x, y), ширину и высоту: ";
        cin >> x >> y >> width >> height;
        try {
            shape = new Rectangle(x, y, width, height);
            double xMin, yMin, xMax, yMax;
            shape->getBoundingBox(xMin, yMin, xMax, yMax);
            cout << "Границы прямоугольника: (" << xMin << ", " << yMin << "), (" << xMax << ", " << yMax << ")" << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "многоугольник") {
        int numVertices;
        cout << "Введите количество вершин многоугольника: ";
        cin >> numVertices;
        vector<pair<double, double>> vertices(numVertices);
        cout << "Введите координаты вершин (x, y): ";
        for (int i = 0; i < numVertices; ++i) {
            cin >> vertices[i].first >> vertices[i].second;
        }
        try {
            shape = new Polygon(vertices);
            double xMin, yMin, xMax, yMax;
            shape->getBoundingBox(xMin, yMin, xMax, yMax);
            cout << "Границы многоугольника: (" << xMin << ", " << yMin << "), (" << xMax << ", " << yMax << ")" << endl;
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