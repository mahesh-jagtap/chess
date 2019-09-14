#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class Queen : public Chess::Chessman
    {
    public:
        Queen(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    };
}