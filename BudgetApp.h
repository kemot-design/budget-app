#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class BudgetApp{
    UserManager userManager;

public:
    BudgetApp();
    void registerUser();
    char selectOptionFromUserMenu();
    void loginUser();


};


#endif // BUDGETAPP_H
