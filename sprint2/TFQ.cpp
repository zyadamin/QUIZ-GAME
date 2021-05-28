#include "TFQ.h"

TFQ::TFQ(){}

TFQ:: TFQ(string question,string answer):Question(question){
this->answer=answer;
}


void TFQ:: print(){
cout<<"(ID:"<<id<<")"<<question<<"(Answer: " <<answer<<")\n"<<endl;
}



int TFQ::answerScore(){

if(playerAnswer==answer){return 1;}

else{return 0;}

}


bool TFQ:: operator ==( Question q){
    if(question==q.getquestion()){

   return 1;
    }
    else{return 0;}
}

void TFQ:: printWith(){

cout<<question<<endl;
cout<<"your answer: ";
cout<<playerAnswer<<"       ";
if(playerAnswer==answer){cout<<"Right"<<setw(12)<<"score: 1"<<endl;}
else {
        cout<<"wrong"<<setw(12)<<"score : 0"<<endl;
        cout<<"Right answer :"<<answer<<endl;
}

    }
