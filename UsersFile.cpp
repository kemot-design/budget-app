#include "UsersFile.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

void UsersFile::saveUserToFile(User user){
    CMarkup fileWithUsers;

    if(fileWithUsers.Load(getFileName())){
        fileWithUsers.FindElem("Users");
        fileWithUsers.IntoElem();
        while(fileWithUsers.FindElem("User")){
        }
        fileWithUsers.AddElem("User");
        fileWithUsers.IntoElem();
        fileWithUsers.AddElem("Id", user.getId());
        fileWithUsers.AddElem("Name", user.getName());
        fileWithUsers.AddElem("Surname", user.getSurname());
        fileWithUsers.AddElem("Login", user.getLogin());
        fileWithUsers.AddElem("Password", user.getPassword());
        fileWithUsers.Save(getFileName());
    }
    else{
        fileWithUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        fileWithUsers.AddElem("Users");
        fileWithUsers.IntoElem();
        fileWithUsers.AddElem("User");
        fileWithUsers.IntoElem();
        fileWithUsers.AddElem("Id", user.getId());
        fileWithUsers.AddElem("Name", user.getName());
        fileWithUsers.AddElem("Surname", user.getSurname());
        fileWithUsers.AddElem("Login", user.getLogin());
        fileWithUsers.AddElem("Password", user.getPassword());
        fileWithUsers.Save(getFileName());
    }
}

vector <User> UsersFile::loadUsersFromFile(){

    User loadedUser;
    string data = "";
    int integerData;
    vector <User> loadedUsers;

    CMarkup fileWithUsers;
    fileWithUsers.ResetPos();

    if(fileWithUsers.Load(getFileName()) == false){
        cout << "Something went wrong with loading users from file" << endl;
        return loadedUsers;
    }

    fileWithUsers.FindElem("Users");
    fileWithUsers.IntoElem();
    while(fileWithUsers.FindElem("User")){
        fileWithUsers.IntoElem();

        fileWithUsers.FindElem("Id");
        integerData = AuxiliaryMethods::convertStrToInt(fileWithUsers.GetData());
        loadedUser.setId(integerData);

        fileWithUsers.FindElem("Name");
        data = fileWithUsers.GetData();
        loadedUser.setName(data);

        fileWithUsers.FindElem("Surname");
        data = fileWithUsers.GetData();
        loadedUser.setSurname(data);

        fileWithUsers.FindElem("Login");
        data = fileWithUsers.GetData();
        loadedUser.setLogin(data);

        fileWithUsers.FindElem("Password");
        data = fileWithUsers.GetData();
        loadedUser.setPassword(data);

        loadedUsers.push_back(loadedUser);

        fileWithUsers.OutOfElem();
    }

    return loadedUsers;
}

void UsersFile::changeUserPasswordInFile(string newPassword, int loggedUserId){
    CMarkup fileWithUsers;
    int userId = 0;

    if(fileWithUsers.Load(getFileName())){
        fileWithUsers.FindElem("Users");
        fileWithUsers.IntoElem();
        while(fileWithUsers.FindElem("User")){
            fileWithUsers.IntoElem();
            fileWithUsers.FindElem("Id");
            userId = AuxiliaryMethods::convertStrToInt(fileWithUsers.GetData());
            if(userId == loggedUserId){
                fileWithUsers.FindElem("Password");
                fileWithUsers.SetData(newPassword);
                fileWithUsers.Save(getFileName());
                return;
            }
            fileWithUsers.OutOfElem();
        }
    }
    else{
        cout << "Something wrong with user file" << endl;
    }
}

