#include <iostream>
#include <stdexcept>
#include <string>
#include "Dog.h"
#include "Cat.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        string dogName, catName;

        cout << "Введите имя собаки: ";
        getline(cin, dogName);
        Dog dog(dogName);
        dog.speak();

        cout << "Введите имя кошки: ";
        getline(cin, catName);
        Cat cat(catName);
        cat.speak();
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}