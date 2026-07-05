#include <iostream>
#include <string>

using namespace std;

// Structure for Branch
struct Branch {
    int ID;
    string Name;
    string Manager;
    Branch* next;

    Branch(int id, const string& name, const string& manager) : ID(id), Name(name), Manager(manager), next(nullptr) {}
};

// Structure for Account Holder
struct AccountHolder {
    int ID;
    string Name;
    string Address;
    double Balance;
    AccountHolder* next;

    AccountHolder(int id, const string& name, const string& address, double balance) : ID(id), Name(name), Address(address), Balance(balance), next(nullptr) {}
};

class BankManagement {

    Branch* branchesHead;
    AccountHolder* holdersHead;

public:
    BankManagement() : branchesHead(nullptr), holdersHead(nullptr) {}

    // Branch functions
    void addBranch() {
        int id;
        string name, manager;

        cout << "Enter Branch ID: ";
        cin >> id;
        cin.ignore();  // Ignore newline character left in the buffer
        cout << "Enter Branch Name: ";
        getline(cin, name);
        cout << "Enter Branch Manager: ";
        getline(cin, manager);

        Branch* newBranch = new Branch(id, name, manager);
        newBranch->next = branchesHead;
        branchesHead = newBranch;

        cout << "Branch added successfully." << endl;
    }

    void displayBranch() {
        Branch* current = branchesHead;
        while (current) {
            cout << "Branch ID: " << current->ID << ", Name: " << current->Name << ", Manager: " << current->Manager << endl;
            current = current->next;
        }
    }

    Branch* searchBranchByID(int id) {
        Branch* current = branchesHead;
        while (current) {
            if (current->ID == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Account Holder functions
    void addHolder() {
        int id;
        string name, address;
        double balance;

        cout << "Enter Holder ID: ";
        cin >> id;
        cin.ignore();  // Ignore newline character left in the buffer
        cout << "Enter Holder Name: ";
        getline(cin, name);
        cout << "Enter Holder Address: ";
        getline(cin, address);
        cout << "Enter Holder Balance: ";
        cin >> balance;

        AccountHolder* newHolder = new AccountHolder(id, name, address, balance);
        newHolder->next = holdersHead;
        holdersHead = newHolder;

        cout << "Account Holder added successfully." << endl;
    }

    void removeHolder(int id) {
        AccountHolder* current = holdersHead;
        AccountHolder* prev = nullptr;

        while (current && current->ID != id) {
            prev = current;
            current = current->next;
        }

        if (current) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                holdersHead = current->next;
            }
            delete current;
            cout << "Account Holder removed successfully." << endl;
        }
        else {
            cout << "Account Holder not found." << endl;
        }
    }

    void displayHolderData() {
        AccountHolder* current = holdersHead;
        while (current) {
            cout << "Holder ID: " << current->ID << ", Name: " << current->Name << ", Address: " << current->Address << ", Balance: " << current->Balance << endl;
            current = current->next;
        }
    }

    AccountHolder* searchHolderByName(const string& name) {
        AccountHolder* current = holdersHead;
        while (current) {
            if (current->Name == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void updateHolderInformation(int id, const string& newName, const string& newAddress, double newBalance) {
        AccountHolder* current = holdersHead;
        while (current) {
            if (current->ID == id) {
                current->Name = newName;
                current->Address = newAddress;
                current->Balance = newBalance;
                cout << "Account Holder information updated successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Account Holder not found." << endl;
    }
};

int main() {
    BankManagement bank;
    char choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add new branch\n";
        cout << "2. Display Branch\n";
        cout << "3. Search for Branch by ID\n";
        cout << "4. Add new holder\n";
        cout << "5. Remove a holder\n";
        cout << "6. Display holder data\n";
        cout << "7. Search for holder by Name\n";
        cout << "8. Update Holder Information\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            bank.addBranch();
            break;
        case '2':
            cout << "Branches:" << endl;
            bank.displayBranch();
            break;
        case '3': {
            int branchID;
            cout << "Enter Branch ID to search: ";
            cin >> branchID;
            Branch* foundBranch = bank.searchBranchByID(branchID);
            if (foundBranch) {
                cout << "Branch found - ID: " << foundBranch->ID << ", Name: " << foundBranch->Name << ", Manager: " << foundBranch->Manager << endl;
            }
            else {
                cout << "Branch not found." << endl;
            }
            break;
        }
        case '4':
            bank.addHolder();
            break;
        case '5': {
            int holderID;
            cout << "Enter Holder ID to remove: ";
            cin >> holderID;
            bank.removeHolder(holderID);
            break;
        }
        case '6':
            cout << "Account Holders:" << endl;
            bank.displayHolderData();
            break;
        case '7': {
            string holderName;
            cout << "Enter Holder Name to search: ";
            cin.ignore();  // Ignore newline character left in the buffer
            getline(cin, holderName);
            AccountHolder* foundHolder = bank.searchHolderByName(holderName);
            if (foundHolder) {
                cout << "Holder found - ID: " << foundHolder->ID << ", Name: " << foundHolder->Name << ", Address: " << foundHolder->Address << ", Balance: " << foundHolder->Balance << endl;
            }
            else {
                cout << "Holder not found." << endl;
            }
            break;
        }
        case '8': {
            int holderID;
            string newName, newAddress;
            double newBalance;

            cout << "Enter Holder ID to update: ";
            cin >> holderID;
            cout << "Enter new Holder Name: ";
            cin.ignore();  // Ignore newline character left in the buffer
            getline(cin, newName);
            cout << "Enter new Holder Address: ";
            getline(cin, newAddress);
            cout << "Enter new Holder Balance: ";
            cin >> newBalance;

            bank.updateHolderInformation(holderID, newName, newAddress, newBalance);
            break;
        }
        case '9':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '9');

    return 0;
}
