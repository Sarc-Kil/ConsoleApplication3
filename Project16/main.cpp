#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Shape {
public:
    virtual void rotate(double angle) = 0; 
    virtual ~Shape() {}
};

class Triangle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("������: ���� ������ ���� � ��������� �� 0 �� 360 ��������.");
        }
        cout << "����������� �������� �� " << angle << " ��������." << endl;
    }
};

class Rectangle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("������: ���� ������ ���� � ��������� �� 0 �� 360 ��������.");
        }
        cout << "������������� �������� �� " << angle << " ��������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        Triangle triangle;
        Rectangle rectangle;

        double angle;

        cout << "������� ���� �������� ��� ������������: ";
        cin >> angle;
        triangle.rotate(angle);

        cout << "������� ���� �������� ��� ��������������: ";
        cin >> angle;
        rectangle.rotate(angle);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}