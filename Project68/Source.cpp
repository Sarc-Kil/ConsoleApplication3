#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class ExceptionHandler {
public:
    virtual void handle(const string& message) = 0;
    virtual ~ExceptionHandler() {}
};

class FileExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& message) override {
        cout << "Обработка ошибки файла: " << message << endl;
    }
};

class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& message) override {
        cout << "Обработка сетевой ошибки: " << message << endl;
    }
};

class InputExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& message) override {
        cout << "Обработка ошибки ввода: " << message << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите тип ошибки для обработки (1 - Файл, 2 - Сеть, 3 - Ввод, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string message;

        cout << "Введите сообщение об ошибке: ";
        getline(cin, message);

        try {
            ExceptionHandler* handler = nullptr;

            if (choice == 1) {
                handler = new FileExceptionHandler();
            }
            else if (choice == 2) {
                handler = new NetworkExceptionHandler();
            }
            else if (choice == 3) {
                handler = new InputExceptionHandler();
            }
            else {
                cout << "Некорректный выбор." << endl;
                continue;
            }

            handler->handle(message);
            delete handler;
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}