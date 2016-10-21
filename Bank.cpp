//  Jessica McMahon
//  Bank.cpp
//  contains all of the methods of the bank class
//


#include "Bank.h"
#include <fstream>
#include <iostream>
#include <string>



//  FIND ACCOUNT
//  input: a string to search for
//  action: uses a for loop to linear search for the string in each entry
//  output: the index if it find the string, -1 if it doesn't exist
int Bank::findAcct(string search) {
     for (int i=0; i < numAccts; i++) {
          if (search == database[i].getAcctNum())
               return i;
     }
     return -1;
}

//  FIND ACCOUNT (using ssn)
//  input: a string to search for
//  action: uses a for loop to search for the ssn
//  output: returns the index where the ssn was found, or -1 if not found
int Bank::findAcctSSN(string search) {
     for (int i=0; i < numAccts; i++) {
          if (search == database[i].getDepo().getSSN())
               return i;
     }
     return -1;
}


//  NEW ACCOUNT
//  input: an int from the result of findAcct, the string searched for and
//    a reference to the output file
//  action: checks if the account already exists, then if it doesn't, makes a
//    new one and prompts user for more information
//  output: none
void Bank::newAcct(int result,string search, ofstream & outfile) {
     string first, last, social, aType;
     double bal;
     if (result != -1) {
          cout << "Error.  Account already exists.  Returning to menu.\n";
          outfile << "Error.  Account already exists.\n\n";
     }
     else {
          cout << "First name: ";
          cin >> first;
          cout << "Last name: ";
          cin >> last;
          cout << "SSN: ";
          cin >> social;
          cout << "Account type: ";
          cin >> aType;
          cout << "Starting balance: ";
          cin >> bal;
          database[numAccts].setName(first, last);
          database[numAccts].setSSN(social);
          database[numAccts].setAcctNum(search);
          database[numAccts].setAcctType(aType);
          database[numAccts].setBal(bal);
          cout << "Account created. Returning to menu.\n\n";
          numAccts++;
     }
    
     return;
}

//  DELETE ACCOUNT
//  input: an int from the result of findAcct and a reference to the output file
//  action: checks if the account doesnt exist, then if it does exist, checks
//    for an active balance, and if none, deletes the account
//  output: none
void Bank::delAcct(int result, ofstream &outfile) {
     if (result == -1) {
          cout << "Error.  Account does not exist. Returning to menu.\n";
          outfile << "Error.  Account does not exist. \n\n";
          return;
     }
     else if (database[result].getBal() != 0) {
          cout << "Error.  Account still has a balance.  Returning to menu.\n";
          outfile << "Error.  Account still has a balance.\n\n";
          return;
     }
     else {
          database[result].setName("N/A", "N/A");
          database[result].setSSN("000-00-0000");
          database[result].setAcctNum("000");
          database[result].setAcctType("N/A");
          database[result].setBal(0.00);
          for (int i=result; i < numAccts; i++) {
               swap(i);
          }
          cout << "Account deletion successful.  Returning to menu.\n";
          outfile << "Account deletion successful.\n\n";
          numAccts--;
          
     }
     return;
}


//  GET ACCOUNT
//  receives an int, returns an account object with the index of the int
Account Bank::getAcct(int j) {
     return database[j];
}

//  READ ACCOUNTS
//  input: none
//  action: reads in the data from a file
//  output: none
void Bank::readAccts() {
     ifstream infile("/Users/jessicamcmahon/Desktop/"
                     "HW_3/HW2_Input.txt");
     numAccts = 0;
     string first, last, social, aNum, aType;
     double bal;

     
     while (infile >> first && numAccts < MAX_NUM) {
          infile >> last;
          infile >> social;
          infile >> aType;
          infile >> aNum;
          infile >> bal;
          database[numAccts].setName(first, last);
          database[numAccts].setSSN(social);
          database[numAccts].setAcctType(aType);
          database[numAccts].setAcctNum(aNum);
          database[numAccts].setBal(bal);
          numAccts ++;
     }
     infile.close();
     return;
}

//  PRINT DATA
//  input: a reference to the output file
//  action: prints out all of the data, with a heading
//  output: none
void Bank::printData(ofstream &outfile) {
     outfile << "Name\t\tSSN\t\tAcct Type\tAcct Number";
     outfile << "\tBalance\n\n";
     for (int i=0; i < numAccts; i++) {
          outfile << database[i].getDepo().getName().getFirst() << "\t";
          outfile << database[i].getDepo().getName().getLast() << "\t";
          outfile << database[i].getDepo().getSSN() << "\t";
          outfile << database[i].getAcctType() << "\t";
          if (database[i].getAcctType() == "CD" ||
              database[i].getAcctType() == "savings") {
               outfile << "\t";
          }
          outfile << database[i].getAcctNum() << "\t\t";
          outfile << database[i].getBal() << endl << endl;
          
     }
     return;
}

//  SWAP
//  recives an int of the index to swap, then swaps it with the one below it
//   for use in delete account
void Bank::swap(int toSwap) {
     Account temp;
     
     temp = database[toSwap];
     database[toSwap] = database[toSwap+1];
     database[toSwap+1] = temp;
     return;
}

//  CALL WITHDRAW
//  input: an int holding the result of findAcct and a reference to an output
//    file
//  action: processes the result, an if valid, calls withdraw
//  output: none
void Bank::callWithdraw(int result, ofstream & outfile) {
     if (result == -1) {
          cout << "Error.  Account does not exist. Returning to menu.\n";
          outfile << "Error.  Account does not exist.\n\n";
     }
     else {
          database[result].withdraw(outfile);
     }
     return;
}

//  CALL DEPOSIT
//  input: an int holding the result of findAcct and a reference to an output
//    file
//  action: processes the result, an if valid, calls deposit
//  output: none
void Bank::callDeposit(int result, ofstream &outfile) {
     if (result == -1) {
          cout << "Error.  Account does not exist. Returning to menu.\n";
          outfile << "Error.  Account does not exist.\n\n";
     }
     else {
          database[result].deposit(outfile);
     }
     return;
}
