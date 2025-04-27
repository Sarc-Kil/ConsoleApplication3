#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class User {
public:
    virtual void updateProfile(const string& name, const string& email) = 0; 
    virtual ~User() {}
};

class AdminUser : public User {
private:
    string name;
    string email;
    string adminLevel; 

public:
    AdminUser(const string& name, const string& email, const string& adminLevel)
        : name(name), email(email), adminLevel(adminLevel) {
        if (name.empty() || email.empty() || adminLevel.empty()) {
            throw invalid_argument("������: ������������ ������ ������� ��������������.");
        }
    }

    void updateProfile(const string& newName, const string& newEmail) override {
        if (newName.empty() || newEmail.empty()) {
            throw invalid_argument("������: ������������ ������ ������� ��������������.");
        }
        name = newName;
        email = newEmail;
        cout << "������� �������������� ��������: " << name << ", " << email << endl;
    }
};

class RegularUser : public User {
private:
    string name;
    string email;
    int age; 

public:
    RegularUser(const string& name, const string& email, int age)
        : name(name), email(email), age(age) {
        if (name.empty() || email.empty() || age <= 0) {
            throw invalid_argument("������: ������������ ������ ������� �������� ������������.");
        }
    }

    void updateProfile(const string& newName, const string& newEmail) override {
        if (newName.empty() || newEmail.empty()) {
            throw invalid_argument("������: ������������ ������ ������� �������� ������������.");
        }
        name = newName;
        email = newEmail;
        cout << "������� �������� ������������ ��������: " << name << ", " << email << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    string userType;
    while (true) {
        cout << "������� ��� ������������ (admin, regular, exit): ";
        cin >> userType;

        if (userType == "exit") {
            cout << "����� �� ���������." << endl;
            break;
        }

        try {
            if (userType == "admin") {
                string name, email, adminLevel;
                cout << "������� ��� ��������������: ";
                cin >> ws; 
                getline(cin, name);
                cout << "������� email ��������������: ";
                getline(cin, email);
                cout << "������� ������� ������� ��������������: ";
                getline(cin, adminLevel);

                AdminUser  admin(name, email, adminLevel);

                string newName, newEmail;
                cout << "������� ����� ��� ��������������: ";
                getline(cin, newName);
                cout << "������� ����� email ��������������: ";
                getline(cin, newEmail);
                admin.updateProfile(newName, newEmail);
            }
            else if (userType == "regular") {
                string name, email;
                int age;
                cout << "������� ��� ������������: ";
                cin >> ws; 
                getline(cin, name);
                cout << "������� email ������������: ";
                getline(cin, email);
                cout << "������� ������� ������������: ";
                cin >> age;

                RegularUser  user(name, email, age);

                string newName, newEmail;
                cout << "������� ����� ��� ������������: ";
                cin >> ws; 
                getline(cin, newName);
                cout << "������� ����� email ������������: ";
                getline(cin, newEmail);
                user.updateProfile(newName, newEmail);
            }
            else {
                cout << "������: ����������� ��� ������������." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}