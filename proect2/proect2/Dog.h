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
            throw invalid_argument("��� ����� �� ����� ���� ������.");
        }
        this->name = name;
    }

    void speak() override {
        cout << "���! � " << name << endl;
    }
};