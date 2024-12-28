#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string accountHolderName;
    double balance;
};

vector<Account> accounts;
int nextAccountNumber = 1;

void createAccount() {
    Account acc;
    acc.accountNumber = nextAccountNumber++;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, acc.accountHolderName);
    acc.balance = 0.0;
    accounts.push_back(acc);
    cout << "Account created successfully with Account Number: " << acc.accountNumber << endl;
}

void displayAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found.\n";
        return;
    }
    for (const auto& acc : accounts) {
        cout << "Account Number: " << acc.accountNumber
            << ", Name: " << acc.accountHolderName
            << ", Balance: " << acc.balance << endl;
    }
}

Account* searchAccount(int accountNumber) {
    for (auto& acc : accounts) {
        if (acc.accountNumber == accountNumber) return &acc;
    }
    return nullptr;
}

void deposit() {
    int accountNumber;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    Account* acc = searchAccount(accountNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        acc->balance += amount;
        cout << "Amount deposited successfully. New Balance: " << acc->balance << endl;
    }
    else {
        cout << "Invalid amount.\n";
    }
}

void withdraw() {
    int accountNumber;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    Account* acc = searchAccount(accountNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && acc->balance >= amount) {
        acc->balance -= amount;
        cout << "Amount withdrawn successfully. New Balance: " << acc->balance << endl;
    }
    else {
        cout << "Invalid amount or insufficient balance.\n";
    }
}

void updateAccount() {
    int accountNumber;
    cout << "Enter Account Number to update: ";
    cin >> accountNumber;
    Account* acc = searchAccount(accountNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Enter new Account Holder Name: ";
    cin.ignore();
    getline(cin, acc->accountHolderName);
    cout << "Account updated successfully.\n";
}

void deleteAccount() {
    int accountNumber;
    cout << "Enter Account Number to delete: ";
    cin >> accountNumber;
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->accountNumber == accountNumber) {
            accounts.erase(it);
            cout << "Account deleted successfully.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void transferMoney() {
    int fromAccount, toAccount;
    double amount;
    cout << "Enter Source Account Number: ";
    cin >> fromAccount;
    cout << "Enter Destination Account Number: ";
    cin >> toAccount;
    cout << "Enter amount to transfer: ";
    cin >> amount;
    Account* fromAcc = searchAccount(fromAccount);
    Account* toAcc = searchAccount(toAccount);
    if (!fromAcc || !toAcc) {
        cout << "Invalid account details.\n";
        return;
    }
    if (amount > 0 && fromAcc->balance >= amount) {
        fromAcc->balance -= amount;
        toAcc->balance += amount;
        cout << "Transfer successful.\n";
    }
    else {
        cout << "Invalid amount or insufficient balance.\n";
    }
}

void checkBalance() {
    int accountNumber;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    Account* acc = searchAccount(accountNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Current Balance: " << acc->balance << endl;
}

void viewAccountHolderName() {
    int accountNumber;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    Account* acc = searchAccount(accountNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Account Holder Name: " << acc->accountHolderName << endl;
}

void viewAccountNumber() {
    string name;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);
    for (const auto& acc : accounts) {
        if (acc.accountHolderName == name) {
            cout << "Account Number: " << acc.accountNumber << endl;
            return;
        }
    }
    cout << "Account not found.\n";
}

void depositInterest() {
    double interestRate;
    cout << "Enter interest rate (in %): ";
    cin >> interestRate;
    for (auto& acc : accounts) {
        acc.balance += acc.balance * (interestRate / 100);
    }
    cout << "Interest deposited successfully.\n";
}

void accountSummary() {
    displayAccounts();
}

void viewAllAccountNumbers() {
    if (accounts.empty()) {
        cout << "No accounts found.\n";
        return;
    }
    for (const auto& acc : accounts) {
        cout << "Account Number: " << acc.accountNumber << endl;
    }
}

void totalBankBalance() {
    double total = 0;
    for (const auto& acc : accounts) {
        total += acc.balance;
    }
    cout << "Total Bank Balance: " << total << endl;
}

int main() {
    int choice;
    do {
        cout << "\nBanking Management System\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Search Account\n";
        cout << "6. Update Account\n";
        cout << "7. Delete Account\n";
        cout << "8. Transfer Money\n";
        cout << "9. Check Balance\n";
        cout << "10. View Account Holder Name\n";
        cout << "11. View Account Number\n";
        cout << "12. Deposit Interest\n";
        cout << "13. Account Summary\n";
        cout << "14. View All Account Numbers\n";
        cout << "15. Total Bank Balance\n";
        cout << "16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createAccount(); break;
        case 2: displayAccounts(); break;
        case 3: deposit(); break;
        case 4: withdraw(); break;
        case 5: {
            int accountNumber;
            cout << "Enter Account Number to search: ";
            cin >> accountNumber;
            Account* acc = searchAccount(accountNumber);
            if (acc) cout << "Account found. Name: " << acc->accountHolderName << ", Balance: " << acc->balance << endl;
            else cout << "Account not found.\n";
            break;
        }
        case 6: updateAccount(); break;
        case 7: deleteAccount(); break;
        case 8: transferMoney(); break;
        case 9: checkBalance(); break;
        case 10: viewAccountHolderName(); break;
        case 11: viewAccountNumber(); break;
        case 12: depositInterest(); break;
        case 13: accountSummary(); break;
        case 14: viewAllAccountNumbers(); break;
        case 15: totalBankBalance(); break;
        case 16: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 16);

    return 0;
}
