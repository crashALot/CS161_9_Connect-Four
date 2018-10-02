/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        5/30/2018
** Description: This program creates an editable playing board of
*               connect four. The included functions will take user(s)
*               input and calculate whether the players have connected
*               4 pieces orthogonally or diagonally or if the game
*               is a draw. This file includes the linked CFBoard.hpp
*               file.
*********************************************************************/

#include "CFBoard.hpp" // Associated header file
#include <iostream>

/********************************************************************* 
** Description: CFBoard::CFBoard()
*               Default constructor. Creates a blank 6*7 grid filled
*               with '.' characters. Also sets game to state
*               "UNFINISHED".
*********************************************************************/
CFBoard::CFBoard()
{
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
            boardArray[row][col]='.';
    }
    gameState=UNFINISHED; // By default, game is unfinished
}

/********************************************************************* 
** Description: bool CFBoard::makeMove(int columnSelection, char playerSelection)
*               Determines state of game before registering user
*               move. Records user move and returns true if game is
*               unfinished.
*********************************************************************/
bool CFBoard::makeMove(int columnSelection, char playerSelection)
{
    int row=0;
    columnSelection=columnSelection-1; // Account for one-off error
        
    if (gameState != UNFINISHED || boardArray[0][columnSelection]!='.')
    {
        return false; // Make sure game isn't finished or column isn't full
    }
    
    while (boardArray[row][columnSelection]=='.') // Find row where player move can be placed
        row++;
    row=row-1;
    
    // Place player piece in user identified column
    if (playerSelection=='x')
    {
        boardArray[row][columnSelection]='x';
    }
    else
    {
        boardArray[row][columnSelection]='o';
    }
    
    CFBoard::updateGameState(row, columnSelection); // Update game state
    return(true);
}

/********************************************************************* 
** Description: void CFBoard::updateGameState(int rowNumIn, int colNumIn)
*               This function determines if either user has connected
*               4 pieces horizontally, orthogonally, diagonally or if
*               game is a draw. Updates game outcome accordingly.
*********************************************************************/
void CFBoard::updateGameState(int rowNumIn, int colNumIn)
{
    char player=boardArray[rowNumIn][colNumIn];
    int connectFourHoriz=1, connectFourDiagNESW=1, connectFourDiagNWSE=1, connectFourVert=1, movesRemain=0;
    int leftMove=1, rightMove=1, downMove=1, upMove=1; 
    
    // Look horizontally for 4 connected pieces
    while (colNumIn-leftMove >=0 && boardArray[rowNumIn][colNumIn-leftMove]==player) // Look left
    {
        connectFourHoriz++;
        leftMove++;
    }
    while (colNumIn+rightMove <=6 && boardArray[rowNumIn][colNumIn+rightMove]==player) // Look right
    {
        connectFourHoriz++;
        rightMove++;
    }
     
    // Look diagonally NESW for 4 connected pieces
    leftMove=1, rightMove=1;  
    while (colNumIn-leftMove >=0 && rowNumIn+downMove <=5 && boardArray[rowNumIn+downMove][colNumIn-leftMove]==player) // Look down and left (SW)
    {
        connectFourDiagNESW++;
        leftMove++;
        downMove++;        
    }
    while (colNumIn+rightMove <=6 && rowNumIn-upMove >=0 && boardArray[rowNumIn-upMove][colNumIn+rightMove]==player) // Look up and right (NE)
    {
        connectFourDiagNESW++;
        rightMove++;
        upMove++;
    }
    
    // Look diagonally NWSE for 4 connected pieces
    leftMove=1, rightMove=1, downMove=1, upMove=1;
    while (colNumIn-leftMove >=0 && rowNumIn-upMove >=0 && boardArray[rowNumIn-upMove][colNumIn-leftMove]==player) // Look up and left (NW)
    {
        connectFourDiagNWSE++;
        leftMove++;
        upMove++;        
    }
    while (colNumIn+rightMove <=6 && rowNumIn+downMove <=5 && boardArray[rowNumIn+downMove][colNumIn+rightMove]==player) // Look down and right (SE)
    {
        connectFourDiagNWSE++;
        rightMove++;
        downMove++;
    }
    
    // Look vertically for 4 connected pieces
    downMove=1; 
    while (rowNumIn+downMove <=5 && boardArray[rowNumIn+downMove][colNumIn]==player) // Look down only
    {
        connectFourVert++;
        downMove++;
    }

    // Determine if table is full (draw)
    for (int row=0; row<6; row++) 
        {
            for (int col=0; col<7; col++)
                if (boardArray[row][col]=='.')
                    movesRemain++;
        }
   
    // Determine winner type or draw
    if (connectFourDiagNWSE>=4 || connectFourDiagNESW>=4 || connectFourHoriz>=4 || connectFourVert>=4 || movesRemain==0) 
        {
            if (movesRemain==0)
            {
                gameState=DRAW;
                return;
            }
            else if (player=='x')
            {
                gameState=X_WON;
                return;
            }
            else
            {
                gameState=O_WON;
                return;
            }
        }
}

/********************************************************************* 
** Description: outcome CFBoard::getGameState()
*               Returns game status upon user request.
*********************************************************************/
outcome CFBoard::getGameState()
{
    return gameState;
}

/********************************************************************* 
** Description: void CFBoard::print()
*               Outputs updated game board to consol.
*********************************************************************/
void CFBoard::print()
{
    std::cout << "1 2 3 4 5 6 7" << std::endl;
    for (int row=0; row<6; row++)
    {
        for (int col=0; col<7; col++)
        {
            std::cout << boardArray[row][col] <<" ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: CFBoard::~CFBoard()
*               CFBoard class destructor.
*********************************************************************/
CFBoard::~CFBoard()
{
}