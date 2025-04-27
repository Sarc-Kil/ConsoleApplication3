#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User(const string& user, const string& pass) : username(user), password(pass) {}
    virtual void login(const string& pass) const = 0; 
    virtual ~User() {}
};

class AdminUser : public User {
public:
    AdminUser(const string& user, const string& pass) : User(user, pass) {}

    void login(const string& pass) const override {
        if (pass != password) {
            throw invalid_argument("������: �������� ������ ��� ��������������.");
        }
        cout << "������������� " << username << " ������� ����� � �������." << endl;
    }
};

class RegularUser : public User {
public:
    RegularUser(const string& user, const string& pass) : User(user, pass) {}

    void login(const string& pass) const override {
        if (pass != password) {
            throw invalid_argument("������: �������� ������ ��� �������� ������������.");
        }
        cout << "������������ " << username << " ������� ����� � �������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    string username, password, inputPassword;
    char userType;

    cout << "������� ��� ������������ (a ��� ��������������, r ��� �������� ������������): ";
    cin >> userType;
    cout << "������� ��� ������������: ";
    cin >> username;
    cout << "������� ������: ";
    cin >> password;

    User* user = nullptr;

    try {
        if (userType == 'a') {
            user = new AdminUser(username, password);
        }
        else if (userType == 'r') {
            user = new RegularUser(username, password);
        }
        else {
            throw invalid_argument("������: �������� ��� ������������.");
        }

        cout << "������� ������ ��� �����: ";
        cin >> inputPassword;
        user->login(inputPassword); 
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

 
    return 0;
}