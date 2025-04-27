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
            throw invalid_argument("������: ������������ ��������� ��� ������������.");
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
            throw invalid_argument("������: ������������ ��������� ��� ��������.");
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
            throw invalid_argument("������: ������������ ��������� ��� �������������.");
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

    cout << "������� ��� ������ (�����������/�������/������������): ";
    cin >> input;

    Shape* shape = nullptr;

    if (input == "�����������") {
        double a, b, c;
        cout << "������� ����� ������ ������������: ";
        cin >> a >> b >> c;
        try {
            shape = new Triangle(a, b, c);
            auto vertices = shape->getVertices();
            cout << "������� ������������: ";
            for (const auto& vertex : vertices) {
                cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            cout << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "�������") {
        double side;
        cout << "������� ����� ������� ��������: ";
        cin >> side;
        try {
            shape = new Square(side);
            auto vertices = shape->getVertices();
            cout << "������� ��������: ";
            for (const auto& vertex : vertices) {
                cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            cout << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "������������") {
        double side;
        cout << "������� ����� ������� �������������: ";
        cin >> side;
        try {
            shape = new Pentagon(side);
            auto vertices = shape->getVertices();
            cout << "������� �������������: ";
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
        cout << "�������� ����." << endl;
    }

    delete shape;
    return 0;
}