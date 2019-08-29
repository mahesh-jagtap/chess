#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class Knight : public Chess::Chessman
    {
    public:
        Knight(Color c, ptr<Chess::BRD::ChessBoard> b) :Chessman(c, b) {};
        bool isValidMove(Move m) override;
    };
}
