#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCardProcessor : public PaymentProcessor {
private:
    double balance;

public:
    CreditCardProcessor(double initialBalance) : balance(initialBalance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            throw runtime_error("������������� ������ �� ��������� �����.");
        }
        balance -= amount;
        cout << "������ �� ��������� ����� �� ����� " << amount << " ��������." << endl;
    }
};

class DebitCardProcessor : public PaymentProcessor {
private:
    double balance;

public:
    DebitCardProcessor(double initialBalance) : balance(initialBalance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            throw runtime_error("������������� ������ �� ��������� �����.");
        }
        balance -= amount;
        cout << "������ �� ��������� ����� �� ����� " << amount << " ��������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double initialBalance, amount;

    cout << "������� ��� ����� (���������/���������): ";
    cin >> input;

    if (input == "���������") {
        cout << "������� ��������� ������ ��������� �����: ";
        cin >> initialBalance;
        CreditCardProcessor processor(initialBalance);
        cout << "������� ����� �������: ";
        cin >> amount;

        try {
            processor.processPayment(amount);
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "���������") {
        cout << "������� ��������� ������ ��������� �����: ";
        cin >> initialBalance;
        DebitCardProcessor processor(initialBalance);
        cout << "������� ����� �������: ";
        cin >> amount;

        try {
            processor.processPayment(amount);
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "�������� ����." << endl;
    }

    return 0;
}