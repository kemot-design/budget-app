#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Date.h"
#include "IncomesFile.h"

using namespace std;

class IncomeManager{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;

    Income setNewIncomeData();
    int getNewIncomeId();
    void sortIncomesChronologically();

public:
    IncomeManager(string incomesFileName, int loggedUserID);
    void addNewIncome();
    void displayIncomes();
    float displayCurrentMonthIncomes();
    float displayPreviousMonthIncomes();

};


#endif // INCOMEMANAGER_H
