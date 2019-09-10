#pragma once
#include "Memory.h"

namespace Chess
{
    namespace BRD
    {
        class ChessBoard;
    }

    class Chessman
    {
    protected:
        Color m_color;
        Chess::BRD::ChessBoard* m_board;
    
    public:
        //Chessman(Color c, ptr<Chess::BRD::ChessBoard> b) :m_color(c), m_board(b) {}
        Chessman(Color c, Chess::BRD::ChessBoard* b) :m_color(c), m_board(b) {}
        virtual bool isValidMove(Move m) = 0;
        
        Color getColor()
        {
            return m_color;
        }

    };
}