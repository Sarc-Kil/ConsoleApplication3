#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class ShoppingCart {
protected:
    vector<string> items; 

public:
    virtual void addItem(const string& item) {
        items.push_back(item);
    }

    virtual void checkout() = 0; 
    virtual ~ShoppingCart() {}
};

class RegularCart : public ShoppingCart {
public:
    void checkout() override {
        if (items.empty()) {
            throw runtime_error("������: ������� �����. �������� ������ ����� ����������� ������.");
        }
        cout << "���������� ������ �� ������� �������:" << endl;
        for (const auto& item : items) {
            cout << "- " << item << endl;
        }
        cout << "����� ������� ��������!" << endl;
    }
};

class DiscountedCart : public ShoppingCart {
public:
    void checkout() override {
        if (items.empty()) {
            throw runtime_error("������: ������� �����. �������� ������ ����� ����������� ������.");
        }
        cout << "���������� ������ �� ������� �� �������:" << endl;
        for (const auto& item : items) {
            cout << "- " << item << endl;
        }
        cout << "����� ������� �������� � ������ ������!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 

    try {
        RegularCart regularCart;
        DiscountedCart discountedCart;

        int choice;
        string item;
        int itemCount;

        
        cout << "������� ���������� ������� ��� ������� �������: ";
        cin >> itemCount;
        cin.ignore(); 

        for (int i = 0; i < itemCount; ++i) {
            cout << "������� �������� ������ " << (i + 1) << ": ";
            getline(cin, item);
            regularCart.addItem(item);
        }

       
        regularCart.checkout();

        
        cout << "������� ���������� ������� ��� ������� �� �������: ";
        cin >> itemCount;
        cin.ignore(); 

        for (int i = 0; i < itemCount; ++i) {
            cout << "������� �������� ������ " << (i + 1) << ": ";
            getline(cin, item);
            discountedCart.addItem(item);
        }

        
        discountedCart.checkout();

    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }

    return 0;
}