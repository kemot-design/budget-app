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
    void sortIncomesChronologically();

public:
    IncomeManager(string incomesFileName, int loggedUserID);
    void addNewIncome();
    float displayCurrentMonthIncomes();
    float displayPreviousMonthIncomes();
    float displaySpecyfiedPeriodIncomes(Date startDate, Date endDate);

};


#endif // INCOMEMANAGER_H
