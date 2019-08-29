#pragma once
#include "Material.h"
#include<string>

namespace Chess
{
    namespace BRD
    {
        namespace MTR
        {
            class Wood : public Material
            {
            public:
                Wood(std::string name) :Material(name) {}

                void makeSound() override
                {
                    PRINT("Wood sound");
                }

                void display() override
                {
                    Material::display();
                }
            };

        }
    }
}