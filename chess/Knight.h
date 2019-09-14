#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class Knight : public Chess::Chessman
    {
    public:
        Knight(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    };
}
