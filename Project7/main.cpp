
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
            throw runtime_error("Ошибка: Деление на ноль.");
        }
        return a / b; 
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    double a, b;
    char operation;
    Calculator* calculator = nullptr; 

    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Введите операцию (+ для сложения, / для деления): ";
    cin >> operation;

    try {
        if (operation == '+') {
            calculator = new Addition();
            cout << "Результат сложения: " << calculator->calculate(a, b) << endl;
        }
        else if (operation == '/') {
            calculator = new Division();
            cout << "Результат деления: " << calculator->calculate(a, b) << endl;
        }
        else {
            cout << "Ошибка: Неверная операция." << endl;
        }

        
        delete calculator;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
        delete calculator; 
    }

    return 0;
}