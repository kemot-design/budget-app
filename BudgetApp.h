#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class BudgetApp{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    BudgetApp(string usersFileName, string incomesFileName, string expensesFileName);
    void registerUser();
    char selectOptionFromUserMenu();
    bool isUserLoggedIn();
    void loginUser();
    char selectOptionFromAppMenu();
    void changeUserPassword();
    void logoutUser();
    void addIncome();
    void addExpense();

};


#endif // BUDGETAPP_H
