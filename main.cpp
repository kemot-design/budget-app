#include <iostream>
#include <stdlib.h>
#include "BudgetApp.h"

using namespace std;

int main()
{
    char selection;
    BudgetApp budgetApp;
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
                cout << "Add income" << endl;
                system("pause");
                break;
            case '2':
                cout << "Add expense" << endl;
                system("pause");
                break;
            case '3':
                cout << "current month balance" << endl;
                system("pause");
                break;
            case '4':
                cout << "Previous month balance" << endl;
                system("pause");
                break;
            case '5':
                cout << "Selected month balance" << endl;
                system("pause");
                break;
            case '6':
                cout << "Change password" << endl;
                system("pause");
                break;
            case '7':
                cout << "Log out" << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
