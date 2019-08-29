#pragma once
#include<memory>
#include<map>

using Position = int;
using Move = std::pair<Position, Position>;

template<typename T>
using ptr = std::shared_ptr<T>;

enum class Color {black, white};

template <typename T, typename... Args>
auto make_ptr(Args&&... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}