//  Jessica McMahon
//  Depositor.cpp
//


#include "Depositor.h"
#include <iostream>
#include <string>
using namespace std;


//  default constructor for depositor
Depositor::Depositor() {
     ssn = "000-00-0000";
}

// one-parameter constructor for depositor (unused)
Depositor::Depositor(string social) {
     ssn = social;
}

//  SET SSN
//  recieves a string, and sets ssn equal to it. returns nothing
void Depositor::setSSN(string social) {
     ssn = social;
     return;
}

//  SET FIRST NAME
//  recieves a string and calls the setFirst method from Name. (unused)
void Depositor::setFirst(string f) {
     name.setFirst(f);
     return;
}

//  SET LAST NAME
//  recieves a string and cals the setLast method from name. (unused)
void Depositor::setLast(string l) {
     name.setLast(l);
     return;
}

//  SET NAME
//  recieves two string parameters, and calls setFirst and setLast to set the
//    name to the recieved parameters.  returns nothing
void Depositor::setName(string f, string l) {
     name.setFirst(f);
     name.setLast(l);
     return;
}

//  GET SSN
//  recieves nothing, returns a string with the social security number of
//    depositor
string Depositor::getSSN() {
     return ssn;
}

//  GET NAME
//  recieves nothing, returns an entire name object.  Used for passing along
//    the output for name.
Name Depositor::getName() {
     return name;
}



