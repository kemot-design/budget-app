#ifndef MONEYOPERATION_H
#define MONEYOPERATION_H

#include <iostream>
#include "Date.h"

using namespace std;

class MoneyOperation{
    int id;
    int userId;
    Date date;
    float value;
    string category;

public:
    void displayOperation();

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(Date newDate);
    void setValue(float newValue);
    void setCategory(string newCategory);

    int getId();
    int getUserId();
    float getValue();
    string getCategory();
    Date getDate();
    string getDateStr();
};

#endif // MONEYOPERATION_H
