#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "BinaryFileHandler.h"
#include "TextFileHandler.h"
#include <string>
using namespace std;

class FileHandler {
protected:
    string filename;

public:
    FileHandler(const string& file) : filename(file) {}

    virtual void open() {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("Файл не найден: " + filename);
        }
        cout << "Файл открыт: " << filename << endl;
        file.close();
    }

    virtual ~FileHandler() {}
};