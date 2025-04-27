#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Task {
public:
    string name;
    bool completed;

    Task(const string& name) : name(name), completed(false) {}
};

class UserStory {
public:
    string title;
    vector<Task> tasks;

    UserStory(const string& title) : title(title) {}

    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    int getTotalTasks() const {
        return tasks.size();
    }

    int getCompletedTasks() const {
        return count_if(tasks.begin(), tasks.end(), [](const Task& task) {
            return task.completed;
            });
    }
};

class Backlog {
public:
    vector<UserStory> userStories;

    void addUserStory(const UserStory& userStory) {
        userStories.push_back(userStory);
    }

    void displayBacklog() const {
        for (const auto& story : userStories) {
            cout << "История: " << story.title << " | Всего задач: " << story.getTotalTasks()
                << " | Завершено задач: " << story.getCompletedTasks() << endl;
        }
    }
};

class TeamMember {
public:
    string name;

    TeamMember(const string& name) : name(name) {}
};

class Sprint {
public:
    string name;
    vector<UserStory> userStories;
    int totalPoints;
    int completedPoints;

    Sprint(const string& name) : name(name), totalPoints(0), completedPoints(0) {}

    void addUserStory(const UserStory& userStory) {
        userStories.push_back(userStory);
        totalPoints += userStory.getTotalTasks();
    }

    void completeTask(const string& userStoryTitle, const string& taskName) {
        for (auto& story : userStories) {
            if (story.title == userStoryTitle) {
                for (auto& task : story.tasks) {
                    if (task.name == taskName) {
                        task.completed = true;
                        completedPoints++;
                        return;
                    }
                }
            }
        }
    }

    void displaySprintProgress() const {
        cout << "Спринт: " << name << " | Всего очков: " << totalPoints
            << " | Завершено очков: " << completedPoints << endl;
    }
};

class BurndownChart {
public:
    map<int, int> progress;

    void addProgress(int day, int remainingPoints) {
        progress[day] = remainingPoints;
    }

    void displayChart() const {
        cout << "График сгорания:" << endl;
        for (const auto& entry : progress) {
            cout << "День " << entry.first << ": Осталось " << entry.second << " очков" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Backlog backlog;
    string storyTitle;
    cout << "Введите название пользовательской истории: ";
    getline(cin, storyTitle);
    UserStory story(storyTitle);

    int taskCount;
    cout << "Введите количество задач: ";
    cin >> taskCount;
    cin.ignore();

    for (int i = 0; i < taskCount; ++i) {
        string taskName;
        cout << "Введите название задачи " << (i + 1) << ": ";
        getline(cin, taskName);
        story.addTask(Task(taskName));
    }

    backlog.addUserStory(story);

    Sprint sprint("Спринт 1");
    sprint.addUserStory(story);

    string taskToComplete;
    cout << "Введите название задачи для завершения: ";
    getline(cin, taskToComplete);
    sprint.completeTask(storyTitle, taskToComplete);

    backlog.displayBacklog();
    sprint.displaySprintProgress();

    BurndownChart burndown;
    for (int day = 1; day <= 5; ++day) {
        int remainingPoints;
        cout << "Введите оставшиеся очки на день " << day << ": ";
        cin >> remainingPoints;
        burndown.addProgress(day, remainingPoints);
    }
    burndown.displayChart();

    return 0;
}