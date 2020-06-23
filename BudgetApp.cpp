#include "BudgetApp.h"
#include "AuxiliaryMethods.h"
#include <cstdlib>

using namespace std;

BudgetApp::BudgetApp(string usersFileName, string incomesFileName, string expensesFileName): userManager(usersFileName),
INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName){

    incomeManager = NULL;
    expenseManager = NULL;
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
    if(isUserLoggedIn()){
        incomeManager = new IncomeManager(INCOMES_FILE_NAME, userManager.getLoggedUserId());
        expenseManager = new ExpenseManager(EXPENSES_FILE_NAME, userManager.getLoggedUserId());
    }
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

void BudgetApp::changeUserPassword(){
    userManager.changeUserPassword();
}

void BudgetApp::logoutUser(){
    userManager.logoutUser();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
}

void BudgetApp::addIncome(){
    incomeManager -> addNewIncome();
}

void BudgetApp::addExpense(){
    expenseManager -> addNewExpense();
}
