#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Bakery {
private:
    char item[30];
    int price;
    int quantity;

public:
    void InsertItem() {
        cout << "Enter item Name: ";
        cin.ignore();  // To clear the newline character from the buffer
        cin.getline(item, sizeof(item));
        cout << "Enter Item price: ";
        cin >> price;
        cout << "Enter Item quantity: ";
        cin >> quantity;
    }

    void DisplayItem() const {
        cout << setw(30) << left << item << setw(10) << price << setw(10) << quantity << endl;
    }

    void DisplayPrice() const {
        cout << setw(30) << left << item << setw(10) << price << endl;
    }

    void DisplayQuantity() const {
        cout << setw(30) << left << item << setw(10) << quantity << endl;
    }

    const char* GetItem() const {
        return item;
    }
};

int main() {
    Bakery items[10];
    int itemCount = 0;

    cout << "***************** Welcome to Unique Bakery ****************\n";
    int choice;

    do {
        cout << "\n1. Insert item\n2. Delete item\n3. Display items\n4. Display prices\n5. Display quantities\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (itemCount < 10) {
                items[itemCount].InsertItem();
                itemCount++;
            } else {
                cout << "\nBakery is full. Cannot insert more items.\n";
            }
            break;

        case 2: {
            if (itemCount == 0) {
                cout << "\nNo items to delete.\n";
                break;
            }

            int itemNum;
            cout << "Enter item number to delete (1 to " << itemCount << "): ";
            cin >> itemNum;

            if (itemNum < 1 || itemNum > itemCount) {
                cout << "\nInvalid item number.\n";
                break;
            }

            for (int i = itemNum - 1; i < itemCount - 1; i++) {
                items[i] = items[i + 1];
            }
            itemCount--;
            cout << "\nItem with item number " << itemNum << " is deleted.\n";
            break;
        }

        case 3:
            if (itemCount > 0) {
                cout << setw(30) << left << "Item" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
                for (int i = 0; i < itemCount; i++) {
                    items[i].DisplayItem();
                }
            } else {
                cout << "\nNo items to display.\n";
            }
            break;

        case 4:
            if (itemCount > 0) {
                cout << setw(30) << left << "Item" << setw(10) << "Price" << endl;
                for (int i = 0; i < itemCount; i++) {
                    items[i].DisplayPrice();
                }
            } else {
                cout << "\nNo items to display.\n";
            }
            break;

        case 5:
            if (itemCount > 0) {
                cout << setw(30) << left << "Item" << setw(10) << "Quantity" << endl;
                for (int i = 0; i < itemCount; i++) {
                    items[i].DisplayQuantity();
                }
            } else {
                cout << "\nNo items to display.\n";
            }
            break;

        case 6:
            cout << "\nTHANK YOU\nGoodbye!\n";
            break;

        default:
            cout << "\nINVALID CHOICE\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
