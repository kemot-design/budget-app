#ifndef DATE_H
#define DATE_H

#include<iostream>

using namespace std;

class Date {
    int year;
    int month;
    int day;
public:
    Date(int y = 2000, int m = 1, int d = 1);
    int getYear();
    int getMonth();
    int getDay();
    bool isIsLaterThan(Date someDate);
    void showDate();
    void getTodaysDate();
    void getDateFromString(string someDate);
};

#endif // DATE_H
