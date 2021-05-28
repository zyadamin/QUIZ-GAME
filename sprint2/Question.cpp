#include "Question.h"
Question::Question(){}

Question::Question(string question){
this->question=question;
}

void Question::setID(int id){
this->id=id;
}

int Question:: getID(){
return id;
}

void Question:: setquestion(string question){
this->question=question;
}

string Question:: getquestion(){
return question;
}

void Question:: printq(){

cout<<question<<endl;
cout<<"your answer: ";
cin>>playerAnswer;
}

void Question:: printWith(){}

int Question::answerScore(){}
