#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Product {
public:
    Product(int id, const string& name, double price)
        : id(id), name(name), price(price) {
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }

private:
    int id;
    string name;
    double price;
};

class Order {
public:
    Order(int id, const vector<Product>& products)
        : id(id), products(products), status("Pending") {
    }

    void setStatus(const string& newStatus) { status = newStatus; }
    string getStatus() const { return status; }
    int getId() const { return id; }
    const vector<Product>& getProducts() const { return products; }

private:
    int id;
    vector<Product> products;
    string status;
};

class Customer {
public:
    Customer(int id, const string& name)
        : id(id), name(name) {
    }

    void addOrder(const Order& order) {
        orders.push_back(order);
    }

    void printOrderHistory() const {
        cout << "Order History for " << name << ":\n";
        for (const auto& order : orders) {
            cout << "Order ID: " << order.getId() << ", Status: " << order.getStatus() << "\n";
        }
    }

private:
    int id;
    string name;
    vector<Order> orders;
};

class ShoppingCart {
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    const vector<Product>& getProducts() const { return products; }
    void clear() { products.clear(); }

private:
    vector<Product> products;
};

class Payment {
public:
    static bool processPayment(double amount) {
        cout << "Processing payment of $" << fixed << setprecision(2) << amount << "...\n";
        return true;
    }
};

class Shipping {
public:
    static void shipOrder(const Order& order) {
        cout << "Shipping Order ID: " << order.getId() << " with status: " << order.getStatus() << "\n";
    }
};

int main() {
    vector<Product> products;
    int productCount;

    cout << "Enter the number of products: ";
    cin >> productCount;

    for (int i = 0; i < productCount; ++i) {
        int id;
        string name;
        double price;

        cout << "Enter product ID: ";
        cin >> id;
        cout << "Enter product name: ";
        cin >> ws; 
        getline(cin, name);
        cout << "Enter product price: ";
        cin >> price;

        products.emplace_back(id, name, price);
    }

    ShoppingCart cart;
    int choice;

    do {
        cout << "Available products:\n";
        for (const auto& product : products) {
            cout << "ID: " << product.getId() << ", Name: " << product.getName() << ", Price: $" << product.getPrice() << "\n";
        }

        cout << "Enter product ID to add to cart (0 to finish): ";
        cin >> choice;

        if (choice == 0) break;

        for (const auto& product : products) {
            if (product.getId() == choice) {
                cart.addProduct(product);
                cout << "Added " << product.getName() << " to cart.\n";
                break;
            }
        }
    } while (true);

    int customerId;
    string customerName;

    cout << "Enter customer ID: ";
    cin >> customerId;
    cout << "Enter customer name: ";
    cin >> ws; 
    getline(cin, customerName);

    Customer customer(customerId, customerName);
    Order order(1, cart.getProducts());

    double totalAmount = 0;
    for (const auto& product : cart.getProducts()) {
        totalAmount += product.getPrice();
    }

    if (Payment::processPayment(totalAmount)) {
        order.setStatus("Paid");
        customer.addOrder(order);
        Shipping::shipOrder(order);
    }

    customer.printOrderHistory();

    return 0;
}