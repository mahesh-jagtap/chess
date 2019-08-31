#pragma once
#include "Memory.h"

namespace Chess
{
    namespace BRD
    {
        class ChessBoard;
    }

    class Chessman
    {
        Color color;
        ptr<Chess::BRD::ChessBoard> board;
    public:
        Chessman(Color c, ptr<Chess::BRD::ChessBoard> b) :color(c), board(b) {}
        virtual bool isValidMove(Move m) = 0;
    };
}