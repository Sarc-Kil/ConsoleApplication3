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
        cout << "Банковская транзакция выполнена." << endl;
    }
};

class CryptoTransaction : public Transaction {
public:
    void commit() override {
        throw runtime_error("Ошибка выполнения криптовалютной транзакции.");
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string input;

    cout << "Введите тип транзакции (банковская/криптовалютная): ";
    cin >> input;

    Transaction* transaction;

    if (input == "банковская") {
        transaction = new BankTransaction();
    }
    else if (input == "криптовалютная") {
        transaction = new CryptoTransaction();
    }
    else {
        cout << "Неверный ввод." << endl;
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