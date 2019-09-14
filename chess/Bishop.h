#pragma once
#include "Chessman.h"
#include "Memory.h"
#include "ChessBoard.h"

namespace Chess
{
    class Bishop : public Chess::Chessman
    {
    private:
        Bishop() {};
        friend class Queen;
    public:
        Bishop(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    };
}