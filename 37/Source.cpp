#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Session {
protected:
    bool isActive;

public:
    Session() : isActive(false) {}
    virtual void startSession() = 0;
};

class UserSession : public Session {
public:
    void startSession() override {
        if (isActive) {
            throw runtime_error("������: ���������� ������ ��� �������� ���������������� ������.");
        }
        isActive = true;
        cout << "���������������� ������ ������." << endl;
    }
};

class AdminSession : public Session {
public:
    void startSession() override {
        if (isActive) {
            throw runtime_error("������: ���������� ������ ��� �������� ���������������� ������.");
        }
        isActive = true;
        cout << "���������������� ������ ������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "������� ��� ������ (����������������/����������������): ";
    cin >> input;

    Session* session;

    if (input == "����������������") {
        session = new UserSession();
    }
    else if (input == "����������������") {
        session = new AdminSession();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    char choice;
    cout << "������ ������ ������? (y/n): ";
    cin >> choice;

    if (choice == 'y') {
        try {
            session->startSession();
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "������ �� ������." << endl;
    }

    delete session;
    return 0;
}