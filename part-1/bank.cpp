#include "types.h"

// Constructor definition
Bank::Bank() : current_account(nullptr) {}

// login function definition
bool Bank::login(int id) {
    if (id < 0 || id >= MAX_ACCOUNTS) {
        return false;
    }

    // Create account if it doesn't exist
    if (!accounts[id].active) {
        accounts[id] = Account(id);
    }

    current_account = &accounts[id];
    return true;
}

// logout function definition
void Bank::logout() {
    current_account = nullptr;
}
