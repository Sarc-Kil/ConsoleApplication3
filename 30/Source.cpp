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
            throw runtime_error("Недостаточный баланс на кредитной карте.");
        }
        balance -= amount;
        cout << "Платеж по кредитной карте на сумму " << amount << " выполнен." << endl;
    }
};

class DebitCardProcessor : public PaymentProcessor {
private:
    double balance;

public:
    DebitCardProcessor(double initialBalance) : balance(initialBalance) {}

    void processPayment(double amount) override {
        if (amount > balance) {
            throw runtime_error("Недостаточный баланс на дебетовой карте.");
        }
        balance -= amount;
        cout << "Платеж по дебетовой карте на сумму " << amount << " выполнен." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    double initialBalance, amount;

    cout << "Введите тип карты (кредитная/дебетовая): ";
    cin >> input;

    if (input == "кредитная") {
        cout << "Введите начальный баланс кредитной карты: ";
        cin >> initialBalance;
        CreditCardProcessor processor(initialBalance);
        cout << "Введите сумму платежа: ";
        cin >> amount;

        try {
            processor.processPayment(amount);
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "дебетовая") {
        cout << "Введите начальный баланс дебетовой карты: ";
        cin >> initialBalance;
        DebitCardProcessor processor(initialBalance);
        cout << "Введите сумму платежа: ";
        cin >> amount;

        try {
            processor.processPayment(amount);
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "Неверный ввод." << endl;
    }

    return 0;
}