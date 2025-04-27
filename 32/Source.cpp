#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class FileReader {
public:
    virtual void read(const string& filename) = 0;
};

class TextFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("������ ������ ���������� �����: ��� ����� �� ����� ���� ������.");
        }
        cout << "������ ���������� �����: " << filename << endl;
    }
};

class BinaryFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("������ ������ ��������� �����: ��� ����� �� ����� ���� ������.");
        }
        cout << "������ ��������� �����: " << filename << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, filename;

    cout << "������� ��� ����� (���������/��������): ";
    cin >> input;

    FileReader* fileReader;

    if (input == "���������") {
        fileReader = new TextFileReader();
    }
    else if (input == "��������") {
        fileReader = new BinaryFileReader();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� ��� �����: ";
    cin.ignore();
    getline(cin, filename);

    try {
        fileReader->read(filename);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete fileReader;
    return 0;
}