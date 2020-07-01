#include "IncomeManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>
#include <time.h>


using namespace std;

IncomeManager::IncomeManager(string incomesFileName, int loggedUserID): incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserID){
    incomes = incomesFile.loadIncomesFromFile(loggedUserID);
    sortIncomesChronologically();
}


void IncomeManager::addNewIncome(){
    Income newIncome;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    newIncome = setNewIncomeData();

    incomes.push_back(newIncome);
    sortIncomesChronologically();
    if(incomesFile.saveIncomeToFile(newIncome)){
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
            incomeDate.specyfyDate();
            newIncome.setDate(incomeDate);
        }
        else{
            cout << "Insert \"y\" or \"n\"" << endl;
        }
    } while(selection != 'y' && selection != 'n');

    cout << "Specify income category: " ;
    string category;
    category = AuxiliaryMethods::loadLine();
    category = AuxiliaryMethods::setFirstLetterUppercaseRestLowercase(category);
    newIncome.setCategory(category);

    cout << "Enter income value (. as separator): " ;
    string valueStr = AuxiliaryMethods::loadLine();

    while(AuxiliaryMethods::isValueFormatOk(valueStr) == false){
        cout << endl << "That is not a valid value format, try again!" << endl;
        valueStr = AuxiliaryMethods::loadLine();
    }
    float value = AuxiliaryMethods::convertStrToFloat(valueStr);
    newIncome.setValue(value);

    return newIncome;
}

int IncomeManager::getNewIncomeId(){
    if (incomes.empty() == true)
        return 1;
    else
        return checkBiggestId() + 1;
}

int IncomeManager::checkBiggestId(){
    int biggestId = 0;
    for(int i = 0 ; i < incomes.size() ; i++){
        if(incomes[i].getId() > biggestId){
            biggestId = incomes[i].getId();
        }
    }
    return biggestId;
}

float IncomeManager::displayCurrentMonthIncomes(){
    Date currentDate;
    currentDate.getTodaysDate();
    float totalIncome = 0;

    for(int i = 0 ; i < incomes.size() ; i++){
        if(incomes[i].getDate().getMonth() == currentDate.getMonth()){
            incomes[i].displayIncome();
            totalIncome += incomes[i].getValue();
        }
    }
    return totalIncome;
}

float IncomeManager::displayPreviousMonthIncomes(){
    Date currentDate;
    currentDate.getTodaysDate();
    float totalIncome = 0;

    for(int i = 0 ; i < incomes.size() ; i++){
        if(incomes[i].getDate().getMonth() == currentDate.getMonth() - 1){
            incomes[i].displayIncome();
            totalIncome += incomes[i].getValue();
        }
    }
    return totalIncome;
}

void IncomeManager::sortIncomesChronologically(){
    int vectorSize = incomes.size();

    for (int i = 0 ; i < vectorSize - 1 ; i++)
    {
        for (int j = i + 1 ; j < vectorSize ; j++)
        {
            if (incomes[i].getDate().getYear() > incomes[j].getDate().getYear())
            {
                swap(incomes[i], incomes[j]);
            }
            else if (incomes[i].getDate().getYear() == incomes[j].getDate().getYear() && incomes[i].getDate().getMonth() > incomes[j].getDate().getMonth())
            {
                swap(incomes[i], incomes[j]);
            }
            else if (incomes[i].getDate().getYear() == incomes[j].getDate().getYear() && incomes[i].getDate().getMonth() == incomes[j].getDate().getMonth() && incomes[i].getDate().getDay() > incomes[j].getDate().getDay())
            {
                swap(incomes[i], incomes[j]);
            }
        }
    }
}

float IncomeManager::displaySpecyfiedPeriodIncomes(Date startDate, Date endDate){
    float totalIncome = 0;

    for(int i = 0 ; i < incomes.size() ; i++){
        if((incomes[i].getDate().isItLaterThan(startDate) && !incomes[i].getDate().isItLaterThan(endDate)) || incomes[i].getDate().isItSameDayAs(startDate)){
            incomes[i].displayIncome();
            totalIncome += incomes[i].getValue();
        }
    }
    return totalIncome;
}
