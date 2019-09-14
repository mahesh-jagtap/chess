#include "ChessBoard.h"
#include "Debug.h"
#include <utility>

using ChessBoard = Chess::BRD::ChessBoard;

ChessBoard::ChessBoard()
{
    for (Position i = 9; i <= 16; i++)
    {
        //m_board.insert(std::make_pair(i, make_ptr<Chess::Pawn>(Color::white)));
    }

    for (Position i = 49; i <= 56; i++)
    {
        //m_board.insert(std::make_pair(i, make_ptr<Chess::Pawn>(Color::black)));
    }

    m_board.insert(std::make_pair(1, std::make_shared<Chess::Rook>(Color::white, this)));
    m_board.insert(std::make_pair(8, make_ptr<Chess::Rook>(Color::white, this)));
    m_board.insert(std::make_pair(57, make_ptr<Chess::Rook>(Color::black, this)));
    m_board.insert(std::make_pair(64, make_ptr<Chess::Rook>(Color::black, this)));

    m_board.insert(std::make_pair(2, make_ptr<Chess::Knight>(Color::white, this)));
    m_board.insert(std::make_pair(7, make_ptr<Chess::Knight>(Color::white, this)));
    m_board.insert(std::make_pair(58, make_ptr<Chess::Knight>(Color::black, this)));
    m_board.insert(std::make_pair(63, make_ptr<Chess::Knight>(Color::black, this)));

    m_board.insert(std::make_pair(3, make_ptr<Chess::Bishop>(Color::white, this)));
    m_board.insert(std::make_pair(6, make_ptr<Chess::Bishop>(Color::white, this)));
    m_board.insert(std::make_pair(59, make_ptr<Chess::Bishop>(Color::black, this)));
    m_board.insert(std::make_pair(62, make_ptr<Chess::Bishop>(Color::black, this)));

    m_board.insert(std::make_pair(5, make_ptr<Chess::King>(Color::white, this)));
    m_board.insert(std::make_pair(61, make_ptr<Chess::King>(Color::black, this)));

    m_board.insert(std::make_pair(4, make_ptr<Chess::Queen>(Color::white, this)));
    m_board.insert(std::make_pair(60, make_ptr<Chess::Queen>(Color::black, this)));

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
    
    return it->second;
}

bool Chess::BRD::ChessBoard::isSameColorChessman(Position from, Position to)
{
    return getChessman(from)->getColor() == getChessman(to)->getColor();
}

bool Chess::BRD::ChessBoard::isChessmanPresent(Position p)
{
    return getChessman(p) != nullptr;
}

bool Chess::BRD::ChessBoard::isValidMove(Move m)
{
    /*For a move to be valid
        1. It must be withing the chess board.
        2. The to Position should be empty OR should contain a piece of opposite color.
        3. It must be valid as per the individual Chessman */

    Position from = m.first;
    Position to = m.second;
    ptr<Chess::Chessman> ptr_move_chessman = getChessman(from);  //m_board.find(m.first)->second;
    ptr<Chess::Chessman> ptr_replace_chessman = getChessman(to); //m_board.find(m.second)->second;

    if (from == to)
        return false;

    if (ptr_move_chessman == nullptr)
    {
        PRINT("Invalid move. No piece available to move.");
        return false;
    }

    if (m.first < 1 or m.first > 64 or m.second < 1 or m.second > 64)
    {
        PRINT("Invalid move. One of the position is out of the chess board.");
        return false;
    }

    if (ptr_replace_chessman != nullptr)
    {
        if (ptr_move_chessman->getColor() == ptr_replace_chessman->getColor())
        {
            PRINT("Invalid move. From and To position have the same color chessman.");
            return false;
        }
    }

    return ptr_move_chessman->isValidMove(m);
}
