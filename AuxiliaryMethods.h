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
    static float loadFloatNumber();
    static string convertIntToString(int number);
    static float convertStrToFloat(string number);
    static string convertFloatToStr(float number);
    static bool checkValueFormat(string value);
    static string replaceComaWithDot(string value);


};



#endif // AUXILIARYMETHODS_H
