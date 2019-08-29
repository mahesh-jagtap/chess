#pragma once
#include<string>
#include<iostream>
#include<memory>
#include "Debug.h"

namespace Chess
{
    namespace BRD
    {
        namespace MTR
        {
            class Material
            {
                std::string const m_name;

            public:
                Material(std::string name) : m_name(name) {}

                virtual void makeSound() {
                    PRINT("I make no sound");
                }

                virtual void display() {
                    PRINT(m_name);
                }
            };
        }
    }
}