#ifndef DATE_H
#define DATE_H

#include<iostream>

using namespace std;

class Date {
    int year;
    int month;
    int day;

    bool isValidYear(int yearToCheck);
    bool isValidMonth(int monthToCheck, int yearToCheck);
    bool isValidDay(int dayToCheck, int monthToCheck, int yearToCheck);
    int getNumberOfDaysInMonth(int yearToCheck, int monthToCheck);
public:
    Date(int y = 2000, int m = 1, int d = 1);
    int getYear();
    int getMonth();
    int getDay();
    string getDate();
    bool isItLaterThan(Date someDate);
    bool isItSameDayAs(Date someDate);
    void showDate();
    void getTodaysDate();
    void specyfyDate();
    void getDateFromString(string someDate);
    bool isValidDateFormat(string someDate);
};

#endif // DATE_H
