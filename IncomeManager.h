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
    Date specyfyIncomeDate();

public:
    IncomeManager(string incomesFileName, int loggedUserID): incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserID){
    };
    void addNewIncome();

};


#endif // INCOMEMANAGER_H
