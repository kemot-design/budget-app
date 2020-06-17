#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Date.h"


using namespace std;

class IncomeManager{
    vector <Income> incomes;
    //UsesFile usersFile;

    Income setNewIncomeData();
    Date specyfyIncomeDate();

public:
    void addNewIncome();

};


#endif // INCOMEMANAGER_H
