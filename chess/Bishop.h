#pragma once
#include "Chessman.h"
#include "Memory.h"
#include "ChessBoard.h"

namespace Chess
{
    class Bishop : public Chess::Chessman
    {
        bool canMoveTo(Position current_position, Position to);
    public:
        Bishop(Color c, Chess::BRD::ChessBoard* b) :Chessman(c, b) {};
        bool isValidMove(Move m) override;
    };
}