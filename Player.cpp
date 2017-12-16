
#include <iostream>
#include "Board.h"
#include "Player.h"
#include <limits>
#include <cstdlib>
namespace TicTacToe
{
    
 //return name of player   
const std::string &GenericPlayer::getName()const
{
    return _name;
}
// return symbol_ of player
char GenericPlayer::getSymbol()const
{
    return _symbol;
}
// get next move from player
int HumanPlayer::getNextMove(const Board& board_)
{
    int choice;
    // check for valid input
    do
    {
        std::cin >> choice;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Invalid choice" << std::endl;
        }
        //check for input between 1 to 9
        else              
        {   
            if(1 <= choice && 9 >= choice && ' ' == board_.getSquare(choice))
                return choice;
            else
                std::cout << "Inavalid choice" << std::endl;
        }
    }while(1);
 
}           
//get next move from computerplayer
int ComputerPlayer::getNextMove(const Board& board_)
{
    int choice;
    //call AI make decision 
    while(choice = decision(board_))
    {
        //check for dicision is valid
        if(0 < choice && 9 >= choice && ' ' == board_.getSquare(choice))
            return choice;
    }
}
//computer AI
int ComputerPlayer::decision(const Board& board_)
{
    int decidePosition;
    //Generate random number
    while(decidePosition = (rand() % 9 + 1))
    {
        if(' ' == board_.getSquare(decidePosition))
            return decidePosition;
    }
}

    
}

