#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Session {
protected:
    bool isActive;

public:
    Session() : isActive(false) {}
    virtual void startSession() = 0;
};

class UserSession : public Session {
public:
    void startSession() override {
        if (isActive) {
            throw runtime_error("Ошибка: Невозможно начать уже активную пользовательскую сессию.");
        }
        isActive = true;
        cout << "Пользовательская сессия начата." << endl;
    }
};

class AdminSession : public Session {
public:
    void startSession() override {
        if (isActive) {
            throw runtime_error("Ошибка: Невозможно начать уже активную административную сессию.");
        }
        isActive = true;
        cout << "Административная сессия начата." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип сессии (пользовательская/административная): ";
    cin >> input;

    Session* session;

    if (input == "пользовательская") {
        session = new UserSession();
    }
    else if (input == "административная") {
        session = new AdminSession();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    char choice;
    cout << "Хотите начать сессию? (y/n): ";
    cin >> choice;

    if (choice == 'y') {
        try {
            session->startSession();
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "Сессия не начата." << endl;
    }

    delete session;
    return 0;
}