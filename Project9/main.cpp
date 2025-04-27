
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
      
        cout << "PDF-документ успешно сохранен!" << endl;
    }
};

class WordDocument : public Document {
public:
    void save() const override {
     
        cout << "Word-документ успешно сохранен!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Document* doc = nullptr;
    char choice;

    cout << "Выберите тип документа (p для PDF, w для Word): ";
    cin >> choice;

    try {
        if (choice == 'p') {
            doc = new PDFDocument();
        }
        else if (choice == 'w') {
            doc = new WordDocument();
        }
        else {
            throw runtime_error("Ошибка: Неверный выбор документа.");
        }

        doc->save(); 
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }

  
    return 0;
}