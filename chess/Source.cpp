#define DEBUG
#include "Debug.h"
#include "Material.h"
#include "Wood.h"
#include "Plastic.h"
#include "Coating.h"
#include "MatteFinish.h"
#include "Shining.h"
#include "Regular.h"
#include <conio.h>
#include "Memory.h"
#include "GameManager.h"
#include "ChessBoard.h"
#include <gtest/gtest.h>

namespace MTR = Chess::BRD::MTR;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    MTR::Material m("Default");
    m.makeSound();
    
    MTR::Wood w("Wood");
    w.makeSound();

    ptr<MTR::Plastic> ptr_plastic = make_ptr<MTR::Plastic>("Plastic");
    ptr_plastic->display();

    std::cout << "-------------------" << std::endl;
    ptr<MTR::Material> w1 = make_ptr<MTR::Wood>("Wood1");
    ptr<MTR::Material> t1 = make_ptr<MTR::MatteFinish>("MatteFinish1", w1);
    ptr<MTR::Material> s1 = make_ptr<MTR::Shining>("Shining1", w1);
    s1->display();

    std::cout << "-------------------" << std::endl;
    ptr<MTR::Material> regular_wood = make_ptr<MTR::Regular>("Regular1", make_ptr<MTR::Material>("Wood2"));
    regular_wood->display();

    Chess::GameManager gm(make_ptr<Chess::BRD::ChessBoard>(), make_ptr<Chess::Notation>());
    
    while (!gm.isGameOver())
    {
        Move m = gm.getMove();
        if (gm.getBoard()->isValidMove(m))
        {
            gm.getBoard()->makeMove(m);
        }
    }

    _getch();
}