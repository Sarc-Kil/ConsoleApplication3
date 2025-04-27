#include <iostream>
#include <string>
#include <stdexcept>
#include <locale>

using namespace std;

class DataProcessor {
public:
    virtual void processData(const string& data) = 0;
    virtual ~DataProcessor() {}
};

class CSVDataProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("������: ������ ������ ��� CSV.");
        cout << "��������� CSV ������: " << data << endl;
    }
};

class XMLDataProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("������: ������ ������ ��� XML.");
        cout << "��������� XML ������: " << data << endl;
    }
};

class JSONDataProcessor : public DataProcessor {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("������: ������ ������ ��� JSON.");
        cout << "��������� JSON ������: " << data << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ������ ������ (1 - CSV, 2 - XML, 3 - JSON, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string data;
        try {
            cout << "������� ������: ";
            getline(cin, data);

            if (choice == 1) {
                CSVDataProcessor csvProcessor;
                csvProcessor.processData(data);
            }
            else if (choice == 2) {
                XMLDataProcessor xmlProcessor;
                xmlProcessor.processData(data);
            }
            else if (choice == 3) {
                JSONDataProcessor jsonProcessor;
                jsonProcessor.processData(data);
            }
            else {
                cout << "������������ �����." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}