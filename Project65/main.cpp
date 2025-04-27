#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class PaymentGateway {
public:
    virtual void processPayment(double amount) = 0; 
    virtual ~PaymentGateway() {}
};

class StripeGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        if (amount <= 0) {
            throw invalid_argument("Ошибка: Сумма платежа должна быть положительной.");
        }
        cout << "Обработка платежа через Stripe на сумму: $" << amount << endl;
       
        cout << "Платеж успешно обработан через Stripe." << endl;
    }
};

class PayPalGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        if (amount <= 0) {
            throw invalid_argument("Ошибка: Сумма платежа должна быть положительной.");
        }
        cout << "Обработка платежа через PayPal на сумму: $" << amount << endl;
        
        cout << "Платеж успешно обработан через PayPal." << endl;
    }
};

class SquareGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        if (amount <= 0) {
            throw invalid_argument("Ошибка: Сумма платежа должна быть положительной.");
        }
        cout << "Обработка платежа через Square на сумму: $" << amount << endl;
       
        cout << "Платеж успешно обработан через Square." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    string gatewayType;
    double amount;

    while (true) {
        cout << "Введите тип платежного шлюза (stripe, paypal, square, exit): ";
        cin >> gatewayType;

        if (gatewayType == "exit") {
            cout << "Выход из программы." << endl;
            break;
        }

        cout << "Введите сумму платежа: ";
        cin >> amount;

        try {
            PaymentGateway* gateway = nullptr;

            if (gatewayType == "stripe") {
                gateway = new StripeGateway();
            }
            else if (gatewayType == "paypal") {
                gateway = new PayPalGateway();
            }
            else if (gatewayType == "square") {
                gateway = new SquareGateway();
            }
            else {
                cout << "Ошибка: Неизвестный тип платежного шлюза." << endl;
                continue;
            }

            gateway->processPayment(amount); 
           
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }
    }

    return 0;
}