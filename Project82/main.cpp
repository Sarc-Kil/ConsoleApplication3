#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>

using namespace std;

class Book {
public:
    Book(int id, const string& title, const string& author, bool available = true)
        : id(id), title(title), author(author), available(available) {
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }
    void setAvailable(bool avail) { available = avail; }

private:
    int id;
    string title;
    string author;
    bool available;
};

class User {
public:
    User(int id, const string& name) : id(id), name(name) {}

    int getId() const { return id; }
    string getName() const { return name; }

private:
    int id;
    string name;
};

class Loan {
public:
    Loan(int userId, int bookId) : userId(userId), bookId(bookId), overdue(false) {}

    void markOverdue() { overdue = true; }
    bool isOverdue() const { return overdue; }
    int getUserId() const { return userId; }
    int getBookId() const { return bookId; }

private:
    int userId;
    int bookId;
    bool overdue;
};

class Reservation {
public:
    Reservation(int userId, int bookId) : userId(userId), bookId(bookId) {}

    int getUserId() const { return userId; }
    int getBookId() const { return bookId; }

private:
    int userId;
    int bookId;
};

class Fine {
public:
    Fine(int userId, double amount) : userId(userId), amount(amount) {}

    int getUserId() const { return userId; }
    double getAmount() const { return amount; }

private:
    int userId;
    double amount;
};

class Library {
public:
    void addBook(const Book& book) { books.push_back(book); }
    void addUser(const User& user) { users.push_back(user); }
    void loanBook(int userId, int bookId);
    void returnBook(int userId, int bookId);
    void reserveBook(int userId, int bookId);
    void searchBooksByTitle(const string& title);
    void searchBooksByAuthor(const string& author);

private:
    vector<Book> books;
    vector<User> users;
    vector<Loan> loans;
    vector<Reservation> reservations;
    vector<Fine> fines;
};

void Library::loanBook(int userId, int bookId) {
    for (auto& book : books) {
        if (book.getId() == bookId && book.isAvailable()) {
            book.setAvailable(false);
            loans.emplace_back(userId, bookId);
            cout << "Книга выдана: " << book.getTitle() << endl;
            return;
        }
    }
    cout << "Книга недоступна." << endl;
}

void Library::returnBook(int userId, int bookId) {
    auto it = remove_if(loans.begin(), loans.end(), [userId, bookId](const Loan& loan) {
        return loan.getUserId() == userId && loan.getBookId() == bookId;
        });
    if (it != loans.end()) {
        loans.erase(it, loans.end());
        for (auto& book : books) {
            if (book.getId() == bookId) {
                book.setAvailable(true);
                cout << "Книга возвращена: " << book.getTitle() << endl;
                return;
            }
        }
    }
    cout << "Запись о займе не найдена." << endl;
}

void Library::reserveBook(int userId, int bookId) {
    for (auto& book : books) {
        if (book.getId() == bookId && book.isAvailable()) {
            reservations.emplace_back(userId, bookId);
            cout << "Книга зарезервирована: " << book.getTitle() << endl;
            return;
        }
    }
    cout << "Книга недоступна для резервирования." << endl;
}

void Library::searchBooksByTitle(const string& title) {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            cout << "Найдена книга: " << book.getTitle() << " автор: " << book.getAuthor() << endl;
            return;
        }
    }
    cout << "Книга с названием \"" << title << "\" не найдена." << endl;
}

void Library::searchBooksByAuthor(const string& author) {
    bool found = false;
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            cout << "Найдена книга: " << book.getTitle() << " автор: " << author << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Книги автора \"" << author << "\" не найдены." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    Library library;
    int choice;

    do {
        cout << "1. Добавить книгу\n2. Добавить пользователя\n3. Выдать книгу\n4. Вернуть книгу\n5. Зарезервировать книгу\n6. Поиск книги по названию\n7. Поиск книги по автору\n8. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Введите ID книги: ";
            cin >> id;
            cout << "Введите название книги: ";
            cin >> ws;
            getline(cin, title);
            cout << "Введите автора книги: ";
            getline(cin, author);
            library.addBook(Book(id, title, author));
        }
        else if (choice == 2) {
            int id;
            string name;
            cout << "Введите ID пользователя: ";
            cin >> id;
            cout << "Введите имя пользователя: ";
            cin >> ws;
            getline(cin, name);
            library.addUser(User(id, name));
        }
        else if (choice == 3) {
            int userId, bookId;
            cout << "Введите ID пользователя: ";
            cin >> userId;
            cout << "Введите ID книги: ";
            cin >> bookId;
            library.loanBook(userId, bookId);
        }
        else if (choice == 4) {
            int userId, bookId;
            cout << "Введите ID пользователя: ";
            cin >> userId;
            cout << "Введите ID книги: ";
            cin >> bookId;
            library.returnBook(userId, bookId);
        }
        else if (choice == 5) {
            int userId, bookId;
            cout << "Введите ID пользователя: ";
            cin >> userId;
            cout << "Введите ID книги: ";
            cin >> bookId;
            library.reserveBook(userId, bookId);
        }
        else if (choice == 6) {
            string title;
            cout << "Введите название книги: ";
            cin >> ws;
            getline(cin, title);
            library.searchBooksByTitle(title);
        }
        else if (choice == 7) {
            string author;
            cout << "Введите имя автора: ";
            cin >> ws;
            getline(cin, author);
            library.searchBooksByAuthor(author);
        }
    } while (choice != 8);

    return 0;
}