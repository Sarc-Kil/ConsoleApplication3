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
            throw invalid_argument("Ошибка: Некорректные данные профиля администратора.");
        }
    }

    void updateProfile(const string& newName, const string& newEmail) override {
        if (newName.empty() || newEmail.empty()) {
            throw invalid_argument("Ошибка: Некорректные данные профиля администратора.");
        }
        name = newName;
        email = newEmail;
        cout << "Профиль администратора обновлен: " << name << ", " << email << endl;
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
            throw invalid_argument("Ошибка: Некорректные данные профиля обычного пользователя.");
        }
    }

    void updateProfile(const string& newName, const string& newEmail) override {
        if (newName.empty() || newEmail.empty()) {
            throw invalid_argument("Ошибка: Некорректные данные профиля обычного пользователя.");
        }
        name = newName;
        email = newEmail;
        cout << "Профиль обычного пользователя обновлен: " << name << ", " << email << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    string userType;
    while (true) {
        cout << "Введите тип пользователя (admin, regular, exit): ";
        cin >> userType;

        if (userType == "exit") {
            cout << "Выход из программы." << endl;
            break;
        }

        try {
            if (userType == "admin") {
                string name, email, adminLevel;
                cout << "Введите имя администратора: ";
                cin >> ws; 
                getline(cin, name);
                cout << "Введите email администратора: ";
                getline(cin, email);
                cout << "Введите уровень доступа администратора: ";
                getline(cin, adminLevel);

                AdminUser  admin(name, email, adminLevel);

                string newName, newEmail;
                cout << "Введите новое имя администратора: ";
                getline(cin, newName);
                cout << "Введите новый email администратора: ";
                getline(cin, newEmail);
                admin.updateProfile(newName, newEmail);
            }
            else if (userType == "regular") {
                string name, email;
                int age;
                cout << "Введите имя пользователя: ";
                cin >> ws; 
                getline(cin, name);
                cout << "Введите email пользователя: ";
                getline(cin, email);
                cout << "Введите возраст пользователя: ";
                cin >> age;

                RegularUser  user(name, email, age);

                string newName, newEmail;
                cout << "Введите новое имя пользователя: ";
                cin >> ws; 
                getline(cin, newName);
                cout << "Введите новый email пользователя: ";
                getline(cin, newEmail);
                user.updateProfile(newName, newEmail);
            }
            else {
                cout << "Ошибка: Неизвестный тип пользователя." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}