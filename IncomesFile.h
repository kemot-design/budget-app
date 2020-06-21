#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "Income.h"

using namespace std;

class IncomesFile: XMLFile{

public:
    IncomesFile(string incomesFileName): XMLFile(incomesFileName) {};
    bool saveIncomeToFile(Income income);
    //vector <Income> loadIncomesFromFile();
};
#endif
