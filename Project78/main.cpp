#include <iostream>
#include <stdexcept>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        if (r <= 0) throw invalid_argument("������ ������ ���� �������������.");
        radius = r;
    }
    double getArea() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) {
        if (w <= 0 || h <= 0) throw invalid_argument("������ � ������ ������ ���� ��������������.");
        width = w;
        height = h;
    }
    double getArea() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) {
        if (b <= 0 || h <= 0) throw invalid_argument("��������� � ������ ������ ���� ��������������.");
        base = b;
        height = h;
    }
    double getArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ������ (1 - ����, 2 - �������������, 3 - �����������, 0 - �����): ";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double radius;
                cout << "������� ������ �����: ";
                cin >> radius;
                Circle circle(radius);
                cout << "������� �����: " << circle.getArea() << endl;
            }
            else if (choice == 2) {
                double width, height;
                cout << "������� ������ � ������ ��������������: ";
                cin >> width >> height;
                Rectangle rectangle(width, height);
                cout << "������� ��������������: " << rectangle.getArea() << endl;
            }
            else if (choice == 3) {
                double base, height;
                cout << "������� ��������� � ������ ������������: ";
                cin >> base >> height;
                Triangle triangle(base, height);
                cout << "������� ������������: " << triangle.getArea() << endl;
            }
            else {
                cout << "������������ �����." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}