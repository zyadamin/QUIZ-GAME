#ifndef MCQ_H
#define MCQ_H
#include "Question.h"
#include <iostream>
#include<iomanip>
using namespace std;

int randomList(int list[],int size,int limit);

class MCQ : public Question
{
    string answer[4];
    int randA[4];

public:

    MCQ();
    MCQ(string question, string answer[4]);

    bool operator ==( Question q); //operator overloading to chick question

    void print();  //to print questions in view all questions

    void printq();  //to print question with palyer answer

    void printWith();  //to print question for taking quiz

    int answerScore();


};

#endif // MCQ_H
