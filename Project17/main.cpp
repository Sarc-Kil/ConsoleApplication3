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
            throw invalid_argument("Ошибка: Недостаточно средств на кредитной карте.");
        }
        balance -= amount; 
        cout << "Оплата кредитной картой на сумму " << amount << " руб. успешно выполнена." << endl;
        cout << "Остаток на карте: " << balance << " руб." << endl;
    }
};

class PayPalPayment : public Payment {
public:
    PayPalPayment(double initialBalance) : Payment(initialBalance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            throw invalid_argument("Ошибка: Недостаточно средств на PayPal.");
        }
        balance -= amount; 
        cout << "Оплата через PayPal на сумму " << amount << " руб. успешно выполнена." << endl;
        cout << "Остаток на счете PayPal: " << balance << " руб." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        double initialBalance, paymentAmount;

        cout << "Введите начальный баланс для кредитной карты: ";
        cin >> initialBalance;
        CreditCardPayment creditCard(initialBalance);

        cout << "Введите сумму для оплаты с кредитной карты: ";
        cin >> paymentAmount;
        creditCard.processPayment(paymentAmount);

        cout << "Введите начальный баланс для PayPal: ";
        cin >> initialBalance;
        PayPalPayment payPal(initialBalance);

        cout << "Введите сумму для оплаты через PayPal: ";
        cin >> paymentAmount;
        payPal.processPayment(paymentAmount);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}