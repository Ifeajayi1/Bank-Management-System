
#ifndef CIS_242_ASSIGNMENTS_OFFICIAL_BANK_H
#define CIS_242_ASSIGNMENTS_OFFICIAL_BANK_H

#include <string>
using namespace std;


/* Base Account class that stores account information
   and basic banking operations such as login, deposit, withdraw, and balance access. */

class Account {

    protected:
    // Static balance shared across the class.
       static double balance;

    // initialBalance stores the original balance used for interest calculations.
        double initialBalance;
    //username and password variables that will be define in constructor
        string username;
        string password;

    public:
       void login(string inputUsername, string inputPassword);
       double getBalance();
       void deposit(double amount);
       void withdraw(double userWithdraw);

    /* Pure virtual function that forces derived classes
         to implement their own interest calculation.*/
       virtual double calculateInterest() = 0;


    /* Constructor that initializes the account with
       default balance, username, and password.*/
    Account() {
        initialBalance = balance;
        username = "admin";
        password = "1234!";
    }

};

/* SavingsAccount class inherits from Account
 and implements its own member function for interest calculation.*/

class SavingsAccount : public Account {
    public:
        double calculateInterest();

};








#endif //CIS_242_ASSIGNMENTS_OFFICIAL_BANK_H
