#include "CFBoard.hpp"
#include <iostream>

int main()
{
    CFBoard newGame;
    
    
    /*
    newGame.makeMove(1,'x'); // Horizontal check start
    newGame.makeMove(2,'x');
    newGame.makeMove(3,'x');
    newGame.makeMove(5,'x');
    newGame.makeMove(6,'x');
    newGame.makeMove(7,'x');
    newGame.makeMove(4,'x');
    */
    
    newGame.makeMove(1,'x'); // Diagonal check start
    newGame.makeMove(2,'o');
    newGame.makeMove(2,'x');
    newGame.makeMove(3,'x');
    newGame.makeMove(3,'x');
    newGame.makeMove(3,'x');
    newGame.makeMove(4,'o');
    newGame.makeMove(4,'x');
    newGame.makeMove(4,'x');
    newGame.makeMove(5,'x');
    newGame.makeMove(5,'o');
    newGame.makeMove(5,'x');
    newGame.makeMove(5,'o');
    newGame.makeMove(5,'x');
    newGame.makeMove(6,'o');
    newGame.makeMove(6,'x');
    newGame.makeMove(6,'o');
    //newGame.makeMove(6,'o');
    newGame.makeMove(6,'o');
    newGame.makeMove(6,'x');
    newGame.makeMove(4,'x');
    std::cout << newGame.getGameState() << std::endl;
    newGame.print();
    /*
    newGame.makeMove(1,'x'); // Start draw
    newGame.makeMove(1,'o'); 
    newGame.makeMove(1,'x'); 
    newGame.makeMove(1,'o');
    newGame.makeMove(1,'x'); 
    newGame.makeMove(1,'o');
    newGame.makeMove(2,'x'); 
    newGame.makeMove(2,'o');
    newGame.makeMove(2,'x'); 
    newGame.makeMove(2,'o'); 
    newGame.makeMove(2,'x');
    newGame.makeMove(2,'o');
    newGame.makeMove(3,'x'); 
    newGame.makeMove(3,'o'); 
    newGame.makeMove(3,'x'); 
    newGame.makeMove(3,'o');
    newGame.makeMove(3,'x'); 
    newGame.makeMove(3,'o');
    newGame.makeMove(5,'x'); 
    newGame.makeMove(4,'o');
    newGame.makeMove(4,'x'); 
    newGame.makeMove(4,'o'); 
    newGame.makeMove(4,'x');
    newGame.makeMove(4,'o');
    newGame.makeMove(4,'x');
    newGame.makeMove(5,'o'); 
    newGame.makeMove(5,'x');
    newGame.makeMove(5,'o'); 
    newGame.makeMove(5,'x'); 
    newGame.makeMove(5,'o');
    newGame.makeMove(5,'x');
    newGame.makeMove(6,'x'); 
    newGame.makeMove(6,'o');
    newGame.makeMove(6,'x'); 
    newGame.makeMove(6,'o'); 
    newGame.makeMove(6,'x');
    newGame.makeMove(6,'o');
    newGame.makeMove(7,'o'); 
    newGame.makeMove(7,'x');
    newGame.makeMove(7,'x'); 
    newGame.makeMove(7,'o'); 
    newGame.makeMove(7,'x');
    newGame.makeMove(7,'o');
    newGame.makeMove(7,'x'); // End draw
    */
    /*
    newGame.makeMove(1); // Start diagonal win x
    newGame.makeMove(2); 
    newGame.makeMove(2); // x
    newGame.makeMove(3);
    newGame.makeMove(3); // x
    newGame.makeMove(4);
    newGame.makeMove(3); // x
    newGame.makeMove(1);
    newGame.makeMove(4); // x
    newGame.makeMove(4); 
    newGame.makeMove(4); // End diagonal win x
    */
    /*
    newGame.makeMove(1); // Start Vertical Win
    newGame.makeMove(2);
    newGame.makeMove(1);
    newGame.makeMove(2);
    newGame.makeMove(1);
    newGame.makeMove(2);
    newGame.makeMove(1); // End vertical win 
    */
    /*
    newGame.makeMove(1); //Start Stacked column
    newGame.makeMove(1);
    newGame.makeMove(1);
    newGame.makeMove(1);
    newGame.makeMove(1);
    newGame.makeMove(1); // End Stacked Column
    */
    /*
    newGame.makeMove(1,'x'); // Start Horizontal win
    newGame.makeMove(2,'x');
    newGame.makeMove(3,'x');  // End horizontal win
    newGame.makeMove(5,'x');
    newGame.makeMove(6,'x');
    newGame.makeMove(7,'x'); 
    newGame.makeMove(4,'x');   
    */
    return 0;
}
