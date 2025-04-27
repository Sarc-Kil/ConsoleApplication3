#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class DataProcessor {
public:
    virtual void process(const string& data) = 0; 
    virtual ~DataProcessor() {}
};

class CSVProcessor : public DataProcessor {
public:
    void process(const string& data) override {
        if (data.empty()) {
            throw invalid_argument("������: ������������ ������ ��� CSV.");
        }
        cout << "��������� CSV ������: " << data << endl;
        
    }
};

class JSONProcessor : public DataProcessor {
public:
    void process(const string& data) override {
        if (data.empty() || data[0] != '{' || data[data.size() - 1] != '}') {
            throw invalid_argument("������: ������������ ������ ��� JSON.");
        }
        cout << "��������� JSON ������: " << data << endl;
       
    }
};

class XMLProcessor : public DataProcessor {
public:
    void process(const string& data) override {
        if (data.empty() || data.substr(0, 5) != "<?xml" || data.substr(data.size() - 6) != "?>") {
            throw invalid_argument("������: ������������ ������ ��� XML.");
        }
        cout << "��������� XML ������: " << data << endl;
       
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    CSVProcessor csvProcessor;
    JSONProcessor jsonProcessor;
    XMLProcessor xmlProcessor;

    string command;
    string data;

    while (true) {
        cout << "������� ������� (csv, json, xml, exit): ";
        cin >> command;

        if (command == "exit") {
            cout << "����� �� ���������." << endl;
            break;
        }

        cout << "������� ������: ";
        cin.ignore(); 
        getline(cin, data); 

        try {
            if (command == "csv") {
                csvProcessor.process(data);
            }
            else if (command == "json") {
                jsonProcessor.process(data);
            }
            else if (command == "xml") {
                xmlProcessor.process(data);
            }
            else {
                cout << "������: ����������� �������." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}