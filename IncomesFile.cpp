#include "IncomesFile.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

bool IncomesFile::saveIncomeToFile(Income income){
    CMarkup incomeXML;

    if(incomeXML.Load(getFileName())){
        incomeXML.FindElem("Incomes");
        incomeXML.IntoElem();
        while(incomeXML.FindElem("Income")){
        }
        incomeXML.AddElem("Income");
        incomeXML.IntoElem();
        incomeXML.AddElem("Id", income.getId());
        incomeXML.AddElem("UserId", income.getUserId());
        incomeXML.AddElem("Date", income.getDate());
        incomeXML.AddElem("Category", income.getCategory());
        incomeXML.AddElem("Value", income.getValue());
        incomeXML.Save(getFileName());
        return true;
    }
    else{
        incomeXML.SetDoc("<?incomeXML version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        incomeXML.AddElem("Incomes");
        incomeXML.IntoElem();
        incomeXML.AddElem("Income");
        incomeXML.IntoElem();
        incomeXML.AddElem("Id", income.getId());
        incomeXML.AddElem("UserId", income.getUserId());
        incomeXML.AddElem("Date", income.getDate());
        incomeXML.AddElem("Category", income.getCategory());
        incomeXML.AddElem("Value", income.getValue());
        incomeXML.Save(getFileName());
        return true;
    }
    return false;
}

