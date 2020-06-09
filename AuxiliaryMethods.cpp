#include "AuxiliaryMethods.h"
#include <sstream>
#include <algorithm>

using namespace std;

char AuxiliaryMethods::loadChar(){
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "That is not a single character. Try again." << endl;
    }
    return character;
}

string AuxiliaryMethods::loadLine(){
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::setFirstLetterUppercaseRestLowercase(string someText){
    if (!someText.empty())
    {
        transform(someText.begin(), someText.end(), someText.begin(), ::tolower);
        someText[0] = toupper(someText[0]);
    }
    return someText;
}
