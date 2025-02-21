#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, string accName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = accName;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    int accNum;
    string accName;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter account holder name: ";
    cin >> accName;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(accNum, accName, initialBalance);

    char choice;
    double amount;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case '2':
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case '3':
                account.display();
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if (choice != '4') {
            cout << "Do you want to continue? (y/n): ";
            cin >> choice;
        }

    } while (choice == 'y');

    return 0;
}
