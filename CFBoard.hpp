/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        5/30/2018
** Description: This header file acts as the interface for the CFBoard
*               class. The included functions and members will create
*               a 6*7 game board of connect four. 
*********************************************************************/

#ifndef CFBOARD_HPP // Include a guard
#define CFBOARD_HPP

enum outcome {X_WON, O_WON, DRAW, UNFINISHED}; // User defined outcome names

class CFBoard
{
private:
    
    char boardArray[6][7]; // [rows][columns]
    outcome gameState; // Reference previous enum
    
public:
    
        CFBoard();
        bool makeMove(int, char);
        void updateGameState(int, int);
        outcome getGameState();
        void print();
        
        ~CFBoard();

};

#endif