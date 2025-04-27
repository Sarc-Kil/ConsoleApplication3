#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Task {
protected:
    bool initialized; 

public:
    Task() : initialized(false) {} 

    virtual void initialize() = 0; 
    virtual void execute() = 0; 
    virtual ~Task() {}
};

class PrintTask : public Task {
private:
    string message;

public:
    void initialize() override {
        cout << "������� ��������� ��� ������: ";
        getline(cin, message);
        initialized = true; 
    }

    void execute() override {
        if (!initialized) {
            throw runtime_error("������: ������ �� ����������������. ���������� ����������.");
        }
        cout << "������ ���������: " << message << endl;
    }
};

class EmailTask : public Task {
private:
    string recipient;
    string subject;
    string body;

public:
    void initialize() override {
        cout << "������� ����� ����������� ����� ����������: ";
        getline(cin, recipient);
        cout << "������� ���� ������: ";
        getline(cin, subject);
        cout << "������� ����� ������: ";
        getline(cin, body);
        initialized = true; 
    }

    void execute() override {
        if (!initialized) {
            throw runtime_error("������: ������ �� ����������������. ���������� ����������.");
        }
        cout << "�������� ������ �� " << recipient << " � �����: " << subject << endl;
        cout << "����� ������: " << body << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        PrintTask printTask;
        EmailTask emailTask;

       
        printTask.initialize();
        printTask.execute();

       
        emailTask.initialize();
        emailTask.execute();

    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }

    return 0;
}