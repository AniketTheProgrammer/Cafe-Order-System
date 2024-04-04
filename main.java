import java.util.ArrayList;
import java.util.Scanner;

class Order {
    int tableNumber;
    String clientName;
    String item;
    String paymentMethod;
    int numberOfPeople;
}

public class RestaurantOrderSystem {
    private ArrayList<Order> orders = new ArrayList<>();

    public void takeOrder() {
        Scanner scanner = new Scanner(System.in);
        Order newOrder = new Order();

        System.out.print("Enter table number: ");
        newOrder.tableNumber = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        System.out.print("Enter client name: ");
        newOrder.clientName = scanner.nextLine();

        System.out.print("Enter item ordered: ");
        newOrder.item = scanner.nextLine();

        System.out.print("Enter payment method: ");
        newOrder.paymentMethod = scanner.nextLine();

        System.out.print("Enter number of people: ");
        newOrder.numberOfPeople = scanner.nextInt();

        orders.add(newOrder);
        System.out.println("Order taken successfully.");
    }

    public void displayOrders() {
        if (orders.isEmpty()) {
            System.out.println("No orders taken yet.");
            return;
        }

        System.out.println("All orders:");
        System.out.println("Table No.\tClient Name\t\tItem\t\tPayment Method\tNo. of People");
        for (Order order : orders) {
            System.out.println(order.tableNumber + "\t\t" + order.clientName + "\t\t" + order.item +
                    "\t\t" + order.paymentMethod + "\t\t" + order.numberOfPeople);
        }
    }

    public static void main(String[] args) {
        RestaurantOrderSystem orderSystem = new RestaurantOrderSystem();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nRestaurant Order System");
            System.out.println("1. Take an order");
            System.out.println("2. Display all orders");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    orderSystem.takeOrder();
                    break;
                case 2:
                    orderSystem.displayOrders();
                    break;
                case 3:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 3);
    }
}
