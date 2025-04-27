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
            throw invalid_argument("������: �������� �� ����� ���� �������������.");
        }
    }

    void runTask() override {
        cout << "������ ������ '" << taskName << "' ����� " << delay << " ������." << endl;
        this_thread::sleep_for(chrono::seconds(delay)); 
        cout << "������ '" << taskName << "' ���������." << endl;
    }
};

class ImmediateTask : public TaskManager {
private:
    string taskName;

public:
    ImmediateTask(const string& name) : taskName(name) {}

    void runTask() override {
        cout << "������ ������ '" << taskName << "' ����������." << endl;
        
        cout << "������ '" << taskName << "' ���������." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    string taskType;
    while (true) {
        cout << "������� ��� ������ (scheduled, immediate, exit): ";
        cin >> taskType;

        if (taskType == "exit") {
            cout << "����� �� ���������." << endl;
            break;
        }

        try {
            if (taskType == "scheduled") {
                string taskName;
                int delay;

                cout << "������� ��� ��������������� ������: ";
                cin >> ws; 
                getline(cin, taskName);
                cout << "������� �������� � ��������: ";
                cin >> delay;

                ScheduledTask scheduled(taskName, delay);
                scheduled.runTask(); 
            }
            else if (taskType == "immediate") {
                string taskName;

                cout << "������� ��� ����������� ������: ";
                cin >> ws; 
                getline(cin, taskName);

                ImmediateTask immediate(taskName);
                immediate.runTask(); 
            }
            else {
                cout << "������: ����������� ��� ������." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}