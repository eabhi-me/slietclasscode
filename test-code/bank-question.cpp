#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string depositorName;
    int accountNumber;
    double balanceAmount;

public:
    // Constructor to initialize data members with default balance value
    BankAccount(string name, int accNo, double balance = 0.0) {
        depositorName = name;
        accountNumber = accNo;
        balanceAmount = balance;
    }

    // Function to deposit money
    void depositMoney(double amount) {
        if (amount > 0) {
            balanceAmount += amount;
            cout << "Amount deposited successfully. Current balance: " << balanceAmount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdrawMoney(double amount) {
        if (amount > 0 && amount <= balanceAmount) {
            balanceAmount -= amount;
            cout << "Amount withdrawn successfully. Current balance: " << balanceAmount << endl;
        } else if (amount > balanceAmount) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Function to display account details and balance
    void displayAccountDetails() const {
        cout << "Depositor Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance Amount: " << balanceAmount << endl;
    }
};

int main() {
    // Creating a BankAccount object
    BankAccount account("John Doe", 12345678, 500.0);

    // Display initial details
    account.displayAccountDetails();

    // Deposit money
    account.depositMoney(300.0);

    // Withdraw money
    account.withdrawMoney(200.0);

    // Display updated details
    account.displayAccountDetails();

    return 0;
}
