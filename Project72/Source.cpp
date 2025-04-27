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
            throw invalid_argument("Ошибка: некорректный адрес электронной почты.");
        }
        cout << "Адрес электронной почты корректен." << endl;
    }
};

class PhoneValidator : public DataValidator {
public:
    void validate(const string& phone) override {
        regex phonePattern(R"(\+?\d{1,3}[- ]?\d{1,4}[- ]?\d{1,4}[- ]?\d{1,9})");
        if (!regex_match(phone, phonePattern)) {
            throw invalid_argument("Ошибка: некорректный номер телефона.");
        }
        cout << "Номер телефона корректен." << endl;
    }
};

class AgeValidator : public DataValidator {
public:
    void validate(const string& ageStr) override {
        int age = stoi(ageStr);
        if (age < 0 || age > 120) {
            throw invalid_argument("Ошибка: некорректный возраст.");
        }
        cout << "Возраст корректен." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите тип данных для проверки (1 - Email, 2 - Телефон, 3 - Возраст, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        try {
            if (choice == 1) {
                string email;
                cout << "Введите адрес электронной почты: ";
                getline(cin, email);
                EmailValidator emailValidator;
                emailValidator.validate(email);
            }
            else if (choice == 2) {
                string phone;
                cout << "Введите номер телефона: ";
                getline(cin, phone);
                PhoneValidator phoneValidator;
                phoneValidator.validate(phone);
            }
            else if (choice == 3) {
                string age;
                cout << "Введите возраст: ";
                getline(cin, age);
                AgeValidator ageValidator;
                ageValidator.validate(age);
            }
            else {
                cout << "Некорректный выбор." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Ошибка: значение вне допустимого диапазона." << endl;
        }
    }

    return 0;
}