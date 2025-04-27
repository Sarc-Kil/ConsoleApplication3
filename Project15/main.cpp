#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Order {
protected:
    string orderID;
    double amount;

public:
    Order(const string& id, double amt) : orderID(id), amount(amt) {
        if (amt <= 0) {
            throw invalid_argument("Ошибка: Сумма заказа должна быть положительной.");
        }
    }

    virtual void process() = 0; 
    virtual ~Order() {}
};

class OnlineOrder : public Order {
private:
    string email;

public:
    OnlineOrder(const string& id, double amt, const string& emailAddress)
        : Order(id, amt), email(emailAddress) {
        if (emailAddress.empty()) {
            throw invalid_argument("Ошибка: Электронная почта не может быть пустой.");
        }
    }

    void process() override {
        cout << "Обработка онлайн-заказа ID: " << orderID << endl;
        cout << "Сумма: " << amount << " руб." << endl;
        cout << "Электронная почта: " << email << endl;
        cout << "Заказ успешно обработан!" << endl;
    }
};

class InStoreOrder : public Order {
private:
    string customerName;

public:
    InStoreOrder(const string& id, double amt, const string& name)
        : Order(id, amt), customerName(name) {
        if (name.empty()) {
            throw invalid_argument("Ошибка: Имя клиента не может быть пустым.");
        }
    }

    void process() override {
        cout << "Обработка заказа в магазине ID: " << orderID << endl;
        cout << "Сумма: " << amount << " руб." << endl;
        cout << "Имя клиента: " << customerName << endl;
        cout << "Заказ успешно обработан!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    try {
        string orderID, email, customerName;
        double amount;

       
        cout << "Введите ID онлайн-заказа: ";
        getline(cin, orderID);
        cout << "Введите сумму заказа: ";
        cin >> amount;
        cin.ignore(); 
        cout << "Введите электронную почту: ";
        getline(cin, email);
        OnlineOrder onlineOrder(orderID, amount, email);
        onlineOrder.process();

      
        cout << "Введите ID заказа в магазине: ";
        getline(cin, orderID);
        cout << "Введите сумму заказа: ";
        cin >> amount;
        cin.ignore(); 
        cout << "Введите имя клиента: ";
        getline(cin, customerName);
        InStoreOrder inStoreOrder(orderID, amount, customerName);
        inStoreOrder.process();

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}