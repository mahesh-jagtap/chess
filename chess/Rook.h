#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class Rook : public Chess::Chessman
    {
    public:
        Rook(Color c, ptr<Chess::BRD::ChessBoard> b) :Chessman(c, b) {};
        bool isValidMove(Move m) override;
    };
}
