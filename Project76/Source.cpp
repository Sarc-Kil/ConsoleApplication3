#include <iostream>
#include <string>
#include <stdexcept>
#include <locale>

using namespace std;

class User {
public:
    virtual void authenticate(const string& username, const string& password) = 0;
    virtual ~User() {}
};

class AdminUser : public User {
public:
    void authenticate(const string& username, const string& password) override {
        if (username != "admin" || password != "admin123") {
            throw invalid_argument("������: �������� ������� ������ ��� ��������������.");
        }
        cout << "�������������� �������������� �������." << endl;
    }
};

class RegularUser : public User {
public:
    void authenticate(const string& username, const string& password) override {
        if (username != "user" || password != "user123") {
            throw invalid_argument("������: �������� ������� ������ ��� �������� ������������.");
        }
        cout << "�������������� �������� ������������ �������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ��� ������������ (1 - �������������, 2 - ������� ������������, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string username, password;
        try {
            cout << "������� ��� ������������: ";
            getline(cin, username);
            cout << "������� ������: ";
            getline(cin, password);

            if (choice == 1) {
                AdminUser  admin;
                admin.authenticate(username, password);
            }
            else if (choice == 2) {
                RegularUser  regular;
                regular.authenticate(username, password);
            }
            else {
                cout << "������������ �����." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}