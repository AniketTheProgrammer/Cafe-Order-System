class Order:
    def __init__(self, table_number, client_name, item, payment_method, num_of_people):
        self.table_number = table_number
        self.client_name = client_name
        self.item = item
        self.payment_method = payment_method
        self.num_of_people = num_of_people

class RestaurantOrderSystem:
    def __init__(self):
        self.orders = []

    def take_order(self):
        table_number = int(input("Enter table number: "))
        client_name = input("Enter client name: ")
        item = input("Enter item ordered: ")
        payment_method = input("Enter payment method: ")
        num_of_people = int(input("Enter number of people: "))

        new_order = Order(table_number, client_name, item, payment_method, num_of_people)
        self.orders.append(new_order)
        print("Order taken successfully.")

    def display_orders(self):
        if not self.orders:
            print("No orders taken yet.")
            return
        print("\n")
        print("All orders:")


        print("Table No.\tClient Name\t\tItem\t\tPayment Method\tNo. of People")
        print("-----------------------------------------------------------------------------------------")
        for order in self.orders:
            print(f"{order.table_number}\t\t{order.client_name}\t\t\t{order.item}\t\t{order.payment_method}\t\t{order.num_of_people}")
            print("------------------------------------------------------------------------------------")

def main():
    order_system = RestaurantOrderSystem()
    choice = 0

    while choice != 3:
        print("\nRestaurant Order System")
        print("1. Take an order")
        print("2. Display all orders")
        print("3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            order_system.take_order()
        elif choice == 2:
            order_system.display_orders()
        elif choice == 3:
            print("Exiting...")
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
