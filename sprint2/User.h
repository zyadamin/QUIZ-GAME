#ifndef USER_H
#define USER_H

#include <iostream>

#include<iomanip>

using namespace std;

class User
{
   protected:

  string userName;
  string password;
  string firstName;
  string lastName;
  string Role;
public:
    User();
    User(string userName,string password,string firstName,string lastName);


    void setUserName(string userName);
    void setPaaword(string password);
    void setFirstName(string firstName);
    void setLastName(string lastName);

    string getUserName();
    string getPassword();
    string getFirstName();
    string getLastName();
    string getRole();

    void print(); //to print all users


};

#endif // USER_H
