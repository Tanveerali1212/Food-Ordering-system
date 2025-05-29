#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ITEMS = 10;

string menuItems[MAX_ITEMS] = { "Burger", "Pizza", "Pasta" };
int prices[MAX_ITEMS] = { 500, 800, 600 };
int menuSize = 3;

int orderQuantities[MAX_ITEMS] = { 0 };

void displayMenu() {
    cout << endl << "========== WELCOME TO FOODIES ==========" << endl;
    cout << "               MENU                    " << endl;
    cout << "========================================" << endl;
    cout << left << setw(5) << "No." << setw(20) << "Item" << setw(10) << "Price (PKR)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < menuSize; i++) {
        cout << left << setw(5) << i + 1
            << setw(20) << menuItems[i]
            << setw(10) << prices[i] << endl;
    }
    cout << "========================================" << endl;
}

void manageMenu() {
    int choice;
    do {
        cout << endl << "========== ADMIN MENU MANAGEMENT ==========" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Update Item" << endl;
        cout << "3. Remove Item" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Please enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (menuSize < MAX_ITEMS) {
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, menuItems[menuSize]);
                cout << "Enter item price (PKR): ";
                cin >> prices[menuSize];
                menuSize++;
                cout << "Item added successfully." << endl;
            }
            else {
                cout << "Menu is full!" << endl;
            }
        }
        else if (choice == 2) {
            displayMenu();
            cout << "Enter item number to update: ";
            int itemNo;
            cin >> itemNo;
            if (itemNo > 0 && itemNo <= menuSize) {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, menuItems[itemNo - 1]);
                cout << "Enter new price (PKR): ";
                cin >> prices[itemNo - 1];
                cout << "Item updated successfully." << endl;
            }
            else {
                cout << "Invalid item number." << endl;
            }
        }
        else if (choice == 3) {
            displayMenu();
            cout << "Enter item number to remove: ";
            int itemNo;
            cin >> itemNo;
            if (itemNo > 0 && itemNo <= menuSize) {
                for (int i = itemNo - 1; i < menuSize - 1; i++) {
                    menuItems[i] = menuItems[i + 1];
                    prices[i] = prices[i + 1];
                }
                menuSize--;
                cout << "Item removed successfully." << endl;
            }
            else {
                cout << "Invalid item number." << endl;
            }
        }
    } while (choice != 0);
}

void takeOrder() {
    int choice, quantity;
    do {
        displayMenu();
        cout << endl << "Enter item number to order (0 to finish): ";
        cin >> choice;

        if (choice > 0 && choice <= menuSize) {
            cout << "Enter quantity for " << menuItems[choice - 1] << ": ";
            cin >> quantity;
            orderQuantities[choice - 1] += quantity;
        }
        else if (choice != 0) {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}

void displayOrderSummary() {
    int total = 0;
    cout << endl << "==========================================" << endl;
    cout << "                ORDER RECEIPT             " << endl;
    cout << "==========================================" << endl;
    cout << left << setw(5) << "No."
        << setw(20) << "Item"
        << setw(10) << "Qty"
        << setw(15) << "Total (PKR)" << endl;
    cout << "==========================================" << endl;

    for (int i = 0; i < menuSize; i++) {
        if (orderQuantities[i] > 0) {
            int itemTotal = orderQuantities[i] * prices[i];
            cout << left << setw(5) << i + 1
                << setw(20) << menuItems[i]
                << setw(10) << orderQuantities[i]
                << setw(15) << itemTotal << endl;
            total += itemTotal;
        }
    }
    cout << "==========================================" << endl;
    cout << right << setw(30) << "Total Bill: " << setw(10) << "PKR " << total << endl;
    cout << "==========================================" << endl;
}

bool validatePayment() {
    string payment;
    cout << endl << "=== Payment ===" << endl;
    cout << "Enter yes to confirm payment: ";
    cin >> payment;
    if (payment == "yes") {
        cout << endl << "==========================================" << endl;
        cout << "        PAYMENT CONFIRMED! THANK YOU      " << endl;
        cout << "==========================================" << endl;
        return true;
    }
    else {
        cout << endl << "Payment not confirmed. Order cancelled." << endl;
        return false;
    }
}

int main() {
    int choice;
    cout << "==========================================" << endl;
    cout << "  WELCOME TO THE FOODIES " << endl;
    cout << "==========================================" << endl;
    do {
        cout << endl << "=== Main Menu ===" << endl;
        cout << "1. View Menu" << endl;
        cout << "2. Place Order" << endl;
        cout << "3. Admin Menu Management" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Please enter choice: ";
        cin >> choice;

        if (choice == 1) {
            displayMenu();
        }
        else if (choice == 2) {
            takeOrder();
            displayOrderSummary();
            if (validatePayment()) {
                cout << endl << "Order placed successfully!" << endl;
            }
            for (int i = 0; i < menuSize; i++) {
                orderQuantities[i] = 0;
            }
        }
        else if (choice == 3) {
            manageMenu();
        }
        else if (choice != 0) {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    cout << "Have a good day as our food !" << endl;
    return 0;
}
