#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"
#include "IncomeManager.h"

using namespace std;

class BudgetApp{
    UserManager userManager;
    IncomeManager *incomeManager;

public:
    BudgetApp(string usersFileName);
    void registerUser();
    char selectOptionFromUserMenu();
    bool isUserLoggedIn();
    void loginUser();
    char selectOptionFromAppMenu();
    void changeUserPassword();
    void logoutUser();
    void addIncome();

};


#endif // BUDGETAPP_H
