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
        return "Прогноз погоды для вашего региона: солнечно.";
    }
};

class RemoteWeatherService : public WeatherService {
public:
    string getForecast() override {
        throw runtime_error("Данные недоступны.");
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип сервиса (локальный/удаленный): ";
    cin >> input;

    WeatherService* service;

    if (input == "локальный") {
        service = new LocalWeatherService();
    }
    else if (input == "удаленный") {
        service = new RemoteWeatherService();
    }
    else {
        cout << "Неверный ввод." << endl;
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