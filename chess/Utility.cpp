#include "Utility.h"

bool Chess::isEdge(Position p)
{
    std::set<int> edges{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 64, 16, 24, 32, 40, 48, 56 };

    return edges.find(p) != edges.end();
    
}

bool Chess::isValidPosition(Position p)
{
    return p >= 1 and p <= 64;
}
