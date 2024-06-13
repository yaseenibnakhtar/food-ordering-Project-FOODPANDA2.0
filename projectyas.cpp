#include <iostream>
#include <string>

using namespace std;

// Structure to represent each menu item
struct MenuItem {
    string itemName;
    double itemPrice;
    MenuItem* next;

    MenuItem(const string& name, double price) : itemName(name), itemPrice(price), next(nullptr) {}
};

// Structure to represent an order
struct Order {
    string itemName;
    double itemPrice;
    Order* next;

    Order(const string& name, double price) : itemName(name), itemPrice(price), next(nullptr) {}
};

// Class for Restaurant Management on Online food delivery
class RestaurantManagement {
private:
    MenuItem* menuHead;
    Order* orderHead;
    double totalBill;

public:
    RestaurantManagement() : menuHead(nullptr), orderHead(nullptr), totalBill(0.0) {}

    // Function to add menu items to the menu
    void addMenuItem(const string& name, double price) {
        MenuItem* newItem = new MenuItem(name, price);
        if (menuHead == nullptr) {
            menuHead = newItem;
        } else {
            MenuItem* temp = menuHead;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newItem;
        }
    }

    // Function to display the menu
    void displayMenu() const {
        if (menuHead == nullptr) {
            cout << "Menu is empty.\n";
            return;
        }
        cout << "Menu:\n";
        MenuItem* temp = menuHead;
        while (temp != nullptr) {
            cout << temp->itemName << " - Pkr" << temp->itemPrice << endl;
            temp = temp->next;
        }
    }

    // Function to place an order
    void placeOrder(const string& itemName) {
        MenuItem* temp = menuHead;
        while (temp != nullptr) {
            if (temp->itemName == itemName) {
                Order* newOrder = new Order(itemName, temp->itemPrice);
                if (orderHead == nullptr) {
                    orderHead = newOrder;
                } else {
                    newOrder->next = orderHead;
                    orderHead = newOrder;
                }
                totalBill += temp->itemPrice;
                cout << "Order placed successfully: " << itemName << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found in the menu.\n";
    }

    // Function to display the order and total bill
    void displayOrder() const {
        if (orderHead == nullptr) {
            cout << "No orders placed yet.\n";
            return;
        }
        cout << "Current Order:\n";
        Order* temp = orderHead;
        while (temp != nullptr) {
            cout << temp->itemName << " - Pkr" << temp->itemPrice << endl;
            temp = temp->next;
        }
        cout << "Total Bill: Pkr" << totalBill << endl;
    }

    ~RestaurantManagement() {
        // Deleting all menu items
        MenuItem* tempMenuItem;
        while (menuHead != nullptr) {
            tempMenuItem = menuHead;
            menuHead = menuHead->next;
            delete tempMenuItem;
        }

        // Deleting all orders
        Order* tempOrder;
        while (orderHead != nullptr) {
            tempOrder = orderHead;
            orderHead = orderHead->next;
            delete tempOrder;
        }
    }
};

int main() {
    RestaurantManagement restaurant;

    // Adding sample menu items
    restaurant.addMenuItem("Burger", 599);
    restaurant.addMenuItem("Pizza", 1199);
    restaurant.addMenuItem("Pasta", 750);
    restaurant.addMenuItem("Salad", 449);

    int choice;
    string itemName;

    cout << "\n                            FOOD PANDO 2.0               \n";
    cout << "\n                        Welcome to Fast Food Hub                 \n";

    do {
        cout << "1. Display Menu and Place Order\n";
        cout << "2. Add more items to the cart\n";
		cout << "3. Display Current Order and Total Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                restaurant.displayMenu();
                cout << "Enter the item name to order: ";
                cin >> itemName;
                restaurant.placeOrder(itemName);
                break;
			case 2:
				restaurant.displayOrder();
                restaurant.displayMenu();
                cout << "Enter the item name to order: ";
                cin >> itemName;
                restaurant.placeOrder(itemName);
                break;
            case 3:
                restaurant.displayOrder();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
