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

            //Check if the given move is valid
            bool isValidMove(Move m);

            //Update the chessboard for the given move
            void makeMove(Move m);

            //Return the chessman at given position
            ptr<Chessman> getChessman(Position p);

            //Check if chessman at two positions have the same color
            bool isSameColorChessman(Position from, Position to);
            bool isSameColorChessman(ptr<Chess::Chessman> c1, ptr<Chess::Chessman> c2);

            //Check if chessman is present at a position
            bool isChessmanPresent(Position p);

            //Display board
            void display();

        };
    }
}