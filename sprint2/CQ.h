#ifndef CQ_H
#define CQ_H

#include "Question.h"


#include <iostream>
#include<iomanip>
using namespace std;


class CQ : public Question
{

string answer;

public:

    CQ();
    CQ(string question,string answer);

    bool operator ==( Question q); //operator overloading to chick question
    void print();
    void printWith();
    int answerScore();

};

#endif // CQ_H
