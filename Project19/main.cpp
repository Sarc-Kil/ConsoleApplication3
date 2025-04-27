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
            throw overflow_error("������: ������ ����������� ��� ������-����� '" + courseName + "'.");
        }
        enrolledStudents++;
        cout << "������� ������� ������� �� ������-���� '" << courseName << "'. ������� �����������: " << enrolledStudents << endl;
    }
};

class OfflineCourse : public Course {
public:
    OfflineCourse(const string& name, int max) : Course(name, max) {}

    void enroll() override {
        if (enrolledStudents >= maxStudents) {
            throw overflow_error("������: ������ ����������� ��� �������-����� '" + courseName + "'.");
        }
        enrolledStudents++;
        cout << "������� ������� ������� �� �������-���� '" << courseName << "'. ������� �����������: " << enrolledStudents << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        string courseName;
        int maxStudents, enrollCount;

    
        cout << "������� �������� ������-�����: ";
        getline(cin, courseName);
        cout << "������� ������������ ���������� ��������� ��� ������-�����: ";
        cin >> maxStudents;

        OnlineCourse onlineCourse(courseName, maxStudents);

        cout << "������� ��������� �� ������ �������� �� ������-����? ";
        cin >> enrollCount;

        for (int i = 0; i < enrollCount; ++i) {
            onlineCourse.enroll();
        }

       
        cin.ignore(); 
        cout << "������� �������� �������-�����: ";
        getline(cin, courseName);
        cout << "������� ������������ ���������� ��������� ��� �������-�����: ";
        cin >> maxStudents;

        OfflineCourse offlineCourse(courseName, maxStudents);

        cout << "������� ��������� �� ������ �������� �� �������-����? ";
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