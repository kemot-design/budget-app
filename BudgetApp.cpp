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
