#include <iostream>
#include <stdexcept>
#include <vector>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void getBoundingBox() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("Некорректный радиус круга.");
        }
    }

    void getBoundingBox() override {
        double diameter = radius * 2;
        cout << "Границы круга: ширина = " << diameter << ", высота = " << diameter << endl;
    }
};

class Polygon : public Shape {
private:
    vector<pair<double, double>> vertices;

public:
    Polygon(const vector<pair<double, double>>& verts) : vertices(verts) {
        if (verts.size() < 3) {
            throw invalid_argument("Недостаточно вершин для полигона.");
        }
    }

    void getBoundingBox() override {
        double minX = vertices[0].first, maxX = vertices[0].first;
        double minY = vertices[0].second, maxY = vertices[0].second;

        for (const auto& vertex : vertices) {
            if (vertex.first < minX) minX = vertex.first;
            if (vertex.first > maxX) maxX = vertex.first;
            if (vertex.second < minY) minY = vertex.second;
            if (vertex.second > maxY) maxY = vertex.second;
        }

        cout << "Границы полигона: ширина = " << (maxX - minX) << ", высота = " << (maxY - minY) << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип фигуры (круг/многоугольник): ";
    cin >> input;

    Shape* shape;

    if (input == "круг") {
        double radius;
        cout << "Введите радиус круга: ";
        cin >> radius;
        try {
            shape = new Circle(radius);
            shape->getBoundingBox();
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "многоугольник") {
        int n;
        cout << "Введите количество вершин многоугольника: ";
        cin >> n;
        vector<pair<double, double>> vertices(n);
        for (int i = 0; i < n; ++i) {
            cout << "Введите координаты вершины " << i + 1 << " (x y): ";
            cin >> vertices[i].first >> vertices[i].second;
        }
        try {
            shape = new Polygon(vertices);
            shape->getBoundingBox();
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