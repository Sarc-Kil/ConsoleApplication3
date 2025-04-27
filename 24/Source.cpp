#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual double getPerimeter() const = 0;
    virtual ~Shape() {}
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("������: ������������ ��������� ��� ������������.");
        }
    }

    double getPerimeter() const override {
        return a + b + c;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) {
            throw invalid_argument("������: ������� �������� ������ ���� �������������.");
        }
    }

    double getPerimeter() const override {
        return 4 * side;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ������ (1 - �����������, 2 - �������, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double a, b, c;
                cout << "������� ������� ������������: ";
                cin >> a >> b >> c;
                Triangle triangle(a, b, c);
                cout << "�������� ������������: " << triangle.getPerimeter() << endl;
            }
            else if (choice == 2) {
                double side;
                cout << "������� ������� ��������: ";
                cin >> side;
                Square square(side);
                cout << "�������� ��������: " << square.getPerimeter() << endl;
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