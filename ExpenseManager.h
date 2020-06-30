#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "Date.h"
#include "ExpensesFile.h"

using namespace std;

class ExpenseManager{
    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    ExpensesFile expensesFile;

    Expense setNewExpenseData();
    int getNewExpenseId();
    void sortExpensesChronologically();

public:
    ExpenseManager(string expensesFileName, int loggedUserID);
    void addNewExpense();

    float displayCurrentMonthExpenses();
    float displayPreviousMonthExpenses();
    float displaySpecyfiedPeriodExpenses(Date startDate, Date endDate);
};


#endif // EXPENSEMANAGER_H
