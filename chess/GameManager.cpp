#include "GameManager.h"
#include <utility>

Move Chess::GameManager::getMove()
{
    Position from, to;

    std::cout << "Enter the move::";
    std::cin >> from >> to;
    return std::make_pair(from, to);
}

bool Chess::GameManager::isGameOver()
{
    return false;
}