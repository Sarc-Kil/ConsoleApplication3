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
            throw invalid_argument("Ошибка: Неверный пароль для администратора.");
        }
        cout << "Администратор успешно вошел в систему." << endl;
    }
};

class RegularUser : public User {
private:
    string correctPassword;

public:
    RegularUser(const string& password) : correctPassword(password) {}

    void login(const string& password) override {
        if (password != correctPassword) {
            throw invalid_argument("Ошибка: Неверный пароль для обычного пользователя.");
        }
        cout << "Обычный пользователь успешно вошел в систему." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, password;

    cout << "Введите тип пользователя (администратор/обычный): ";
    cin >> input;

    User* user = nullptr;

    if (input == "администратор") {
        cout << "Введите пароль администратора: ";
        cin >> password;
        user = new AdminUser(password);
    }
    else if (input == "обычный") {
        cout << "Введите пароль обычного пользователя: ";
        cin >> password;
        user = new RegularUser(password);
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    string inputPassword;
    cout << "Введите пароль для входа: ";
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