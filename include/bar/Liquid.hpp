#ifndef LIQUID_HPP
#define LIQUID_HPP

#include "support/support.hpp"

struct Liquid
{
    enum Type
    {
        NO_LIQUID,
        VODA
    };

    static String getName(Type type) noexcept 
    {
        String name;
        
        switch (type)
        {
        case VODA:
            name = "Voda";
            break;
        
        default:
            break;
        }

        return name;
    }
    
};

#endif // LIQUID_HPP