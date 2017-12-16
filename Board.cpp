
#include "Board.h"
#include <iostream>
#include <iomanip>
namespace TicTacToe
{

 //Board constructor   
Board::Board()
{
    reset();
}
//reset the Board
void Board::reset()
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            _squares[i][j] = ' ';
        }
    }
}
//return true if requisted position  filled else return false if requisted position is not empty
 bool Board::setSquare(const int index_  , char symbol_)
{
    int row = int ((index_ - 1) / 3);
    int column = ((index_ - 1) - row * 3);
    if(' ' == getSquare(row, column))
    {
        _squares[row][column] = symbol_;
        return true;
    }
    else
        return false;
}
//get a char from Board by index_
char Board::getSquare(const int index_)const
{
    int row = int ((index_ - 1) / 3);
    int column = ((index_ -1) - row * 3);
    return _squares[row][column];
}
//fill symbol_  by its cordinate
bool Board::setSquare(const int row_, const int column_, char symbol_)
{
    if(' ' == _squares[row_][column_])
    {
        _squares[row_][column_] = symbol_;
        return true;
    }
    else
        return false;
}
//get char by cordinate
char Board::getSquare(const int row_, const int column_)const
{
    return _squares[row_][column_];
}
//print board
void Board::printBoard()const
{
        std::cout << std::setw(31) << "-------------" << std::endl;
    std::cout << std::setw(20) << "| " << _squares[0][0] << " | " << _squares[0][1] <<  " | " << _squares[0][2] << " |" << std::endl;
    std::cout << std::setw(31) << "-------------" << std::endl;
    std::cout << std::setw(20) << "| " << _squares[1][0]<<" | " <<  _squares[1][1]<< " | " << _squares[1][2]<< " |" << std::endl;
    std::cout << std::setw(31) << "-------------" << std::endl;
    std::cout << std::setw(20) << "| " <<  _squares[2][0]<<" | " << _squares[2][1] <<" | " << _squares[2][2] << " |" << std::endl;
    std::cout << std::setw(31) << "-------------" <<std::endl;
}
 
}  
