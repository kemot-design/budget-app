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
    cout << year << "-";
    if(month < 10){
        cout << "0" << month << "-";
    }
    else cout << month << "-";
    if(day < 10){
        cout << "0" << day;
    }
    else cout << day;
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
        }
        else if(i == 4){
            numberStr = "";
        }
        else if(i == 6){
            if(numberStr[0] == '0'){
                numberStr = numberStr[1];
            }
            month = AuxiliaryMethods::convertStrToInt(numberStr);
        }
        else if(i == 7){
            numberStr = "";
        }
        else if(i == 9){
            if(numberStr[0] == '0'){
                numberStr = numberStr[1];
            }
            day = AuxiliaryMethods::convertStrToInt(numberStr);
        }
    }
}

bool Date::isValidDateFormat(string someDate){
    string dateElement;
    int year, month, day;

    if(someDate.length() != 10) return false;

    for(int i = 0 ; i < someDate.length() ; i++){
        if(i < 4){
            dateElement = dateElement + someDate[i];
            if(i == 3){
                year = AuxiliaryMethods::convertStrToInt(dateElement);
                if(isValidYear(year)){
                    dateElement = "";
                }
                else return false;
            }
        }

        if(i == 5 || i == 6){
            dateElement = dateElement + someDate[i];
            if(i == 6){
                month = AuxiliaryMethods::convertStrToInt(dateElement);

                if(isValidMonth(month, year)){
                    dateElement = "";
                }
                else return false;
            }
        }

        if(i == 8 || i == 9){
            dateElement = dateElement + someDate[i];
            if(i == 9){
                day = AuxiliaryMethods::convertStrToInt(dateElement);
                if(isValidDay(day, month, year)){
                    dateElement = "";
                }
                else return false;
            }
        }

        if(i == 4 || i == 7){
            if(someDate[i] != '-' ) return false;
        }
    }
    return true;
}

bool Date::isValidYear(int yearToCheck){
    Date currentDate;
    currentDate.getTodaysDate();

    if(yearToCheck >= 2000 && yearToCheck <= currentDate.getYear()) return true;
    return false;
}

bool Date::isValidMonth(int monthToCheck, int yearToCheck){
    Date currentDate;
    currentDate.getTodaysDate();
    if(monthToCheck > 0 && monthToCheck < 13){
        if(yearToCheck < currentDate.getYear()) return true;
        else if(yearToCheck == currentDate.getYear() && monthToCheck <= currentDate.getMonth()) return true;
    };
    return false;
}

bool Date::isValidDay(int dayToCheck, int monthToCheck, int yearToCheck){
    int maxDaysInMonth = getNumberOfDaysInMonth(monthToCheck, yearToCheck);
    if(dayToCheck > 0 && dayToCheck <= maxDaysInMonth) return true;
    else return false;
}

int  Date::getNumberOfDaysInMonth(int monthToCheck, int yearToCheck){
	//leap year condition, if month is 2
	if( monthToCheck == 2){
		if((yearToCheck % 400 == 0) || (yearToCheck % 4 == 0 && yearToCheck % 100 != 0))
			return 29;
		else
			return 28;
	}
	else if(monthToCheck == 1 || monthToCheck == 3 || monthToCheck == 5 || monthToCheck == 7 || monthToCheck == 8
	|| monthToCheck == 10 || monthToCheck==12)
		return 31;
	else
		return 30;
}

string Date::getDate(){
    string date = "";
    date = date + AuxiliaryMethods::convertIntToString(year) + "-";
    if(month < 10){
        date = date + "0" + AuxiliaryMethods::convertIntToString(month) + "-";
    }
    else date = date + AuxiliaryMethods::convertIntToString(month) + "-";
    if(day < 10){
        date = date + "0" + AuxiliaryMethods::convertIntToString(day);
    }
    else date = date + AuxiliaryMethods::convertIntToString(day);
    return date;
}

void Date::specyfyDate(){
    string dateStr;

    cout << "Specyfy date (yyyy-mm-dd)" << endl;
    dateStr = AuxiliaryMethods::loadLine();
    while(isValidDateFormat(dateStr) == false){
        cout << "Please enter date in correct format yyyy-mm-dd" << endl;
        dateStr = AuxiliaryMethods::loadLine();
    }
    getDateFromString(dateStr);
}
