#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "Cat.h"
#include "Dog.h"
using namespace std;
class Animal {
public:
    virtual void speak() = 0;
};
