#include <iostream>
#include <vector>
#include <limits> // for numeric_limits
using namespace std;

// Transaction structure to hold transaction details
struct Transaction {
    string type;
    double amount;
};

// Function declarations
void showMenu();
void processOption(int option, double& balance, vector<Transaction>& transactions);
void checkBalance(double balance, const vector<Transaction>& transactions);
void deposit(double& balance, vector<Transaction>& transactions);
void withdraw(double& balance, vector<Transaction>& transactions);
void showTransactionHistory(const vector<Transaction>& transactions);

int main()
{
    int option;
    double balance = 1000;
    vector<Transaction> transactions;

    // Main loop to display menu and process user input
    do {
        // Display menu
        showMenu();
        cout << "Option: ";

        // Handle invalid input (non-numeric or out-of-range)
        while (!(cin >> option) || option < 1 || option > 5) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 5: ";
        }

        system("cls"); // Clear screen

        // Process user's option
        processOption(option, balance, transactions);

    } while (option != 5); // Repeat until user selects Exit option

    system("pause>0"); // Pause console before exiting
}

// Function to display menu options
void showMenu()
{
    cout << "**********MENU**********" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. View transaction history" << endl;
    cout << "5. Exit" << endl;
    cout << "************************" << endl;
}

// Function to process user's option
void processOption(int option, double& balance, vector<Transaction>& transactions)
{
    switch (option)
    {
    case 1: // Check balance
        checkBalance(balance, transactions);
        break;
    case 2: // Deposit
        deposit(balance, transactions);
        break;
    case 3: // Withdraw
        withdraw(balance, transactions);
        break;
    case 4: // View transaction history
        showTransactionHistory(transactions);
        break;
    }
}

// Function to display current balance and transaction history
void checkBalance(double balance, const vector<Transaction>& transactions)
{
    cout << "Balance is: $" << balance << endl;
}

// Function to deposit money into account
void deposit(double& balance, vector<Transaction>& transactions)
{
    double depositAmount;
    cout << "Deposit amount: ";

    // Handle invalid input (non-numeric or negative)
    while (!(cin >> depositAmount) || depositAmount < 0) {
        cin.clear(); // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Please enter a non-negative number: ";
    }

    balance += depositAmount; // Add deposit amount to balance
    cout << "Deposit successful." << endl;

    // Add transaction to history
    transactions.push_back({ "Deposit", depositAmount });
}

// Function to withdraw money from account
void withdraw(double& balance, vector<Transaction>& transactions)
{
    double withdrawAmount;
    cout << "Withdraw amount: ";

    // Handle invalid input (non-numeric, negative, or insufficient balance)
    while (!(cin >> withdrawAmount) || withdrawAmount < 0 || withdrawAmount > balance) {
        cin.clear(); // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        if (withdrawAmount < 0)
            cout << "Invalid input. Please enter a non-negative number: ";
        else if (withdrawAmount > balance)
            cout << "Insufficient balance. Please enter a valid amount: ";
    }

    balance -= withdrawAmount; // Subtract withdraw amount from balance
    cout << "Withdrawal successful." << endl;

    // Add transaction to history
    transactions.push_back({ "Withdrawal", withdrawAmount });
}

// Function to display transaction history
void showTransactionHistory(const vector<Transaction>& transactions)
{
    cout << "Transaction History:" << endl;
    for (const auto& transaction : transactions) {
        cout << "Type: " << transaction.type << ", Amount: $" << transaction.amount << endl;
    }
}
