#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

class Shape {
public:
    virtual void reflect(double angle) = 0;
};

class Circle : public Shape {
public:
    void reflect(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("������������ ���� ��������� ��� �����. ���� ������ ���� �� 0 �� 360.");
        }
        cout << "���� ������� �� ���� " << angle << " ��������." << endl;
    }
};

class Rectangle : public Shape {
public:
    void reflect(double angle) override {
        if (angle < 0 || angle >= 360) {
            throw invalid_argument("������������ ���� ��������� ��� ��������������. ���� ������ ���� �� 0 �� 360.");
        }
        cout << "������������� ������� �� ���� " << angle << " ��������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double angle;

    cout << "������� ��� ������ (����/�������������): ";
    cin >> input;

    Shape* shape;

    if (input == "����") {
        shape = new Circle();
    }
    else if (input == "�������������") {
        shape = new Rectangle();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ���� ��������� (0-360): ";
    cin >> angle;

    try {
        shape->reflect(angle);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete shape;
    return 0;
}