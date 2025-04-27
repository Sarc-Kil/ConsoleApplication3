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
            cout << "����� ������: " << book.getTitle() << endl;
            return;
        }
    }
    cout << "����� ����������." << endl;
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
                cout << "����� ����������: " << book.getTitle() << endl;
                return;
            }
        }
    }
    cout << "������ � ����� �� �������." << endl;
}

void Library::reserveBook(int userId, int bookId) {
    for (auto& book : books) {
        if (book.getId() == bookId && book.isAvailable()) {
            reservations.emplace_back(userId, bookId);
            cout << "����� ���������������: " << book.getTitle() << endl;
            return;
        }
    }
    cout << "����� ���������� ��� ��������������." << endl;
}

void Library::searchBooksByTitle(const string& title) {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            cout << "������� �����: " << book.getTitle() << " �����: " << book.getAuthor() << endl;
            return;
        }
    }
    cout << "����� � ��������� \"" << title << "\" �� �������." << endl;
}

void Library::searchBooksByAuthor(const string& author) {
    bool found = false;
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            cout << "������� �����: " << book.getTitle() << " �����: " << author << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "����� ������ \"" << author << "\" �� �������." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    Library library;
    int choice;

    do {
        cout << "1. �������� �����\n2. �������� ������������\n3. ������ �����\n4. ������� �����\n5. ��������������� �����\n6. ����� ����� �� ��������\n7. ����� ����� �� ������\n8. �����\n";
        cout << "������� ��� �����: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "������� ID �����: ";
            cin >> id;
            cout << "������� �������� �����: ";
            cin >> ws;
            getline(cin, title);
            cout << "������� ������ �����: ";
            getline(cin, author);
            library.addBook(Book(id, title, author));
        }
        else if (choice == 2) {
            int id;
            string name;
            cout << "������� ID ������������: ";
            cin >> id;
            cout << "������� ��� ������������: ";
            cin >> ws;
            getline(cin, name);
            library.addUser(User(id, name));
        }
        else if (choice == 3) {
            int userId, bookId;
            cout << "������� ID ������������: ";
            cin >> userId;
            cout << "������� ID �����: ";
            cin >> bookId;
            library.loanBook(userId, bookId);
        }
        else if (choice == 4) {
            int userId, bookId;
            cout << "������� ID ������������: ";
            cin >> userId;
            cout << "������� ID �����: ";
            cin >> bookId;
            library.returnBook(userId, bookId);
        }
        else if (choice == 5) {
            int userId, bookId;
            cout << "������� ID ������������: ";
            cin >> userId;
            cout << "������� ID �����: ";
            cin >> bookId;
            library.reserveBook(userId, bookId);
        }
        else if (choice == 6) {
            string title;
            cout << "������� �������� �����: ";
            cin >> ws;
            getline(cin, title);
            library.searchBooksByTitle(title);
        }
        else if (choice == 7) {
            string author;
            cout << "������� ��� ������: ";
            cin >> ws;
            getline(cin, author);
            library.searchBooksByAuthor(author);
        }
    } while (choice != 8);

    return 0;
}