#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Date.h"
#include "Income.h"

using namespace std;

class Expense: public Income{

public:
    void displayExpense();

};

#endif // EXPENSE_H
