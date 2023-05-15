// ============================================================================
// File: cdie.h (Fall 2018)
// ============================================================================
// This is the header file for the CDie class, which is used to represent a
// single die.
// ============================================================================

#ifndef CDIE_H
#define CDIE_H
// class declaration
class   CDie
{
public:
    // constructors
    CDie(int  initVal = 1);

    // member functions
    void    Draw() const;
    int     GetVal() const;
    void    Toss();

private:
    int     m_value;
};

#endif // CDIE_H
