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
            throw invalid_argument("������: ����� ������� ������ ���� �������������.");
        }
        cout << "��������� ������� ����� Stripe �� �����: $" << amount << endl;
       
        cout << "������ ������� ��������� ����� Stripe." << endl;
    }
};

class PayPalGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        if (amount <= 0) {
            throw invalid_argument("������: ����� ������� ������ ���� �������������.");
        }
        cout << "��������� ������� ����� PayPal �� �����: $" << amount << endl;
        
        cout << "������ ������� ��������� ����� PayPal." << endl;
    }
};

class SquareGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        if (amount <= 0) {
            throw invalid_argument("������: ����� ������� ������ ���� �������������.");
        }
        cout << "��������� ������� ����� Square �� �����: $" << amount << endl;
       
        cout << "������ ������� ��������� ����� Square." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    string gatewayType;
    double amount;

    while (true) {
        cout << "������� ��� ���������� ����� (stripe, paypal, square, exit): ";
        cin >> gatewayType;

        if (gatewayType == "exit") {
            cout << "����� �� ���������." << endl;
            break;
        }

        cout << "������� ����� �������: ";
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
                cout << "������: ����������� ��� ���������� �����." << endl;
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