#include "IncomeManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>
#include <time.h>


using namespace std;

IncomeManager::IncomeManager(string incomesFileName, int loggedUserID): incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserID){
    incomes = incomesFile.loadIncomesFromFile();
}


void IncomeManager::addNewIncome(){
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = setNewIncomeData();

    incomes.push_back(income);
    if(incomesFile.saveIncomeToFile(income)){
        cout << "New income has been added" << endl;
    }
    else {
        cout << "Error, new income haven't been added properly." << endl;
    }
    system("pause");
}

Income IncomeManager::setNewIncomeData(){
    Income newIncome;
    char selection;
    Date incomeDate;

    newIncome.setId(getNewIncomeId());
    newIncome.setUserId(LOGGED_USER_ID);

    cout << "Is the income from today? (y/n)" << endl;

    do{
        selection = AuxiliaryMethods::loadChar();

        if(selection == 'y'){
            incomeDate.getTodaysDate();
            newIncome.setDate(incomeDate);
        }
        else if(selection == 'n'){
            incomeDate = specyfyIncomeDate();
            newIncome.setDate(incomeDate);
        }
        else{
            cout << "Insert \"y\" or \"n\"" << endl;
        }
    } while(selection != 'y' && selection != 'n');

    cout << "Specify income category: " ;
    string category;
    category = AuxiliaryMethods::loadLine();
    newIncome.setCategory(category);

    cout << "Enter income value (. as separator): " ;
    float value = AuxiliaryMethods::loadFloatNumber();
    newIncome.setValue(value);

    return newIncome;
}

Date IncomeManager::specyfyIncomeDate(){
    string incomeDateStr;
    Date incomeDate;

    cout << "Specyfy income date (yyyy-mm-dd" << endl;
    incomeDateStr = AuxiliaryMethods::loadLine();
    while(incomeDate.isValidDateFormat(incomeDateStr) == false){
        cout << "Please enter date in correct format yyyy-mm-dd" << endl;
        incomeDateStr = AuxiliaryMethods::loadLine();
    }

    incomeDate.getDateFromString(incomeDateStr);
    return incomeDate;
}

int IncomeManager::getNewIncomeId(){
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}