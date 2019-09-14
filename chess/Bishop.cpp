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
    Color from_color = m_board->getChessman(from)->getColor();

    if ((diff % 9 != 0) and (diff % 7 != 0))
        return false;

    Position current_position = from;
    
    std::vector<int> inc{ 9, 7 };
    int factor{ 1 };
    if (current_position > to)
    {
        factor = -1;
    }
    
    for (auto i : inc)
    {
        current_position = from;
        while (!Chess::isEdge(from))
        {
            current_position += factor * i;
            ptr<Chess::Chessman> current_chessman = m_board->getChessman(current_position);

            if (current_position == to and (!current_chessman or current_chessman->getColor() != from_color))
                return true;

            if (current_chessman)
            {
                if (current_position != to)
                {
                    break;
                }
                else //current_position==to
                {
                    if (current_chessman->getColor() == from_color)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Chess::Bishop::isPositionReachable(Move m)
{
    return false;
}