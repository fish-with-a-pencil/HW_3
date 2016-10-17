//
//  Depositor.h
//  HW_3
//  Jessica McMahon


#ifndef __HW_3__Depositor__
#define __HW_3__Depositor__

#include <iostream>
#include <string>
#include "Name.h"
using namespace std;

class Depositor {
public:
     Depositor();
     Depositor(string);
     void setSSN(string);
     void setFirst(string);
     void setLast(string);
     void setName(string, string);
     string getSSN();
     Name getName();
private:
     Name name;
     string ssn;
};


#endif /* defined(__HW_3__Depositor__) */
