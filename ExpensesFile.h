#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "Expense.h"

using namespace std;

class ExpensesFile: XMLFile{

public:
    ExpensesFile(string expensesFileName): XMLFile(expensesFileName) {};
    bool saveExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedUserId);
};
#endif
