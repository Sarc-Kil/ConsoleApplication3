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
            throw invalid_argument("Ошибка: Неверный пароль для администратора.");
        }
        cout << "Администратор " << username << " успешно вошел в систему." << endl;
    }
};

class RegularUser : public User {
public:
    RegularUser(const string& user, const string& pass) : User(user, pass) {}

    void login(const string& pass) const override {
        if (pass != password) {
            throw invalid_argument("Ошибка: Неверный пароль для обычного пользователя.");
        }
        cout << "Пользователь " << username << " успешно вошел в систему." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    string username, password, inputPassword;
    char userType;

    cout << "Введите тип пользователя (a для администратора, r для обычного пользователя): ";
    cin >> userType;
    cout << "Введите имя пользователя: ";
    cin >> username;
    cout << "Введите пароль: ";
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
            throw invalid_argument("Ошибка: Неверный тип пользователя.");
        }

        cout << "Введите пароль для входа: ";
        cin >> inputPassword;
        user->login(inputPassword); 
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

 
    return 0;
}