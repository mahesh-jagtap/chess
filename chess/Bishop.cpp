#include "Bishop.h"
#include<vector>
#include "Utility.h"

bool Chess::Bishop::isChessmanMove(Move m)
{
    //Check if the difference is divisible by 7 or 9
    //If yes, then check for all positions in between:
    //    1. If you find any chessman in between then stop.
    //    2. If you encounter edge of board then stop.

    Position from = m.first;
    Position to = m.second;
    Position diff = std::abs(from - to);

    return (diff % 9 == 0) or (diff % 7 == 0);
}

bool Chess::Bishop::isPositionReachable(Move m)
{
    Position from = m.first;
    Position to = m.second;
    Position diff = std::abs(from - to);
    Color from_color = m_board->getChessman(from)->getColor();

    Position current_position;

    std::vector<int> increments{ 9, 7 };
    int direction{ 1 };
    if (from > to)
    {
        direction = -1;
    }

    for (auto i : increments)
    {
        int current_position = from + i * direction;
        while (Chess::isValidPosition(current_position))
        {
            if (current_position == to)
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

            current_position = current_position + i * direction;
        }
    }

    return false;
}