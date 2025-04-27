#include <iostream>
#include <stdexcept>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("������: ������������ ������ �����.");
        }
    }

    double getArea() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw invalid_argument("������: ������������ ��������� ��������������.");
        }
    }

    double getArea() override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {
        if (b <= 0 || h <= 0) {
            throw invalid_argument("������: ������������ ��������� ������������.");
        }
    }

    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "������� ��� ������ (����/�������������/�����������): ";
    cin >> input;

    Shape* shape = nullptr;

    if (input == "����") {
        double radius;
        cout << "������� ������ �����: ";
        cin >> radius;
        try {
            shape = new Circle(radius);
            cout << "������� �����: " << shape->getArea() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "�������������") {
        double width, height;
        cout << "������� ������ � ������ ��������������: ";
        cin >> width >> height;
        try {
            shape = new Rectangle(width, height);
            cout << "������� ��������������: " << shape->getArea() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "�����������") {
        double base, height;
        cout << "������� ��������� � ������ ������������: ";
        cin >> base >> height;
        try {
            shape = new Triangle(base, height);
            cout << "������� ������������: " << shape->getArea() << endl;
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