#include "ChessBoard.h"
#include "Debug.h"
#include <utility>

using ChessBoard = Chess::BRD::ChessBoard;

ChessBoard::ChessBoard()
{
    for (Position i = 9; i <= 16; i++)
    {
        m_board.insert(std::make_pair(i, make_ptr<Chess::Pawn>(Color::white)));
    }

    for (Position i = 49; i <= 56; i++)
    {
        m_board.insert(std::make_pair(i, make_ptr<Chess::Pawn>(Color::black)));
    }

    m_board.insert(std::make_pair(1, make_ptr<Chess::Rook>(Color::white)));
    m_board.insert(std::make_pair(8, make_ptr<Chess::Rook>(Color::white)));
    m_board.insert(std::make_pair(57, make_ptr<Chess::Rook>(Color::black)));
    m_board.insert(std::make_pair(64, make_ptr<Chess::Rook>(Color::black)));

    m_board.insert(std::make_pair(2, make_ptr<Chess::Knight>(Color::white)));
    m_board.insert(std::make_pair(7, make_ptr<Chess::Knight>(Color::white)));
    m_board.insert(std::make_pair(58, make_ptr<Chess::Knight>(Color::black)));
    m_board.insert(std::make_pair(63, make_ptr<Chess::Knight>(Color::black)));

    m_board.insert(std::make_pair(3, make_ptr<Chess::Bishop>(Color::white)));
    m_board.insert(std::make_pair(6, make_ptr<Chess::Bishop>(Color::white)));
    m_board.insert(std::make_pair(59, make_ptr<Chess::Bishop>(Color::black)));
    m_board.insert(std::make_pair(62, make_ptr<Chess::Bishop>(Color::black)));

    m_board.insert(std::make_pair(5, make_ptr<Chess::King>(Color::white)));
    m_board.insert(std::make_pair(61, make_ptr<Chess::King>(Color::black)));

    m_board.insert(std::make_pair(4, make_ptr<Chess::Queen>(Color::white)));
    m_board.insert(std::make_pair(60, make_ptr<Chess::Queen>(Color::black)));

}

void Chess::BRD::ChessBoard::makeMove(Move m)
{
    m_board[m.second] = m_board[m.first];
    m_board.erase(m.first);
}

ptr<Chess::Chessman> ChessBoard::getChessman(Position p)
{
    auto it = m_board.find(p);
    
    if (it == m_board.end())
        return nullptr;
    
    return it;
}

bool Chess::BRD::ChessBoard::isValidMove(Move m)
{
    /*For a move to be valid
        1. It must be withing the chess board.
        2. The to Position should be empty OR should contain a piece of opposite color.
        3. It must be valid as per the individual Chessman */

    Position from = m.first;
    Position to = m.second;
    ptr<Chess::Chessman> ptr_move_chessman = m_board.find(m.first);
    ptr<Chess::Chessman> ptr_replace_chessman = m_board.find(m.second);

    if (from == to)
        return false;

    if (ptr_move_chessman == m_board.end())
    {
        PRINT("Invalid move. No piece available to move.");
        return false;
    }

    if (m.first < 1 or m.first > 64 or m.second < 1 or m.second > 64)
    {
        PRINT("Invalid move. One of the position is out of the chess board.");
        return false;
    }

    if (ptr_replace_chessman != m_board.end())
    {
        if (ptr_move_chessman->getColor() == ptr_replace_chessman->getColor())
        {
            PRINT("Invalid move. From and To position have the same color chessman.");
            return false;
        }
    }

    return ptr_move_chessman->isValidMove(m);
}
