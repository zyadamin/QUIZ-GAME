#ifndef TFQ_H
#define TFQ_H

#include "Question.h"

#include <iostream>
#include<iomanip>
using namespace std;

class TFQ : public Question
{
string answer;

public:
    TFQ();
    TFQ(string question,string answer);

    bool  operator ==( Question q); //operator overloading to chick question
    void print();    //to print questions in view all questions
    void printWith();    //to print question for taking quiz
    int answerScore();

};

#endif // TFQ_H
