#include "MoneyOperation.h"
#include "AuxiliaryMethods.h"
#include <iomanip>

using namespace std;

void MoneyOperation::setId(int newId){
    id = newId;
}

void MoneyOperation::setUserId(int newUserId){
    userId = newUserId;
}

void MoneyOperation::setDate(Date newDate){
    date = newDate;
}

void MoneyOperation::setValue(float newValue){
    value = newValue;
}

void MoneyOperation::setCategory(string newCategory){
    category = newCategory;
}

int MoneyOperation::getId(){
    return id;
}

int MoneyOperation::getUserId(){
    return userId;
}

string MoneyOperation::getDateStr(){
    string dateStr = date.getDate();
    return dateStr;
}

float MoneyOperation::getValue(){
    return value;
}

string MoneyOperation::getCategory(){
    return category;
}

void MoneyOperation::displayOperation(){
    date.showDate();
    cout << " $ " << setprecision(2) << fixed << value << " (" << category << ")" << endl;
}

Date MoneyOperation::getDate(){
    return date;
}
