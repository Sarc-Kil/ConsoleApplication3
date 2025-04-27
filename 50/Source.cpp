#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void rotate(double angle) = 0;
};

class Circle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("������: ������������ ���� ��� �������� �����. ���� ������ ���� � ��������� �� 0 �� 360.");
        }
        cout << "���� ������ �� " << angle << " ��������." << endl;
    }
};

class Square : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("������: ������������ ���� ��� �������� ��������. ���� ������ ���� � ��������� �� 0 �� 360.");
        }
        cout << "������� ������ �� " << angle << " ��������." << endl;
    }
};

class Triangle : public Shape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("������: ������������ ���� ��� �������� ������������. ���� ������ ���� � ��������� �� 0 �� 360.");
        }
        cout << "����������� ������ �� " << angle << " ��������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double angle;

    cout << "������� ��� ������ (����/�������/�����������): ";
    cin >> input;

    Shape* shape = nullptr;

    if (input == "����") {
        shape = new Circle();
    }
    else if (input == "�������") {
        shape = new Square();
    }
    else if (input == "�����������") {
        shape = new Triangle();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ���� �������� (0-360): ";
    cin >> angle;

    try {
        shape->rotate(angle);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete shape;
    return 0;
}