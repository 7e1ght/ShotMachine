#ifndef BARMAN_HPP
#define BARMAN_HPP

#include "support/support.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Cocktail.hpp"

class Barman
{
private:
    supp::Vector<supp::Pair<Glass, Cocktail>> mCocktail;

    void moveHandToGlass(const Glass& glass) const noexcept;

public:
    void executeOrder() const noexcept;
    void addOrder(const Glass& glass, const Cocktail& cocktail) noexcept;
};

#endif // BARMAN_HPP