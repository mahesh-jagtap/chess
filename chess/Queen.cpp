#include "Queen.h"
#include "Utility.h"
#include "Rook.h"
#include "Bishop.h"

bool Chess::Queen::isChessmanMove(Move m)
{
    Chess::Rook r = Chess::Rook();
    Chess::Bishop b = Chess::Bishop();

    return r.isChessmanMove(m) or b.isChessmanMove(m);
}
bool Chess::Queen::isPositionReachable(Move m)
{
    Chess::Rook r = Chess::Rook();
    Chess::Bishop b = Chess::Bishop();

    return r.isPositionReachable(m) or b.isPositionReachable(m);
}