#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class User {
public:
    virtual void login(const string& password) = 0;
};

class AdminUser : public User {
private:
    string correctPassword;

public:
    AdminUser(const string& password) : correctPassword(password) {}

    void login(const string& password) override {
        if (password != correctPassword) {
            throw invalid_argument("������: �������� ������ ��� ��������������.");
        }
        cout << "������������� ������� ����� � �������." << endl;
    }
};

class RegularUser : public User {
private:
    string correctPassword;

public:
    RegularUser(const string& password) : correctPassword(password) {}

    void login(const string& password) override {
        if (password != correctPassword) {
            throw invalid_argument("������: �������� ������ ��� �������� ������������.");
        }
        cout << "������� ������������ ������� ����� � �������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, password;

    cout << "������� ��� ������������ (�������������/�������): ";
    cin >> input;

    User* user = nullptr;

    if (input == "�������������") {
        cout << "������� ������ ��������������: ";
        cin >> password;
        user = new AdminUser(password);
    }
    else if (input == "�������") {
        cout << "������� ������ �������� ������������: ";
        cin >> password;
        user = new RegularUser(password);
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    string inputPassword;
    cout << "������� ������ ��� �����: ";
    cin >> inputPassword;

    try {
        user->login(inputPassword);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete user;
    return 0;
}