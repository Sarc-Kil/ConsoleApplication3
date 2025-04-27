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
        return "������: ���� �� ������.";
    }
};

class InvalidInputException : public Exception {
public:
    string what() const override {
        return "������: �������� ����.";
    }
};

class NetworkException : public Exception {
public:
    string what() const override {
        return "������: �������� � �����.";
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "������� ��� ������ (����/����/����): ";
    cin >> input;

    Exception* exception = nullptr;

    if (input == "����") {
        exception = new FileNotFoundException();
    }
    else if (input == "����") {
        exception = new InvalidInputException();
    }
    else if (input == "����") {
        exception = new NetworkException();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << exception->what() << endl;

    delete exception;
    return 0;
}