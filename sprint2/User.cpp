#include "User.h"

User::User(){

}

User::User(string userName,string password,string firstName,string lastName){
this->userName=userName;
this->password=password;
this->firstName=firstName;
this->lastName=lastName;
}

void User:: setUserName(string userName){
this->userName=userName;
}

void User:: setPaaword(string password){
this->password=password;
}


void User::setFirstName(string firstName){
this->firstName=firstName;
}


void User::setLastName(string lastName){
this->lastName=lastName;
}

string User::getUserName(){
return userName;
}
string User:: getPassword(){
return password;
}

string User::getFirstName(){

return firstName;
}
string User::getLastName(){
return lastName;
}

string User:: getRole(){
return Role;
}

void User:: print(){
cout<<setw(13)<<firstName<<setw(12)<<lastName<<setw(12)<<userName<<setw(8)<<Role<<endl;
}
