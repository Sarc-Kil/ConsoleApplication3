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
        cout << "��������� ������ �����: " << message << endl;
    }
};

class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& message) override {
        cout << "��������� ������� ������: " << message << endl;
    }
};

class InputExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& message) override {
        cout << "��������� ������ �����: " << message << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ��� ������ ��� ��������� (1 - ����, 2 - ����, 3 - ����, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string message;

        cout << "������� ��������� �� ������: ";
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
                cout << "������������ �����." << endl;
                continue;
            }

            handler->handle(message);
            delete handler;
        }
        catch (const exception& e) {
            cout << "������: " << e.what() << endl;
        }
    }

    return 0;
}