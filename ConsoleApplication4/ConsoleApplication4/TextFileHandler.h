#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "BinaryFileHandler.h"
#include "FileHandler.h"
#include <string>
using namespace std;

class TextFileHandler : public FileHandler {
public:
    TextFileHandler(const string& file) : FileHandler(file) {}

    void open() override {
        FileHandler::open();
        cout << "Обработка текстового файла: " << filename << endl;
    }
};