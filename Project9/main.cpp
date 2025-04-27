
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Document {
public:
    virtual void save() const = 0; 
    virtual ~Document() {}
};

class PDFDocument : public Document {
public:
    void save() const override {
      
        cout << "PDF-�������� ������� ��������!" << endl;
    }
};

class WordDocument : public Document {
public:
    void save() const override {
     
        cout << "Word-�������� ������� ��������!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Document* doc = nullptr;
    char choice;

    cout << "�������� ��� ��������� (p ��� PDF, w ��� Word): ";
    cin >> choice;

    try {
        if (choice == 'p') {
            doc = new PDFDocument();
        }
        else if (choice == 'w') {
            doc = new WordDocument();
        }
        else {
            throw runtime_error("������: �������� ����� ���������.");
        }

        doc->save(); 
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }

  
    return 0;
}