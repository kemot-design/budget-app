#include "Expense.h"
#include "AuxiliaryMethods.h"
#include <iomanip>

void Expense::displayExpense(){
    cout << getDate();
    cout << " $ " << setprecision(2) << fixed << getValue() << " (" << getCategory() << ")" << endl;
}

