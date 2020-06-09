#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include <cstdlib>

using namespace std;

UserManager::UserManager(){
    loggedUserId = 0;
}

void UserManager::registerUser(){
    User user = setNewUserData();

    users.push_back(user);

    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Your account was successfully registered" << endl << endl;
    system("pause");
}

User UserManager::setNewUserData(){
    User user;

    user.setId(getNewUserId());

    string name, surname, login, password;

    cout << "Name: ";
    name = AuxiliaryMethods::loadLine();
    name = AuxiliaryMethods::setFirstLetterUppercaseRestLowercase(name);
    user.setName(name);

    cout << "Surname: ";
    surname = AuxiliaryMethods::loadLine();
    surname = AuxiliaryMethods::setFirstLetterUppercaseRestLowercase(surname);
    user.setSurname(surname);

    do
    {
        cout << "Login: ";
        login = AuxiliaryMethods::loadLine();
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Password: ";
    password = AuxiliaryMethods::loadLine();
    user.setPassword(password);

    return user;

}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login){
    for(int i = 0 ; i < users.size() ; i++){
        if(users[i].getLogin() == login){
            cout << endl << "Login already exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loginUser(){
    User user;
    string login = "", password = "";

    cout << "Your login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Your password (attempts left : " << attempts << ") : ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You are logged in." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getId();
                    cout << "Id zalogowanego uzytkownika = " << loggedUserId << endl;
                    system("pause");
                    return;
                }
            }
            cout << "You have entered wrong password 3 times." << endl;
            system("pause");
            loggedUserId = 0;
            return;
        }
        itr++;
    }
    cout << "There is no user with that login" << endl << endl;
    system("pause");
    loggedUserId = 0;
}
