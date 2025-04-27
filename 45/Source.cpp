#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class BankAccount {
public:
    virtual void transfer(double amount, BankAccount& toAccount) = 0;
    virtual double getBalance() const = 0;
};

class SavingsAccount : public BankAccount {
private:
    double balance;

public:
    SavingsAccount(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Некорректный начальный баланс. Баланс не может быть отрицательным.");
        }
    }

    void transfer(double amount, BankAccount& toAccount) override {
        if (amount > balance) {
            throw runtime_error("Недостаточно средств для перевода.");
        }
        balance -= amount;
        toAccount.transfer(amount, *this);
        cout << "Переведено " << amount << " на сберегательный счет." << endl;
    }

    double getBalance() const override {
        return balance;
    }
};

class CheckingAccount : public BankAccount {
private:
    double balance;

public:
    CheckingAccount(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Некорректный начальный баланс. Баланс не может быть отрицательным.");
        }
    }

    void transfer(double amount, BankAccount& toAccount) override {
        balance -= amount;
        cout << "Переведено " << amount << " на расчетный счет." << endl;
    }

    double getBalance() const override {
        return balance;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    double initialBalance, transferAmount;
    string accountType;

    cout << "Введите тип счета (сберегательный/расчетный): ";
    cin >> accountType;

    BankAccount* account;

    if (accountType == "сберегательный") {
        cout << "Введите начальный баланс сберегательного счета: ";
        cin >> initialBalance;
        try {
            account = new SavingsAccount(initialBalance);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    else if (accountType == "расчетный") {
        cout << "Введите начальный баланс расчетного счета: ";
        cin >> initialBalance;
        try {
            account = new CheckingAccount(initialBalance);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите сумму для перевода: ";
    cin >> transferAmount;

    try {
        account->transfer(transferAmount, *account);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete account;
    return 0;
}