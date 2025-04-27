#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <locale>

using namespace std;

class DataReader {
public:
    virtual void readData(const string& filename) = 0;
};

class CSVReader : public DataReader {
public:
    void readData(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("������: ���� �� ������ ��� �� ����� ���� ������.");
        }

        string line;
        while (getline(file, line)) {
            if (line.empty() || line.find(',') == string::npos) {
                throw runtime_error("������: �������� ������ CSV �����.");
            }
            cout << "������ ������ CSV: " << line << endl;
        }
        file.close();
    }
};

class XMLReader : public DataReader {
public:
    void readData(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("������: ���� �� ������ ��� �� ����� ���� ������.");
        }

        string line;
        bool isValid = false;
        while (getline(file, line)) {
            if (line.find("<") != string::npos && line.find(">") != string::npos) {
                isValid = true;
                cout << "������ ������ XML: " << line << endl;
            }
        }
        if (!isValid) {
            throw runtime_error("������: �������� ������ XML �����.");
        }
        file.close();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, filename;

    cout << "������� ��� ����� (CSV/XML): ";
    cin >> input;

    DataReader* reader;

    if (input == "CSV") {
        reader = new CSVReader();
    }
    else if (input == "XML") {
        reader = new XMLReader();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ��� ����� ��� ������: ";
    cin >> filename;

    try {
        reader->readData(filename);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete reader;
    return 0;
}