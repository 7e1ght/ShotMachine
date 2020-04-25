#ifndef BARMAN_HPP
#define BARMAN_HPP

#include "support/support.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Cocktail.hpp"

namespace supp
{
  static Vector<Glass> allGlass;
  static Vector<Cocktail> shotMap;
}

class Barman
{
private:
  supp::Vector<supp::Pair<Glass, Cocktail>> mCocktail;

  void moveHandToGlass(const Glass& glass) const noexcept;
  int8_t getOrderByGlass(const Glass& glass) const noexcept;

  Barman(){}

public:
  void executeOrder() noexcept;
  void addOrder(const Glass& glass, const Cocktail& cocktail) noexcept;

  bool isContains(const Glass& glass) const noexcept;
  
  static Barman& getInstance() noexcept;
};

#endif // BARMAN_HPP