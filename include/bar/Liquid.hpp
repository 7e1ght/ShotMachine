#ifndef LIQUID_HPP
#define LIQUID_HPP

#include "support/support.hpp"

struct Liquid
{
    enum Type
    {
        NO_LIQUID,
        RUM,
        ORANGE_JUICE,
        COLA,
        SYRUP_COCONUT,
        MARTINI,
        LIQUOR_CHERRY,
        SPRITE,
        PINEAPPLE_JUICE
    };

    static String getName(Type type) noexcept 
    {
        String name = "ERROR";
        
        switch (type)
        {
        case RUM:
            name = "Rum";
            break;
        case ORANGE_JUICE:
            name = "Orange juice";
            break;
        case SYRUP_COCONUT:
            name = "Syrup coconut";
            break;
        case COLA: 
            name = "Cola";
            break;
        case MARTINI:
            name = "Martini";
            break;
        case LIQUOR_CHERRY:
            name = "Liquor cherry";
            break;
        case SPRITE:
            name = "Sprite";
            break;
        case PINEAPPLE_JUICE:
            name = "Pineapple juice";
            break;
        default:
            break;
        }

        return name;
    }
    
};

#endif // LIQUID_HPP