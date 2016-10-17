//
//  Bank.h
//  HW_3
// Jessica McMahon


#ifndef __HW_3__Bank__
#define __HW_3__Bank__
const int MAX_NUM = 50;

#include "Account.h"
#include <fstream>
using namespace std;


// bank needs new account, delete account, find acct, read accts

class Bank {
public :
     int findAcct(string);
     int findAcctSSN(string);
     void newAcct(int, string, ofstream&);
     void delAcct(int, ofstream&);
     void readAccts();
     void printData(ofstream&);
     void swap(int);
     void callWithdraw(int, ofstream&);
     void callDeposit(int, ofstream&);
     Account getAcct(int);

private:
     Account database[MAX_NUM];
     int numAccts;
     
};

#endif /* defined(__HW_3__Bank__) */
