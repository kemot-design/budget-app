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
