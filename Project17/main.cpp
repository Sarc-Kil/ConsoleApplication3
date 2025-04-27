#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Payment {
protected:
    double balance;

public:
    Payment(double initialBalance) : balance(initialBalance) {}

    virtual void processPayment(double amount) = 0; 
    virtual ~Payment() {}
};

class CreditCardPayment : public Payment {
public:
    CreditCardPayment(double initialBalance) : Payment(initialBalance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            throw invalid_argument("������: ������������ ������� �� ��������� �����.");
        }
        balance -= amount; 
        cout << "������ ��������� ������ �� ����� " << amount << " ���. ������� ���������." << endl;
        cout << "������� �� �����: " << balance << " ���." << endl;
    }
};

class PayPalPayment : public Payment {
public:
    PayPalPayment(double initialBalance) : Payment(initialBalance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            throw invalid_argument("������: ������������ ������� �� PayPal.");
        }
        balance -= amount; 
        cout << "������ ����� PayPal �� ����� " << amount << " ���. ������� ���������." << endl;
        cout << "������� �� ����� PayPal: " << balance << " ���." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        double initialBalance, paymentAmount;

        cout << "������� ��������� ������ ��� ��������� �����: ";
        cin >> initialBalance;
        CreditCardPayment creditCard(initialBalance);

        cout << "������� ����� ��� ������ � ��������� �����: ";
        cin >> paymentAmount;
        creditCard.processPayment(paymentAmount);

        cout << "������� ��������� ������ ��� PayPal: ";
        cin >> initialBalance;
        PayPalPayment payPal(initialBalance);

        cout << "������� ����� ��� ������ ����� PayPal: ";
        cin >> paymentAmount;
        payPal.processPayment(paymentAmount);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}