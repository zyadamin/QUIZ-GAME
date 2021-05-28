/* zyad moahmed amin          20180111

   salsabil mohamed hemada    20180121

   manar atef sayed           20180290
*/
#include <iostream>

#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Question.h"
#include "MCQ.h"
#include "TFQ.h"
#include "CQ.h"
#include "Quiz.h"

#include<cstring>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

float Quiz:: mc=0; // to initialize counter
float Quiz:: tf=0;  // to initialize counter
float Quiz:: c=0;  // to initialize counter
int randomList(int list[],int size,int limit);
static int count;  // for id of questions
using namespace std;
int main()
{
int addMC=0,addTF=0,addC=0,type,Delete=0,ID;
int check=0;//number of Quizzes taken
string filename;
string ques,ans;//get line from file
Question z;
    string line;//get line from file
    char Back;
    int c=0;//c is a counter to check
    int Role;
    User test;
   int member;   //index number in vector
vector<Admin> AdminList={Admin("admin1","admin","manar","atef"),Admin("admin2","admin123","zyad","amin")};
vector<Player> PlayerList={Player("player","player","salsabil","mohamed")};
vector<MCQ>MC;
vector<TFQ>TF;
vector<CQ>C;

string name , password,first,last,pass;
int admin,player;//counter to check in login
int change;//to choose what you want to change in update Your name
int wrong=0; //for not valid account in login
int adminChoose,playerchoose;

ifstream file("exam2.txt");
string arrAns[4];//to get answer of MCQ from file

while(!file.eof()){

getline(file,line);

if(line=="MCQ"){

getline(file,line);
string Qu=line;  //put the question in variable

    for(int i=0;i<4;i++){
    getline(file,line);
    arrAns[i]=line;   //put answers in array
        }
   MCQ mcq1(Qu,arrAns);

   mcq1.setID(++count);
   MC.push_back(mcq1);
   }


else if(line=="TF"){
getline(file,line);
string Qu=line;
getline(file,line);
string An=line;

TFQ tf1(Qu,An);
tf1.setID(++count);
TF.push_back(tf1);

}


else if(line=="COMPLETE"){
getline(file,line);
string Qu=line;
getline(file,line);
string An=line;

CQ cq1(Qu,An);
cq1.setID(++count);
C.push_back(cq1);

}

}


cout<<"*******************************************************************"<<endl;
cout<<"           Welcome to the Quiz game program V2.0!"<<endl;
cout<<"******************************************************************* \n"<<endl;
login:
admin=0,player=0;

    if(wrong !=0){

        cout<<"enter valid username and password\n"<<endl;

    }


cout<<"Please enter your username: ";
cin>>name;

cout<<endl;

cout<<"Please enter your password: ";
cin>>password;
cout<<endl;



for(int i=0;i<AdminList.size();i++){

        if(name==AdminList[i].getUserName()&&password==AdminList[i].getPassword()){

            admin++;
            member=i;
    }


    }
     for(int i=0;i<PlayerList.size();i++){

        if(name==PlayerList[i].getUserName()&&password==PlayerList[i].getPassword()){

            player++;
            member=i;
        }

    }

    if(player==0&&admin==0){
            wrong++;
        goto login;
    }
wrong=0;
menu:
    Back=' ';
    if(admin!=0){
        AdminList[member].printAdminList();
        cin>>adminChoose;
    if(adminChoose==1){
        goto login;
    }

else if(adminChoose==2){
cout<<"choose from the following:"<<endl;
cout<<"[1] To change first name"<<endl;
cout<<"[2] To change last name"<<endl;
cout<<"[3] To change password"<<endl;
cin>>change;
while(change<1||change>3){
    cout<<"please,enter a valid choice"<<endl;
    cin>>change;

}
if(change==1){
        cout<<"enter first name\n";
cin>>first;
    AdminList[member].setFirstName(first);
}
else if(change==2){
        cout<<"enter last name\n";
cin>>last;
    AdminList[member].setLastName(last);
}
else if(change==3){
        cout<<"enter password\n";
cin>>pass;
    AdminList[member].setPaaword(pass);
}

cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>Back;
while(Back!='b'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}

}



else if(adminChoose==3){

cout<<"Existing users in the system:"<<endl;
cout<<setw(13)<<"Firstname"<<setw(12)<<"Lastname"<<setw(12)<<"Username"<<setw(8)<<"Role"<<endl;

   for(int i=0;i<AdminList.size();i++){
        AdminList[i].print();

   }
   for(int i=0;i<PlayerList.size();i++){
    PlayerList[i].print();


   }
   cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<  "Press [n] if you want to add a new user or [b] to go back to the main menu."<<endl;
cin>>Back;
while(Back!='b'&&Back!='n'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}
if(Back=='n'){goto add;}
}

else if(adminChoose==4){
    add:
c=0;

    cout<<"enter user name"<<endl;
    cin>>name;
    cout<<"enter your password"<<endl;
    cin>>pass;
    cout<<"enter first and last name "<<endl;
    cin>>first>>last;
    cout<<"please choose type of the user"<<endl;
cout<<"[1] Admin "<<endl;
cout<<"[2] Player"<<endl;
    cin>>Role;
    while(Role!=1&&Role!=2){
        cout<<"please,enter a valid choice"<<endl;
        cin>>Role;
    }
    test.setUserName(name);
    for(int i=0;i<AdminList.size();i++){

        if(AdminList[i]==test){c++;}

    }

        for(int i=0;i<PlayerList.size();i++){

        if(PlayerList[i]==test){c++;}

    }

    if(c!=0){
            cout<<"enter valid user name"<<endl;
        goto add;
    }
else{
    if(Role==1){

    Admin newUser(name,pass,first,last);


    AdminList.push_back(newUser);
    }
     if(Role==2){

    Player newUser(name,pass,first,last);


    PlayerList.push_back(newUser);
    }
}
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>Back;
while(Back!='b'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}


}


else if(adminChoose==5){
repeat:
cout<<"Number of questions available:"<<MC.size()+TF.size()+C.size()<<endl;
cout<<"---------------------------------------------------"<<endl;

cout<<"MC Questions list (Total: "<< MC.size()<< " Questions)"<<endl;
cout<<"---------------------------------------------------"<<endl;

for(int i=0;i<MC.size();i++){
cout<<"["<<i+1<<"]";
MC[i].print();

}

cout<<"---------------------------------------------------"<<endl;
cout<<"TF Questions list (Total: "<<TF.size()<<" Questions)"<<endl;
cout<<"---------------------------------------------------"<<endl;
for(int i=0;i<TF.size();i++){
cout<<"["<<i+1<<"]";
TF[i].print();

}

cout<<"---------------------------------------------------"<<endl;
cout<<"Complete Questions list (Total: "<<C.size()<<" Questions)"<<endl;
cout<<"---------------------------------------------------"<<endl;

for(int i=0;i<C.size();i++){
cout<<"["<<i+1<<"]";
C[i].print();



}
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [d] and the question ID if you want to delete a question (Example: d 2)"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>Back;
while(Back!='b'&&Back!='d'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}

if(Back=='d'){
     Delet:
     Delete=0;
    cin>>ID;
for(int i=0;i<MC.size();i++){

    if(ID==MC[i].getID()){MC.erase(MC.begin()+i);
    Delete++;
    }

}

 for(int i=0;i<TF.size();i++){

    if(ID==TF[i].getID()){TF.erase(TF.begin()+i);
           Delete++;
    }

}

    for(int i=0;i<C.size();i++){

    if(ID==C[i].getID()){C.erase(C.begin()+i);
           Delete++;
    }

}
  if(Delete==0){

    cout<<"ID not found"<<endl<<"enter valid ID"<<endl;
    goto Delet;
  }
}
if(Back!='b'){
goto repeat;
}
}


    else if(adminChoose==6){

 addQuestion:
    addC=0;
    addMC=0;
    addTF=0;
        cout<<"choose type the question"<<endl;
        cout<<"[1] MC Question \n"<<"[2] TF Question \n"<<"[3] Complete Questions \n";
        cin>>type;
        while(type<1||type>3){
            cout<<"please,enter a valid choice"<<endl;
            cin>>type;
        }
        cout<<"enter the question"<<endl;
          cin.ignore();
     getline(cin,ques);
        z.setquestion(ques);

for(int i=0;i<MC.size();i++){
if(MC[i]==z.getquestion()){addMC++;}
            }
for(int i=0;i<TF.size();i++){
    if(TF[i]==z.getquestion()){addTF++;}
            }
for(int i=0;i<C.size();i++){
    if(C[i]==z.getquestion()){addC++;}
            }




if(addMC!=0||addTF!=0||addC!=0){
    cout<<"the question already existed:"<<endl;
    cout<<"Please,enter valid question"<<endl;
    goto addQuestion;
}

else{
    if(type==1){
        cout<<"enter answer"<<endl;
        for(int i=0;i<4;i++){
            cin>>arrAns[i];
        }
       MCQ mcq2(ques,arrAns);
         mcq2.setID(++count);
        MC.push_back(mcq2);
    }

      if(type==2){
        cout<<"enter answer"<<endl;
       cin>>ans;
         TFQ tf2(ques,ans);
        tf2.setID(++count);
        TF.push_back(tf2);
    }


      if(type==3){
        cout<<"enter answer"<<endl;
       cin>>ans;
         CQ cq2(ques,ans);
            cq2.setID(++count);
        C.push_back(cq2);
    }
}
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>Back;
while(Back!='b'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}


}
else if(adminChoose==7){
    cout<<"Enter file name and path   EX: D:\\Assignment2\\exam2"<<endl;
    cin.ignore();
    getline(cin,filename);
    ifstream newfile(filename+".txt");
    while(!newfile.is_open()){
    cout<<"try again"<<endl;
    cin>>filename;
    newfile.open(filename+".txt",ios::in);
    }
addC=addMC=addTF=0;

while(!newfile.eof()){

getline(newfile,line);

if(line=="MCQ"){
getline(newfile,line);
string Qu=line;
z.setquestion(Qu);
for(int i=0;i<MC.size();i++){
if(MC[i]==z.getquestion()){addMC++;}
}


for(int i=0;i<4;i++){
    getline(newfile,line);
    arrAns[i]=line;
        }

if(addMC==0){


   MCQ mcq1(Qu,arrAns);
   mcq1.setID(++count);
   MC.push_back(mcq1);
}

   }


else if(line=="TF"){
getline(newfile,line);
string Qu=line;
z.setquestion(Qu);
for(int i=0;i<TF.size();i++){
    if(TF[i]==z.getquestion()){addTF++;}
            }
getline(newfile,line);
string An=line;
if(addTF==0){
TFQ tf1(Qu,An);
tf1.setID(++count);
TF.push_back(tf1);
}
}


else if(line=="COMPLETE"){
getline(newfile,line);
string Qu=line;
z.setquestion(Qu);
for(int i=0;i<C.size();i++){
    if(C[i]==z.getquestion()){addC++;}
            }
getline(newfile,line);
string An=line;
if(addC==0){
CQ cq1(Qu,An);
cq1.setID(++count);
C.push_back(cq1);
}
}

}


cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>Back;
while(Back!='b'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}



}
else if(adminChoose==8){cout<<"thank you for using our application"<<endl;}

while(adminChoose<1||adminChoose>8){
cout<<"please,enter a valid choose"<<endl;
goto menu;}

    }


    else{

PlayerList[member].printPlayerList();
        cin>>playerchoose;
    if(playerchoose==1){
        goto login;
    }

else if(playerchoose==2){
cout<<"choose from the following:"<<endl;
cout<<"[1] To change first name"<<endl;
cout<<"[2] To change last name"<<endl;
cout<<"[3] To change password"<<endl;
cin>>change;
while(change<1||change>3){
    cout<<"please,enter a valid choice"<<endl;
    cin>>change;

}
if(change==1){
        cout<<"enter first name\n";
cin>>first;
    PlayerList[member].setFirstName(first);
}
else if(change==2){
        cout<<"enter last name\n";
cin>>last;
    PlayerList[member].setLastName(last);
}
else if(change==3){
        cout<<"enter password\n";
cin>>pass;
    PlayerList[member].setPaaword(pass);
}

cout<<"Press [b] if you want to go back to the main menu"<<endl;
cout<<"My choice: ";
cin>>Back;
}

else if(playerchoose==3){

        if(MC.size()<2||TF.size()<2||C.size()<1){
          cout<<"not valid quiz now"<<endl;
        goto menu;

        }

else{
check++;
Question* quess[5];

int randMC[2],randTF[2],randC[1];

randomList(randMC,2,MC.size());
randomList(randTF,2,TF.size());
randomList(randC,1,C.size());

quess[0]=&MC[randMC[0]];
quess[1]=&MC[randMC[1]];
quess[2]=&TF[randTF[0]];
quess[3]=&TF[randTF[1]];
quess[4]=&C[randC[0]];

Quiz quiz1(quess);

PlayerList[member].startNew(quiz1);

cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>Back;
while(Back!='b'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}
}

}




else if(playerchoose==4){
       if( check==0){cout<<"Please, Take Quiz\n "<<endl;
       Back='b';


       }

else{


PlayerList[member].maxSum(); //print highest score
PlayerList[member].minSum();  //print lowest score
PlayerList[member].average();  //print average

PlayerList[member].getRight();
PlayerList[member].getaverage();

cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu or [e] to exit:"<<endl;
cout<<"My choice: ";
cin>>Back;

while(Back!='b' && Back!='e'){
    cout<<"please, enter a valid choice"<<endl;
    cin>>Back;
}
}
}

else if(playerchoose==5){

       if( check==0){cout<<"Please, Take Quiz\n "<<endl;
       Back='b';
       }
       else{
    PlayerList[member].getAllScore();

cout<<"-----------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu "<<endl;
cout<<"My choice: ";
cin>>Back;
}

}


else if(playerchoose ==6){
       if( check==0){cout<<"Please, Take Quiz\n "<<endl;
       Back='b';}
       else{
    PlayerList[member].lastQuiz();

cout<<"-----------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cout<<"My choice: ";
cin>>Back;
       }
}

 if(playerchoose==7|| Back=='e'){cout<<"thank you for using our application"<<endl;}


while(playerchoose<1||playerchoose>7){
cout<<"please,enter a valid choose"<<endl;
cout<<endl;
goto menu;
}
}



if(Back=='b'){

    goto menu;
}

    return 0;

}


int randomList(int list[5],int size,int limit){
int k, c=0;
vector<int>li(1);
li[0]=-1;
srand(time(0));
do{
k=rand()%limit;

for(int i=0;i<li.size();i++){
    if(k==li[i]){c++;}
}
if(c==0){li.push_back(k);}
c=0;
}while(li.size()!=size+1);
li.erase(li.begin());

for(int i=0;i<size;i++){
    list[i]=li[i];
}

}
