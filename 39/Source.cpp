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
            throw runtime_error("������ ������ � ���: ��������� �� ����� ���� ������.");
        }
        cout << "������ � ���� ����: " << message << endl;
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        if (message.empty()) {
            throw runtime_error("������ ������ � ���: ��������� �� ����� ���� ������.");
        }
        cout << "������ � ���������� ���: " << message << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, message;

    cout << "������� ��� ������� (����/�������): ";
    cin >> input;

    Logger* logger;

    if (input == "����") {
        logger = new FileLogger();
    }
    else if (input == "�������") {
        logger = new ConsoleLogger();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ��������� ��� ������ � ���: ";
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