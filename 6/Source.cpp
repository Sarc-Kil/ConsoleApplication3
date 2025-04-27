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
            throw invalid_argument("Ошибка: некорректное имя или возраст.");
        }
    }

    virtual void display() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
public:
    Student(const string& name, int age) : Person(name, age) {}

    void display() const override {
        cout << "Студент: " << name << ", Возраст: " << age << " лет." << endl;
    }
};

class Teacher : public Person {
public:
    Teacher(const string& name, int age) : Person(name, age) {}

    void display() const override {
        cout << "Учитель: " << name << ", Возраст: " << age << " лет." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "Выберите тип человека (1 - Студент, 2 - Учитель, 0 - Выход): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string name;
        int age;

        cout << "Введите имя: ";
        getline(cin, name);
        cout << "Введите возраст: ";
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
                cout << "Некорректный выбор." << endl;
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