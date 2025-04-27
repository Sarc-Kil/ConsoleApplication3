#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Exception {
public:
    virtual string what() const = 0;
};

class FileNotFoundException : public Exception {
public:
    string what() const override {
        return "Ошибка: Файл не найден.";
    }
};

class InvalidInputException : public Exception {
public:
    string what() const override {
        return "Ошибка: Неверный ввод.";
    }
};

class NetworkException : public Exception {
public:
    string what() const override {
        return "Ошибка: Проблема с сетью.";
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип ошибки (файл/ввод/сеть): ";
    cin >> input;

    Exception* exception = nullptr;

    if (input == "файл") {
        exception = new FileNotFoundException();
    }
    else if (input == "ввод") {
        exception = new InvalidInputException();
    }
    else if (input == "сеть") {
        exception = new NetworkException();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << exception->what() << endl;

    delete exception;
    return 0;
}