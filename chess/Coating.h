#pragma once
#include "Material.h"
#include<string>
#include<memory>

namespace Chess
{
    namespace BRD
    {
        namespace MTR
        {
            class Coating : public Material
            {
                std::shared_ptr<Material> m_ptr_material;
            public:
                Coating(std::string name, std::shared_ptr<Material> ptr_material) :Material(name), m_ptr_material(ptr_material) {}

                void display() override
                {
                    Material::display();
                    m_ptr_material->display();
                }
            };

        }
    }
}