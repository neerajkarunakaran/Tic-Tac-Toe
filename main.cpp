#include <iostream>
#include "GameController.h"
#include "Player.h"
#include "Board.h"
#include <limits>

int main()
{

    std::string name; 
    int numberOfPlayers;     
    std::cout << "Welcome to TicTacToe : Enter number of players 1 or 2 " << std::endl;
    
    do
    {
        std::cin >> numberOfPlayers;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Invalid Selection" << std::endl;
        }
        else
        {
            if(1 == numberOfPlayers || 2 == numberOfPlayers)
                break;
            else
                std::cout << "Invalid Selection" << std::endl;
        }
    }while(1);
    
    TicTacToe::GameController gameController(numberOfPlayers);
    if(gameController.welcome())                      //show game instructions ,return true if players wish to start game
    {

        gameController.startGame();                   //game start
    }
    return 0;
}

