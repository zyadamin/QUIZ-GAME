#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"

#include <iostream>
using namespace std;


class Quiz
{

protected:

Question* ques[5];
int right=0,wrong=0,sum=0;
  static float mc,tf,c;

  public:

    int arr[5]={};

    Quiz();

    Quiz(Question *ques[5]);

    int getSum();

    float getmc();

    float gettf();

    float getc();

    void  allScore();

    void  rightAnswer();

    void last2();

    void start();

};

#endif // QUIZ_H
