#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Library {
public:
    virtual void borrowBook(const string& bookTitle) = 0; 
    virtual ~Library() {}
};

class FictionLibrary : public Library {
private:
    vector<string> availableBooks;

public:
    FictionLibrary() {
        
        availableBooks = { "1984", "To Kill a Mockingbird", "The Great Gatsby" };
    }

    void borrowBook(const string& bookTitle) override {
        auto it = find(availableBooks.begin(), availableBooks.end(), bookTitle);
        if (it == availableBooks.end()) {
            throw invalid_argument("Ошибка: Книга '" + bookTitle + "' недоступна.");
        }
        availableBooks.erase(it);
        cout << "Вы одолжили книгу '" << bookTitle << "' из художественной библиотеки." << endl;
    }
};

class NonFictionLibrary : public Library {
private:
    vector<string> availableBooks;

public:
    NonFictionLibrary() {
        
        availableBooks = { "Sapiens", "Educated", "The Immortal Life of Henrietta Lacks" };
    }

    void borrowBook(const string& bookTitle) override {
        auto it = find(availableBooks.begin(), availableBooks.end(), bookTitle);
        if (it == availableBooks.end()) {
            throw invalid_argument("Ошибка: Книга '" + bookTitle + "' недоступна.");
        }
        availableBooks.erase(it); 
        cout << "Вы одолжили книгу '" << bookTitle << "' из научной библиотеки." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        FictionLibrary fictionLibrary;
        NonFictionLibrary nonFictionLibrary;

        string bookTitle;

        cout << "Введите название книги для заимствования из художественной библиотеки: ";
        getline(cin, bookTitle);
        fictionLibrary.borrowBook(bookTitle);

        cout << "Введите название книги для заимствования из научной библиотеки: ";
        getline(cin, bookTitle);
        nonFictionLibrary.borrowBook(bookTitle);

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}