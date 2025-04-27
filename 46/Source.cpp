#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class NetworkRequest {
public:
    virtual void send() = 0;
};

class HttpRequest : public NetworkRequest {
private:
    string url;

public:
    HttpRequest(const string& url) : url(url) {
        if (url.empty()) {
            throw invalid_argument("Некорректный URL для HTTP запроса. URL не может быть пустым.");
        }
    }

    void send() override {
        // Симуляция отправки HTTP запроса
        cout << "Отправка HTTP запроса на " << url << endl;
        // Здесь можно добавить логику для обработки ошибок сети
        // Например, если произошла ошибка сети, можно выбросить исключение
        throw runtime_error("Ошибка сети при отправке HTTP запроса.");
    }
};

class FtpRequest : public NetworkRequest {
private:
    string server;

public:
    FtpRequest(const string& server) : server(server) {
        if (server.empty()) {
            throw invalid_argument("Некорректный сервер для FTP запроса. Сервер не может быть пустым.");
        }
    }

    void send() override {
        // Симуляция отправки FTP запроса
        cout << "Отправка FTP запроса на " << server << endl;
        // Здесь можно добавить логику для обработки ошибок сети
        // Например, если произошла ошибка сети, можно выбросить исключение
        throw runtime_error("Ошибка сети при отправке FTP запроса.");
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, address;

    cout << "Введите тип запроса (HTTP/FTP): ";
    cin >> input;

    NetworkRequest* request;

    if (input == "HTTP") {
        cout << "Введите URL для HTTP запроса: ";
        cin >> address;
        try {
            request = new HttpRequest(address);
            request->send();
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else if (input == "FTP") {
        cout << "Введите сервер для FTP запроса: ";
        cin >> address;
        try {
            request = new FtpRequest(address);
            request->send();
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    else {
        cout << "Неверный ввод." << endl;
    }

    delete request;
    return 0;
}