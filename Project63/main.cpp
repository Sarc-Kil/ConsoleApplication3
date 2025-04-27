#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class TaskManager {
public:
    virtual void runTask() = 0; 
    virtual ~TaskManager() {}
};

class ScheduledTask : public TaskManager {
private:
    string taskName;
    int delay; 

public:
    ScheduledTask(const string& name, int delay) : taskName(name), delay(delay) {
        if (delay < 0) {
            throw invalid_argument("Ошибка: Задержка не может быть отрицательной.");
        }
    }

    void runTask() override {
        cout << "Запуск задачи '" << taskName << "' через " << delay << " секунд." << endl;
        this_thread::sleep_for(chrono::seconds(delay)); 
        cout << "Задача '" << taskName << "' выполнена." << endl;
    }
};

class ImmediateTask : public TaskManager {
private:
    string taskName;

public:
    ImmediateTask(const string& name) : taskName(name) {}

    void runTask() override {
        cout << "Запуск задачи '" << taskName << "' немедленно." << endl;
        
        cout << "Задача '" << taskName << "' выполнена." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    string taskType;
    while (true) {
        cout << "Введите тип задачи (scheduled, immediate, exit): ";
        cin >> taskType;

        if (taskType == "exit") {
            cout << "Выход из программы." << endl;
            break;
        }

        try {
            if (taskType == "scheduled") {
                string taskName;
                int delay;

                cout << "Введите имя запланированной задачи: ";
                cin >> ws; 
                getline(cin, taskName);
                cout << "Введите задержку в секундах: ";
                cin >> delay;

                ScheduledTask scheduled(taskName, delay);
                scheduled.runTask(); 
            }
            else if (taskType == "immediate") {
                string taskName;

                cout << "Введите имя немедленной задачи: ";
                cin >> ws; 
                getline(cin, taskName);

                ImmediateTask immediate(taskName);
                immediate.runTask(); 
            }
            else {
                cout << "Ошибка: Неизвестный тип задачи." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}