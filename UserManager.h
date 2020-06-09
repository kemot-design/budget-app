#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"


using namespace std;

class UserManager{
    vector <User> users;
    int loggedUserId;
    //UsesFile usersFile;

    User setNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
    UserManager();
    void registerUser();

};


#endif // USERMANAGER_H
