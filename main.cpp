//
//  Jessica McMahon: HW 3
//
//  A bank program using separate compilation that moves the functionality of
//  the program to the classes instead of main.
//
//  note: the cpp files have a few unused functions.  I used them during testing
//    and decided to keep them just in case I use these for later programs.
//    unused functions will be marked as such in comments.

#include <iostream>
#include <fstream>
#include <string>

#include "Name.h"
#include "Depositor.h"
#include "Account.h"
#include "Bank.h"
using namespace std;


// **PROTOTYPES** //
void menu();
void new_acct (Bank &bank, ofstream &outfile);
void del_acct (Bank &bank, ofstream &outfile);
void withdraw (Bank &bank, ofstream & outfile);
void deposit (Bank &bank, ofstream &outfile);
void balance (Bank &bank, ofstream &outfile);
void acctInfo (Bank &bank, ofstream &outfile);


// **MAIN PROGRAM** //
int main() {
     Bank database;
     char select;
     
     //sets up the output file and it's precision, then prints a heading
     ofstream outfile("/Users/jessicamcmahon/Desktop/"
                      "HW_3/HW3_Output.txt");
     outfile.setf(ios::fixed,ios::floatfield);
     outfile.precision(2);
     outfile << "Name: Jessica McMahon\nOutput for HW 3\n\n";
     
     //initial read in of data
     database.readAccts();
     outfile << "Initial database:\n";
     database.printData(outfile);
     
     do {
          menu();
          cin >> select;
          switch (select)
          {
               case 'q':
               case 'Q':
                    cout << "Quitting program.  Printing final database to";
                    cout << " the output file.\n";
                    database.printData(outfile);
                    break;
               case 'w':
               case 'W':
                    withdraw(database, outfile);
                    break;
               case 'd':
               case 'D':
                    deposit(database, outfile);
                    break;
               case 'n':
               case 'N':
                    new_acct(database, outfile);
                    break;
               case 'b':
               case 'B':
                    balance(database, outfile);
                    break;
               case 'i':
               case 'I':
                    acctInfo(database, outfile);
                    break;
               case 'x':
               case 'X':
                    del_acct(database, outfile);
                    break;
               default:
                    cout << "Error.  Invalid selection.  Returning to menu.";
                    cout << "\n\n";
          }
     } while (select != 'q' && select != 'Q');
     return 0;
}

//** FUNCTIONS**//

//  MENU
//  input: none
//  action: prints a menu to the screen
//  output: none;
void menu() {
     cout << "\nSelect from the following:\n\nW: Withdrawal\nD: Deposit";
     cout << "\nN: New Account\nB: Balance\nI: Account Info\n";
     cout << "X: Delete Account\nQ: Quit\n";
     return;
}


//  NEW ACCOUNT
//  input: a reference to a Bank object and a reference to the output file
//  action: prompts the user for an account number, then calls the find function
//    and sends the needed information to the new account method of bank
//  output: none
void new_acct (Bank &bank, ofstream &outfile) {
     string search;
     int result;
     
     cout << "Enter account number: ";
     cin >> search;
     outfile << "Action: Create Account\n";
     outfile << "Account number: " << search << endl;
     result = bank.findAcct(search);
     bank.newAcct(result, search, outfile);
     return;
}

//  DELETE ACCOUNT
//  input: a reference to a Bank object and a reference to the output file
//  action: prompts the user for an account number, then calls the find function
//    and sends the needed information to the delete account method of bank
//  output: none
void del_acct (Bank &bank, ofstream &outfile) {
     string search;
     int result;
     
     cout << "Enter account number: ";
     cin >> search;
     outfile << "Action: Delete Account\n";
     outfile << "Account number: " << search << endl;
     result = bank.findAcct(search);
     bank.delAcct(result, outfile);
     return;
}

//  WITHDRAW
//  input: a reference to a Bank object and a reference to the output file
//  action: prompts the user for an account number, then calls the find function
//    and sends the needed information to the the callWithdraw method of bank
//  output: none
void withdraw (Bank &bank, ofstream &outfile) {
     string search;
     int result;
     
     cout << "Enter account number: ";
     cin >> search;
     outfile << "Action: Withdrawal\n";
     outfile << "Account Number: " << search << endl;
     result = bank.findAcct(search);
     bank.callWithdraw(result, outfile);
     return;
}

//  DEPOSIT
//  input: a reference to a Bank object and a reference to the output file
//  action: prompts the user for an account number, then calls the find function
//    and sends the needed information to the callDeposit method of bank
//  output: none
void deposit (Bank &bank, ofstream &outfile) {
     string search;
     int result;
     
     cout << "Enter account number: ";
     cin >> search;
     outfile << "Action: Deposit\n";
     outfile << "Account Number: " << search << endl;
     result = bank.findAcct(search);
     bank.callDeposit(result, outfile);
     return;
}

//  BALANCE
//  input: a reference to a Bank object and a reference to the output file
//  action: prompts the user for an account number, then calls the find function
//    and, if it find the account, prints the balance to the output file and
//    the screen
//  output: none
void balance (Bank &bank, ofstream &outfile) {
     string search;
     int result;
     
     cout << "Enter account number: ";
     cin >> search;
     outfile << "Action: Balance Inquiry\n";
     outfile << "Account Number: " << search << endl;
     result = bank.findAcct(search);
     if (result == -1) {
          cout << "Error.  Account does not exist.  Returning to menu.\n";
          outfile << "Error.  Account does not exist.\n\n";
     }
     else {
          cout << "Balance of account number: " << search << " is $";
          cout << bank.getAcct(result).getBal() << endl;
          outfile << "Balance of account number: " << search << " is $";
          outfile << bank.getAcct(result).getBal() << endl << endl;
     }
     return;
}

//  ACCOUNT INFO
//  input: a reference to a Bank object and a reference to the output file
//  action: prompts the user for a social security number, then calls the
//    find account by SSN function.  if the account exists, the function prints
//    the account information to the output file
//  output: none
void acctInfo (Bank &bank, ofstream &outfile) {
     string search;
     int result;
     
     cout << "Enter account SSN: ";
     cin >> search;
     outfile << "Action: Account Inquiry\n";
     outfile << "Account SSN: " << search << endl;
     result = bank.findAcctSSN(search);
     if (result == -1) {
          cout << "Error.  Account does not exist.  Returning to menu.\n";
          outfile << "Error.  Account does not exist.\n\n";
     }
     else {
          cout << "Account information was printed to the file.\n";
          bank.getAcct(result).acctInfo(outfile);
     }
     return;
}







