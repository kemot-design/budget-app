#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "Income.h"

using namespace std;

class IncomesFile: XMLFile{
    int lastIncomeId;

public:
    IncomesFile(string incomesFileName): XMLFile(incomesFileName), lastIncomeId(0) {};
    bool saveIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int loggedUserId);
    int getLastIncomeId();
};
#endif
