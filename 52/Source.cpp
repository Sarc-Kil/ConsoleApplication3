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
            throw invalid_argument("Ошибка: Недостаточно средств на кредитной карте.");
        }
        balance -= amount;
        cout << "Оплата с кредитной карты на сумму " << amount << " выполнена." << endl;
    }
};

class PayPalPayment : public Payment {
public:
    PayPalPayment(double initialBalance) : Payment(initialBalance) {}

    void process(double amount) override {
        if (amount > balance) {
            throw invalid_argument("Ошибка: Недостаточно средств на PayPal.");
        }
        balance -= amount;
        cout << "Оплата через PayPal на сумму " << amount << " выполнена." << endl;
    }
};

class BankTransfer : public Payment {
public:
    BankTransfer(double initialBalance) : Payment(initialBalance) {}

    void process(double amount) override {
        if (amount > balance) {
            throw invalid_argument("Ошибка: Недостаточно средств на банковском счете.");
        }
        balance -= amount;
        cout << "Банковский перевод на сумму " << amount << " выполнен." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double initialBalance, amount;

    cout << "Введите способ оплаты (кредитная карта/PayPal/банковский перевод): ";
    cin >> input;

    cout << "Введите начальный баланс: ";
    cin >> initialBalance;

    Payment* payment = nullptr;

    if (input == "кредитная карта") {
        payment = new CreditCardPayment(initialBalance);
    }
    else if (input == "PayPal") {
        payment = new PayPalPayment(initialBalance);
    }
    else if (input == "банковский перевод") {
        payment = new BankTransfer(initialBalance);
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите сумму для оплаты: ";
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