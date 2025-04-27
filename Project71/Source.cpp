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
            throw runtime_error("������: ������������ ������ ��� �������� ����������� ����� ����� SMTP.");
        }
        cout << "Email ��������� ����� SMTP �� �����: " << recipient << endl;
    }
};

class APIService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("������: ������������ ������ ��� �������� ����������� ����� ����� API.");
        }
        cout << "Email ��������� ����� API �� �����: " << recipient << endl;
    }
};

class MockEmailService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("������: ������������ ������ ��� �������� ����������� ����� ����� Mock-������.");
        }
        cout << "Email (����) ��������� �� �����: " << recipient << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ������ �������� ����������� ����� (1 - SMTP, 2 - API, 3 - Mock, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string recipient, subject, body;

        cout << "������� ����� ����������: ";
        getline(cin, recipient);
        cout << "������� ���� ������: ";
        getline(cin, subject);
        cout << "������� ����� ������: ";
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
                cout << "������������ �����." << endl;
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