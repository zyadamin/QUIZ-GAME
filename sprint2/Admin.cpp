#include "Admin.h"

Admin::Admin(){


}

Admin::Admin(string userName,string password,string firstName,string lastName):User( userName,password, firstName,lastName){

Role="admin";
}

void Admin:: printAdminList(){

cout<<"Welcome ("<<firstName<<"), please choose from the following options:"<<endl;
cout<<"[1] Switch accounts"<<endl;
cout<<"[2] Update your name"<<endl;
cout<<"[3] View all users"<<endl;
cout<<"[4] Add new user"<<endl;
cout<<"[5] View all questions"<<endl;
cout<<"[6] Add new question"<<endl;
cout<<"[7] Load questions from file"<<endl;
cout<<"[8] Exit"<<endl;
cout<<"My choice: ";
}

 bool Admin:: operator ==( User b){
    if(userName==b.getUserName()){
        return 1;}

    else{return 0;}

    }
