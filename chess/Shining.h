#pragma once
#include "Coating.h"
#include<string>
#include<memory>

namespace Chess
{
    namespace BRD
    {
        namespace MTR
        {
            class Shining : public Coating
            {
            public:
                Shining(std::string name, std::shared_ptr<Material> ptr_material) :Coating(name, ptr_material) {}

            };
        }
    }
}