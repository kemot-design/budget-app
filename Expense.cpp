#include "Expense.h"
#include "AuxiliaryMethods.h"
#include <iomanip>

void Expense::displayExpense(){
    getDate().showDate();
    cout << " $ " << setprecision(2) << fixed << getValue() << " (" << getCategory() << ")" << endl;
}

