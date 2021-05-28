/*
zyad mohamed amin .........   20180111
manar atef sayed  .........   20180290
salsabil mohamed hemeda ..... 20180121

*/

#include <iostream>
#include <fstream>
#include<string.h>
#include<vector>
#include<ctime>
#include<cstdlib>

int randomList(int list[],int size,int limit);
void menu1();
void menu2();

using namespace std;
int main()
{
vector<string>quest(8);
vector<string>ans(32);
vector<int>right;
vector<int>wrong;

int high=0,low=6;
float numOfQuize=0,sum=0;

int c=0;

char x;
int choose,choose1,y;
string q,name="USER";


ifstream open("out.txt");
for(int i=0;i<8;i++){
getline(open,q);
quest[i]=q;

for(int j=0;j<4;j++){
getline(open,q);
ans[j+c]=q;

}
c+=4;

}
open.close();


do{
 x={};
menu1();
cout<<"My choice: ";

cin>>choose;
while(choose>6 || choose<1){
    cout<<"Pleas Enter Number from 1 to 6 "<<endl;
    cin>>choose;
}
cout<<endl;

if(choose==1){
do{
x={};
 menu2();
cout<<"My choice:  ";

cin>>choose1;
while(choose1>4 || choose1<1){
    cout<<"Pleas Enter Number from 1 to 4 "<<endl;
    cin>>choose1;
}
cout<<endl;

if(choose1==1){

do{
c=0;
cout<<"Number of questions available: "<<quest.size()<<endl;
cout<<"Questions list: "<<endl;
cout<<"-------------------"<<endl;

for(int i=0;i<quest.size();i++){
cout<<"["<<i+1<<"] "<<quest[i]<<endl;

cout<<"   *[a]"<<ans[c]<<"   [c]"<<ans[1+c]<<"   [d]"<<ans[2+c]<<"   [e]"<<ans[3+c]<<endl;


c+=4;
  }
cout<<"-------------------------------------------------------------------------------------"<<endl;

cout<<"Press [d] and the question ID if you want to delete a question (Example: d 2)"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;

cin>>x;
while(x!='b'&&x!='d'){
cout<<"Pleas, Enter Valid Char "<<endl;
cin>>x;
}

if(x=='d'){
c=0;
cin>>y;
while(y<1  || y>quest.size() ){

cout<<"Pleas, Enter Valid Number "<<endl;
cin>>y;
}

int z=y-1;
c=z*4;
quest.erase(quest.begin()+z);
for(int i=0;i<4;i++){
ans.erase(ans.begin()+i+c);
}
}


}while( x=='d');

}

else if(choose1 ==2){
int numOfAdd;
cout<<"Pleas Enter Number Of Questions "<<endl;
cin>>numOfAdd;

while(numOfAdd<0){
 cout<<"Pleas Enter Valid Number "<<endl;
cin>>numOfAdd;
}
for(int i=0;i<numOfAdd;i++){
    cout<<"Pleas Enter Question"<<endl;

cin.ignore();
getline(cin ,q);
quest.push_back(q);

for(int i=0;i<4;i++){
cout<<"choice"<<i+1<<": ";
getline(cin ,q);
ans.push_back(q);
}
}
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [a] if you want to go back to the administration menu"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>x;
while(x!='a'&&x!='b'){
cout<<"Please,Enter Valid Char"<<endl;
 cin>>x;
}
}


else if(choose1 ==3){
string fileNAme;


cout<<"enter file name and pass  Ex: D:\\Assignment1\\out "<<endl;
cin.ignore();
getline(cin,fileNAme);
ifstream open(fileNAme+".txt");
while(!open.is_open()){
   // open.clear();
    cout<<"try again!"<<endl;
    cin>>fileNAme;
    open.open(fileNAme+".txt",ios::in);
}

while(!open.eof()){
getline(open,q);
quest.push_back(q);
for(int i=0;i<4;i++){
getline(open,q);
ans.push_back(q);
}

}
open.close();
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [a] if you want to go back to the administration menu"<<endl;
cout<<"Press [b] if you want to go back to the main menu"<<endl;
cin>>x;
while(x!='a'&&x!='b'){
cout<<"Please,Enter Valid Char"<<endl;
 cin>>x;
}

}

}while(x=='a');

}

else if(choose==2){
cout<<"pleas enter new name: "<<endl;
cout<<"------------------------------"<<endl;
cin.ignore();
getline(cin,name);
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] to go back to the main menu"<<endl;
cin>>x;
while(x!='b'){
cout<<"Please,Enter Valid Char"<<endl;
cin>>x;

}
}
char answer;
int w=0,r=0;

 if(choose==3){
if(quest.size()<5){
cout<<"Pleas Add More Question! "<<endl;
cout<<endl;
x='b';
}

else{
numOfQuize++;
cout<<"name is: "<<name<<endl;
cout<<"number of quiz is: "<<numOfQuize<<endl;
cout<<"-------------------"<<endl;

int randQ[5],randA[4];
randomList(randQ,5,quest.size());

for(int i=0;i<5;i++){

randomList(randA,4,4);


c=randQ[i]*4;
cout<<"["<<i+1<<"] "<<quest[randQ[i]]<<endl;
cout<<"   [a]"<<ans[randA[0]+c]<<"   [c]"<<ans[randA[1]+c]<<"   [d]"<<ans[randA[2]+c]<<"   [e]"<<ans[randA[3]+c]<<endl;


string ansa,ansc,ansd,anse;

ansa=ans[randA[0]+c];
ansc=ans[randA[1]+c];
ansd=ans[randA[2]+c];
anse=ans[randA[3]+c];
cout<<"your answer: ";
cin>>answer;
while(answer!='a'&&answer!='c'&&answer!='d'&&answer!='e'){
    cout<<"Please,Enter Valid Char"<<endl;
cin>>answer;
}
if(answer=='a'){
    if(ansa==ans[c]){r++;}
    else{w++;}
}

else if(answer=='c'){
    if(ansc==ans[c]){r++;}
    else{w++;}
}

else if(answer=='d'){
    if(ansd==ans[c]){r++;}
    else{w++;}
}

else if(answer=='e'){
    if(anse==ans[c]){r++;}
    else{w++;}
}
}
right.push_back(r);
wrong.push_back(w);

if(r>high){high=r;}
if(r<low){low=r;}


sum+=r;
cout<<endl;
cout<<"your score: "<<right[numOfQuize-1]<<"/5"<<endl;
cout<<"number of right answers: "<<right[numOfQuize-1]<<endl;
cout<<"number of wrong answers: "<<wrong[numOfQuize-1]<<endl;

cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] to go back to the main menu"<<endl;
cin>>x;
while(x!='b'){
cout<<"Please,Enter Valid Char"<<endl;
cin>>x;

}
}
}

 if(choose==4){
if(numOfQuize==0){
    low=0;
}
cout<<"Your score statistics:"<<endl;
cout<<"         - Number of Quizzes taken: "<<numOfQuize<<endl;
cout<<"         - Highest score: "<<high<<endl;
cout<<"         - Lowest score:  "<<low<<endl;
cout<<"         - Average score: "<<sum/numOfQuize<<endl;

cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Press [b] if you want to go back to the main menu or [e] to exit"<<endl;

cout<<"My choice: ";
cin>>x;
while(x!='b'&&x!='e'){
cout<<"Please,Enter Valid Char"<<endl;
cin>>x;

}

}

else if(choose==5){
cout<<" Number of Quizzes taken: "<<numOfQuize<<endl;
    for(int i=0;i<right.size();i++){
        cout<<"Score in Quiz "<<i+1<<"  : "<<right[i]<<"/5"<<endl;
cout<<"number of right answers: "<<right[i]<<endl;
cout<<"number of wrong answers: "<<wrong[i]<<endl;
cout<<"---------------------------"<<endl;
    }
cout<<"Press [b] to go back to the main menu"<<endl;
cin>>x;
while(x!='b'){
cout<<"Please,Enter Valid Char"<<endl;
cin>>x;

}

}

}while(choose1 ==4 ||x=='b');

cout<<endl;
if(choose==6||x=='e'){cout<<"Thanks for using our application"<<endl;}



    return 0;
}
void menu1(){
cout<<"Welcome USER, please choose from the following options:"<<endl;
cout<<"[1] Go to administration menu"<<endl;
cout<<"[2] Update your name "<<endl;
cout<<"[3] Start a new quiz "<<endl;
cout<<"[4] Display your scores statistics "<<endl;
cout<<"[5] Display all your scores"<<endl;
cout<<"[6] Exit"<<endl;}

void menu2(){
cout<<"Welcome to the administration menu, please choose from the following options:"<<endl;
cout<<"[1] View all questions"<<endl;
cout<<"[2] Add new question"<<endl;
cout<<"[3] Load questions from file"<<endl;
cout<<"[4] Go back to main menu"<<endl;}


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


