#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "CheckingAccount.h"
using namespace std;
class BankAccount {
protected:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    virtual void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Недостаточно средств на счете.");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    virtual ~BankAccount() {}
};
