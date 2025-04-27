#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

class WeatherService {
public:
    virtual string getForecast() = 0;
};

class LocalWeatherService : public WeatherService {
public:
    string getForecast() override {
        return "������� ������ ��� ������ �������: ��������.";
    }
};

class RemoteWeatherService : public WeatherService {
public:
    string getForecast() override {
        throw runtime_error("������ ����������.");
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "������� ��� ������� (���������/���������): ";
    cin >> input;

    WeatherService* service;

    if (input == "���������") {
        service = new LocalWeatherService();
    }
    else if (input == "���������") {
        service = new RemoteWeatherService();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    try {
        cout << service->getForecast() << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete service;
    return 0;
}