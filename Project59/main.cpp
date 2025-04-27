#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Session {
protected:
    bool active; 

public:
    Session() : active(false) {}

    virtual void start() = 0;
    virtual void end() {
        if (!active) {
            throw runtime_error("������: ������ ��� ���������.");
        }
        active = false;
        cout << "������ ���������." << endl;
    }

    virtual ~Session() {}
};

class UserSession : public Session {
public:
    void start() override {
        if (active) {
            throw runtime_error("������: ������ ��� ������� ��� ������������.");
        }
        active = true;
        cout << "���������������� ������ ������." << endl;
    }
};

class AdminSession : public Session {
public:
    void start() override {
        if (active) {
            throw runtime_error("������: ������ ��� ������� ��� ��������������.");
        }
        active = true;
        cout << "���������������� ������ ������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    UserSession userSession;
    AdminSession adminSession;

    string command;

    while (true) {
        cout << "������� ������� (start_user, end_user, start_admin, end_admin, exit): ";
        cin >> command;

        try {
            if (command == "start_user") {
                userSession.start();
            }
            else if (command == "end_user") {
                userSession.end();
            }
            else if (command == "start_admin") {
                adminSession.start();
            }
            else if (command == "end_admin") {
                adminSession.end();
            }
            else if (command == "exit") {
                cout << "����� �� ���������." << endl;
                break;
            }
            else {
                cout << "������: ����������� �������." << endl;
            }
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}