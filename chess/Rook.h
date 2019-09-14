#pragma once
#include "Chessman.h"
#include "Memory.h"
#include "Queen.h"
#include "ChessBoard.h"

namespace Chess
{
    class Rook : public Chess::Chessman
    {
    private:
        Rook() {};
        friend class Chess::Queen;
    protected:
        bool isChessmanMove(Move m) override;
        bool isPositionReachable(Move m) override;
    public:
        Rook(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
    };
}
