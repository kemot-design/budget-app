#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "Expense.h"

using namespace std;

class ExpensesFile: XMLFile{
    int lastExpenseId;

public:
    ExpensesFile(string expensesFileName): XMLFile(expensesFileName), lastExpenseId(0) {};
    bool saveExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedUserId);
    int getLastExpenseId();
};
#endif
