#include "Quiz.h"

Quiz::Quiz()
{
    //ctor
}

Quiz:: Quiz(Question* ques[5]){
for(int i=0;i<5;i++){
this->ques[i]=ques[i];}

}


void Quiz:: start(){

for(int i=0;i<5;i++){

if(i==0){cout<<"\n(a) MC Questions\n----------------------------------"<<endl;}
if(i==2){cout<<"\n(b) TF Questions\n-----------------------------------"<<endl;}
if(i==4){cout<<"\n(c) Complete Questions\n-------------------------------------"<<endl;}

cout<<"["<<i+1<<"] ";
ques[i]->printq();

arr[i]=ques[i]->answerScore();


sum+=arr[i];

if(arr[i]==0){wrong++;}


if(i==0||i==1){
    if(arr[i]!=0){mc++;}
}
if(i==2||i==3){
    if(arr[i]!=0){tf++;}
}
if(i==4){
    if(arr[i]!=0){c++;}

}

}
right=5-wrong;

cout<<"score = "<<sum<<"/9"<<endl;
cout<<"number of right answers : "<<right<<endl<<"number of wrong answers : "<<wrong<<endl;

}

void Quiz:: rightAnswer(){

cout<<"---------------------------------------------------------------------------------------"<<endl;
cout<<"Your score statistics per question type: "<<endl;
cout<<"- Number of MC questions: "<<mc<<endl;
cout<<"- Number of Complete questions: "<<c<<endl;
cout<<"- Number of T/F Questions: "<<tf<<endl;


}


void Quiz:: allScore(){

cout<<"score = "<<sum<<"/9"<<endl;
cout<<"number of right answers : "<<right<<endl<<"number of wrong answers : "<<wrong<<endl;
cout<<"---------------------------------------------------------------------------------------"<<endl;

}

float Quiz::getmc(){
return mc;
}
float Quiz::gettf(){
return tf;
}
float Quiz::getc(){
return c;
}
int Quiz::getSum(){
return sum;
}


void Quiz:: last2(){

for(int i=0;i<5;i++){
if(i==0){cout<<"\n(a) MC Questions\n----------------------------------"<<endl;}
if(i==2){cout<<"\n(b) TF Questions\n-----------------------------------"<<endl;}
if(i==4){cout<<"\n(c) Complete Questions\n-------------------------------------"<<endl;}

cout<<"["<<i+1<<"] ";
ques[i]->printWith();


}


}

