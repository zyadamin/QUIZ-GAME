#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

using namespace std;
#include "User.h"

class Admin : public User
{
    public:

    Admin();
    Admin(string userName,string password,string firstName,string lastName);

    void printAdminList();  //to print Admin list

    bool operator ==(User b);  // operator overloading to check user
};

#endif // ADMIN_H
