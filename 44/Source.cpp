#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void scale(double factor) = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("������������ ������ ��� �����. ������ ������ ���� �������������.");
        }
    }

    void scale(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("������������ ����������� ���������������. �� ������ ���� �������������.");
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
            throw invalid_argument("������������ ������� ��� ��������. ������� ������ ���� �������������.");
        }
    }

    void scale(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("������������ ����������� ���������������. �� ������ ���� �������������.");
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
                throw invalid_argument("������������ ������� ��� ��������������. ��� ������� ������ ���� ��������������.");
            }
        }
    }

    void scale(double factor) override {
        if (factor <= 0) {
            throw invalid_argument("������������ ����������� ���������������. �� ������ ���� �������������.");
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
    setlocale(LC_ALL, "ru");
    string input;
    double value;

    cout << "������� ��� ������ (����/�������/�������������): ";
    cin >> input;

    Shape* shape;

    if (input == "����") {
        cout << "������� ������ �����: ";
        cin >> value;
        try {
            shape = new Circle(value);
            cout << "������� ����������� ���������������: ";
            cin >> value;
            shape->scale(value);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "�������") {
        cout << "������� ������� ��������: ";
        cin >> value;
        try {
            shape = new Square(value);
            cout << "������� ����������� ���������������: ";
            cin >> value;
            shape->scale(value);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "�������������") {
        int numSides;
        cout << "������� ���������� ������ ��������������: ";
        cin >> numSides;
        vector<double> sides(numSides);
        cout << "������� ����� ������: ";
        for (int i = 0; i < numSides; ++i) {
            cin >> sides[i];
        }
        try {
            shape = new Polygon(sides);
            cout << "������� ����������� ���������������: ";
            cin >> value;
            shape->scale(value);
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