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
            throw invalid_argument("������: ������ �� ����� ���� ������ ��� MySQL.");
        }
        cout << "���������� ������� MySQL: " << sql << endl;
    }
};

class SQLiteDatabase : public Database {
public:
    void query(const string& sql) override {
        if (sql.empty()) {
            throw invalid_argument("������: ������ �� ����� ���� ������ ��� SQLite.");
        }
        cout << "���������� ������� SQLite: " << sql << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input, sql;

    cout << "������� ��� ���� ������ (MySQL/SQLite): ";
    cin >> input;

    Database* database = nullptr;

    if (input == "MySQL") {
        database = new MySQLDatabase();
    }
    else if (input == "SQLite") {
        database = new SQLiteDatabase();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    cout << "������� SQL ������: ";
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