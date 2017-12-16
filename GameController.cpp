
#include <iostream>
#include <cstdlib>
#include "Board.h"
#include "Player.h"
#include "GameController.h"


namespace TicTacToe
{
//constructor
GameController::GameController(int numberOfPlayers_)
{
    _board = new Board();
    std::string name1, name2;
    //create players for gaem between computer and human
    if(1 == numberOfPlayers_)
    {
        std::cout << "Enter player name" << std::endl;
        std::cin >>  name1;
        //create player1 with their name and symbol
        _player1 = new HumanPlayer(name1, 'X');
        _player2 = new ComputerPlayer();
    }
    //create player for game between humen
    else
    {
        std::cout << "Enter player1 name" << std::endl;
        std::cin >> name1;
        _player1 = new HumanPlayer(name1, 'X');
        std::cout << "Enter player2 name " << std::endl;
        std::cin >> name2;
        _player2 = new HumanPlayer(name2, 'O');
    }
    std::cout << std::endl;
}
//distructor
GameController::~GameController()
{
    delete _board;
    delete _player1;
    delete _player2;
}
//give instructions and return true if player procedes to continue
bool GameController::welcome()const
{
    std::cout << ".................................................." << std::endl;
    std::cout << "       Instructions: " << std::endl;
    std::cout << "Use number 1 to 9 for  sellect squares " << std::endl;
    _board->printBoard();
    char response; 
    std::cout << "Do you wish to continue [y/n]" << std::endl;
    //check for valid input
    do
    {
        std::cin >> response;
        if('y' == response)
            return true;
        if('n' == response)
            return false;
        std::cout << "choose y/n" << std::endl;
    }while(1);
}
void GameController::startGame()
{
    do
      {
        //paly game 
        playGame();
      }while(playAgain());   //check for player wish to play again
          
}
//start play
void GameController::playGame()
{
    //clear screen
    system("clear");
    int choice;
    do
    {
        _board->printBoard();
        std::cout << _player1->getName() << " turn" << std::endl;
        //get Next move from player1
        choice =  _player1->getNextMove(*_board);
        // mark board 
        _board->setSquare(choice, 'X');
        system("clear");
        _board->printBoard();
        //check for win or draw
        if(checkWin('X') || checkDraw())
            break;
        std::cout << _player2->getName() << " turn" << std::endl;
        choice = _player2->getNextMove(*_board);
        _board->setSquare(choice, 'O');
        system("clear");
        _board->printBoard();
        if(checkWin('O') || checkDraw())
            break;
        system("clear");
    }while(1);
}
//return true if player Wish to paly game again
bool GameController::playAgain()
{
    char response;
    std::cout << "Do you wish to  play again [y/n]" << std::endl;
    do
    {   //check for valid input
        std::cin >> response;
        if('y' == response)
        {
            // reset board
            _board->reset();
            return true;
        }
        if('n' == response)
            return false;
        std::cout << "Choose y/n" << std::endl;
    }while(1);
}
//return true if Draw
bool GameController::checkDraw()const
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(' ' == _board->getSquare(i, j))
                return false;
        }
    }
    std::cout << "          Draw           " << std::endl;
    return true;
}
// return true if symobol_ win      
bool GameController::checkWin(char symbol_)const
{
    bool winner = false;
    // row and column check
    for(int i = 0; i < 3; ++i)
    {
        if(symbol_ == _board->getSquare(i, 0) && symbol_ == _board->getSquare(i, 1) && symbol_ == _board->getSquare(i, 2))
            winner = true;
        if(symbol_ == _board->getSquare(0, i) && symbol_ == _board->getSquare(1, i) && symbol_ ==  _board->getSquare(2, i))
            winner =  true;
    }
    // diagonal check
    if(symbol_ == _board->getSquare(0, 0) && symbol_ == _board->getSquare(1, 1) && symbol_ == _board->getSquare(2, 2))
        winner = true;
    if(symbol_ == _board->getSquare(0, 2) && symbol_ == _board->getSquare(1, 1) && symbol_ ==  _board->getSquare(2, 0))
       winner = true;
    if(winner)
    {
        if('X' == symbol_)
        {
            std::cout << _player1->getName() << "  Won   " << std::endl;
            return winner;
        }
        else
        {
            std::cout << _player2->getName() << "  Won  " << std::endl;
            return winner;
        }
    }
    return winner;
}

}



    


