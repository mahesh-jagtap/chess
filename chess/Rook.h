#pragma once
#include "Chessman.h"
#include "Memory.h"
#include "ChessBoard.h"

namespace Chess
{
    class Rook : public Chess::Chessman
    {
    protected:
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    public:
        Rook(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
    };
}
