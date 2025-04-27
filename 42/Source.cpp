#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Employee {
public:
    virtual double calculateSalary(int hoursWorked) = 0;
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {
        if (salary < 0) {
            throw invalid_argument("Некорректная зарплата для полного рабочего дня. Зарплата не может быть отрицательной.");
        }
    }

    double calculateSalary(int hoursWorked) override {
        if (hoursWorked < 0) {
            throw invalid_argument("Некорректные часы работы. Часы работы не могут быть отрицательными.");
        }
        return monthlySalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;

public:
    PartTimeEmployee(double rate) : hourlyRate(rate) {
        if (rate < 0) {
            throw invalid_argument("Некорректная почасовая ставка. Ставка не может быть отрицательной.");
        }
    }

    double calculateSalary(int hoursWorked) override {
        if (hoursWorked < 0) {
            throw invalid_argument("Некорректные часы работы. Часы работы не могут быть отрицательными.");
        }
        return hourlyRate * hoursWorked;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double salaryOrRate;
    int hoursWorked;

    cout << "Введите тип сотрудника (полный/частичный): ";
    cin >> input;

    Employee* employee;

    if (input == "полный") {
        cout << "Введите месячную зарплату: ";
        cin >> salaryOrRate;
        try {
            employee = new FullTimeEmployee(salaryOrRate);
            cout << "Введите часы работы: ";
            cin >> hoursWorked;
            cout << "Зарплата: " << employee->calculateSalary(hoursWorked) << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "частичный") {
        cout << "Введите почасовую ставку: ";
        cin >> salaryOrRate;
        try {
            employee = new PartTimeEmployee(salaryOrRate);
            cout << "Введите часы работы: ";
            cin >> hoursWorked;
            cout << "Зарплата: " << employee->calculateSalary(hoursWorked) << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "Неверный ввод." << endl;
    }

    delete employee;
    return 0;
}