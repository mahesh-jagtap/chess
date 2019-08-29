#pragma once
#include "Memory.h"
#include "ChessBoard.h"
#include "Notation.h"

namespace Chess
{
    enum class Player { white, black };

    class GameManager
    {
        ptr<Chess::BRD::ChessBoard> m_ptr_board;
        ptr<Chess::Notation> m_ptr_notation;
        Player turn;
        Player winner;

    public:
        GameManager(ptr<Chess::BRD::ChessBoard> board, ptr<Chess::Notation> notation):m_ptr_board(board), m_ptr_notation(notation)
        {
            turn = Player::white;
        }

        auto getBoard() { return m_ptr_board; }
        bool isGameOver(); //Currently only check for CheckMate, Time limits not applicable
        Move getMove(); //Take user input and convert to Move object
    };
}