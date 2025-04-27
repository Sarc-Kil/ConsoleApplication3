#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Logger {
public:
    virtual void log(const string& message) = 0;
};

class FileLogger : public Logger {
private:
    ofstream file;

public:
    FileLogger(const string& filename) {
        file.open(filename, ios::app);
        if (!file.is_open()) {
            throw invalid_argument("������: �� ������� ������� ���� ��� �����������.");
        }
    }

    void log(const string& message) override {
        if (!(file << message << endl)) {
            throw runtime_error("������: �� ������� �������� ��������� � ��� ����.");
        }
    }

    ~FileLogger() {
        if (file.is_open()) {
            file.close();
        }
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        if (cout.fail()) {
            throw runtime_error("������: �� ������� �������� ��������� � �������.");
        }
        cout << message << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, message;

    cout << "������� ������ ����������� (����/�������): ";
    cin >> input;

    Logger* logger = nullptr;

    if (input == "����") {
        string filename;
        cout << "������� ��� ����� ��� �����������: ";
        cin >> filename;
        try {
            logger = new FileLogger(filename);
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    else if (input == "�������") {
        logger = new ConsoleLogger();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ��������� ��� �����������: ";
    cin.ignore();
    getline(cin, message);

    try {
        logger->log(message);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete logger;
    return 0;
}