#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 50
#define MAX_NAME_LENGTH 50
#define MAX_ITEM_LENGTH 50

struct Order {
    int tableNumber;
    char clientName[MAX_NAME_LENGTH];
    char item[MAX_ITEM_LENGTH];
    char paymentMethod[20];
    int numberOfPeople;
};

struct Order orders[MAX_ORDERS];
int totalOrders = 0;

void takeOrder() {
    if (totalOrders >= MAX_ORDERS) {
        printf("Maximum orders reached.\n");
        return;
    }

    struct Order newOrder;

    printf("Enter table number: ");
    scanf("%d", &newOrder.tableNumber);

    printf("Enter client name: ");
    scanf("%s", newOrder.clientName);

    printf("Enter item ordered: ");
    scanf("%s", newOrder.item);

    printf("Enter payment method: ");
    scanf("%s", newOrder.paymentMethod);

    printf("Enter number of people: ");
    scanf("%d", &newOrder.numberOfPeople);

    orders[totalOrders++] = newOrder;
    printf("Order taken successfully.\n");
}

void displayOrders() {
    if (totalOrders == 0) {
        printf("No orders taken yet.\n");
        return;
    }

    printf("All orders:\n");
    printf("Table No.\tClient Name\t\tItem\t\tPayment Method\tNo. of People\n");
    for (int i = 0; i < totalOrders; ++i) {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\n", orders[i].tableNumber, orders[i].clientName,
               orders[i].item, orders[i].paymentMethod, orders[i].numberOfPeople);
    }
}

int main() {
    int choice;
    do {
        printf("\nRestaurant Order System\n");
        printf("1. Take an order\n");
        printf("2. Display all orders\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeOrder();
                break;
            case 2:
                displayOrders();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
