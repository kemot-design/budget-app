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

int AuxiliaryMethods::convertStrToInt(string numberStr){
    int numberInt;
    istringstream iss(numberStr);
    iss >> numberInt;

    return numberInt;
}

float AuxiliaryMethods::loadFloatNumber()
{
    string input = "";
    float number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "That is not a correct number. Pleas enter again. " << endl;
    }
    return number;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;

}

float AuxiliaryMethods::convertStrToFloat(string numberStr){
    float numberFloat;
    istringstream iss(numberStr);
    iss >> numberFloat;

    return numberFloat;
}

string AuxiliaryMethods::convertFloatToStr(float number){
    string numberStr;
    stringstream ss;
    ss << number;
    numberStr = ss.str();

    return numberStr;
}

bool AuxiliaryMethods::checkValueFormat(string value){
    int letterInAscii;
    for(int i = 0 ; i < value.length() ; i++){
       letterInAscii = value[i];
        if((letterInAscii < 48 || letterInAscii > 57) && letterInAscii != 44 && letterInAscii != 46) return false;
    }
    return true;
}

string AuxiliaryMethods::replaceComaWithDot(string value){
    string correctValue = "";
    for(int i = 0 ; i < value.length() ; i++){
        correctValue += value[i];
        if(value[i] == ','){
            correctValue.replace(i,1,".");
        }
    }
    return correctValue;
}
