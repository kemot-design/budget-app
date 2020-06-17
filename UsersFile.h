#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "User.h"

using namespace std;

class UsersFile: XMLFile{

public:
    UsersFile(string usersFileName): XMLFile(usersFileName) {};
    void saveUserToFile(User user);
};
#endif
