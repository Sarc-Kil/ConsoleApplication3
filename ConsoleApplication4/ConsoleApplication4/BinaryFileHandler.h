#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "FileHandler.h"
#include "TextFileHandler.h"
#include <string>
using namespace std;

class BinaryFileHandler : public FileHandler {
public:
    BinaryFileHandler(const string& file) : FileHandler(file) {}

    void open() override {
        FileHandler::open();
        cout << "Обработка бинарного файла: " << filename << endl;
    }
};