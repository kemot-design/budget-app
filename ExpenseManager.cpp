#include "ExpenseManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>


using namespace std;

ExpenseManager::ExpenseManager(string expensesFileName, int loggedUserID): expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserID){
    expenses = expensesFile.loadExpensesFromFile();
}


void ExpenseManager::addNewExpense(){
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = setNewExpenseData();

    expenses.push_back(expense);
    if(expensesFile.saveExpenseToFile(expense)){
        cout << "New expense has been added" << endl;
    }
    else {
        cout << "Error, new expense haven't been added properly." << endl;
    }
    system("pause");
}

Expense ExpenseManager::setNewExpenseData(){
    Expense newExpense;
    char selection;
    Date expenseDate;

    newExpense.setId(getNewExpenseId());
    newExpense.setUserId(LOGGED_USER_ID);

    cout << "Is the expense from today? (y/n)" << endl;

    do{
        selection = AuxiliaryMethods::loadChar();

        if(selection == 'y'){
            expenseDate.getTodaysDate();
            newExpense.setDate(expenseDate);
        }
        else if(selection == 'n'){
            expenseDate.specyfyDate();
            newExpense.setDate(expenseDate);
        }
        else{
            cout << "Insert \"y\" or \"n\"" << endl;
        }
    } while(selection != 'y' && selection != 'n');

    cout << "Specify expense category: " ;
    string category;
    category = AuxiliaryMethods::loadLine();
    newExpense.setCategory(category);

    cout << "Enter expense value (. as separator): " ;
    float value = AuxiliaryMethods::loadFloatNumber();
    newExpense.setValue(value);

    return newExpense;
}

int ExpenseManager::getNewExpenseId(){
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}
