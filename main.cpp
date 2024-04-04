#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Order {
public:
    int tableNumber;
    string clientName;
    string item;
    string paymentMethod;
    int numberOfPeople;
};

class RestaurantOrderSystem {
private:
    vector<Order> orders;

public:
    void takeOrder() {
        Order newOrder;

        cout << "Enter table number: ";
        cin >> newOrder.tableNumber;

        cout << "Enter client name: ";
        cin >> newOrder.clientName;

        cout << "Enter item ordered: ";
        cin >> newOrder.item;

        cout << "Enter payment method: ";
        cin >> newOrder.paymentMethod;

        cout << "Enter number of people: ";
        cin >> newOrder.numberOfPeople;

        orders.push_back(newOrder);
        cout << "Order taken successfully." << endl;
    }

    void displayOrders() {
        if (orders.empty()) {
            cout << "No orders taken yet." << endl;
            return;
        }

        cout << "All orders:" << endl;
        cout << "Table No.\tClient Name\t\tItem\t\tPayment Method\tNo. of People" << endl;
        for (const auto& order : orders) {
            cout << order.tableNumber << "\t\t" << order.clientName << "\t\t" << order.item
                 << "\t\t" << order.paymentMethod << "\t\t" << order.numberOfPeople << endl;
        }
    }
};

int main() {
    RestaurantOrderSystem orderSystem;
    int choice;

    do {
        cout << "\nRestaurant Order System" << endl;
        cout << "1. Take an order" << endl;
        cout << "2. Display all orders" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                orderSystem.takeOrder();
                break;
            case 2:
                orderSystem.displayOrders();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 3);

    return 0;
}
