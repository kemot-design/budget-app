#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

void Income::setDate(Date newDate){
    date = newDate;
}

void Income::setValue(float newValue){
    value = newValue;
}

void Income::setCategory(string newCategory){
    category = newCategory;
}

Date Income::getDate(){
    return date;
}

float Income::getValue(){
    return value;
}

string Income::getCategory(){
    return category;
}

