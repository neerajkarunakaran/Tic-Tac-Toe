
//GameController header
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Board.h"
#include "Player.h"

namespace TicTacToe
{

class GameController
{
    public:
        GameController(int numberOfPlayers = 1 );
        ~GameController();
        bool            welcome()const;                           //TicTacToe game instructions and welcome note
        void            startGame();                               //start game

   private:

        Board           *_board;
        GenericPlayer   *_player1;
        GenericPlayer   *_player2;
        void            playGame();
        bool            checkDraw()const;
        bool            checkWin(char symbol_)const;
        bool            playAgain();
};
}

#endif
