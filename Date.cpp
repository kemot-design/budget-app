#include "Date.h"
#include "AuxiliaryMethods.h"
#include <time.h>

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
