#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Shape {
public:
    virtual void translate(double x, double y) = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    double centerX;
    double centerY;

public:
    Circle(double r, double x, double y) : radius(r), centerX(x), centerY(y) {}

    void translate(double x, double y) override {
        if (x < 0 || y < 0) {
            throw invalid_argument("������: ������ ���������� ���� �� ������������� ����������.");
        }
        centerX += x;
        centerY += y;
        cout << "���� ��������� �� ����� ����������: (" << centerX << ", " << centerY << ")" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    double topLeftX;
    double topLeftY;

public:
    Rectangle(double w, double h, double x, double y) : width(w), height(h), topLeftX(x), topLeftY(y) {}

    void translate(double x, double y) override {
        if (x < 0 || y < 0) {
            throw invalid_argument("������: ������ ���������� ������������� �� ������������� ����������.");
        }
        topLeftX += x;
        topLeftY += y;
        cout << "������������� ��������� �� ����� ����������: (" << topLeftX << ", " << topLeftY << ")" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        Circle circle(5.0, 0.0, 0.0);
        Rectangle rectangle(4.0, 3.0, 0.0, 0.0);

        double x, y;

        
        cout << "������� ���������� ��� ����������� ����� (x y): ";
        cin >> x >> y;
        circle.translate(x, y);

        
        cout << "������� ���������� ��� ����������� �������������� (x y): ";
        cin >> x >> y;
        rectangle.translate(x, y);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}