#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class EmailService {
public:
    virtual void sendEmail(const string& recipient, const string& subject, const string& body) = 0;
};

class SMTPService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("Ошибка отправки: все поля должны быть заполнены.");
        }
        cout << "SMTP: Письмо отправлено на " << recipient << " с темой \"" << subject << "\"." << endl;
    }
};

class APIService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("Ошибка отправки: все поля должны быть заполнены.");
        }
        cout << "API: Письмо отправлено на " << recipient << " с темой \"" << subject << "\"." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, recipient, subject, body;

    cout << "Введите тип сервиса (SMTP/API): ";
    cin >> input;

    EmailService* emailService;

    if (input == "SMTP") {
        emailService = new SMTPService();
    }
    else if (input == "API") {
        emailService = new APIService();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите адрес получателя: ";
    cin.ignore();
    getline(cin, recipient);
    cout << "Введите тему письма: ";
    getline(cin, subject);
    cout << "Введите текст письма: ";
    getline(cin, body);

    try {
        emailService->sendEmail(recipient, subject, body);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete emailService;
    return 0;
}