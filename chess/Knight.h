#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class Knight : public Chess::Chessman
    {
    protected:
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    public:
        Knight(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
    };
}
