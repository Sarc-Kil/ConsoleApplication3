#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <locale>

using namespace std;

class Service {
public:
    string name;
    bool isActive;

    Service(string n) : name(n), isActive(true) {}

    void checkStatus() {
        cout << "������ " << name << (isActive ? " �������." : " ���������.") << endl;
    }
};

class Database {
public:
    map<string, string> data;

    void save(string key, string value) {
        data[key] = value;
    }

    string load(string key) {
        return data.count(key) ? data[key] : "������ �� �������.";
    }
};

class MessageQueue {
public:
    vector<string> messages;

    void sendMessage(string message) {
        messages.push_back(message);
    }

    string receiveMessage() {
        if (messages.empty()) return "��� ���������.";
        string msg = messages.front();
        messages.erase(messages.begin());
        return msg;
    }
};

class LoadBalancer {
public:
    vector<Service*> services;

    void addService(Service* service) {
        services.push_back(service);
    }

    Service* getService() {
        if (services.empty()) return nullptr;
        return services[rand() % services.size()];
    }
};

class API {
public:
    LoadBalancer* loadBalancer;

    API(LoadBalancer* lb) : loadBalancer(lb) {}

    void handleRequest(string request) {
        Service* service = loadBalancer->getService();
        if (service) {
            cout << "��������� ������� \"" << request << "\" �������� " << service->name << endl;
        }
        else {
            cout << "��� ��������� �������� ��� ��������� �������." << endl;
        }
    }
};

class Client {
public:
    API* api;

    Client(API* a) : api(a) {}

    void makeRequest(string request) {
        api->handleRequest(request);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    LoadBalancer lb;
    int serviceCount;

    cout << "������� ���������� ��������: ";
    cin >> serviceCount;
    cin.ignore(); 

    for (int i = 0; i < serviceCount; ++i) {
        string serviceName;
        cout << "������� �������� ������� " << (i + 1) << ": ";
        getline(cin, serviceName);
        Service* service = new Service(serviceName);
        lb.addService(service);
    }

    API api(&lb);
    Client client(&api);

    string request;
    while (true) {
        cout << "������� ������ (��� 'exit' ��� ������): ";
        getline(cin, request);
        if (request == "exit") break;
        client.makeRequest(request);
    }

    return 0;
}