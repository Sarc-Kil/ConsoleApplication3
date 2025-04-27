#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual string getDescription() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("������: ������ ����� ������ ���� �������������.");
    }

    string getDescription() const override {
        return "���� � �������� " + to_string(radius);
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw invalid_argument("������: ������� �������� ������ ���� �������������.");
    }

    string getDescription() const override {
        return "������� �� �������� " + to_string(side);
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {
        if (b <= 0 || h <= 0) throw invalid_argument("������: ��������� � ������ ������������ ������ ���� ��������������.");
    }

    string getDescription() const override {
        return "����������� � ���������� " + to_string(base) + " � ������� " + to_string(height);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ������ (1 - ����, 2 - �������, 3 - �����������, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double radius;
                cout << "������� ������ �����: ";
                cin >> radius;
                Circle circle(radius);
                cout << circle.getDescription() << endl;
            }
            else if (choice == 2) {
                double side;
                cout << "������� ������� ��������: ";
                cin >> side;
                Square square(side);
                cout << square.getDescription() << endl;
            }
            else if (choice == 3) {
                double base, height;
                cout << "������� ��������� � ������ ������������: ";
                cin >> base >> height;
                Triangle triangle(base, height);
                cout << triangle.getDescription() << endl;
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