#include <iostream>
#include <stdexcept>
#include <regex>
#include <string>
#include <locale>

using namespace std;

class DataValidator {
public:
    virtual void validate(const string& data) = 0;
    virtual ~DataValidator() {}
};

class EmailValidator : public DataValidator {
public:
    void validate(const string& email) override {
        regex emailPattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
        if (!regex_match(email, emailPattern)) {
            throw invalid_argument("������: ������������ ����� ����������� �����.");
        }
        cout << "����� ����������� ����� ���������." << endl;
    }
};

class PhoneValidator : public DataValidator {
public:
    void validate(const string& phone) override {
        regex phonePattern(R"(\+?\d{1,3}[- ]?\d{1,4}[- ]?\d{1,4}[- ]?\d{1,9})");
        if (!regex_match(phone, phonePattern)) {
            throw invalid_argument("������: ������������ ����� ��������.");
        }
        cout << "����� �������� ���������." << endl;
    }
};

class AgeValidator : public DataValidator {
public:
    void validate(const string& ageStr) override {
        int age = stoi(ageStr);
        if (age < 0 || age > 120) {
            throw invalid_argument("������: ������������ �������.");
        }
        cout << "������� ���������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ��� ������ ��� �������� (1 - Email, 2 - �������, 3 - �������, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        try {
            if (choice == 1) {
                string email;
                cout << "������� ����� ����������� �����: ";
                getline(cin, email);
                EmailValidator emailValidator;
                emailValidator.validate(email);
            }
            else if (choice == 2) {
                string phone;
                cout << "������� ����� ��������: ";
                getline(cin, phone);
                PhoneValidator phoneValidator;
                phoneValidator.validate(phone);
            }
            else if (choice == 3) {
                string age;
                cout << "������� �������: ";
                getline(cin, age);
                AgeValidator ageValidator;
                ageValidator.validate(age);
            }
            else {
                cout << "������������ �����." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "������: �������� ��� ����������� ���������." << endl;
        }
    }

    return 0;
}