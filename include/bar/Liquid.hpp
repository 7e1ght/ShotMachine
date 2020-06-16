#ifndef LIQUID_HPP
#define LIQUID_HPP

#include "support/support.hpp"

struct Liquid
{
    enum Type
    {
        NO_LIQUID,
        VODKA,
        ORANGE_JUICE,
        LIQUOR_COCONUT,
        SYRUP_RASPBERRY,
        MARTINI,
        LEMON_JUICE,
        SPRITE,
        CURACAO
    };

    static String getName(Type type) noexcept 
    {
        String name = "ERROR";
        
        switch (type)
        {
        case VODKA:
            name = "Vodka";
            break;
        case ORANGE_JUICE:
            name = "Orange juice";
            break;
        case LIQUOR_COCONUT:
            name = "Liquor coconut";
            break;
        case SYRUP_RASPBERRY: 
            name = "Syrup raspberry";
            break;
        case MARTINI:
            name = "Martini";
            break;
        case LEMON_JUICE:
            name = "Lemon juice";
            break;
        case SPRITE:
            name = "Sprite";
            break;
        case CURACAO:
            name = "Curacao";
            break;
        default:
            break;
        }

        return name;
    }
    
};

#endif // LIQUID_HPP