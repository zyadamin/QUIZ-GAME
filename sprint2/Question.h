#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
using namespace std;
class Question
{
protected:

    string  question;   //the question
    string playerAnswer;
    int  id;
public:
    Question();
    Question(string question);

    void setquestion(string question);

    void setID(int id);

    virtual int answerScore();

    int getID();

    string getquestion();

    virtual void printq();  //to print question for taking quiz

    virtual void printWith();  //to print question with palyer answer

};

#endif // QUESTION_H
