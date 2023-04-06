#include<iostream>
using namespace std;

int main() {

    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 5;
    //bool outOfGuesses = false;                                                // Alternate approach using bool

    while(guess != secretNum && guessCount != guessLimit) {                    // while(guess != secretNum && !outOfGuesses)
                                                                              // if(guessCount < guessLimit) {
        cout<<"\nGuess the no. : ";                                           
        cin>>guess;
        guessCount++;
                                                                             // } else
                                                                            //       outOfGuesses = true;
    }

    if(guess == secretNum)                                                  // if(outOfGuesses) 
        cout<<"\nYou Win!"<<endl;                                          //       cout<<"You lose";
    else                                                                  // else
        cout<<"\nYou lose";                                              //     cout<<"You Win";

    return 0;
}