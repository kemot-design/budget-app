#include "ExpenseManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>


using namespace std;

ExpenseManager::ExpenseManager(string expensesFileName, int loggedUserID): expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserID){
    expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);
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
    category = AuxiliaryMethods::setFirstLetterUppercaseRestLowercase(category);
    newExpense.setCategory(category);

    cout << "Enter expense value (. as separator): " ;
    string valueStr = AuxiliaryMethods::loadLine();
    while(AuxiliaryMethods::checkValueFormat(valueStr) == false){
        cout << "That is not a valid value format, try again." << endl;
        valueStr = AuxiliaryMethods::loadLine();
    }
    valueStr = AuxiliaryMethods::replaceComaWithDot(valueStr);
    float value = AuxiliaryMethods::convertStrToFloat(valueStr);
    newExpense.setValue(value);

    return newExpense;
}

int ExpenseManager::getNewExpenseId(){
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}


void ExpenseManager::displayExpenses(){
    sortExpensesChronologically();
    cout << "EXPENSES" << endl;
    for(int i = 0 ; i < expenses.size() ; i++){
        expenses[i].displayExpense();
    }
}

void ExpenseManager::sortExpensesChronologically(){
    int numberOfDates = expenses.size();

    for (int i = 0 ; i < numberOfDates - 1 ; i++)
    {
        for (int j = i + 1 ; j < numberOfDates ; j++)
        {
            if (expenses[i].getFullDate().getYear() > expenses[j].getFullDate().getYear())
            {
                swap(expenses[i], expenses[j]);
            }
            else if (expenses[i].getFullDate().getYear() == expenses[j].getFullDate().getYear() && expenses[i].getFullDate().getMonth() > expenses[j].getFullDate().getMonth())
            {
                swap(expenses[i], expenses[j]);
            }
            else if (expenses[i].getFullDate().getYear() == expenses[j].getFullDate().getYear() && expenses[i].getFullDate().getMonth() == expenses[j].getFullDate().getMonth() && expenses[i].getFullDate().getDay() > expenses[j].getFullDate().getDay())
            {
                swap(expenses[i], expenses[j]);
            }

        }
    }
}
