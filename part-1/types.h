#ifndef _TYPES_H_
#define _TYPES_H_

const int MAX_ACCOUNTS = 10;

// Simple account structure to store balance
struct Account {
    int id;
    double balance;
    bool active;
    
    Account(): id(-1), balance(0), active(false) {}
    Account(int i): id(i), balance(0), active(true) {}
};

// Simple bank class to handle basic operations
class Bank {
public:
    Account accounts[MAX_ACCOUNTS];
    Account* current_account;

    Bank();  // Constructor declaration
    bool login(int id);  // Function declaration
    void logout();       // Function declaration
};

#endif
