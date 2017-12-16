
// Player header
#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
namespace TicTacToe
{
//Abstract class
class GenericPlayer
{
    public:
        GenericPlayer(){_name = "Computer"; _symbol = 'X';}
        GenericPlayer(std::string &name_, char symbol_):_name(name_), _symbol(symbol_){}
        virtual int             getNextMove(const Board& board_) = 0;
        const std::string &     getName()const;                                         //return name of player
        char                    getSymbol()const;                                       // get symbol of player
    protected:
        char                    _symbol;
        std::string             _name;
};
        
class HumanPlayer: public GenericPlayer
{
    public:

        HumanPlayer(std::string &name_, char symbol_):GenericPlayer(name_, symbol_){}
        virtual int             getNextMove(const Board& board_);                       //get next move 
};

class ComputerPlayer: public GenericPlayer
{
    public:
        ComputerPlayer(){}
        virtual int             getNextMove(const Board& board_);                       //get next move
    private:
        int                     decision(const Board& board_);
};

}

#endif



