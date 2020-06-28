#include "Income.h"
#include "AuxiliaryMethods.h"
#include <iomanip>

using namespace std;

void Income::setId(int newId){
    id = newId;
}

void Income::setUserId(int newUserId){
    userId = newUserId;
}

void Income::setDate(Date newDate){
    date = newDate;
}

void Income::setValue(float newValue){
    value = newValue;
}

void Income::setCategory(string newCategory){
    category = newCategory;
}

int Income::getId(){
    return id;
}

int Income::getUserId(){
    return userId;
}

string Income::getDate(){
    string dateStr = date.getDate();
    return dateStr;
}

float Income::getValue(){
    return value;
}

string Income::getCategory(){
    return category;
}

void Income::displayIncome(){
    date.showDate();
    cout << " $ " << setprecision(2) << fixed << value << " (" << category << ")" << endl;
}

Date Income::getFullDate(){
    return date;
}
