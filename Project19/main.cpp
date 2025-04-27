#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Course {
protected:
    string courseName;
    int maxStudents;
    int enrolledStudents;

public:
    Course(const string& name, int max) : courseName(name), maxStudents(max), enrolledStudents(0) {}

    virtual void enroll() = 0; 
    virtual ~Course() {}
};

class OnlineCourse : public Course {
public:
    OnlineCourse(const string& name, int max) : Course(name, max) {}

    void enroll() override {
        if (enrolledStudents >= maxStudents) {
            throw overflow_error("Ошибка: Группа переполнена для онлайн-курса '" + courseName + "'.");
        }
        enrolledStudents++;
        cout << "Студент успешно записан на онлайн-курс '" << courseName << "'. Текущая численность: " << enrolledStudents << endl;
    }
};

class OfflineCourse : public Course {
public:
    OfflineCourse(const string& name, int max) : Course(name, max) {}

    void enroll() override {
        if (enrolledStudents >= maxStudents) {
            throw overflow_error("Ошибка: Группа переполнена для оффлайн-курса '" + courseName + "'.");
        }
        enrolledStudents++;
        cout << "Студент успешно записан на оффлайн-курс '" << courseName << "'. Текущая численность: " << enrolledStudents << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        string courseName;
        int maxStudents, enrollCount;

    
        cout << "Введите название онлайн-курса: ";
        getline(cin, courseName);
        cout << "Введите максимальное количество студентов для онлайн-курса: ";
        cin >> maxStudents;

        OnlineCourse onlineCourse(courseName, maxStudents);

        cout << "Сколько студентов вы хотите записать на онлайн-курс? ";
        cin >> enrollCount;

        for (int i = 0; i < enrollCount; ++i) {
            onlineCourse.enroll();
        }

       
        cin.ignore(); 
        cout << "Введите название оффлайн-курса: ";
        getline(cin, courseName);
        cout << "Введите максимальное количество студентов для оффлайн-курса: ";
        cin >> maxStudents;

        OfflineCourse offlineCourse(courseName, maxStudents);

        cout << "Сколько студентов вы хотите записать на оффлайн-курс? ";
        cin >> enrollCount;

        for (int i = 0; i < enrollCount; ++i) {
            offlineCourse.enroll();
        }

    }
    catch (const overflow_error& e) {
        cout << e.what() << endl; 
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}