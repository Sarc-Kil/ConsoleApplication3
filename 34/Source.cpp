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
            throw runtime_error("������ ��������: ��� ���� ������ ���� ���������.");
        }
        cout << "SMTP: ������ ���������� �� " << recipient << " � ����� \"" << subject << "\"." << endl;
    }
};

class APIService : public EmailService {
public:
    void sendEmail(const string& recipient, const string& subject, const string& body) override {
        if (recipient.empty() || subject.empty() || body.empty()) {
            throw runtime_error("������ ��������: ��� ���� ������ ���� ���������.");
        }
        cout << "API: ������ ���������� �� " << recipient << " � ����� \"" << subject << "\"." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, recipient, subject, body;

    cout << "������� ��� ������� (SMTP/API): ";
    cin >> input;

    EmailService* emailService;

    if (input == "SMTP") {
        emailService = new SMTPService();
    }
    else if (input == "API") {
        emailService = new APIService();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ����� ����������: ";
    cin.ignore();
    getline(cin, recipient);
    cout << "������� ���� ������: ";
    getline(cin, subject);
    cout << "������� ����� ������: ";
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