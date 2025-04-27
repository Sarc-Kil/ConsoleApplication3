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
            throw invalid_argument("������������ URL ��� HTTP �������. URL �� ����� ���� ������.");
        }
    }

    void send() override {
        // ��������� �������� HTTP �������
        cout << "�������� HTTP ������� �� " << url << endl;
        // ����� ����� �������� ������ ��� ��������� ������ ����
        // ��������, ���� ��������� ������ ����, ����� ��������� ����������
        throw runtime_error("������ ���� ��� �������� HTTP �������.");
    }
};

class FtpRequest : public NetworkRequest {
private:
    string server;

public:
    FtpRequest(const string& server) : server(server) {
        if (server.empty()) {
            throw invalid_argument("������������ ������ ��� FTP �������. ������ �� ����� ���� ������.");
        }
    }

    void send() override {
        // ��������� �������� FTP �������
        cout << "�������� FTP ������� �� " << server << endl;
        // ����� ����� �������� ������ ��� ��������� ������ ����
        // ��������, ���� ��������� ������ ����, ����� ��������� ����������
        throw runtime_error("������ ���� ��� �������� FTP �������.");
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, address;

    cout << "������� ��� ������� (HTTP/FTP): ";
    cin >> input;

    NetworkRequest* request;

    if (input == "HTTP") {
        cout << "������� URL ��� HTTP �������: ";
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
        cout << "������� ������ ��� FTP �������: ";
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
        cout << "�������� ����." << endl;
    }

    delete request;
    return 0;
}