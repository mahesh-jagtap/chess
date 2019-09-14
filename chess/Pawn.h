#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class Pawn : public Chessman
    {
    protected:
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    public:
        Pawn(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
    };
}