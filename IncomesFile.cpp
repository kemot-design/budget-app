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

vector <Income> IncomesFile::loadIncomesFromFile(){

    Income loadedIncome;
    string loadedData = "";
    int loadedIntegerData;
    float loadedFloatData;
    Date loadeIncomedDate;
    vector <Income> loadedIncomes;

    CMarkup fileWithIncomes;
    fileWithIncomes.ResetPos();

    if(fileWithIncomes.Load(getFileName()) == false){
        cout << "Something went wrong with loading incomes from file" << endl;
        return loadedIncomes;
    }

    fileWithIncomes.FindElem("Incomes");
    fileWithIncomes.IntoElem();
    while(fileWithIncomes.FindElem("Income")){
        fileWithIncomes.IntoElem();

        fileWithIncomes.FindElem("Id");
        loadedIntegerData = AuxiliaryMethods::convertStrToInt(fileWithIncomes.GetData());
        loadedIncome.setId(loadedIntegerData);

        fileWithIncomes.FindElem("UserId");
        loadedIntegerData = AuxiliaryMethods::convertStrToInt(fileWithIncomes.GetData());
        loadedIncome.setUserId(loadedIntegerData);

        fileWithIncomes.FindElem("Date");
        loadedData = fileWithIncomes.GetData();
        loadeIncomedDate.getDateFromString(loadedData);
        loadedIncome.setDate(loadeIncomedDate);

        fileWithIncomes.FindElem("Category");
        loadedData = fileWithIncomes.GetData();
        loadedIncome.setCategory(loadedData);

        fileWithIncomes.FindElem("Value");
        loadedFloatData = AuxiliaryMethods::convertStrToFloat(fileWithIncomes.GetData());
        loadedIncome.setValue(loadedFloatData);

        loadedIncomes.push_back(loadedIncome);

        fileWithIncomes.OutOfElem();
    }

    return loadedIncomes;
}