#include "Player.h"

Player::Player(){

}

Player::Player(string userName,string password, string firstName,string lastName):User( userName, password, firstName, lastName ){
Role="player";
};

void Player:: printPlayerList(){

cout<<"Welcome ("<<firstName<<"), please choose from the following options:"<<endl;
cout<<"[1] Switch accounts"<<endl;
cout<<"[2] Update your name"<<endl;
cout<<"[3] Start a new quiz"<<endl;
cout<<"[4] Display your scores statistics"<<endl;
cout<<"[5] Display all your scores"<<endl;
cout<<"[6] Display details of your last 2 quizzes"<<endl;
cout<<"[7] Exit the program"<<endl;
cout<<"My choice: ";

}

 bool Player:: operator ==( User b){
    if(userName==b.getUserName()){
        return 1;}

    else{return 0;}

    }



void Player::startNew( Quiz q ){

q.start();

quizes.push_back(q);

}

void Player :: maxSum(){
    int high=quizes[0].getSum();
    for(int i=1;i<quizes.size();i++){
         if(high<quizes[i].getSum())
            { high=quizes[i].getSum();}
    }
    cout<<"Your score statistics per quiz: "<<endl;

    cout<<"- Number of Quizzes taken: "<<quizes.size()<<endl;

    cout<<"- Highest quiz score: "<<high<<"/9"<<endl;
}

void Player:: minSum(){
    int low=quizes[0].getSum();
    for(int i=1;i<quizes.size();i++){
        if(low>quizes[i].getSum())
            { low=quizes[i].getSum();}
}
cout<<"-Lowest quiz score: "<<low<<"/9"<<endl;
}


void Player:: average(){

    float sum=0.0;
    for(int i=0;i<quizes.size();i++){
        sum+=quizes[i].getSum();
    }
    float x=sum/quizes.size();
    cout<<"- Average quiz score: "<<x<<"/9"<<endl;
}


void Player:: getRight(){

quizes[0].rightAnswer();
}

void Player::getaverage(){
float m=0.0;
cout<<"---------------------------------------------------------------------------------------"<<endl;

m=quizes[0].getmc()/(2*quizes.size());
cout<<"- Average grade for MC questions: "<<m<<"/2"<<endl;

m=quizes[0].getc()/(quizes.size());
cout<<"- Average grade for Complete questions: "<<m<<"/3"<<endl;

m=quizes[0].gettf()/(2*quizes.size());
cout<<"- Average grade for T/F questions: "<<m<<"/1"<<endl;

}

void Player::getAllScore(){
    cout<<"- Number of Quizzes taken: "<<quizes.size()<<endl;
    for(int i=0;i<quizes.size();i++){
        cout<<" quiz number "<<i+1<<" : "<<endl;
        quizes[i].allScore();}

}

void Player:: lastQuiz(){
   int i=quizes.size();
   if(i==1){
    quizes[i-1].last2();
   }
   else{
quizes[i-1].last2();
quizes[i-2].last2();
}}
