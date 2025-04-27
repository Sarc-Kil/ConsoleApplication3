#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student {
public:
    string name;
    int id;

    Student(const string& name, int id) : name(name), id(id) {}
};

class Instructor {
public:
    string name;
    int id;

    Instructor(const string& name, int id) : name(name), id(id) {}
};

class Course {
public:
    string title;
    int id;
    Instructor* instructor;

    Course(const string& title, int id, Instructor* instructor) : title(title), id(id), instructor(instructor) {}
};

class Grade {
public:
    Course* course;
    float score;

    Grade(Course* course, float score) : course(course), score(score) {}
};

class Enrollment {
public:
    Student* student;
    Course* course;
    vector<Grade> grades;

    Enrollment(Student* student, Course* course) : student(student), course(course) {}

    void addGrade(float score) {
        grades.emplace_back(course, score);
    }

    float getAverageGrade() const { 
        if (grades.empty()) return 0.0f;
        float total = 0.0f;
        for (const auto& grade : grades) {
            total += grade.score;
        }
        return total / grades.size();
    }
};

class Schedule {
public:
    Course* course;
    string time;

    Schedule(Course* course, const string& time) : course(course), time(time) {}
};

class SchoolSystem {
private:
    vector<Student> students;
    vector<Instructor> instructors;
    vector<Course> courses;
    vector<Enrollment> enrollments;
    vector<Schedule> schedules;

public:
    void addStudent(const string& name, int id) {
        students.emplace_back(name, id);
    }

    void addInstructor(const string& name, int id) {
        instructors.emplace_back(name, id);
    }

    void addCourse(const string& title, int id, int instructorId) {
        Instructor* instructor = nullptr;
        for (auto& inst : instructors) {
            if (inst.id == instructorId) {
                instructor = &inst;
                break;
            }
        }
        if (instructor) {
            courses.emplace_back(title, id, instructor);
        }
        else {
            cout << "������������� �� ������." << endl;
        }
    }

    void enrollStudent(int studentId, int courseId) {
        Student* student = nullptr;
        Course* course = nullptr;

        for (auto& s : students) {
            if (s.id == studentId) {
                student = &s;
                break;
            }
        }

        for (auto& c : courses) {
            if (c.id == courseId) {
                course = &c;
                break;
            }
        }

        if (student && course) {
            enrollments.emplace_back(student, course);
        }
        else {
            cout << "������� ��� ���� �� �������." << endl;
        }
    }

    void addGrade(int studentId, int courseId, float score) {
        for (auto& enrollment : enrollments) {
            if (enrollment.student->id == studentId && enrollment.course->id == courseId) {
                enrollment.addGrade(score);
                return;
            }
        }
        cout << "������ � ���������� �� �������." << endl;
    }

    void addSchedule(int courseId, const string& time) {
        Course* course = nullptr;
        for (auto& c : courses) {
            if (c.id == courseId) {
                course = &c;
                break;
            }
        }
        if (course) {
            schedules.emplace_back(course, time);
        }
        else {
            cout << "���� �� ������." << endl;
        }
    }

    void printReport(int studentId) {
        for (const auto& enrollment : enrollments) {
            if (enrollment.student->id == studentId) {
                cout << "����� �� ������������ ��� ��������: " << enrollment.student->name << endl;
                cout << "����: " << enrollment.course->title << endl;
                cout << "������� ������: " << fixed << setprecision(2) << enrollment.getAverageGrade() << endl;
            }
        }
    }
};

int main() {
    SchoolSystem schoolSystem;

    
    while (true) {
        string command;
        cout << "������� ������� (add student, add instructor, add course, enroll, add grade, add schedule, report, exit): ";
        cin >> command;

        if (command == "add student") {
            string name;
            int id;
            cout << "������� ��� �������� � ID: ";
            cin >> name >> id;
            schoolSystem.addStudent(name, id);
        }
        else if (command == "add instructor") {
            string name;
            int id;
            cout << "������� ��� ������������� � ID: ";
            cin >> name >> id;
            schoolSystem.addInstructor(name, id);
        }
        else if (command == "add course") {
            string title;
            int id, instructorId;
            cout << "������� �������� �����, ID � ID �������������: ";
            cin >> title >> id >> instructorId;
            schoolSystem.addCourse(title, id, instructorId);
        }
        else if (command == "enroll") {
            int studentId, courseId;
            cout << "������� ID �������� � ID �����: ";
            cin >> studentId >> courseId;
            schoolSystem.enrollStudent(studentId, courseId);
        }
        else if (command == "add grade") {
            int studentId, courseId;
            float score;
            cout << "������� ID ��������, ID ����� � ������: ";
            cin >> studentId >> courseId >> score;
            schoolSystem.addGrade(studentId, courseId, score);
        }
        else if (command == "add schedule") {
            int courseId;
            string time;
            cout << "������� ID ����� � �����: ";
            cin >> courseId >> time;
            schoolSystem.addSchedule(courseId, time);
        }
        else if (command == "report") {
            int studentId;
            cout << "������� ID �������� ��� ������: ";
            cin >> studentId;
            schoolSystem.printReport(studentId);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "����������� �������." << endl;
        }
    }

    
    cout << "���������� ������ �������." << endl;
    return 0;
}