#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class King : public Chess::Chessman
    {
 
    public:
        King(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    };
}