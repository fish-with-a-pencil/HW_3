//
//  Account.h
//  HW_3
//  Jessica McMahon

#ifndef __HW_3__Account__
#define __HW_3__Account__

#include <iostream>
#include <string>
#include <fstream>
#include "Depositor.h"
#include "Name.h"

//  account needs withdrawal function, deposit function, balance inquiry and
//    account info

class Account {
private:
     Depositor customer;
     string acctNum, acctType;
     double balance;
public:
     Account();
     Account(string, string, double);
     void setAcctNum(string);
     void setAcctType(string);
     void setBal(double);
     void setName(string, string);
     void setSSN (string);
     string getAcctNum();
     string getAcctType();
     double getBal();
     void withdraw(ofstream&);
     void deposit(ofstream&);
     void acctInfo(ofstream&);
     Depositor getDepo();
     
     
     
};


#endif /* defined(__HW_3__Account__) */
