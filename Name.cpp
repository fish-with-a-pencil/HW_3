//  Jessica McMahon
//  Name.cpp
//

#include "Name.h"
#include <string>
#include <iostream>
using namespace std;

// default constructor for name
Name::Name() {
     first = "Rico";
     last = "Suave";
}

//  two parameter constructor for Name (unused)
Name::Name(string f, string l) {
     first = f;
     last = l;
}

//  SET FIRST NAME (unused)
//  recieves a string and sets first name equal to it.  returns nothing
void Name::setFirst(string f) {
     first = f;
     return;
}

//  SET LAST NAME
//  recieves a string and sets last name equal to it.  returns nothing
void Name::setLast(string l) {
     last = l;
     return;
}

//  GET FIRST NAME
//  recieves nothing, returns first name string.  Used by other functions to
//    access the data in Name
string Name::getFirst() {
     return first;
}

//  GET LAST NAME
//  recieves nothing, returns last name string  Called by other functions to
//    access the data in name
string Name::getLast() {
     return last;
}

