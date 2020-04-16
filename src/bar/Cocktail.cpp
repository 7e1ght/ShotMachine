#include "bar/Cocktail.hpp"

void Cocktail::makeCocktail() noexcept
{
    for(uint8_t i = 0; mRecipe.size() > i; ++i)
    {
        mRecipe[i].getValue().pour(mRecipe[i].getKey());
    }
}