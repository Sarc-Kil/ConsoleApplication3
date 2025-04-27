#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class UserProfile {
public:
    virtual void save() = 0;
    virtual ~UserProfile() {}
};

class AdminProfile : public UserProfile {
private:
    string adminName;
public:
    AdminProfile(const string& name) : adminName(name) {}

    void save() override {
        if (adminName.empty()) {
            throw runtime_error("������: ��� �������������� �� ����� ���� ������.");
        }
        cout << "������� �������������� '" << adminName << "' ������� ��������." << endl;
    }
};

class RegularProfile : public UserProfile {
private:
    string userName;
public:
    RegularProfile(const string& name) : userName(name) {}

    void save() override {
        if (userName.empty()) {
            throw runtime_error("������: ��� ������������ �� ����� ���� ������.");
        }
        cout << "������� ������������ '" << userName << "' ������� ��������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ��� ������� (1 - �������������, 2 - ������� ������������, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string name;

        cout << "������� ���: ";
        getline(cin, name);

        try {
            UserProfile* profile = nullptr;

            if (choice == 1) {
                profile = new AdminProfile(name);
            }
            else if (choice == 2) {
                profile = new RegularProfile(name);
            }
            else {
                cout << "������������ �����." << endl;
                continue;
            }

            profile->save();
            delete profile;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}