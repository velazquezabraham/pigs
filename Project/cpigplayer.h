// ============================================================================
// File: cpigplayer.h (Fall 2018)
// ============================================================================
// This is the header file for the CPigPlayer class, which is used to represent
// a single player in the "Pig" game.
// ============================================================================

#ifndef CPIGPLAYER_H
#define CPIGPLAYER_H

#include    <iostream>
#include    <cstdlib>
#include    <cstring>
using namespace std;
#include    "cdie.h"

// defined constants
const   int     BUFLEN = 50;
const   char    DEFAULT_NAME[] = "Hal";
const   int     NAMELEN = 50;
const   int     NUMDICE = 2;
const   int     WIN_POINTS = 100;

// class declaration
class   CPigPlayer
{
public:
    // constructor
    CPigPlayer(const char  *name = DEFAULT_NAME)
                                   { strncpy(m_name, name, NAMELEN);
                                     m_score = 0; }

    // member functions
    int     GetScore() const { return m_score; }
    void    RollDice();
    void    ShowDice() const;
    bool    TakeTurn();
    void    SetName(const char  *name) { strncpy(m_name, name, NAMELEN); }
    void    WriteName(ostream  &outStream = cout) const { outStream << m_name; }

private:
    char    m_name[NAMELEN];
    int     m_score;
    CDie    m_dice[NUMDICE];
};

#endif // CPIGPLAYER_H
