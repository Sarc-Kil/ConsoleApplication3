#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Logger {
public:
    virtual void log(const string& message) = 0;
};

class FileLogger : public Logger {
private:
    ofstream file;

public:
    FileLogger(const string& filename) {
        file.open(filename, ios::app);
        if (!file.is_open()) {
            throw invalid_argument("Ошибка: Не удалось открыть файл для логирования.");
        }
    }

    void log(const string& message) override {
        if (!(file << message << endl)) {
            throw runtime_error("Ошибка: Не удалось записать сообщение в лог файл.");
        }
    }

    ~FileLogger() {
        if (file.is_open()) {
            file.close();
        }
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        if (cout.fail()) {
            throw runtime_error("Ошибка: Не удалось записать сообщение в консоль.");
        }
        cout << message << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, message;

    cout << "Введите способ логирования (файл/консоль): ";
    cin >> input;

    Logger* logger = nullptr;

    if (input == "файл") {
        string filename;
        cout << "Введите имя файла для логирования: ";
        cin >> filename;
        try {
            logger = new FileLogger(filename);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    else if (input == "консоль") {
        logger = new ConsoleLogger();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите сообщение для логирования: ";
    cin.ignore();
    getline(cin, message);

    try {
        logger->log(message);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete logger;
    return 0;
}