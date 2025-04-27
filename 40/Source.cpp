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
            throw invalid_argument("������������ ������ ��� CSV. ������ �� ����� ���� ������� � ������ ��������� �������.");
        }
        cout << "��������� CSV ������: " << data << endl;
    }
};

class JSONProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty() || data.front() != '{' || data.back() != '}') {
            throw invalid_argument("������������ ������ ��� JSON. ������ ������ ���� ��������� � ���������� � '{' � ������������� �� '}'.");
        }
        cout << "��������� JSON ������: " << data << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, data;

    cout << "������� ��� ���������� ������ (CSV/JSON): ";
    cin >> input;

    DataProcessor* processor;

    if (input == "CSV") {
        processor = new CSVProcessor();
    }
    else if (input == "JSON") {
        processor = new JSONProcessor();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ������ ��� ���������: ";
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