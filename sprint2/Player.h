#ifndef PLAYER_H
#define PLAYER_H

#include "User.h"
#include "Quiz.h"
#include <vector>
#include <iostream>
using namespace std;

class Player : public User{

vector< Quiz> quizes;

public:

    Player();

    Player(string userName,string password,string firstName,string lastName);


    bool operator ==(User b); // operator overloading to check user

    void printPlayerList();  //to print player list

    void startNew(Quiz q );  //to take quiz

    void minSum();    //to  get Lowest quiz score

    void maxSum();    //to  get highest quiz score

    void average();  //to get average the score

    void getRight();  // to get right answers  for types of the questions

    void getaverage();  // to get average of  right answers  for types of the questions

    void getAllScore();   // to get number of right answer , wrong answer and the score

    void lastQuiz(); // to get score for last to quizzes

};
#endif // PLAYER_H
