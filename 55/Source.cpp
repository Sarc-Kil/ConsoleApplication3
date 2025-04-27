#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

using namespace std;

class Database {
public:
    virtual void query(const string& sql) = 0;
};

class MySQLDatabase : public Database {
public:
    void query(const string& sql) override {
        if (sql.empty()) {
            throw invalid_argument("Ошибка: Запрос не может быть пустым для MySQL.");
        }
        cout << "Выполнение запроса MySQL: " << sql << endl;
    }
};

class SQLiteDatabase : public Database {
public:
    void query(const string& sql) override {
        if (sql.empty()) {
            throw invalid_argument("Ошибка: Запрос не может быть пустым для SQLite.");
        }
        cout << "Выполнение запроса SQLite: " << sql << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, sql;

    cout << "Введите тип базы данных (MySQL/SQLite): ";
    cin >> input;

    Database* database = nullptr;

    if (input == "MySQL") {
        database = new MySQLDatabase();
    }
    else if (input == "SQLite") {
        database = new SQLiteDatabase();
    }
    else {
        cout << "Неверный ввод." << endl;
        return 1;
    }

    cout << "Введите SQL запрос: ";
    cin.ignore();
    getline(cin, sql);

    try {
        database->query(sql);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    delete database;
    return 0;
}