#include "bar/GlassScanner.hpp"

#include "bar/Barman.hpp"

void GlassScanner::update() noexcept
{
    for(uint8_t i = 0; i < Barman::allGlass.size(); ++i)
    {
        Barman::allGlass[i].update();
    }
}