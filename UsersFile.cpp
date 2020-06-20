#include "UsersFile.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

void UsersFile::saveUserToFile(User user){
    CMarkup xml;

    if(xml.Load(getFileName())){
        xml.FindElem("Users");
        xml.IntoElem();
        while(xml.FindElem("User")){

        }
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("Id", user.getId());
        xml.AddElem("Name", user.getName());
        xml.AddElem("Surname", user.getSurname());
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Password", user.getPassword());
        xml.Save(getFileName());
    }
    else{
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("Id", user.getId());
        xml.AddElem("Name", user.getName());
        xml.AddElem("Surname", user.getSurname());
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Password", user.getPassword());
        xml.Save(getFileName());
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
