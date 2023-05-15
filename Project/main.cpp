// ============================================================================
// File: main.cpp (Fall 2018)
// ============================================================================
// Programmer: Abraham Velazquez
// Date: 11/14/2018
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time:  4:30pm MW
// Instructor: Mr. Edwards
// Project: Pigs
//
// Description:
//      This program will ask for the two players names
//		and then it will loop the turns of each player. The loop will
//		contain the calling methods of the TakeTurn and the DispScores
//      until either one player wins or decides to quit.
// ============================================================================

#include    <iostream>
using namespace std;
#include    "cpigplayer.h"


// function prototypes
void    DispScores(const CPigPlayer  &playOne, const CPigPlayer  &playTwo);


// ==== main ==================================================================
// 
// ============================================================================

int     main()
{
    char                name[NAMELEN];
    CPigPlayer          playerOne;
    CPigPlayer          playerTwo;

    // seed the random number generator with the current system time
    srand(time(NULL));

    // get names for the players
    cout << "Please enter a name for player #1: ";
    cin.getline(name, NAMELEN);
    playerOne.SetName(name);
    cout << "Please enter a name for player #2: ";
    cin.getline(name, NAMELEN);
    playerTwo.SetName(name);

    // loop and let the players alternate turns, until one of them wins
    bool	check;
    int	win = 100;
    do
    {
        do
        {
            DispScores(playerOne, playerTwo);
            check = playerOne.TakeTurn();
        }while(check != true && playerOne.GetScore() >= win);    
        
        //check if he won
        if(playerOne.GetScore() >= win)
            {
                // exit loop if player won
                break;
            }
        else if( playerOne.GetScore() < win && check == true)
            {
                //exit loop if player quits
                break;
            }
        do
        {
            DispScores(playerOne, playerTwo);
            check = playerTwo.TakeTurn();
        }while( check != true && playerTwo.GetScore() >= win);    
        
        //check if he won
        if(playerTwo.GetScore() >= win)
            {
                //check if player won;
                break;
            }
        else if( playerTwo.GetScore() < win && check == true)
            {
                //exit if player quits
                break;
            }

        
    }while(true);  
    cout << "Bye, thanks for playing!" << endl << endl;
    return 0;

}  // end of "main"



// ==== DispScores ============================================================
// 
// This function displays the current scores of the two CPigPlayer parameters
// to stdout.
// 
// Input:
//      playOne [IN]    -- a const reference to the first CPigPlayer object
// 
//      playTwo [IN]    -- a const reference to the second CPigPlayer object
// 
// Output:
//      Nothing.
// 
// ============================================================================

void    DispScores(const CPigPlayer  &playOne, const CPigPlayer  &playTwo)
{
    cout << endl;
    cout << "================== Current Scores ==================" << endl;
    playOne.WriteName();
    cout << ": " << playOne.GetScore() << " points" << endl;
    playTwo.WriteName();
    cout << ": " << playTwo.GetScore() << " points" << endl;
    cout << "====================================================" << endl;
    cout << endl;

}  // end of "DispScores"
