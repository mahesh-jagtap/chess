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
        Chessman() = default;
            
    public:
        Chessman(Color c, Chess::BRD::ChessBoard* b) :m_color(c), m_board(b) {}
        
        virtual bool isChessmanMove(Move m) = 0;
        virtual bool isPositionReachable(Move m) = 0;

        bool isValidMove(Move m);
        
        Color getColor()
        {
            return m_color;
        }

    };
}