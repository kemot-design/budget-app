#include "BudgetApp.h"
#include "AuxiliaryMethods.h"
#include <cstdlib>

using namespace std;

BudgetApp::BudgetApp(){

}

char BudgetApp::selectOptionFromUserMenu(){
    char selection;

    system("cls");
    cout << "    >>> BUDGET APP <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register new user" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your selection: ";
    selection = AuxiliaryMethods::loadChar();

    return selection;
}

void BudgetApp::registerUser(){
    userManager.registerUser();
}

void BudgetApp::loginUser(){
    userManager.loginUser();
}

bool BudgetApp::isUserLoggedIn(){
    userManager.isUserLoggedIn();
}

char BudgetApp::selectOptionFromAppMenu(){
    char selection;

    system("cls");
    cout << " >>> APP MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show current month balance" << endl;
    cout << "4. Show previous month balance" << endl;
    cout << "5. Show selected period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your selection: ";
    selection = AuxiliaryMethods::loadChar();

    return selection;
}
