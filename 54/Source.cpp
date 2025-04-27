#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class FileHandler {
public:
    virtual void open(const string& filename) = 0;
};

class TextFileHandler : public FileHandler {
public:
    void open(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open()) {
            throw invalid_argument("Ошибка: Не удалось открыть текстовый файл.");
        }
        cout << "Текстовый файл '" << filename << "' успешно открыт." << endl;
        file.close();
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void open(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            throw invalid_argument("Ошибка: Не удалось открыть бинарный файл.");
        }
        cout << "Бинарный файл '" << filename << "' успешно открыт." << endl;
        file.close();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, filename;

    cout << "Введите тип файла (текстовый/бинарный): ";
    cin >> input;

    FileHandler* fileHandler = nullptr;

    if (input == "текстовый") {
        fileHandler = new TextFileHandler();
    }
    else if (input == "бинарный") {
        fileHandler = new BinaryFileHandler();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите имя файла: ";
    cin >> filename;

    try {
        fileHandler->open(filename);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete fileHandler;
    return 0;
}