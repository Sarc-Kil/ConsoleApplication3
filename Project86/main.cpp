#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Task {
public:
    string name;
    bool completed;
    int estimatedTime; 

    Task(const string& name, int estimatedTime) : name(name), completed(false), estimatedTime(estimatedTime) {}
};

class User {
public:
    string name;
    string email;

    User(const string& name, const string& email) : name(name), email(email) {}
};

class Project {
public:
    string title;
    vector<Task> tasks;
    User owner;
    string apiEndpoint;

    Project(const string& title, const User& owner) : title(title), owner(owner) {}

    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void setApiEndpoint(const string& endpoint) {
        apiEndpoint = endpoint;
    }
};

class ExternalAPI {
public:
    string endpoint;

    ExternalAPI(const string& endpoint) : endpoint(endpoint) {}

    int getTaskTime(const string& taskName) {
        // ����� ������ ���� ������ �� �������� API . � ���� ����� �� ��� ������ �������!!!!!!!!!!!!!!!!������������������������������������������������������������!!!!!!!!!!
        return 5; // ������ 
    }
};

class Notification {
public:
    void send(const User& user, const string& message) {
        cout << "����������� ��� " << user.name << " (" << user.email << "): " << message << endl;
    }
};

class Report {
public:
    Project project;

    Report(const Project& project) : project(project) {}

    void generate() {
        cout << "����� �� �������: " << project.title << endl;
        cout << "��������: " << project.owner.name << endl;
        cout << "������:" << endl;
        for (const auto& task : project.tasks) {
            cout << "- " << task.name << " | ���������: " << (task.completed ? "��" : "���")
                << " | ��������� �����: " << task.estimatedTime << " �����" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    string projectTitle, userName, userEmail, apiEndpoint;
    cout << "������� �������� �������: ";
    getline(cin, projectTitle);
    cout << "������� ��� ��������� �������: ";
    getline(cin, userName);
    cout << "������� email ��������� �������: ";
    getline(cin, userEmail);
    cout << "������� API-��������: ";
    getline(cin, apiEndpoint);

    User owner(userName, userEmail);
    Project project(projectTitle, owner);
    project.setApiEndpoint(apiEndpoint);

    int taskCount;
    cout << "������� ���������� �����: ";
    cin >> taskCount;
    cin.ignore();

    for (int i = 0; i < taskCount; ++i) {
        string taskName;
        int estimatedTime;
        cout << "������� �������� ������ " << (i + 1) << ": ";
        getline(cin, taskName);
        cout << "������� ��������� ����� ���������� ������ (� �����): ";
        cin >> estimatedTime;
        cin.ignore();
        project.addTask(Task(taskName, estimatedTime));
    }

    ExternalAPI api(project.apiEndpoint);
    for (const auto& task : project.tasks) {
        int actualTime = api.getTaskTime(task.name);
        cout << "����������� ����� ���������� ������ \"" << task.name << "\": " << actualTime << " �����" << endl;
    }

    Notification notification;
    notification.send(owner, "������ \"" + project.title + "\" ������� ������.");

    Report report(project);
    report.generate();

    return 0;
}