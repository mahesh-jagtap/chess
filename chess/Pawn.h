#pragma once
#include "Chessman.h"
#include "Memory.h"

namespace Chess
{
    class Pawn : public Chessman
    {
    public:
        Pawn(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
        bool isValidMove(Move m) override;
    };
}