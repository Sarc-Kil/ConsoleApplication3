#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Database {
public:
    virtual void connect() = 0; 
    virtual ~Database() {}
};

class MySQLDatabase : public Database {
private:
    string connectionString;

public:
    MySQLDatabase(const string& connStr) : connectionString(connStr) {}

    void connect() override {
       
        if (connectionString.empty()) {
            throw runtime_error("������ ����������� � MySQL: ������ ����������� �����.");
        }
        cout << "����������� � MySQL � �������������� ������ �����������: " << connectionString << endl;
       
    }
};

class SQLiteDatabase : public Database {
private:
    string databaseFile;

public:
    SQLiteDatabase(const string& dbFile) : databaseFile(dbFile) {}

    void connect() override {
     
        if (databaseFile.empty()) {
            throw runtime_error("������ ����������� � SQLite: ���� ���� ������ �� ������.");
        }
        cout << "����������� � SQLite � �������������� ����� ���� ������: " << databaseFile << endl;
      
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 

    try {
        string mysqlConnStr, sqliteDbFile;

       
        cout << "������� ������ ����������� ��� MySQL: ";
        getline(cin, mysqlConnStr);
        MySQLDatabase mysqlDatabase(mysqlConnStr);
        mysqlDatabase.connect();

     
        cout << "������� ��� ����� ���� ������ ��� SQLite: ";
        getline(cin, sqliteDbFile);
        SQLiteDatabase sqliteDatabase(sqliteDbFile);
        sqliteDatabase.connect();

    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }

    return 0;
}