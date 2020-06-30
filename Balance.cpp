#include "Balance.h"
#include <windows.h>

using namespace std;




void Balance::displayCurrentMonthBalance(){
    system("cls");
    float totalIncome = 0;
    float totalExpense = 0;

    cout<< "--------------------" << endl;
    cout<< "Current month balance" << endl;
    cout<< "--------------------" << endl;
    cout << "Incomes" << endl;
    totalIncome = incomeManager -> displayCurrentMonthIncomes();
    cout << endl << "Expenses" << endl;
    totalExpense = expenseManager -> displayCurrentMonthExpenses();
    cout << endl << "Total incomes: " << totalIncome << " $" << endl;
    cout << "Total expense: " << totalExpense << " $" << endl;
    cout << "Current month balance: " << totalIncome - totalExpense << " $" << endl;
    system("pause");
}

void Balance::displayPreviousMonthBalance(){
    system("cls");
    float totalIncome = 0;
    float totalExpense = 0;

    cout<< "--------------------" << endl;
    cout<< "Previous month balance" << endl;
    cout<< "--------------------" << endl;
    cout << "Incomes" << endl;
    totalIncome = incomeManager -> displayPreviousMonthIncomes();
    cout << endl << "Expenses" << endl;
    totalExpense = expenseManager -> displayPreviousMonthExpenses();
    cout << endl << "Total incomes: " << totalIncome << " $" << endl;
    cout << "Total expense: " << totalExpense << " $" << endl;
    cout << "Current month balance: " << totalIncome - totalExpense << " $" << endl;
    system("pause");
}

void Balance::displaySpecyfiedPeriodBalance(){
    system("cls");
    cout << "Please enter period start date" << endl;
    Date startDate;
    startDate.specyfyDate();
    cout << "Please enter period end date" << endl;
    Date endDate;
    endDate.specyfyDate();

    float totalIncome = 0;
    float totalExpense = 0;

    system("cls");
    cout << "--------------------" << endl;
    startDate.showDate();
    cout << " - ";
    endDate.showDate();
    cout << " balance" << endl;
    cout << "--------------------" << endl;
    cout << "Incomes" << endl;
    totalIncome = incomeManager -> displaySpecyfiedPeriodIncomes(startDate, endDate);
    cout << endl << "Expenses" << endl;
    totalExpense = expenseManager -> displaySpecyfiedPeriodExpenses(startDate, endDate);
    cout << endl << "Total incomes: " << totalIncome << " $" << endl;
    cout << "Total expense: " << totalExpense << " $" << endl;
    cout << "Current month balance: " << totalIncome - totalExpense << " $" << endl;
    system("pause");


}

