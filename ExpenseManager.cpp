#include "ExpenseManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>


using namespace std;

ExpenseManager::ExpenseManager(string expensesFileName, int loggedUserID): expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserID){
    expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);
    sortExpensesChronologically();
}


void ExpenseManager::addNewExpense(){
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = setNewExpenseData();

    expenses.push_back(expense);
    sortExpensesChronologically();
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

    newExpense.setId(expensesFile.getLastExpenseId() + 1);
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
    while(AuxiliaryMethods::isValueFormatOk(valueStr) == false){
        cout << endl << "That is not a valid value format, try again!" << endl;
        valueStr = AuxiliaryMethods::loadLine();
    }
    float value = AuxiliaryMethods::convertStrToFloat(valueStr);
    newExpense.setValue(value);

    return newExpense;
}

float ExpenseManager::displayCurrentMonthExpenses(){
    Date currentDate;
    currentDate.getTodaysDate();
    float totalExpense = 0;

    for(int i = 0 ; i < expenses.size() ; i++){
        if(expenses[i].getDate().getMonth() == currentDate.getMonth()){
            expenses[i].displayOperation();
            totalExpense += expenses[i].getValue();
        }
    }
    return totalExpense;
}

float ExpenseManager::displayPreviousMonthExpenses(){
    Date currentDate;
    currentDate.getTodaysDate();
    float totalExpense = 0;

    for(int i = 0 ; i < expenses.size() ; i++){
        if(expenses[i].getDate().getMonth() == currentDate.getMonth() - 1){
            expenses[i].displayOperation();
            totalExpense += expenses[i].getValue();
        }
    }
    return totalExpense;
}

void ExpenseManager::sortExpensesChronologically(){
    int vectorSize = expenses.size();

    for (int i = 0 ; i < vectorSize - 1 ; i++)
    {
        for (int j = i + 1 ; j < vectorSize ; j++)
        {
            if (expenses[i].getDate().getYear() > expenses[j].getDate().getYear())
            {
                swap(expenses[i], expenses[j]);
            }
            else if (expenses[i].getDate().getYear() == expenses[j].getDate().getYear() && expenses[i].getDate().getMonth() > expenses[j].getDate().getMonth())
            {
                swap(expenses[i], expenses[j]);
            }
            else if (expenses[i].getDate().getYear() == expenses[j].getDate().getYear() && expenses[i].getDate().getMonth() == expenses[j].getDate().getMonth() && expenses[i].getDate().getDay() > expenses[j].getDate().getDay())
            {
                swap(expenses[i], expenses[j]);
            }
        }
    }
}

float ExpenseManager::displaySpecyfiedPeriodExpenses(Date startDate, Date endDate){
    float totalExpense = 0;

    for(int i = 0 ; i < expenses.size() ; i++){
        if((expenses[i].getDate().isItLaterThan(startDate) && !expenses[i].getDate().isItLaterThan(endDate)) || expenses[i].getDate().isItSameDayAs(startDate)){
            expenses[i].displayOperation();
            totalExpense += expenses[i].getValue();
        }
    }
    return totalExpense;
}
