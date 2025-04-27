#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Shape {
public:
    virtual string getColor() = 0;
};

class Circle : public Shape {
private:
    string color;

public:
    Circle(const string& c) : color(c) {
        if (c.empty()) {
            throw invalid_argument("������������ �������� ��� ����� �����. ���� �� ����� ���� ������.");
        }
    }

    string getColor() override {
        return color;
    }
};

class Square : public Shape {
private:
    string color;

public:
    Square(const string& c) : color(c) {
        if (c.empty()) {
            throw invalid_argument("������������ �������� ��� ����� ��������. ���� �� ����� ���� ������.");
        }
    }

    string getColor() override {
        return color;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, color;

    cout << "������� ��� ������ (����/�������): ";
    cin >> input;

    Shape* shape;

    if (input == "����") {
        cout << "������� ���� �����: ";
        cin >> color;
        try {
            shape = new Circle(color);
            cout << "���� �����: " << shape->getColor() << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "�������") {
        cout << "������� ���� ��������: ";
        cin >> color;
        try {
            shape = new Square(color);
            cout << "���� ��������: " << shape->getColor() << endl;
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