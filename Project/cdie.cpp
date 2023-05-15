#include "cdie.h"
#include <cstdlib>
#include <iostream>
using namespace std;

CDie::CDie(int initval)
{
 
  m_value = initval;
}//end of CDie

//==== Draw ===============================================================
//	This function uses the random function to generate a random number
//	and thisplays random drawings from the 1 to 6
//=====================================================================

void CDie::Draw()const
{
    if( 1 == m_value )
        {
             cout <<  "*********\n";
             cout <<  "*       *\n";
             cout <<  "*   @   *\n";
             cout <<  "*       *\n";
             cout <<  "*********\n";
  
        }
    else if( 2 == m_value )
        {
            cout << "*********\n";
            cout << "* @     *\n";
            cout << "*       *\n";
            cout << "*     @ *\n";
            cout << "*********\n";
        }
    else if( 3 == m_value )
        {
            cout << "*********\n";
            cout << "* @     *\n";
            cout << "*   @   *\n";
            cout << "*     @ *\n";
            cout << "*********\n";
        }
    else if( 4 == m_value )
        {
            cout << "*********\n";
            cout << "* @   @ *\n";
            cout << "*       *\n";
            cout << "* @   @ *\n";
            cout << "*********\n";
        }
    else if( 5 == m_value )
        {
            cout << "*********\n";
            cout << "* @   @ *\n";
            cout << "*   @   *\n";
            cout << "* @   @ *\n";
            cout << "*********\n";
        }
    else if ( 6 == m_value )
        {
            cout << "*********\n";
            cout << "* @   @ *\n";
            cout << "* @   @ *\n";
            cout << "* @   @ *\n";
            cout << "*********\n";
        }
}//end of Draw()



//==== Toss =========================================================
//	This function will set the m_value to a random number
//==============================================================

void CDie::Toss()
{
    //calls to set a random number
    m_value = (random() % 6) + 1;
}//end of Toss



//==== GetVal ======================================================
//	this function will retrun an integer value
//=================================================================

int	CDie::GetVal()const
{
    return m_value;
 
}//end of GetVal
