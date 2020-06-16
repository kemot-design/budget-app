#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Date.h"

using namespace std;

class Income{
    Date date;
    double value;
    string category;

public:
    void setDate(Date newDate);
    void setValue(float newValue);
    void setCategory(string newCategory);

    Date getDate();
    float getValue();
    string getCategory();

};

#endif // INCOME_H
