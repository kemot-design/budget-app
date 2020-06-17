#include "IncomeManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>
#include <time.h>


using namespace std;

void IncomeManager::addNewIncome(){
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = setNewIncomeData();

    incomes.push_back(income);
    /*if(plikZAdresatami.dopiszAdresataDoPliku(adresat)){
        cout << "Nowy adresat zostal dodany" << endl;
    }
    else {
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    }*/
    system("pause");
}

Income IncomeManager::setNewIncomeData(){
    Income newIncome;
    char selection;
    Date incomeDate;

    cout << "Is the income from today? (y/n)" << endl;

    do{
        selection = AuxiliaryMethods::loadChar();

        if(selection == 'y'){
            incomeDate.getTodaysDate();
            newIncome.setDate(incomeDate);
            incomeDate.showDate();
        }
        else if(selection == 'n'){
            incomeDate = specyfyIncomeDate();
            newIncome.setDate(incomeDate);
            incomeDate.showDate();
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
    float value;
    cin >> value; //implement loadFloat in Auxiliary methods
    newIncome.setValue(value);
}

Date IncomeManager::specyfyIncomeDate(){
    string incomeDateStr;
    Date incomeDate;

    cout << "Specyfy income date (yyyy-mm-dd" << endl;
    incomeDateStr = AuxiliaryMethods::loadLine();
    incomeDate.getDateFromString(incomeDateStr);
    return incomeDate;
}
