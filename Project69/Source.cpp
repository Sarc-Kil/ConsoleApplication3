#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class UserProfile {
public:
    virtual void save() = 0;
    virtual ~UserProfile() {}
};

class AdminProfile : public UserProfile {
private:
    string adminName;
public:
    AdminProfile(const string& name) : adminName(name) {}

    void save() override {
        if (adminName.empty()) {
            throw runtime_error("Ошибка: имя администратора не может быть пустым.");
        }
        cout << "Профиль администратора '" << adminName << "' успешно сохранен." << endl;
    }
};

class RegularProfile : public UserProfile {
private:
    string userName;
public:
    RegularProfile(const string& name) : userName(name) {}

    void save() override {
        if (userName.empty()) {
            throw runtime_error("Ошибка: имя пользователя не может быть пустым.");
        }
        cout << "Профиль пользователя '" << userName << "' успешно сохранен." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите тип профиля (1 - Администратор, 2 - Обычный пользователь, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string name;

        cout << "Введите имя: ";
        getline(cin, name);

        try {
            UserProfile* profile = nullptr;

            if (choice == 1) {
                profile = new AdminProfile(name);
            }
            else if (choice == 2) {
                profile = new RegularProfile(name);
            }
            else {
                cout << "Некорректный выбор." << endl;
                continue;
            }

            profile->save();
            delete profile;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}