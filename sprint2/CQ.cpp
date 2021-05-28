#include "CQ.h"

CQ::CQ(){}

CQ:: CQ(string question,string answer):Question(question){

this->answer=answer;
}


void CQ:: print(){

cout<<"(ID:"<<id<<")"<<question<<"(Answer: " <<answer<<")\n"<<endl;
}

int CQ::answerScore(){

if(playerAnswer==answer){return 3;}

else{return 0;}

}


bool CQ:: operator ==( Question q){
    if(question==q.getquestion()){
    return 1;
    }
    else{return 0;}

    }


void CQ:: printWith(){

cout<<question<<endl;
cout<<"your answer: ";
cout<<playerAnswer<<"       ";
if(playerAnswer==answer){cout<<"Right"<<setw(9)<<"score: 3"<<endl;}
else {
    cout<<"wrong"<<setw(12)<<"score : 0"<<endl;
    cout<<"Right answer :"<<answer<<endl;
}


    }
