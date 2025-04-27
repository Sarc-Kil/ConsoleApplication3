#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Permission {
public:
    string name;

    Permission(const string& name) : name(name) {}
};

class Role {
public:
    string name;
    vector<Permission> permissions;

    Role(const string& name) : name(name) {}

    void addPermission(const Permission& permission) {
        permissions.push_back(permission);
    }

    bool hasPermission(const string& permissionName) const {
        for (const auto& permission : permissions) {
            if (permission.name == permissionName) {
                return true;
            }
        }
        return false;
    }
};

class User {
public:
    string username;
    vector<Role> roles;

    User(const string& username) : username(username) {}

    void addRole(const Role& role) {
        roles.push_back(role);
    }

    bool hasPermission(const string& permissionName) const {
        for (const auto& role : roles) {
            if (role.hasPermission(permissionName)) {
                return true;
            }
        }
        return false;
    }
};

class Comment {
public:
    string content;
    User* author;

    Comment(const string& content, User* author) : content(content), author(author) {}
};

class Task {
public:
    string title;
    string status;
    vector<Comment> comments;

    Task(const string& title) : title(title), status("Open") {}

    void addComment(const Comment& comment) {
        comments.push_back(comment);
    }
};

class Project {
public:
    string name;
    vector<Task> tasks;

    Project(const string& name) : name(name) {}

    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void notifyNewComment(const Comment& comment) {
        cout << "Новый комментарий от " << comment.author->username << ": " << comment.content << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    vector<Role> roles;
    vector<User> users;
    vector<Project> projects;

    
    while (true) {
        string roleName;
        cout << "Введите имя роли (или 'exit' для завершения): ";
        cin >> roleName;

        if (roleName == "exit") {
            break;
        }

        Role role(roleName);
        while (true) {
            string permissionName;
            cout << "Введите разрешение для роли (или 'done' для завершения): ";
            cin >> permissionName;

            if (permissionName == "done") {
                break;
            }

            role.addPermission(Permission(permissionName));
        }
        roles.push_back(role);
    }

    
    while (true) {
        string username;
        cout << "Введите имя пользователя (или 'exit' для завершения): ";
        cin >> username;

        if (username == "exit") {
            break;
        }

        User user(username);
        while (true) {
            string roleName;
            cout << "Введите имя роли для пользователя (или 'done' для завершения): ";
            cin >> roleName;

            if (roleName == "done") {
                break;
            }

            
            for (const auto& role : roles) {
                if (role.name == roleName) {
                    user.addRole(role);
                    break;
                }
            }
        }
        users.push_back(user);
    }

    
    while (true) {
        string projectName;
        cout << "Введите имя проекта (или 'exit' для завершения): ";
        cin >> projectName;

        if (projectName == "exit") {
            break;
        }

        Project project(projectName);
        while (true) {
            string taskTitle;
            cout << "Введите название задачи для проекта (или 'done' для завершения): ";
            cin >> taskTitle;

            if (taskTitle == "done") {
                break;
            }

            Task task(taskTitle);
            project.addTask(task);
        }
        projects.push_back(project);
    }

    
    while (true) {
        string username;
        cout << "Введите имя пользователя для добавления комментария (или 'exit' для завершения): ";
        cin >> username;

        if (username == "exit") {
            break;
        }

       
        User* user = nullptr;
        for (auto& u : users) {
            if (u.username == username) {
                user = &u;
                break;
            }
        }

        if (user == nullptr) {
            cout << "Пользователь не найден." << endl;
            continue;
        }

        
        string projectName, taskTitle, commentContent;
        cout << "Введите имя проекта: ";
        cin >> projectName;
        cout << "Введите название задачи: ";
        cin >> taskTitle;

        
        Project* project = nullptr;
        Task* task = nullptr;

        for (auto& p : projects) {
            if (p.name == projectName) {
                project = &p;
                for (auto& t : p.tasks) {
                    if (t.title == taskTitle) {
                        task = &t;
                        break;
                    }
                }
                break;
            }
        }

        if (project == nullptr || task == nullptr) {
            cout << "Проект или задача не найдены." << endl;
            continue;
        }

        
        if (user->hasPermission("add_comments")) {
            cout << "Введите текст комментария: ";
            cin.ignore(); 
            getline(cin, commentContent);

            Comment comment(commentContent, user);
            task->addComment(comment);
            project->notifyNewComment(comment);
        }
        else {
            cout << "У пользователя " << user->username << " нет прав на добавление комментариев." << endl;
        }
    }

    return 0;
}