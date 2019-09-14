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
        virtual bool isChessmanMove(Move m) = 0;
        virtual bool isPositionReachable(Move m) = 0;
            
    public:
        //Chessman(Color c, ptr<Chess::BRD::ChessBoard> b) :m_color(c), m_board(b) {}
        Chessman(Color c, Chess::BRD::ChessBoard* b) :m_color(c), m_board(b) {}
        
        bool isValidMove(Move m)
        {
            return isChessmanMove(m) and isPositionReachable(m);
        }
        
        Color getColor()
        {
            return m_color;
        }

    };
}