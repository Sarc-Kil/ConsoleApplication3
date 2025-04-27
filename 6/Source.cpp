#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& name, int age) : name(name), age(age) {
        if (name.empty() || age < 0) {
            throw invalid_argument("������: ������������ ��� ��� �������.");
        }
    }

    virtual void display() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
public:
    Student(const string& name, int age) : Person(name, age) {}

    void display() const override {
        cout << "�������: " << name << ", �������: " << age << " ���." << endl;
    }
};

class Teacher : public Person {
public:
    Teacher(const string& name, int age) : Person(name, age) {}

    void display() const override {
        cout << "�������: " << name << ", �������: " << age << " ���." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ��� �������� (1 - �������, 2 - �������, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string name;
        int age;

        cout << "������� ���: ";
        getline(cin, name);
        cout << "������� �������: ";
        cin >> age;

        try {
            Person* person = nullptr;

            if (choice == 1) {
                person = new Student(name, age);
            }
            else if (choice == 2) {
                person = new Teacher(name, age);
            }
            else {
                cout << "������������ �����." << endl;
                continue;
            }

            person->display();
            delete person;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}