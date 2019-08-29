#pragma once
#include "Coating.h"

namespace Chess
{
    namespace BRD
    {
        namespace MTR
        {

            class MatteFinish : public Coating
            {
            public:
                MatteFinish(std::string name, std::shared_ptr<Material> ptr_material) :Coating(name, ptr_material) {}

            };

        }
    }
}
