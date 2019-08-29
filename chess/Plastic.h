#pragma once
#include "Material.h"
#include<string>

namespace Chess
{
    namespace BRD
    {
        namespace MTR
        {
            class Plastic : public Material
            {
            public:
                Plastic(std::string name) :Material(name) {}

                void makeSound() override
                {
                    PRINT("Plastic sound");
                }

                void display() override
                {
                    Material::display();
                }
            };

        }
    }
}