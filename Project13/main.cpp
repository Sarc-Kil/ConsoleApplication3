#include <iostream>
#include <stdexcept>
#include <cmath>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void scale(double factor) = 0; 
    virtual double area() const = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("������: ������ ������ ���� �������������.");
        }
    }

    void scale(double factor) override {
        if (factor < 0) {
            throw invalid_argument("������: ��������������� �� ������������� �������� ����������.");
        }
        radius *= factor; 
    }

    double area() const override {
        return 3.14 * radius * radius; 
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        if (s <= 0) {
            throw invalid_argument("������: ������� ������ ���� �������������.");
        }
    }

    void scale(double factor) override {
        if (factor < 0) {
            throw invalid_argument("������: ��������������� �� ������������� �������� ����������.");
        }
        side *= factor; 
    }

    double area() const override {
        return side * side; 
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        double radius, side;

        
        cout << "������� ������ �����: ";
        cin >> radius;
        Circle circle(radius);

        
        cout << "������� ������� ��������: ";
        cin >> side;
        Square square(side);

        cout << "������� �����: " << circle.area() << endl;
        cout << "������� ��������: " << square.area() << endl;

        double scaleFactor;
        cout << "������� ����������� ��������������� ��� �����: ";
        cin >> scaleFactor;
        circle.scale(scaleFactor);
        cout << "����� ������� �����: " << circle.area() << endl;

        cout << "������� ����������� ��������������� ��� ��������: ";
        cin >> scaleFactor;
        square.scale(scaleFactor);
        cout << "����� ������� ��������: " << square.area() << endl;

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}