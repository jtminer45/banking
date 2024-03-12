#include <iostream>
#include <random>
#include <map>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    long accountNumber; 
    double balance;

public:
    // Constructor for class of bank account
    BankAccount(const string& name, double initialBalance)
        : accountHolderName(name), balance(initialBalance) {
        // Generate a 10-digit random account number
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<long> distribution(1000000000, 9999999999);
        accountNumber = distribution(gen);
    }

    // for depositing
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    //for withdrawing

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    //function for displaying info of person in bank

    void displayInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    // Create a bank account with an initial balance
    BankAccount myAccount("pula", 1000.0);

    // Perform transactions
    myAccount.deposit(500.89);
    myAccount.withdraw(278.77);

    // Display account information
    myAccount.displayInfo();

    return 0;
}

