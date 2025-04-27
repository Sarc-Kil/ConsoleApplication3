#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Logger {
public:
    virtual void log(const string& message) = 0;
};

class FileLogger : public Logger {
public:
    void log(const string& message) override {
        if (message.empty()) {
            throw runtime_error("Ошибка записи в лог: сообщение не может быть пустым.");
        }
        cout << "Запись в файл лога: " << message << endl;
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        if (message.empty()) {
            throw runtime_error("Ошибка записи в лог: сообщение не может быть пустым.");
        }
        cout << "Запись в консольный лог: " << message << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, message;

    cout << "Введите тип логгера (файл/консоль): ";
    cin >> input;

    Logger* logger;

    if (input == "файл") {
        logger = new FileLogger();
    }
    else if (input == "консоль") {
        logger = new ConsoleLogger();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите сообщение для записи в лог: ";
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