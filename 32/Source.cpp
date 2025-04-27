#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class FileReader {
public:
    virtual void read(const string& filename) = 0;
};

class TextFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("Ошибка чтения текстового файла: имя файла не может быть пустым.");
        }
        cout << "Чтение текстового файла: " << filename << endl;
    }
};

class BinaryFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("Ошибка чтения бинарного файла: имя файла не может быть пустым.");
        }
        cout << "Чтение бинарного файла: " << filename << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, filename;

    cout << "Введите тип файла (текстовый/бинарный): ";
    cin >> input;

    FileReader* fileReader;

    if (input == "текстовый") {
        fileReader = new TextFileReader();
    }
    else if (input == "бинарный") {
        fileReader = new BinaryFileReader();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите имя файла: ";
    cin.ignore();
    getline(cin, filename);

    try {
        fileReader->read(filename);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete fileReader;
    return 0;
}