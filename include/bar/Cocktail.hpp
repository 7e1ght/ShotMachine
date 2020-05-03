#ifndef COCKTAIL_HPP
#define COCKTAIL_HPP

#include "support/Vector.hpp"
#include "support/support.hpp"
#include "Bottle.hpp"

class Cocktail
{
public:
    using RecipeVector = supp::Vector<supp::Pair<uint16_t, Liquid::Type>>;

    const RecipeVector& getRecipe() const noexcept { return mRecipe; }

    void addStep(uint16_t capacity, Liquid::Type liquid) noexcept
    {
        mRecipe.push_back(supp::Pair<uint16_t, Liquid::Type>(capacity, liquid));
    }

    const String& getName() const noexcept
    {
        return mName;
    }

    Cocktail(String name) : mName(name), mRecipe(8) 
    { 
    }
    
    Cocktail() : mRecipe(8) {}
private:
    String mName;
    RecipeVector mRecipe;
};

#endif // COCKTAIL_HPP