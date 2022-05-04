#ifndef FUNCTIONS__CPP_INCLUDED
#define FUNCTIONS__CPP_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;

int calculator(){

    int num1, num2;
    char op;
    cout<<"Enter first number"<<endl;
    cin>>num1;
    cout<<"Enter operator: "<<endl;
    cin>>op;
    cout<<"Enter second number"<<endl;
    cin>>num2;

    int result1;
    if (op=='+'){
        result1=num1+num2;
    } else if (op=='-'){
        result1=num1-num2;
    } else if (op=='*'){
        result1=num1*num2;
    } else if (op=='/'){
        result1=num1/num2;
    } else {
        cout<<"Incorrect operator."<<endl;
    }

    cout<<result1;
    }

string getDayName(int dayNumber){

    string dayName;

    switch(dayNumber) {
     case 0:
        dayName="Monday";
        break;
     case 1:
        dayName="Tuesday";
        break;
     case 2:
        dayName="Wednesday";
        break;
     case 3:
        dayName="Thursday";
        break;
     case 4:
        dayName="Friday";
        break;
     case 5:
        dayName="Saturday";
        break;
     case 6:
        dayName="Sunday";
        break;
     default:
        dayName="Invalid day number.";
        break;

    }

    return dayName;

}


int printingValues(){
    int number;
    cout<<"Enter number: ";
    cin>>number;

    while(number>=0){
        cout<<number<<endl;
        number--;
    }
}

string guessGame() {
    int secretnum =5;
    int tries;
    int guess;
    cout<<"How many times would you like to try?"<<endl;
    cin>>tries;

    int guessCount=0;
    while (tries>guessCount) {
        cout<<"Enter guess: "<<endl;
        cin>>guess;
        guessCount++;
        if (guess==secretnum) {
            cout<<"You win!"<<endl;
            break;
        }
    } if (guess!=secretnum){
        cout<<"You lost :(";
    }
}

//or:
/**
    bool outOfGuesses = false;
    while (secretnum!=guess && !outOfGuesses){
        if(guessCount<tries){
            cout<<"Enter guess: "<<endl;
            cin>>guess;
            guessCount++;
        } else {
            outOfGuesses=true;
        }
    }
    if (outOfGuesses){
        cout<<"You lost";
    } else {
        cout<<"You win!";
    }
 */

 int power(int baseNum, int powerNum){
    int result=1;
    for (int i=0; i<powerNum; i++){
        result=result*baseNum;
    }
    return result;
 }




#endif // FUNCTIONS__CPP_INCLUDED
