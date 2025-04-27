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
        cout << "����� ����������� �� " << comment.author->username << ": " << comment.content << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    vector<Role> roles;
    vector<User> users;
    vector<Project> projects;

    
    while (true) {
        string roleName;
        cout << "������� ��� ���� (��� 'exit' ��� ����������): ";
        cin >> roleName;

        if (roleName == "exit") {
            break;
        }

        Role role(roleName);
        while (true) {
            string permissionName;
            cout << "������� ���������� ��� ���� (��� 'done' ��� ����������): ";
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
        cout << "������� ��� ������������ (��� 'exit' ��� ����������): ";
        cin >> username;

        if (username == "exit") {
            break;
        }

        User user(username);
        while (true) {
            string roleName;
            cout << "������� ��� ���� ��� ������������ (��� 'done' ��� ����������): ";
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
        cout << "������� ��� ������� (��� 'exit' ��� ����������): ";
        cin >> projectName;

        if (projectName == "exit") {
            break;
        }

        Project project(projectName);
        while (true) {
            string taskTitle;
            cout << "������� �������� ������ ��� ������� (��� 'done' ��� ����������): ";
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
        cout << "������� ��� ������������ ��� ���������� ����������� (��� 'exit' ��� ����������): ";
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
            cout << "������������ �� ������." << endl;
            continue;
        }

        
        string projectName, taskTitle, commentContent;
        cout << "������� ��� �������: ";
        cin >> projectName;
        cout << "������� �������� ������: ";
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
            cout << "������ ��� ������ �� �������." << endl;
            continue;
        }

        
        if (user->hasPermission("add_comments")) {
            cout << "������� ����� �����������: ";
            cin.ignore(); 
            getline(cin, commentContent);

            Comment comment(commentContent, user);
            task->addComment(comment);
            project->notifyNewComment(comment);
        }
        else {
            cout << "� ������������ " << user->username << " ��� ���� �� ���������� ������������." << endl;
        }
    }

    return 0;
}