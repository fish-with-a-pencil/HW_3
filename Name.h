//
//  Name.h
//  HW_3
//  Jessica McMahon


#ifndef __HW_3__Name__
#define __HW_3__Name__

#include <iostream>
#include <string>
using namespace std;

class Name {
public:
     Name();
     Name(string, string);
     void setFirst(string);
     void setLast(string);
     string getFirst();
     string getLast();

private:
     string first, last;
};

#endif /* defined(__HW_3__Name__) */
