#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class UserProfile {
public:
    virtual void updateProfile(const string& data) = 0;
};

class AdminProfile : public UserProfile {
public:
    void updateProfile(const string& data) override {
        if (data.empty()) {
            throw invalid_argument("Некорректные данные для обновления профиля администратора.");
        }
        cout << "Профиль администратора обновлен: " << data << endl;
    }
};

class GuestProfile : public UserProfile {
public:
    void updateProfile(const string& data) override {
        if (data.empty()) {
            throw invalid_argument("Некорректные данные для обновления профиля гостя.");
        }
        cout << "Профиль гостя обновлен: " << data << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, data;

    cout << "Введите тип профиля (администратор/гость): ";
    cin >> input;

    UserProfile* profile;

    if (input == "администратор") {
        profile = new AdminProfile();
    }
    else if (input == "гость") {
        profile = new GuestProfile();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите данные для обновления профиля: ";
    cin.ignore();
    getline(cin, data);

    try {
        profile->updateProfile(data);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete profile;
    return 0;
}