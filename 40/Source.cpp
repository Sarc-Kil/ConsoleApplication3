#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class DataProcessor {
public:
    virtual void processData(const string& data) = 0;
};

class CSVProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty() || data.find(',') == string::npos) {
            throw invalid_argument("Некорректные данные для CSV. Данные не могут быть пустыми и должны содержать запятые.");
        }
        cout << "Обработка CSV данных: " << data << endl;
    }
};

class JSONProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty() || data.front() != '{' || data.back() != '}') {
            throw invalid_argument("Некорректные данные для JSON. Данные должны быть непустыми и начинаться с '{' и заканчиваться на '}'.");
        }
        cout << "Обработка JSON данных: " << data << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, data;

    cout << "Введите тип процессора данных (CSV/JSON): ";
    cin >> input;

    DataProcessor* processor;

    if (input == "CSV") {
        processor = new CSVProcessor();
    }
    else if (input == "JSON") {
        processor = new JSONProcessor();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите данные для обработки: ";
    cin.ignore();
    getline(cin, data);

    try {
        processor->processData(data);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete processor;
    return 0;
}