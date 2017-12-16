
// Board header
#ifndef BOARD_H
#define BOARD_H

namespace TicTacToe
{

class Board
{
    public:
        Board();
        bool        setSquare(const int index_, char symbol_);                         //mark  symbol_ on board by index
        bool        setSquare(const int row_, const int column_, char symbol_);        // mark  symbol_ on board by cordinate
        char        getSquare(const int row_, const int column_)const;                 // get symbol_ by cordinate
        char        getSquare(const int index)const;                                   // get symbol_ by  index;
        void        reset();                                                           // reset Board
        void        printBoard()const;                                                 // diplay board
    private:
        char        _squares[3][3];
};

}
#endif
