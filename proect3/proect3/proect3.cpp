#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>
#include "CheckingAccount.h"
#include "BankAccount.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    double initialBalance;
    cout << "Введите начальный баланс: ";
    cin >> initialBalance;

    CheckingAccount checkingAccount(initialBalance);

    double amountToWithdraw;
    cout << "Введите сумму для снятия: ";
    cin >> amountToWithdraw;

    

    try {
        checkingAccount.withdraw(amountToWithdraw);
        cout << "Снятие успешно. Остаток на расчетном счете: " << checkingAccount.getBalance() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}