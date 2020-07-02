#include "ExpensesFile.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

bool ExpensesFile::saveExpenseToFile(Expense expense){
    CMarkup expenseXML;

    if(expenseXML.Load(getFileName())){
        expenseXML.FindElem("Expenses");
        expenseXML.IntoElem();
        while(expenseXML.FindElem("Expense")){
        }
        expenseXML.AddElem("Expense");
        expenseXML.IntoElem();
        expenseXML.AddElem("UserId", expense.getUserId());
        expenseXML.AddElem("Id", expense.getId());
        expenseXML.AddElem("Date", expense.getDateStr());
        expenseXML.AddElem("Category", expense.getCategory());
        expenseXML.AddElem("Value", AuxiliaryMethods::convertFloatToStr(expense.getValue()));
        expenseXML.Save(getFileName());
        lastExpenseId++;
        return true;
    }
    else{
        expenseXML.SetDoc("<?expenseXML version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        expenseXML.AddElem("Expenses");
        expenseXML.IntoElem();
        expenseXML.AddElem("Expense");
        expenseXML.IntoElem();
        expenseXML.AddElem("UserId", expense.getUserId());
        expenseXML.AddElem("Id", expense.getId());
        expenseXML.AddElem("Date", expense.getDateStr());
        expenseXML.AddElem("Category", expense.getCategory());
        expenseXML.AddElem("Value", AuxiliaryMethods::convertFloatToStr(expense.getValue()));
        expenseXML.Save(getFileName());
        lastExpenseId++;
        return true;
    }
    return false;
}

vector <Expense> ExpensesFile::loadExpensesFromFile(int loggedUserId){

    Expense loadedExpense;
    string loadedData = "";
    int loadedIntegerData;
    float loadedFloatData;
    Date loadedExpenseDate;
    vector <Expense> loadedExpenses;

    CMarkup fileWithExpenses;
    fileWithExpenses.ResetPos();

    if(fileWithExpenses.Load(getFileName()) == false){
        cout << "Something went wrong with loading expenses from file" << endl;
        return loadedExpenses;
    }

    fileWithExpenses.FindElem("Expenses");
    fileWithExpenses.IntoElem();
    while(fileWithExpenses.FindElem("Expense")){
        fileWithExpenses.IntoElem();

        fileWithExpenses.FindElem("UserId");
        loadedIntegerData = AuxiliaryMethods::convertStrToInt(fileWithExpenses.GetData());
        if(loadedIntegerData == loggedUserId){
            loadedExpense.setUserId(loadedIntegerData);

            fileWithExpenses.FindElem("Id");
            loadedIntegerData = AuxiliaryMethods::convertStrToInt(fileWithExpenses.GetData());
            loadedExpense.setId(loadedIntegerData);
            lastExpenseId = loadedIntegerData;

            fileWithExpenses.FindElem("Date");
            loadedData = fileWithExpenses.GetData();
            loadedExpenseDate.getDateFromString(loadedData);
            loadedExpense.setDate(loadedExpenseDate);

            fileWithExpenses.FindElem("Category");
            loadedData = fileWithExpenses.GetData();
            loadedExpense.setCategory(loadedData);

            fileWithExpenses.FindElem("Value");
            loadedFloatData = AuxiliaryMethods::convertStrToFloat(fileWithExpenses.GetData());
            loadedExpense.setValue(loadedFloatData);

            loadedExpenses.push_back(loadedExpense);
        }
        else{
            fileWithExpenses.FindElem("Id");
            loadedIntegerData = AuxiliaryMethods::convertStrToInt(fileWithExpenses.GetData());
            lastExpenseId = loadedIntegerData;
        }

        fileWithExpenses.OutOfElem();
    }

    return loadedExpenses;
}

int ExpensesFile::getLastExpenseId(){
    return lastExpenseId;
}
