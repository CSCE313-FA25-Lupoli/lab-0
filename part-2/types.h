#ifndef TYPES_H
#define TYPES_H

#include <cstring>
#include <stdexcept>

const int MAX_ACCOUNTS = 10000000;
const int MAX_TRANSACTIONS = 2;

// Transaction structure
struct Transaction {
    int accountId;
    double amount;
    char* description;  // Task 4: Memory leak - no deallocation
};

// Account structure
class Account {
public:
    int id;
    double balance;
    bool active;
    Transaction* transactions;
    int transactionCount;
    
    Account() {
        id = -1;
        balance = 0;
        active = false;
        transactionCount = 0;
        transactions = nullptr;
    }
    
    Account(int i): id(i) {
        active = true;
        balance = 0;
        transactionCount = 0;
        // Task 1: Missing transactions array initialization
    }
    
    bool addTransaction(double amount, const char* desc) {
        // Task 3: Buffer overflow potential
        transactions[transactionCount].accountId = id;
        transactions[transactionCount].amount = amount;
        
        transactions[transactionCount].description = new char[strlen(desc) + 1];
        strcpy(transactions[transactionCount].description, desc);
        
        transactionCount++;
        return true;
    }

    ~Account() {
        // Task 4: Memory leak - no deallocation
    }

    Account(const Account& other) {
        id = other.id;
        balance = other.balance;
        active = other.active;
        transactionCount = other.transactionCount;
        // Task 1: Missing transactions array initialization
        transactions = nullptr;
    }

    Account& operator=(const Account& other) {
        if (this != &other) {
            delete[] transactions; 
            
            id = other.id;
            balance = other.balance;
            active = other.active;
            transactionCount = other.transactionCount;
            // Task 1: Missing transactions array initialization
            transactions = nullptr;
        }
        return *this;
    }
};

// Bank class declaration
class Bank {
private:
    Account* accounts;
    int accountCount;

public:
    Account* current_account;

    Bank();
    ~Bank();
    bool login(int id);
    void logout();
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // TYPES_H