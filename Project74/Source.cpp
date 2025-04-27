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
        if (amt <= 0) throw invalid_argument("������: ����� �������� ������ ���� �������������.");
    }

    void execute() override {
        cout << "������� �� �����: " << amount << " ������� ��������." << endl;
    }
};

class WithdrawalTransaction : public Transaction {
private:
    double amount;
    double& balance;
public:
    WithdrawalTransaction(double amt, double& bal) : amount(amt), balance(bal) {
        if (amt <= 0) throw invalid_argument("������: ����� ������ ������ ���� �������������.");
    }

    void execute() override {
        if (amount > balance) throw runtime_error("������: ������������ ������� ��� ������.");
        balance -= amount;
        cout << "������ �� �����: " << amount << " ������� ���������. �������: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    double balance = 1000.0;

    while (true) {
        cout << "�������� ���������� (1 - �������, 2 - ������, 0 - �����): ";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        try {
            if (choice == 1) {
                double amount;
                cout << "������� ����� ��������: ";
                cin >> amount;
                DepositTransaction deposit(amount);
                deposit.execute();
            }
            else if (choice == 2) {
                double amount;
                cout << "������� ����� ������: ";
                cin >> amount;
                WithdrawalTransaction withdrawal(amount, balance);
                withdrawal.execute();
            }
            else {
                cout << "������������ �����." << endl;
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