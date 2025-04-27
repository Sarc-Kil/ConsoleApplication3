#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Task {
public:
    virtual void execute() = 0;
};

class PrintTask : public Task {
private:
    string message;

public:
    PrintTask(const string& msg) : message(msg) {
        if (msg.empty()) {
            throw invalid_argument("Ошибка: Задача не инициализирована. Сообщение не может быть пустым.");
        }
    }

    void execute() override {
        cout << "Печать сообщения: " << message << endl;
    }
};

class EmailTask : public Task {
private:
    string email;

public:
    EmailTask(const string& emailAddr) : email(emailAddr) {
        if (emailAddr.empty()) {
            throw invalid_argument("Ошибка: Задача не инициализирована. Email не может быть пустым.");
        }
    }

    void execute() override {
        cout << "Отправка email на: " << email << endl;
    }
};

class DatabaseTask : public Task {
private:
    string query;

public:
    DatabaseTask(const string& sqlQuery) : query(sqlQuery) {
        if (sqlQuery.empty()) {
            throw invalid_argument("Ошибка: Задача не инициализирована. Запрос не может быть пустым.");
        }
    }

    void execute() override {
        cout << "Выполнение запроса к базе данных: " << query << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип задачи (печать/email/база): ";
    cin >> input;

    Task* task = nullptr;

    if (input == "печать") {
        string message;
        cout << "Введите сообщение для печати: ";
        cin.ignore();
        getline(cin, message);
        try {
            task = new PrintTask(message);
            task->execute();
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "email") {
        string email;
        cout << "Введите email для отправки: ";
        cin >> email;
        try {
            task = new EmailTask(email);
            task->execute();
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "база") {
        string query;
        cout << "Введите SQL запрос: ";
        cin.ignore();
        getline(cin, query);
        try {
            task = new DatabaseTask(query);
            task->execute();
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "Неверный ввод." << endl;
    }

    delete task;
    return 0;
}