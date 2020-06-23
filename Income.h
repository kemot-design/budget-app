#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Date.h"

using namespace std;

class Income{
    int id;
    int userId;
    Date date;
    double value;
    string category;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(Date newDate);
    void setValue(float newValue);
    void setCategory(string newCategory);

    int getId();
    int getUserId();
    string getDate();
    float getValue();
    string getCategory();

};

#endif // INCOME_H
