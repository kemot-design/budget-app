#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>

using namespace std;

class AuxiliaryMethods{
public:
    static char loadChar();
    static string loadLine();
    static string setFirstLetterUppercaseRestLowercase(string someText);
    static int convertStrToInt(string number);
};



#endif // AUXILIARYMETHODS_H
