#include "UsersFile.h"
#include "Markup.h"


using namespace std;

void UsersFile::saveUserToFile(User user){
    CMarkup xml;

    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");

    xml.AddElem("Users");
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.Save("Users.xml");

}
