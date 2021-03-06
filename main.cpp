#include <iostream>
#include <stdlib.h>
#include "BudgetApp.h"

using namespace std;

int main()
{
    char selection;
    BudgetApp budgetApp("Users.xml", "Incomes.xml", "Expenses.xml");
    while (true)
    {
        if (!budgetApp.isUserLoggedIn())
        {
            selection = budgetApp.selectOptionFromUserMenu();

            switch (selection)
            {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            selection = budgetApp.selectOptionFromAppMenu();

            switch (selection)
            {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
                budgetApp.addExpense();
                break;
            case '3':
                budgetApp.showCurrentMonthBalance();
                break;
            case '4':
                budgetApp.showPreviousMonthBalance();
                break;
            case '5':
                budgetApp.showSpecyfiedPeriodBalance();
                break;
            case '6':
                budgetApp.changeUserPassword();
                break;
            case '7':
                budgetApp.logoutUser();
                break;
            }
        }
    }

    return 0;
}
