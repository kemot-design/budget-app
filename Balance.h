#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include "IncomeManager.h"
#include "ExpenseManager.h"


using namespace std;

class Balance{
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

public:
    Balance(IncomeManager *incomes, ExpenseManager *expenses){
        incomeManager = incomes;
        expenseManager = expenses;
    };
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();

};

#endif // BALANCE_H
