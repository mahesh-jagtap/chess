#pragma once
#include "Chessman.h"
#include "Material.h"
#include "Memory.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include<map>

namespace Chess
{
    namespace BRD
    {
        class ChessBoard
        {
            std::map<Position, ptr<Chess::Chessman>> m_board;

        public:
            
            ChessBoard();
            bool isValidMove(Move m);
            void makeMove(Move m);
            ptr<Chessman> getChessman(Position p);

        };
    }
}