#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Payment {
protected:
    double balance;

public:
    Payment(double initialBalance) : balance(initialBalance) {}
    virtual void process(double amount) = 0;
};

class CreditCardPayment : public Payment {
public:
    CreditCardPayment(double initialBalance) : Payment(initialBalance) {}

    void process(double amount) override {
        if (amount > balance) {
            throw invalid_argument("������: ������������ ������� �� ��������� �����.");
        }
        balance -= amount;
        cout << "������ � ��������� ����� �� ����� " << amount << " ���������." << endl;
    }
};

class PayPalPayment : public Payment {
public:
    PayPalPayment(double initialBalance) : Payment(initialBalance) {}

    void process(double amount) override {
        if (amount > balance) {
            throw invalid_argument("������: ������������ ������� �� PayPal.");
        }
        balance -= amount;
        cout << "������ ����� PayPal �� ����� " << amount << " ���������." << endl;
    }
};

class BankTransfer : public Payment {
public:
    BankTransfer(double initialBalance) : Payment(initialBalance) {}

    void process(double amount) override {
        if (amount > balance) {
            throw invalid_argument("������: ������������ ������� �� ���������� �����.");
        }
        balance -= amount;
        cout << "���������� ������� �� ����� " << amount << " ��������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double initialBalance, amount;

    cout << "������� ������ ������ (��������� �����/PayPal/���������� �������): ";
    cin >> input;

    cout << "������� ��������� ������: ";
    cin >> initialBalance;

    Payment* payment = nullptr;

    if (input == "��������� �����") {
        payment = new CreditCardPayment(initialBalance);
    }
    else if (input == "PayPal") {
        payment = new PayPalPayment(initialBalance);
    }
    else if (input == "���������� �������") {
        payment = new BankTransfer(initialBalance);
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ����� ��� ������: ";
    cin >> amount;

    try {
        payment->process(amount);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete payment;
    return 0;
}