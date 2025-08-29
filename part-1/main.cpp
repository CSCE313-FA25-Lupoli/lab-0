/******************************************************************************
 * File: main.cpp
 * 
 * Object-Oriented Financial System
 * Implementation of a financial system
 * 
 * CSCE 313: Intro to Computer Systems
 * Spring 2025
 *****************************************************************************/

#include "types.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void print_menu() {
    std::cout << "\n=== Banking System Menu ===\n"
              << "1. Login\n"
              << "2. Deposit\n"
              << "3. Withdraw\n"
              << "4. View Balance\n"
              << "5. Upload File\n"
              << "6. Download File\n"
              << "7. Logout\n"
              << "0. Exit\n"
              << "Enter choice: ";
}

int main() {
    Bank bank;
    bool running = true;
    
    while (running) {
        print_menu();
        
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        try {
            switch (choice) {
                case 0: {  // Exit
                    running = false;
                    break;
                }
                
                case 1: {  // Login
                    if (bank.current_account) {
                        std::cout << "Already logged in! Please logout first.\n";
                        break;
                    }
                    
                    int id;
                    std::cout << "Enter user ID: ";
                    std::cin >> id;
                    
                    if (bank.login(id)) {
                        std::cout << "Logged in as user " << id << std::endl;
                    } else {
                        std::cout << "Login failed\n";
                    }
                    break;
                }
                
                case 2: {  // Deposit
                    if (!bank.current_account) {
                        std::cout << "Please login first!\n";
                        break;
                    }
                    
                    double amount;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    
                    if (amount > 0) {
                        bank.current_account->balance += amount;
                        std::cout << "Deposit successful. New balance: " << bank.current_account->balance << std::endl;
                    } else {
                        std::cout << "Invalid amount\n";
                    }
                    break;
                }
                
                case 3: {  // Withdraw
                    if (!bank.current_account) {
                        std::cout << "Please login first!\n";
                        break;
                    }
                    
                    double amount;
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    
                    if (amount > 0 && amount <= bank.current_account->balance) {
                        bank.current_account->balance -= amount;
                        std::cout << "Withdrawal successful. New balance: " << bank.current_account->balance << std::endl;
                    } else {
                        std::cout << "Invalid amount or insufficient funds\n";
                    }
                    break;
                }
                
                case 4: {  // View Balance
                    if (!bank.current_account) {
                        std::cout << "Please login first!\n";
                        break;
                    }
                    
                    std::cout << "Current balance: " << bank.current_account->balance << std::endl;
                    break;
                }
                
                case 5: {  // Upload File
                    if (!bank.current_account) {
                        std::cout << "Please login first!\n";
                        break;
                    }
                    
                    std::string filename;
                    std::cout << "Enter filename to upload: ";
                    std::getline(std::cin, filename);
                    
                    std::ifstream infile(filename);
                    if (!infile) {
                        std::cout << "Error: Could not open file\n";
                        break;
                    }
                    
                    std::string content;
                    std::getline(infile, content);
                    std::cout << "File uploaded successfully\n";
                    break;
                }
                
                case 6: {  // Download File
                    if (!bank.current_account) {
                        std::cout << "Please login first!\n";
                        break;
                    }
                    
                    std::string filename;
                    std::cout << "Enter filename to download: ";
                    std::getline(std::cin, filename);
                    
                    std::ofstream outfile(filename);
                    if (!outfile) {
                        std::cout << "Error: Could not create file\n";
                        break;
                    }
                    
                    std::cout << "File downloaded successfully\n";
                    break;
                }
                
                case 7: {  // Logout
                    if (!bank.current_account) {
                        std::cout << "Not logged in!\n";
                        break;
                    }
                    
                    bank.logout();
                    std::cout << "Logged out successfully\n";
                    break;
                }
                
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    
    return 0;
}