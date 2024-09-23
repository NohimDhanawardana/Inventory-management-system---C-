#include <iostream>
#include <string>
#include <vector>

#define MAX_ITEMS 100

class InventoryItem {
public:
    int id;
    std::string name;
    int quantity;
    float price;

    InventoryItem(int id, std::string name, int quantity, float price)
        : id(id), name(name), quantity(quantity), price(price) {}
};

std::vector<InventoryItem> inventory;

void addItem();
void viewItems();
void updateItem();
void deleteItem();
int findItemById(int id);

int main() {
    int choice;

    while (true) {
        std::cout << "\nInventory Management System\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. View Items\n";
        std::cout << "3. Update Item\n";
        std::cout << "4. Delete Item\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number.\n";
            // Clear the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

void addItem() {
    if (inventory.size() >= MAX_ITEMS) {
        std::cout << "Inventory is full!\n";
        return;
    }

    int id;
    std::string name;
    int quantity;
    float price;

    std::cout << "Enter item ID: ";
    if (!(std::cin >> id)) {
        std::cout << "Invalid input! Please enter a number.\n";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(); // To ignore the leftover newline character from previous input
    std::cout << "Enter item name: ";
    std::getline(std::cin, name);
    std::cout << "Enter item quantity: ";
    if (!(std::cin >> quantity)) {
        std::cout << "Invalid input! Please enter a number.\n";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << "Enter item price: ";
    if (!(std::cin >> price)) {
        std::cout << "Invalid input! Please enter a number.\n";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    inventory.emplace_back(id, name, quantity, price);
    std::cout << "Item added successfully!\n";
}

void viewItems() {
    if (inventory.empty()) {
        std::cout << "No items in the inventory.\n";
        return;
    }

    std::cout << "\nInventory Items:\n";
    for (const auto& item : inventory) {
        std::cout << "ID: " << item.id << ", Name: " << item.name
                  << ", Quantity: " << item.quantity << ", Price: " << item.price << "\n";
    }
}

void updateItem() {
    int id, quantity;
    float price;

    std::cout << "Enter item ID to update: ";
    if (!(std::cin >> id)) {
        std::cout << "Invalid input! Please enter a number.\n";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    int index = findItemById(id);
    if (index == -1) {
        std::cout << "Item not found!\n";
        return;
    }

    std::cout << "Enter new quantity: ";
    if (!(std::cin >> quantity)) {
        std::cout << "Invalid input! Please enter a number.\n";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << "Enter new price: ";
    if (!(std::cin >> price)) {
        std::cout << "Invalid input! Please enter a number.\n";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    inventory[index].quantity = quantity;
    inventory[index].price = price;
    std::cout << "Item updated successfully!\n";
}

void deleteItem() {
    int id;

    std::cout << "Enter item ID to delete: ";
    if (!(std::cin >> id)) {
        std::cout << "Invalid input! Please enter a number.\n";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    int index = findItemById(id);
    if (index == -1) {
        std::cout << "Item not found!\n";
        return;
    }

    inventory.erase(inventory.begin() + index);
    std::cout << "Item deleted successfully!\n";
}

int findItemById(int id) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}
