#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"


using namespace std;

class UserManager{
    vector <User> users;
    int loggedUserId;
    UsersFile usersFile;

    User setNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
    UserManager(string usersFileName);
    void registerUser();
    void loginUser();
    bool isUserLoggedIn();
    void changeUserPassword();
    void logoutUser();

};


#endif // USERMANAGER_H
