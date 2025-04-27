#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

class Transaction {
public:
    virtual void execute() = 0;
    virtual ~Transaction() {}
};

class DepositTransaction : public Transaction {
private:
    double amount;
public:
    DepositTransaction(double amt) : amount(amt) {
        if (amt <= 0) throw invalid_argument("Ошибка: сумма депозита должна быть положительной.");
    }

    void execute() override {
        cout << "Депозит на сумму: " << amount << " успешно выполнен." << endl;
    }
};

class WithdrawalTransaction : public Transaction {
private:
    double amount;
    double& balance;
public:
    WithdrawalTransaction(double amt, double& bal) : amount(amt), balance(bal) {
        if (amt <= 0) throw invalid_argument("Ошибка: сумма снятия должна быть положительной.");
    }

    void execute() override {
        if (amount > balance) throw runtime_error("Ошибка: недостаточно средств для снятия.");
        balance -= amount;
        cout << "Снятие на сумму: " << amount << " успешно выполнено. Остаток: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    double balance = 1000.0;

    while (true) {
        cout << "Выберите транзакцию (1 - Депозит, 2 - Снятие, 0 - Выход): ";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double amount;
                cout << "Введите сумму депозита: ";
                cin >> amount;
                DepositTransaction deposit(amount);
                deposit.execute();
            }
            else if (choice == 2) {
                double amount;
                cout << "Введите сумму снятия: ";
                cin >> amount;
                WithdrawalTransaction withdrawal(amount, balance);
                withdrawal.execute();
            }
            else {
                cout << "Некорректный выбор." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}