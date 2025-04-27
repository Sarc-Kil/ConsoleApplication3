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
            throw invalid_argument("������������ �������� ��� ������� �������� ���. �������� �� ����� ���� �������������.");
        }
    }

    double calculateSalary(int hoursWorked) override {
        if (hoursWorked < 0) {
            throw invalid_argument("������������ ���� ������. ���� ������ �� ����� ���� ��������������.");
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
            throw invalid_argument("������������ ��������� ������. ������ �� ����� ���� �������������.");
        }
    }

    double calculateSalary(int hoursWorked) override {
        if (hoursWorked < 0) {
            throw invalid_argument("������������ ���� ������. ���� ������ �� ����� ���� ��������������.");
        }
        return hourlyRate * hoursWorked;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double salaryOrRate;
    int hoursWorked;

    cout << "������� ��� ���������� (������/���������): ";
    cin >> input;

    Employee* employee;

    if (input == "������") {
        cout << "������� �������� ��������: ";
        cin >> salaryOrRate;
        try {
            employee = new FullTimeEmployee(salaryOrRate);
            cout << "������� ���� ������: ";
            cin >> hoursWorked;
            cout << "��������: " << employee->calculateSalary(hoursWorked) << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "���������") {
        cout << "������� ��������� ������: ";
        cin >> salaryOrRate;
        try {
            employee = new PartTimeEmployee(salaryOrRate);
            cout << "������� ���� ������: ";
            cin >> hoursWorked;
            cout << "��������: " << employee->calculateSalary(hoursWorked) << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "�������� ����." << endl;
    }

    delete employee;
    return 0;
}