#pragma once
#include"Coating.h"
#include<string>

namespace Chess
{
    namespace BRD
    {
        namespace MTR
        {
            class Regular :public Coating
            {
            public:
                Regular(std::string name, std::shared_ptr<Material> ptr_material) :Coating(name, ptr_material) {}
            };
        }
    }
}