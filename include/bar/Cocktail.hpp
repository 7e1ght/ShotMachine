#ifndef COCKTAIL_HPP
#define COCKTAIL_HPP

#include "support/Vector.hpp"
#include "support/support.hpp"
#include "Bottle.hpp"

class Cocktail
{
private:
    String mName;
    supp::Vector<supp::Pair<uint16_t, Bottle>> mRecipe;

public:
    void makeCocktail() noexcept;

    const supp::Vector<supp::Pair<uint16_t, Bottle>>& getRecipe() const noexcept { return mRecipe; }

    void addStep(uint16_t capacity, const Bottle& bottle) noexcept
    {
        mRecipe.push_back(supp::Pair<uint16_t, Bottle>(capacity, bottle));
    }

    const String& getName() const noexcept
    {
        return mName;
    }

    Cocktail(String name) : mName(name), mRecipe(8) {}
    Cocktail() : mRecipe(8) {}
};

#endif // COCKTAIL_HPP