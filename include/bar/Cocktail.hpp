#ifndef COCKTAIL_HPP
#define COCKTAIL_HPP

#include "support/Vector.hpp"
#include "support/support.hpp"
#include "Bottle.hpp"

class Cocktail
{
private:
    String mName;
    supp::Vector<supp::Pair<uint16_t, Liquid::Type>> mRecipe;

public:

    const supp::Vector<supp::Pair<uint16_t, Liquid::Type>>& getRecipe() const noexcept { return mRecipe; }

    void addStep(uint16_t capacity, Liquid::Type liquid) noexcept
    {
        mRecipe.push_back(supp::Pair<uint16_t, Liquid::Type>(capacity, liquid));
    }

    const String& getName() noexcept
    {
        return mName;
    }

    Cocktail(String name) : mName(name), mRecipe(8) 
    { 
    }
    
    Cocktail() : mRecipe(8) {}
};

#endif // COCKTAIL_HPP