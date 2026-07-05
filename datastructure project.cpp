#include <iostream>
#include <string>

using namespace std;

// Node structure for linked lists
struct Node {
    int id;
    string name;
    string address;  // Added address for account holders
    double balance;  // Added balance for account holders
    Node* next;
};

// Function prototypes
void addBranch(Node*& head, int id, const string& name);
void displayBranch(Node* head);
Node* searchBranchById(Node* head, int id);
void removeBranch(Node*& head, int id);

void addHolder(Node*& head, int id, const string& name, const string& address, double balance);
void displayHolder(Node* head);
Node* searchHolderByName(Node* head, const string& name);
void removeHolder(Node*& head, int id);
void updateHolderInfo(Node* head, int id);

// Function to display success message
void displaySuccessMessage(const string& processName);

int main() {
    // Dummy data for demonstration
    Node* branchList = nullptr;  // Linked list for branches
    Node* holderList = nullptr;  // Linked list for account holders

    // Password input
    int password;
        cout << "Welcome to Bank Management System\n";
    do {
        
        cout << "Enter password (1 for employee, 2 for manager, 0 to exit): ";
        cin >> password;

        if (password == 1) {
            // Employee functionalities
            int empChoice;
            do {
                // Employee menu
                cout << "\nEmployee Menu:\n";
                cout << "1. Add new holder\n";
                cout << "2. Remove a holder\n";
                cout << "3. Display holder data\n";
                cout << "4. Search for holder by Name\n";
                cout << "5. Update Holder Information\n";
                cout << "0. return to login\n";
                cout << "Enter your choice: ";
                cin >> empChoice;

                switch (empChoice) {
                case 1: {
                    int id;
                    string name, address;
                    double balance;
                    cout << "Enter holder ID: ";
                    cin >> id;
                    cout << "Enter holder name: ";
                    cin.ignore(); // Clear buffer
                    getline(cin, name);
                    cout << "Enter holder address: ";
                    getline(cin, address);
                    cout << "Enter holder balance: ";
                    cin >> balance;
                    addHolder(holderList, id, name, address, balance);
                    displaySuccessMessage("Add Holder");
                    break;
                }
                case 2: {
                    int id;
                    cout << "Enter holder ID to remove: ";
                    cin >> id;
                    removeHolder(holderList, id);
                    displaySuccessMessage("Remove Holder");
                    break;
                }
                case 3:
                    displayHolder(holderList);
                    break;
                case 4: {
                    string name;
                    cout << "Enter holder name to search: ";
                    cin.ignore(); // Clear buffer
                    getline(cin, name);
                    Node* result = searchHolderByName(holderList, name);
                    if (result != nullptr) {
                        cout << "Holder found: " << result->name << endl;
                    }
                    else {
                        cout << "Holder not found.\n";
                    }
                    break;
                }
                case 5: {
                    int id;
                    cout << "Enter holder ID to update information: ";
                    cin >> id;
                    updateHolderInfo(holderList, id);
                    displaySuccessMessage("Update Holder Information");
                    break;
                }
                case 0:
                    cout << "Exiting employee menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                }
            } while (empChoice != 0);
        }
        else if (password == 2) {
            // Manager functionalities
            int mgrChoice;
            do {
                // Manager menu
                cout << "\nManager Menu:\n";
                cout << "1. Add new branch\n";
                cout << "2. Display Branch\n";
                cout << "3. Search for Branch by ID\n";
                cout << "4. Remove Branch\n";
                cout << "0. return to login\n";
                cout << "Enter your choice: ";
                cin >> mgrChoice;

                switch (mgrChoice) {
                case 1: {
                    int id;
                    string name;
                    cout << "Enter branch ID: ";
                    cin >> id;
                    cout << "Enter branch name: ";
                    cin.ignore(); // Clear buffer
                    getline(cin, name);
                    addBranch(branchList, id, name);
                    displaySuccessMessage("Add Branch");
                    break;
                }
                case 2:
                    displayBranch(branchList);
                    break;
                case 3: {
                    int id;
                    cout << "Enter branch ID to search: ";
                    cin >> id;
                    Node* result = searchBranchById(branchList, id);
                    if (result != nullptr) {
                        cout << "Branch found: " << result->name << endl;
                    }
                    else {
                        cout << "Branch not found.\n";
                    }
                    break;
                }
                case 4: {
                    int id;
                    cout << "Enter branch ID to remove: ";
                    cin >> id;
                    removeBranch(branchList, id);
                    displaySuccessMessage("Remove Branch");
                    break;
                }
                case 0:
                    cout << "Exiting manager menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                }
            } while (mgrChoice != 0);
        }
        else if (password != 0) {
            cout << "Your password is wrong. Try again.\n";
        }
    } while (password != 0);

    // Clean up linked lists (free memory)
    Node* currentBranch = branchList;
    while (currentBranch != nullptr) {
        Node* nextBranch = currentBranch->next;
        delete currentBranch;
        currentBranch = nextBranch;
    }

    Node* currentHolder = holderList;
    while (currentHolder != nullptr) {
        Node* nextHolder = currentHolder->next;
        delete currentHolder;
        currentHolder = nextHolder;
    }

    return 0;
}

// Functions for Branches
void addBranch(Node*& head, int id, const string& name) {
    Node* newNode = new Node{ id, name, "", 0.0, nullptr };
    newNode->next = head;
    head = newNode;
}

void displayBranch(Node* head) {
    cout << "Branches:\n";
    while (head != nullptr) {
        cout << "ID: " << head->id << ", Name: " << head->name << endl;
        head = head->next;
    }
}

Node* searchBranchById(Node* head, int id) {
    while (head != nullptr) {
        if (head->id == id) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

void removeBranch(Node*& head, int id) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev == nullptr) {
            // Node to be removed is the head
            head = current->next;
        }
        else {
            prev->next = current->next;
        }

        delete current; // Free memory
        cout << "Branch removed.\n";
    }
    else {
        cout << "Branch not found.\n";
    }
}

// Functions for Account Holders
void addHolder(Node*& head, int id, const string& name, const string& address, double balance) {
    Node* newNode = new Node{ id, name, address, balance, nullptr };
    newNode->next = head;
    head = newNode;
}

void displayHolder(Node* head) {
    cout << "Account Holders:\n";
    while (head != nullptr) {
        cout << "ID: " << head->id << ", Name: " << head->name << ", Address: " << head->address << ", Balance: " << head->balance << endl;
        head = head->next;
    }
}

Node* searchHolderByName(Node* head, const string& name) {
    while (head != nullptr) {
        if (head->name == name) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

void removeHolder(Node*& head, int id) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev == nullptr) {
            // Node to be removed is the head
            head = current->next;
        }
        else {
            prev->next = current->next;
        }

        delete current; // Free memory
        cout << "Holder removed.\n";
    }
    else {
        cout << "Holder not found.\n";
    }
}

void updateHolderInfo(Node* head, int id) {
    while (head != nullptr) {
        if (head->id == id) {
            // Update information (for simplicity, let's just update the balance)
            cout << "Enter new balance for holder " << id << ": ";
            cin >> head->balance;
            cout << "Holder information updated.\n";
            return;
        }
        head = head->next;
    }
    cout << "Holder not found.\n";
}

void displaySuccessMessage(const string& processName) {
    cout << processName << " was completed successfully.\n";
}
