#include "cpigplayer.h"
#include "cdie.cpp"
#include <iostream>
#include <unistd.h>
using namespace std;

//============ void CPigPlayer::RollDice() ====================================
//	this function has to do is make sure that each array element is tossed.
//input:
//	nothing
//output:
//  nothing
//=============================================================================

void CPigPlayer::RollDice()
{

    //arrays call toss
    
        m_dice[0].Toss();
        m_dice[1].Toss();
}//end of RollDice



//========= CPigPlayer::ShowDice() ============================================
//	 this member function just sees to it that each CDie object in the
//	 array is displayed.
//input:
//	nothing
//output:
//	nothing
//=============================================================================

void CPigPlayer::ShowDice() const
{
    //show dice for each array
    m_dice[0].Draw();
    m_dice[1].Draw();
}//end of ShowDice



//========= CPigPlayer::TakeTurn() ============================================
//	When this function executes, it first displays the player's current
//	 score and then asks the player if he/she wishes to roll the dice. 
//	If the answer is "Yes", then the dice are rolled and their values 
//	displayed to the screen.
//	The results of the rolled dice are added to the player's current score. 
//	These steps keep repeating in a loop until the player either: 
//	a) wins the game; 
//	b) the player decides to stop rolling;
//	c) the player decides to quit the game altogether. 
//	The function returns a value of true if the game should end
//	 (because either the player has a winning score or 
//	because the player wishes to quit the game), or
//	false if the game should continue to the other player.
//input:
//	nothing.
//output:
//	nothing
//============================================================================

bool  CPigPlayer::TakeTurn()
{
    char	ans;
    int		miniScore = 0;
    int		roundCount = 0;
    
            do
            {
                //prompt the user to roll
                cout << m_name << "'s current score is: " 
                     << m_score << " roll? (y/n/q) ";
                cin >> ans;
                ans = tolower(ans);
                if('y' == ans )
                    {
                        sleep(1);
                        RollDice();
                        ShowDice();
                        miniScore = m_dice[0].GetVal() + m_dice[1].GetVal();
                        roundCount = roundCount + miniScore;
                        m_score = m_score + miniScore;
                        
                        if(WIN_POINTS <= m_score )
                            {
                                cout << m_name << " wins with " 
                                     << m_score << " points!\n";
                                return true;
                            }
                        if( (1 == m_dice[0].GetVal() || 1 == m_dice[1].GetVal())
							 && miniScore != 2 )
                            {
                                m_score = m_score - roundCount;
                                cout << "Rolled a single '1' --"
                                     << " This turn is cancelled!\n";

                                roundCount = 0;
                                return false;
                            }
                        if( 2 == miniScore)
                            {
                                cout << "Rolled two '1s' --"
				     <<" start all over again!\n";
                                m_score = 0;
                                return false;
                            }
                    }
                    else if('n' == ans )
                    {
                        return false;
                    }
                    else if('q' == ans )
                    {
                        return true;
                    }
        
            }while(m_score < WIN_POINTS);
 
    return true;     
}//end of false       
