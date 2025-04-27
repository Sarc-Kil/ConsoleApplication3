#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

class Transaction {
public:
    virtual void commit() = 0;
};

class BankTransaction : public Transaction {
public:
    void commit() override {
        cout << "���������� ���������� ���������." << endl;
    }
};

class CryptoTransaction : public Transaction {
public:
    void commit() override {
        throw runtime_error("������ ���������� �������������� ����������.");
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "������� ��� ���������� (����������/��������������): ";
    cin >> input;

    Transaction* transaction;

    if (input == "����������") {
        transaction = new BankTransaction();
    }
    else if (input == "��������������") {
        transaction = new CryptoTransaction();
    }
    else {
        cout << "�������� ����." << endl;
        return 1;
    }

    try {
        transaction->commit();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    delete transaction;
    return 0;
}