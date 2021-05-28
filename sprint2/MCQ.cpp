#include "MCQ.h"

MCQ::MCQ(){}

MCQ::MCQ(string question,string answer[4]):Question(question){

for(int i=0;i<4;i++){
    this->answer[i]=answer[i];}

}


void MCQ:: print(){

cout<<"(ID:"<<id<<")"<<question<<endl;
cout<<" *[a]"<<answer[0]<<"    [b]"<<answer[1]<<"    [c]"<<answer[2]<<"    [d]"<<answer[3]<<endl;

}


void MCQ:: printq(){

randomList( randA ,4 ,4);
cout<<question<<endl;
cout<<"  [a]"<<answer[randA[0]]<<"    [b]"<<answer[randA[1]]<<"    [c]"<<answer[randA[2]]<<"    [d]"<<answer[randA[3]]<<endl;
cout<<"your answer: ";
cin>>playerAnswer;

}



int MCQ::answerScore(){

string  ansa=answer[randA[0]];
string  ansb=answer[randA[1]];
string  ansc=answer[randA[2]];
string  ansd=answer[randA[3]];

if(playerAnswer=="a"){
    if(ansa==answer[0]){return 2;}
     else{return 0;}
}

else if(playerAnswer=="b"){
    if(ansb==answer[0]){return 2;}
     else{return 0;}
}

else if(playerAnswer=="c"){
    if(ansc==answer[0]){return 2;}
     else{return 0;}
}

else if(playerAnswer=="d"){
    if(ansd==answer[0]){return 2;}
     else{return 0;}
}
else{return 0;}

}

void  MCQ::printWith(){

cout<<question<<endl;
cout<<"  [a]"<<answer[randA[0]]<<"    [b]"<<answer[randA[1]]<<"    [c]"<<answer[randA[2]]<<"    [d]"<<answer[randA[3]]<<endl;
cout<<"your answer: ";
cout<<playerAnswer<<"          ";
string  ansa=answer[randA[0]];
string  ansb=answer[randA[1]];
string  ansc=answer[randA[2]];
string  ansd=answer[randA[3]];

if(playerAnswer=="a"){
    if(ansa==answer[0]){cout<<"Right"<<setw(12)<<"score : 2  "<<endl;}
     else{
         cout<<"wrong"<<setw(12)<<"score : 0"<<endl;
         cout<<"Right answer : "<<answer[0]<<endl;}
}

else if(playerAnswer=="b"){
    if(ansb==answer[0]){cout<<"Right"<<setw(12)<<"score : 2  "<<endl;}
     else {
        cout<<"wrong"<<setw(12)<<"score : 0"<<endl;
        cout<<"Right answer : "<<answer[0]<<endl;
}
     }

else if(playerAnswer=="c"){
    if(ansc==answer[0]){cout<<"Right"<<setw(12)<<"score : 2  "<<endl;}
  else{
        cout<<"wrong"<<setw(12)<<"score : 0"<<endl;
        cout<<"Right answer : "<<answer[0]<<endl;
     }
}


else if(playerAnswer=="d"){
    if(ansd==answer[0]){cout<<"Right"<<setw(12)<<"score : 2  "<<endl;}
  else{
        cout<<"wrong"<<setw(12)<<"score : 0"<<endl;
        cout<<"Right answer : "<<answer[0]<<endl;
     }
}

}



bool MCQ:: operator ==( Question q){
    if(question==q.getquestion()){

   return 1;
    }
    else{return 0;}

    }
