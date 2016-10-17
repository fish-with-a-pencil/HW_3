//  Jessica McMahon
//  Account.cpp
//


#include "Account.h"
#include <string>
#include <fstream>
#include <iostream>



//  default depositor for account
Account::Account() {
     acctNum = "000";
     acctType = "N/A";
     balance = 0.00;
}

//  three parameter depositor for account (unused)
Account::Account(string num, string type, double bal) {
     acctNum = num;
     acctType = type;
     balance = bal;
}

//  SET ACCOUNT NUMBER
//  recieves a string and sets the account number equal to it.  returns nothing
void Account::setAcctNum(string num) {
     acctNum = num;
     return;
}

//  SET ACCOUNT TYPE
//  recieves a string and sets the account type equal to it.  returns nothing
void Account::setAcctType(string type) {
     acctType = type;
     return;
}

//  SET BALANCE
//  recieves a double and sets the balance equal to it.  retruns nothing
void Account::setBal(double bal) {
     balance = bal;
     return;
}

//  GET ACCOUNT NUMBER
//  recieves nothing, returns the account number string
string Account::getAcctNum() {
     return acctNum;
}

//  GET ACCOUNT TYPE
//  recieves nothing, returns the account type string
string Account::getAcctType() {
     return acctType;
}

//  GET BALANCE
//  recieves nothing, returns the balance double
double Account::getBal() {
     return balance;
}

//  SET NAME
//  recieves two strings, then calls setName to pass them along so they can be
//    used in Name.  returns nothing
void Account::setName(string f, string l) {
     customer.setName(f,l);
     return;
}

//  SET SSN
//  recieves a string, then calls setSSN from depositor to set the ssn
//    returns nothing
void Account::setSSN(string social) {
     customer.setSSN(social);
     return;
}

//  WITHDRAW
//  input: recieves a reference to the output file
//  action: prompts the user for a withdrawal amount, checks it for valitity,
//    and then, if valid, removes the withdrawal from the balance
//  output: none
void Account::withdraw(ofstream &outfile) {
     double bal;
     
          cout << "Enter withdrawal amount: ";
          cin >> bal;
          outfile << "Withdrawal amount: " << bal << endl;
          outfile << "Existing balance: $" << balance << endl;
          if (bal < 0) {
               cout <<"Error. Negative withdrawal amount. Returning to menu.\n";
               outfile << "Error. Negative withdrawal.\n\n";
          }
          else if (balance < bal){
               cout << "Error.  Insufficient funds. Returning to menu.\n";
               outfile << "Error.  Insufficient funds.\n\n";
          }
          else {
               balance -= bal;
               cout << "Transaction successful.  Balance is now: $" << balance;
               cout << " Returning to menu.\n";
               outfile << "Transaction successful.  Balance is now: $";
               outfile << balance << endl << endl;
          }
    return;
}

//  DEPOSIT
//  input: recieves a reference to the output file
//  action: prompts the user for a deposit amount, checks it for valitity,
//    and then, if valid, posts the deposit to the balance
//  output: none
void Account::deposit(ofstream &outfile) {
     double bal;
     
     cout << "Enter deposit amount: ";
     cin >> bal;
     outfile << "Deposit amount: " << bal << endl;
     outfile << "Existing balance: $" << balance << endl;
     if (bal < 0) {
          cout <<"Error. Negative deposit amount. Returning to menu.\n";
          outfile << "Error. Negative deposit.\n\n";
     }
     else {
          balance += bal;
          cout << "Transaction successful.  Balance is now: $" << balance;
          cout << " Returning to menu.\n";
          outfile << "Transaction successful.  Balance is now: $";
          outfile << balance << endl << endl;
     }
     return;
}

//  ACCOUNT INFO
//  input: recieves one reference to the output file
//  action: prints all of the account information to the output file
//  output: none
void Account::acctInfo(ofstream &outfile) {
     outfile << "This is requested account info:\n\n";
     outfile << "Name: " << customer.getName().getFirst() << " ";
     outfile << customer.getName().getLast() << "\nSSN: ";
     outfile << customer.getSSN() << "\nAcct Num: " << acctNum;
     outfile << "\nAcct Type: " << acctType << "\nBalance: " << balance<<"\n\n";
     return;
}

//  GET DEPOSITOR
//  recieves nothing, returns a depositor object.  Used for passing along the
//    information to functions inside of main
Depositor Account::getDepo() {
     return customer;
}

