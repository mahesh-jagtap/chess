#include "Rook.h"
#include "Utility.h"
#include <cstdlib>

bool Chess::Rook::isChessmanMove(Move m)
{
    Position from = m.first;
    Position to = m.second;

    //Check if from and to positions are in the same column
    if (abs(from - to) % 8 == 0)
        return true;

    //Check if from and to positions are in the same row
    if ((from - 1) / 8 == (to - 1) / 8)
        return true;

    return false;
}

bool Chess::Rook::isPositionReachable(Move m)
{
    // We have already confirmed that the move is doable for the piece.
    // So we can write logic accordingly.
    
    Position from = m.first;
    Position to = m.second;
    Position diff = std::abs(from - to);
    Color from_color = m_board->getChessman(from)->getColor();

    int value = 1; //from and to positions are in the same row
    int direction = 1;

    if (diff >= 8)
    {
        // from and to positions are in the same column
        value = 8;
    }
    if (from > to)
    {
        direction = -1;
    }

    int current_position = from + value * direction;
    while (Chess::isValidPosition(current_position))
    {
        if (current_position==to)
        {
            if (!m_board->isSameColorChessman(from, to))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            //current_position is somewhere in between from and to

            if (m_board->isChessmanPresent(current_position))
            {
                //a Chessman is present in between from and to
                return false;
            }
        }

        current_position = current_position + value * direction;
    }
    return false;
}