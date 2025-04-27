
#include <iostream>
#include <stdexcept>

using namespace std;

class Calculator {
public:
    virtual double calculate(double a, double b) const = 0; 
    virtual ~Calculator() {}
};

class Addition : public Calculator {
public:
    double calculate(double a, double b) const override {
        return a + b; 
    }
};

class Division : public Calculator {
public:
    double calculate(double a, double b) const override {
        if (b == 0) {
            throw runtime_error("������: ������� �� ����.");
        }
        return a / b; 
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    double a, b;
    char operation;
    Calculator* calculator = nullptr; 

    cout << "������� ������ �����: ";
    cin >> a;
    cout << "������� ������ �����: ";
    cin >> b;
    cout << "������� �������� (+ ��� ��������, / ��� �������): ";
    cin >> operation;

    try {
        if (operation == '+') {
            calculator = new Addition();
            cout << "��������� ��������: " << calculator->calculate(a, b) << endl;
        }
        else if (operation == '/') {
            calculator = new Division();
            cout << "��������� �������: " << calculator->calculate(a, b) << endl;
        }
        else {
            cout << "������: �������� ��������." << endl;
        }

        
        delete calculator;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
        delete calculator; 
    }

    return 0;
}