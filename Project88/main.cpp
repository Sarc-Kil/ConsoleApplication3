#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

class Currency {
public:
    string name;
    string code;

    Currency() : name(""), code("") {}
    Currency(const string& name, const string& code) : name(name), code(code) {}
};

class ExchangeRate {
public:
    Currency from;
    Currency to;
    double rate;

    ExchangeRate() : from(Currency()), to(Currency()), rate(0.0) {}  // Конструктор по умолчанию
    ExchangeRate(const Currency& from, const Currency& to, double rate)
        : from(from), to(to), rate(rate) {
    }
};

class Transaction {
public:
    double amount;
    Currency currency;
    string description;

    Transaction(double amount, const Currency& currency, const string& description)
        : amount(amount), currency(currency), description(description) {
    }
};

class Account {
public:
    string owner;
    vector<Transaction> transactions;

    Account(const string& owner) : owner(owner) {}

    void addTransaction(const Transaction& transaction) {
        transactions.push_back(transaction);
    }

    double getTotalAmount(const Currency& currency, const map<string, ExchangeRate>& rates) {
        double total = 0;
        for (const auto& transaction : transactions) {
            if (transaction.currency.code == currency.code) {
                total += transaction.amount;
            }
            else {
                total += transaction.amount * rates.at(transaction.currency.code + "_" + currency.code).rate;
            }
        }
        return total;
    }
};

class Budget {
public:
    double limit;
    Currency currency;

    Budget(double limit, const Currency& currency) : limit(limit), currency(currency) {}
};

class Report {
public:
    Account account;

    Report(const Account& account) : account(account) {}

    void generate() {
        cout << "Отчет для аккаунта: " << account.owner << endl;
        cout << "Транзакции:" << endl;
        for (const auto& transaction : account.transactions) {
            cout << "- " << transaction.description << ": " << transaction.amount << " " << transaction.currency.code << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    map<string, ExchangeRate> exchangeRates;

    Currency usd("Доллар США", "USD");
    Currency eur("Евро", "EUR");
    Currency rub("Российский рубль", "RUB");

    exchangeRates["USD_EUR"] = ExchangeRate(usd, eur, 0.85);
    exchangeRates["EUR_USD"] = ExchangeRate(eur, usd, 1.18);
    exchangeRates["USD_RUB"] = ExchangeRate(usd, rub, 75.0);
    exchangeRates["RUB_USD"] = ExchangeRate(rub, usd, 0.013);
    exchangeRates["EUR_RUB"] = ExchangeRate(eur, rub, 88.0);
    exchangeRates["RUB_EUR"] = ExchangeRate(rub, eur, 0.011);

    string owner;
    cout << "Введите имя владельца аккаунта: ";
    getline(cin, owner);
    Account account(owner);

    int transactionCount;
    cout << "Введите количество транзакций: ";
    cin >> transactionCount;

    for (int i = 0; i < transactionCount; ++i) {
        double amount;
        string currencyCode, description;
        cout << "Введите сумму транзакции: ";
        cin >> amount;
        cout << "Введите код валюты (USD, EUR, RUB): ";
        cin >> currencyCode;
        cin.ignore();
        cout << "Введите описание транзакции: ";
        getline(cin, description);

        Currency currency("", currencyCode);
        account.addTransaction(Transaction(amount, currency, description));
    }

    Currency reportCurrency;
    string reportCurrencyCode;
    cout << "Введите код валюты для отчета (USD, EUR, RUB): ";
    cin >> reportCurrencyCode;
    reportCurrency = Currency("", reportCurrencyCode);

    double totalAmount = account.getTotalAmount(reportCurrency, exchangeRates);
    cout << "Общая сумма в " << reportCurrency.code << ": " << fixed << setprecision(2) << totalAmount << endl;

    Report report(account);
    report.generate();

    return 0;
}