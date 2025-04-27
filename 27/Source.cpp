#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

class Notification {
public:
    virtual void send() = 0;
};

class EmailNotification : public Notification {
public:
    void send() override {
        cout << "Электронное письмо отправлено." << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send() override {
        throw runtime_error("Ошибка отправки SMS уведомления.");
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип уведомления (email/SMS): ";
    cin >> input;

    Notification* notification;

    if (input == "email") {
        notification = new EmailNotification();
    }
    else if (input == "SMS") {
        notification = new SMSNotification();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    try {
        notification->send();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete notification;
    return 0;
}
