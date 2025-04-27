#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class FileReader {
public:
    virtual void read(const string& filename) = 0;
    virtual ~FileReader() {}
};

class TextFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("Ошибка: имя текстового файла не может быть пустым.");
        }
        cout << "Чтение текстового файла: " << filename << endl;
    }
};

class BinaryFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("Ошибка: имя бинарного файла не может быть пустым.");
        }
        cout << "Чтение бинарного файла: " << filename << endl;
    }
};

class JsonFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("Ошибка: имя JSON файла не может быть пустым.");
        }
        cout << "Чтение JSON файла: " << filename << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите формат файла для чтения (1 - Текстовый, 2 - Бинарный, 3 - JSON, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string filename;

        cout << "Введите имя файла: ";
        getline(cin, filename);

        try {
            FileReader* fileReader = nullptr;

            if (choice == 1) {
                fileReader = new TextFileReader();
            }
            else if (choice == 2) {
                fileReader = new BinaryFileReader();
            }
            else if (choice == 3) {
                fileReader = new JsonFileReader();
            }
            else {
                cout << "Некорректный выбор." << endl;
                continue;
            }

            fileReader->read(filename);
            delete fileReader;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}