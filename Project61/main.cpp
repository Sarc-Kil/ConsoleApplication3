#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual void transform(double factor) = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("������: ������ ����� ������ ���� �������������.");
        }
    }

    void transform(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("������: ������ ������������� ������ ���� �������������.");
        }
        radius *= factor; 
        cout << "����� ������ �����: " << radius << endl;
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

    void transform(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("������: ������ ������������� ������ ���� �������������.");
        }
        side *= factor; 
        cout << "����� ������� ��������: " << side << endl;
    }
};

class Polygon : public Shape {
private:
    vector<double> sides;

public:
    Polygon(const vector<double>& s) : sides(s) {
        for (double side : sides) {
            if (side <= 0) {
                throw invalid_argument("������: ��� ������� �������������� ������ ���� ��������������.");
            }
        }
    }

    void transform(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("������: ������ ������������� ������ ���� �������������.");
        }
        for (double& side : sides) {
            side *= factor; 
        }
        cout << "����� ������� ��������������: ";
        for (double side : sides) {
            cout << side << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    string shapeType;
    while (true) {
        cout << "������� ��� ������ (circle, square, polygon, exit): ";
        cin >> shapeType;

        if (shapeType == "exit") {
            cout << "����� �� ���������." << endl;
            break;
        }

        try {
            if (shapeType == "circle") {
                double radius;
                cout << "������� ������ �����: ";
                cin >> radius;
                Circle circle(radius);

                double factor;
                cout << "������� ������ �������������: ";
                cin >> factor;
                circle.transform(factor);
            }
            else if (shapeType == "square") {
                double side;
                cout << "������� ������� ��������: ";
                cin >> side;
                Square square(side);

                double factor;
                cout << "������� ������ �������������: ";
                cin >> factor;
                square.transform(factor);
            }
            else if (shapeType == "polygon") {
                int numSides;
                cout << "������� ���������� ������ ��������������: ";
                cin >> numSides;

                vector<double> sides(numSides);
                for (int i = 0; i < numSides; ++i) {
                    cout << "������� ����� ������� " << (i + 1) << ": ";
                    cin >> sides[i];
                }
                Polygon polygon(sides);

                double factor;
                cout << "������� ������ �������������: ";
                cin >> factor;
                polygon.transform(factor);
            }
            else {
                cout << "������: ����������� ��� ������." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}