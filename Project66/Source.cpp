#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class FileReader {
public:
    virtual void read(const string& filename) = 0;
    virtual ~FileReader() {}
};

class TextFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("������: ��� ���������� ����� �� ����� ���� ������.");
        }
        cout << "������ ���������� �����: " << filename << endl;
    }
};

class BinaryFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("������: ��� ��������� ����� �� ����� ���� ������.");
        }
        cout << "������ ��������� �����: " << filename << endl;
    }
};

class JsonFileReader : public FileReader {
public:
    void read(const string& filename) override {
        if (filename.empty()) {
            throw runtime_error("������: ��� JSON ����� �� ����� ���� ������.");
        }
        cout << "������ JSON �����: " << filename << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        cout << "�������� ������ ����� ��� ������ (1 - ���������, 2 - ��������, 3 - JSON, 0 - �����): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        string filename;

        cout << "������� ��� �����: ";
        getline(cin, filename);

        try {
            FileReader* fileReader = nullptr;

            if (choice == 1) {
                fileReader = new TextFileReader();
            }
            else if (choice == 2) {
                fileReader = new BinaryFileReader();
            }
            else if (choice == 3) {
                fileReader = new JsonFileReader();
            }
            else {
                cout << "������������ �����." << endl;
                continue;
            }

            fileReader->read(filename);
            delete fileReader;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}