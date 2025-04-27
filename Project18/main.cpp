#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class ExceptionHandler {
public:
    virtual void handle(const string& errorMessage) = 0; 
    virtual ~ExceptionHandler() {}
};

class FileExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& errorMessage) override {
        if (errorMessage.empty()) {
            throw invalid_argument("������: ��������� �� ������ �� ����� ���� ������.");
        }
        cout << "��������� ������ �����: " << errorMessage << endl;
    }
};

class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& errorMessage) override {
        if (errorMessage.empty()) {
            throw invalid_argument("������: ��������� �� ������ �� ����� ���� ������.");
        }
        cout << "��������� ������� ������: " << errorMessage << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        FileExceptionHandler fileHandler;
        NetworkExceptionHandler networkHandler;

        string errorMessage;

       
        cout << "������� ��������� �� ������ �����: ";
        getline(cin, errorMessage);
        fileHandler.handle(errorMessage);

      
        cout << "������� ��������� �� ������ ����: ";
        getline(cin, errorMessage);
        networkHandler.handle(errorMessage);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}