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
            throw invalid_argument("������������ ������ ��� ���������� ������� ��������������.");
        }
        cout << "������� �������������� ��������: " << data << endl;
    }
};

class GuestProfile : public UserProfile {
public:
    void updateProfile(const string& data) override {
        if (data.empty()) {
            throw invalid_argument("������������ ������ ��� ���������� ������� �����.");
        }
        cout << "������� ����� ��������: " << data << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, data;

    cout << "������� ��� ������� (�������������/�����): ";
    cin >> input;

    UserProfile* profile;

    if (input == "�������������") {
        profile = new AdminProfile();
    }
    else if (input == "�����") {
        profile = new GuestProfile();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ������ ��� ���������� �������: ";
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