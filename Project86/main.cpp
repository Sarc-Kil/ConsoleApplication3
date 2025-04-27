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
        // Здесь должна быть логика из внешнего API . У МЕНЯ СВОЕЙ ТО НЕТ ОТКУДА ВНЕШНЯЯ!!!!!!!!!!!!!!!!АААААААААААААААААААААААААААААААААААААААААААААААААААААААААААА!!!!!!!!!!
        return 5; // Пример 
    }
};

class Notification {
public:
    void send(const User& user, const string& message) {
        cout << "Уведомление для " << user.name << " (" << user.email << "): " << message << endl;
    }
};

class Report {
public:
    Project project;

    Report(const Project& project) : project(project) {}

    void generate() {
        cout << "Отчет по проекту: " << project.title << endl;
        cout << "Владелец: " << project.owner.name << endl;
        cout << "Задачи:" << endl;
        for (const auto& task : project.tasks) {
            cout << "- " << task.name << " | Завершена: " << (task.completed ? "Да" : "Нет")
                << " | Оценочное время: " << task.estimatedTime << " часов" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    string projectTitle, userName, userEmail, apiEndpoint;
    cout << "Введите название проекта: ";
    getline(cin, projectTitle);
    cout << "Введите имя владельца проекта: ";
    getline(cin, userName);
    cout << "Введите email владельца проекта: ";
    getline(cin, userEmail);
    cout << "Введите API-эндпоинт: ";
    getline(cin, apiEndpoint);

    User owner(userName, userEmail);
    Project project(projectTitle, owner);
    project.setApiEndpoint(apiEndpoint);

    int taskCount;
    cout << "Введите количество задач: ";
    cin >> taskCount;
    cin.ignore();

    for (int i = 0; i < taskCount; ++i) {
        string taskName;
        int estimatedTime;
        cout << "Введите название задачи " << (i + 1) << ": ";
        getline(cin, taskName);
        cout << "Введите оценочное время выполнения задачи (в часах): ";
        cin >> estimatedTime;
        cin.ignore();
        project.addTask(Task(taskName, estimatedTime));
    }

    ExternalAPI api(project.apiEndpoint);
    for (const auto& task : project.tasks) {
        int actualTime = api.getTaskTime(task.name);
        cout << "Фактическое время выполнения задачи \"" << task.name << "\": " << actualTime << " часов" << endl;
    }

    Notification notification;
    notification.send(owner, "Проект \"" + project.title + "\" успешно создан.");

    Report report(project);
    report.generate();

    return 0;
}