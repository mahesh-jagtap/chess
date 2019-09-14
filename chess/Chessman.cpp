#include "Chessman.h"

bool Chess::Chessman::isValidMove(Move m)
{
    return isChessmanMove(m) and isPositionReachable(m);
}