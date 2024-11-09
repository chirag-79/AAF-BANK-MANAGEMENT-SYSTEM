#include <iostream>
#include <string>
using namespace std;

class Bank {
    string name, address;
    char acc_type;
    float balance;

public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
    void loan_requirement();  
};

// Function to open the account
void Bank::open_account() {
    cout << "Enter your full name: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "What type of account you want to open saving(S) or Current(C): ";
    cin >> acc_type;
    cout << "Enter the amount you want to deposit: ";
    cin >> balance;
    cout << "Account Created Successfully\n";
}

// Function to deposit money into the account
void Bank::deposit_money() {
    float amount;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    balance += amount;
    cout << "\nAvailable Balance: " << balance << endl;
}

// Function to withdraw money from the account
void Bank::withdraw_money() {
    float amount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance!\n";
    } else {
        balance -= amount;
        cout << "\nAvailable Balance: " << balance << endl;
    }
}

// Function to display account details
void Bank::display_account() {
    cout << "\nAccount Details:\n";
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Account Type: " << acc_type << endl;
    cout << "Balance: " << balance << endl;
}

// Function to handle loan requirements with additional checks
void Bank::loan_requirement() {
    float loan_amount;
    char has_documents;

    cout << "Enter the loan amount you require (maximum 10 lakh): ";
    cin >> loan_amount;

    if (loan_amount > 1000000) {
        cout << "Loan request exceeds maximum limit of 10 lakh.\n";
        return;
    }

    cout << "Do you have house documents as proof? (Y/N): ";
    cin >> has_documents;

    // Check eligibility based on balance, loan amount, and document proof
    if (balance >= 5000 && (has_documents == 'Y' || has_documents == 'y')) {
        cout << "Loan Approved for amount: " << loan_amount << endl;
    } else if (balance < 5000) {
        cout << "Loan not approved. Minimum balance of 5000 required for loan eligibility.\n";
    } else {
        cout << "Loan not approved. House documents are required for loan approval.\n";
    }
}

int main() {
    Bank customer;
    int choice;
    cout << "HELLO CUSTOMER! WELCOME TO MY SONA CHANDI BANK\n";
    do {
        cout << "\nBank Management System\n";
        cout << "1) Open account\n";
        cout << "2) Deposit money\n";
        cout << "3) Withdraw money\n";
        cout << "4) Display account\n";
        cout << "5) Loan requirement\n"; 
        cout << "6) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                customer.open_account();
                break;
            case 2:
                customer.deposit_money();
                break;
            case 3:
                customer.withdraw_money();
                break;
            case 4:
                customer.display_account();
                break;
            case 5:
                customer.loan_requirement();
                break;
            case 6:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
