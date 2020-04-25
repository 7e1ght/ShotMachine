#include "bar/GlassScanner.hpp"

void GlassScanner::update() noexcept
{
    for(uint8_t i = 0; i < supp::allGlass.size(); ++i)
    {
        supp::allGlass[i].update();
    }
}