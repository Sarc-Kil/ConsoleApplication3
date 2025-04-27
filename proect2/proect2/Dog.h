#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "Animal.h"
#include "Cat.h"
using namespace std;

class Dog : public Animal {
private:
    string name;

public:
    Dog(const string& name) {
        if (name.empty()) {
            throw invalid_argument("Имя псины не может быть пустым.");
        }
        this->name = name;
    }

    void speak() override {
        cout << "Гав! Я " << name << endl;
    }
};