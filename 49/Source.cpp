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
            throw invalid_argument("������: ������ �� ����������������. ��������� �� ����� ���� ������.");
        }
    }

    void execute() override {
        cout << "������ ���������: " << message << endl;
    }
};

class EmailTask : public Task {
private:
    string email;

public:
    EmailTask(const string& emailAddr) : email(emailAddr) {
        if (emailAddr.empty()) {
            throw invalid_argument("������: ������ �� ����������������. Email �� ����� ���� ������.");
        }
    }

    void execute() override {
        cout << "�������� email ��: " << email << endl;
    }
};

class DatabaseTask : public Task {
private:
    string query;

public:
    DatabaseTask(const string& sqlQuery) : query(sqlQuery) {
        if (sqlQuery.empty()) {
            throw invalid_argument("������: ������ �� ����������������. ������ �� ����� ���� ������.");
        }
    }

    void execute() override {
        cout << "���������� ������� � ���� ������: " << query << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "������� ��� ������ (������/email/����): ";
    cin >> input;

    Task* task = nullptr;

    if (input == "������") {
        string message;
        cout << "������� ��������� ��� ������: ";
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
        cout << "������� email ��� ��������: ";
        cin >> email;
        try {
            task = new EmailTask(email);
            task->execute();
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "����") {
        string query;
        cout << "������� SQL ������: ";
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
        cout << "�������� ����." << endl;
    }

    delete task;
    return 0;
}