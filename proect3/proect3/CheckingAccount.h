#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "BankAccount.h"
using namespace std;
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(double initialBalance) : BankAccount(initialBalance) {}

    void withdraw(double amount) override {
        BankAccount::withdraw(amount);
    }
};