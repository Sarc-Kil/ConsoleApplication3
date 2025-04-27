#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class EmailService {
public:
    virtual void sendEmail(const string& recipient, const string& subject, const string& body) = 0;
    virtual ~EmailService() {}
};

class SMTPService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("Ошибка: некорректные данные для отправки электронной почты через SMTP.");
        }
        cout << "Email отправлен через SMTP на адрес: " << recipient << endl;
    }
};

class APIService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("Ошибка: некорректные данные для отправки электронной почты через API.");
        }
        cout << "Email отправлен через API на адрес: " << recipient << endl;
    }
};

class MockEmailService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("Ошибка: некорректные данные для отправки электронной почты через Mock-сервис.");
        }
        cout << "Email (тест) отправлен на адрес: " << recipient << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите способ отправки электронной почты (1 - SMTP, 2 - API, 3 - Mock, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string recipient, subject, body;

        cout << "Введите адрес получателя: ";
        getline(cin, recipient);
        cout << "Введите тему письма: ";
        getline(cin, subject);
        cout << "Введите текст письма: ";
        getline(cin, body);

        try {
            EmailService* emailService = nullptr;

            if (choice == 1) {
                emailService = new SMTPService();
            }
            else if (choice == 2) {
                emailService = new APIService();
            }
            else if (choice == 3) {
                emailService = new MockEmailService();
            }
            else {
                cout << "Некорректный выбор." << endl;
                continue;
            }

            emailService->sendEmail(recipient, subject, body);
            delete emailService;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}