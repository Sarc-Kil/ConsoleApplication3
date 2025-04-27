#include <iostream>
#include <stdexcept>
#include <cmath>
#include "BinaryFileHandler.h"
#include "FileHandler.h"
#include "TextFileHandler.h"
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string filename;

    cout << "Введите имя файла: ";
    cin >> filename;

    TextFileHandler textFileHandler(filename);
    BinaryFileHandler binaryFileHandler(filename);

    try {
        textFileHandler.open();
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        binaryFileHandler.open();
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}