#include "Date.h"
#include "AuxiliaryMethods.h"
#include <time.h>
#include <windows.h>

using namespace std;


Date::Date(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

int Date::getYear(){
    return year;
}

int Date::getMonth(){
    return month;
}

int Date::getDay(){
    return day;
}

bool Date::isIsLaterThan(Date someDate){
    if(year > someDate.year) return true;
    else if(year < someDate.year) return false;
    else{
        if(month > someDate.month) return true;
        else if(month < someDate.month) return false;
        else{
            if(day > someDate.day) return true;
            else if (day < someDate.day) return false;
            else return false;
        }
    }
}

void Date::showDate(){
    cout << year << "-" << month << "-" << day << endl;
}

void Date::getTodaysDate(){

    time_t todaysTime;
    struct tm * timeSpecifiers;

    time(&todaysTime);

    timeSpecifiers = localtime(&todaysTime);

    year = timeSpecifiers -> tm_year + 1900;
    month = timeSpecifiers -> tm_mon + 1;
    day = timeSpecifiers -> tm_mday;
}

void Date::getDateFromString(string someDate){
    string numberStr = "";
    for(int i = 0 ; i < 10 ; i++){
        numberStr = numberStr + someDate[i];
        if(i == 3){
            year = AuxiliaryMethods::convertStrToInt(numberStr);
            cout << year << endl;
            system("pause");
        }
        else if(i == 4){
            numberStr = "";
        }
        else if(i == 6){
            if(numberStr[0] == '0'){
                numberStr = numberStr[1];
            }
            month = AuxiliaryMethods::convertStrToInt(numberStr);
            cout << month << endl;
            system("pause");
        }
        else if(i == 7){
            numberStr = "";
        }
        else if(i == 9){
            if(numberStr[0] == '0'){
                numberStr = numberStr[1];
            }
            day = AuxiliaryMethods::convertStrToInt(numberStr);
            cout << day << endl;
            system("pause");
        }
    }
}
