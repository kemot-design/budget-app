#include "Expense.h"
#include "AuxiliaryMethods.h"

void Expense::displayExpense(){
    cout << getDate();
    cout << " $ " << getValue() << " (" << getCategory() << ")" << endl;
}

