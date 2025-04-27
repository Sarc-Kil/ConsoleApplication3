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
            throw invalid_argument("Ошибка: неверные учетные данные для администратора.");
        }
        cout << "Аутентификация администратора успешна." << endl;
    }
};

class RegularUser : public User {
public:
    void authenticate(const string& username, const string& password) override {
        if (username != "user" || password != "user123") {
            throw invalid_argument("Ошибка: неверные учетные данные для обычного пользователя.");
        }
        cout << "Аутентификация обычного пользователя успешна." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите тип пользователя (1 - Администратор, 2 - Обычный пользователь, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string username, password;
        try {
            cout << "Введите имя пользователя: ";
            getline(cin, username);
            cout << "Введите пароль: ";
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
                cout << "Некорректный выбор." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}