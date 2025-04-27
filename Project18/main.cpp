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
            throw invalid_argument("Ошибка: Сообщение об ошибке не может быть пустым.");
        }
        cout << "Обработка ошибки файла: " << errorMessage << endl;
    }
};

class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const string& errorMessage) override {
        if (errorMessage.empty()) {
            throw invalid_argument("Ошибка: Сообщение об ошибке не может быть пустым.");
        }
        cout << "Обработка сетевой ошибки: " << errorMessage << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        FileExceptionHandler fileHandler;
        NetworkExceptionHandler networkHandler;

        string errorMessage;

       
        cout << "Введите сообщение об ошибке файла: ";
        getline(cin, errorMessage);
        fileHandler.handle(errorMessage);

      
        cout << "Введите сообщение об ошибке сети: ";
        getline(cin, errorMessage);
        networkHandler.handle(errorMessage);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}