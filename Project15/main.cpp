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
            throw invalid_argument("������: ����� ������ ������ ���� �������������.");
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
            throw invalid_argument("������: ����������� ����� �� ����� ���� ������.");
        }
    }

    void process() override {
        cout << "��������� ������-������ ID: " << orderID << endl;
        cout << "�����: " << amount << " ���." << endl;
        cout << "����������� �����: " << email << endl;
        cout << "����� ������� ���������!" << endl;
    }
};

class InStoreOrder : public Order {
private:
    string customerName;

public:
    InStoreOrder(const string& id, double amt, const string& name)
        : Order(id, amt), customerName(name) {
        if (name.empty()) {
            throw invalid_argument("������: ��� ������� �� ����� ���� ������.");
        }
    }

    void process() override {
        cout << "��������� ������ � �������� ID: " << orderID << endl;
        cout << "�����: " << amount << " ���." << endl;
        cout << "��� �������: " << customerName << endl;
        cout << "����� ������� ���������!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    try {
        string orderID, email, customerName;
        double amount;

       
        cout << "������� ID ������-������: ";
        getline(cin, orderID);
        cout << "������� ����� ������: ";
        cin >> amount;
        cin.ignore(); 
        cout << "������� ����������� �����: ";
        getline(cin, email);
        OnlineOrder onlineOrder(orderID, amount, email);
        onlineOrder.process();

      
        cout << "������� ID ������ � ��������: ";
        getline(cin, orderID);
        cout << "������� ����� ������: ";
        cin >> amount;
        cin.ignore(); 
        cout << "������� ��� �������: ";
        getline(cin, customerName);
        InStoreOrder inStoreOrder(orderID, amount, customerName);
        inStoreOrder.process();

    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}