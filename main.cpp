#include <iostream>
#include <string>
#include "bank.h"


using namespace std;



/* Main program that acts as a simple banking system.
 The user must first login with a username and password.
 After logging in, the user can deposit money, withdraw money,
 view their balance and interest via the main menu, or exit the program.
*/


int main() {

// variables to store user input
    double userAmount;
    string enteredUsername, enteredPassword;
    int menuOption;



// creating object for savingsAccount and storing address in pointer
    SavingsAccount myBank;
    SavingsAccount* ptrBank = &myBank;



    cout << "Welcome to National Bank! Please enter username and password to get started!" << endl;

    // bool to ensure login keeps looping until username and password are correct
    bool loggedIn = false;


    while (!loggedIn) {

        cin >> enteredUsername >> enteredPassword; //username: admin , password: 1234!

//try the username and if correct set bool variable  = true, exit loop, and enter main menu
        try {
           ptrBank -> login(enteredUsername, enteredPassword);
                loggedIn = true;
        }
//catches an error and sets bool = false, then loop keeps running
        catch (const char* error) {
            cout << error << endl;
            loggedIn = false;
        }

    }


     //do while loop to ensure main menu keeps running until exited by user. Loop runs while menuOption does no equal 3.

    do {

        // Display current balance and interest calculated from the starting balance
      cout << "Your current balance is: " << ptrBank -> getBalance() << endl
           << "Your interest is: " << ptrBank -> calculateInterest() << endl << endl;


        // Display menu options
      cout << "Please select a menu option: " << endl
           << "1. Deposit" << endl
           << "2. Withdraw" << endl
           << "3. Exit" << endl;

      cin >> menuOption;

        /*if else statements to ask check what operations user wants run. Then they are asked
         *the amount they want to deposit or withdraw. Each operation has a try and catch to ensure
         *user has valid inputs
        */

        if (menuOption == 1) {
            cout << "Enter the amount you want to deposit: " << endl;
            cin >> userAmount;

            try {
                ptrBank -> deposit(userAmount);
                cout << "Your account deposit has been made. Your total balance is now: " << ptrBank -> getBalance() << endl;
            }
            catch (const char* error) {
                cout << error << endl;
            }

           //ask user if they want to exit
            cout << "Do you want to exit(3) or go back to main(1)?: ";
            cin >> menuOption;
            //if user chooses to exit they immediately exit loop
            if (menuOption == 3) {
                break;
            }

        } else if (menuOption == 2) {
            cout << "Enter the amount you want to withdraw: " << endl;
            cin >> userAmount;

            try {
                ptrBank -> withdraw(userAmount);
                cout << "Your account withdraw has been made. Your balance is now: " << ptrBank -> getBalance() << endl;

            }
            catch (const char* error) {
                cout << error << endl;
            }

            cout << "Do you want to exit(3) or go back to main(1)?: ";
            cin >> menuOption;
            if (menuOption == 3) {
                break;
            }

            // if menuOption entered at beginning of menu is invalid they will encounter an error
        } else if (menuOption < 1 || menuOption > 3) {
            cout << "Please enter a valid option." << endl;
        }
// exit loop when menuOption = 3 otherwise loop will keep running
    } while (menuOption != 3);

    //exit message
   cout << "Thank you for choosing National Bank. Goodbye!" << endl;

    return 0;


}

//declare static variable for balance
double Account::balance = 2000;

//class member function that checks if username and password are both correct
void Account::login(string inputUsername, string inputPassword) {

    if (inputUsername != username || inputPassword != password) {
        throw ("Invalid Username or Password. Please try again.");
    }
}


//class member function that is pure virtual. It calculates the interest from the intiial balance

double SavingsAccount::calculateInterest() {
    double interest = initialBalance * 0.01;
    return interest;
}


//class member function that always return current balance at any point in program
double Account::getBalance() {
    return balance;
}

//class member function that checks to make sure deposit amount is not negative or 0
void Account::deposit(double amount) {
     if (amount <= 0) {
         throw ("Entry must be greater than 0.");
     }
    balance += amount;
}


//class member function that checks to make sure withdraw amount is not negative, 0 , or greater than account balance
void Account::withdraw(double amount) {

    if (amount > balance) {
        throw ("Insufficient funds.");
    }
     if ( amount <= 0) {
         throw ("Entry must be greater than 0.");
     }

     balance = balance - amount;
}

