#ifndef BARMAN_HPP
#define BARMAN_HPP

#include "support/support.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Cocktail.hpp"

class Barman
{

public:
   using GlassId = uint8_t;
   using CocktailIdx = uint8_t;

   void executeOrder() noexcept;
   void addOrder(const GlassId glass, const CocktailIdx cocktail) noexcept;

   bool isContains(const Glass& glass) const noexcept;

   bool isAnyAvailableGlass() const noexcept;

   GlassId getNextAvailableGlassId() const noexcept;
   const Cocktail& getCocktailByIndex(const CocktailIdx index) const noexcept;
   const Bottle& getBottleByLiquid(const Liquid::Type liquid) const noexcept;

   supp::Vector<Bottle>& get() { return mBottleShelf; }

   static Barman& getInstance() noexcept;
private:
   supp::Vector<supp::Pair<GlassId, CocktailIdx>> mOrder;

   void moveHandToGlass(const GlassId id) const noexcept;
   int8_t getOrderByGlassId(const GlassId glass) const noexcept;
   void makeCocktail(const CocktailIdx index) const noexcept;

   supp::Vector<Bottle> mBottleShelf;
   supp::Vector<Glass> mGlasses;
   supp::Vector<Cocktail> mShotMap;

   mutable int8_t mLastGivenGlassIndex; 

   void initGlass() noexcept;
   void initShotMap() noexcept;
   void initBottleShelf() noexcept;

   Barman();

   void water() noexcept;
   void vlad() noexcept;
   void die() noexcept;
};

inline void Barman::initGlass() noexcept
{
   mGlasses.push_back(Glass(A1, A0));
   mGlasses.push_back(Glass(A3, A2));
   mGlasses.push_back(Glass(A5, A4));
   mGlasses.push_back(Glass(A7, A6));
   mGlasses.push_back(Glass(A9, A8));
   mGlasses.push_back(Glass(A11, A10));
   mGlasses.push_back(Glass(A13, A12));
   mGlasses.push_back(Glass(A15, A14));
}

inline void Barman::water() noexcept
{
  Cocktail water("Water");

  water.addStep(100, Liquid::VODA);
  water.addStep(200, Liquid::VODKA);

  mShotMap.push_back(water);
}

inline void Barman::vlad() noexcept
{
  Cocktail water2("Vlad");

  water2.addStep(30, Liquid::VODA);
  water2.addStep(110, Liquid::VODA);
  water2.addStep(40, Liquid::VODA);
  water2.addStep(60, Liquid::VODKA);
  water2.addStep(20, Liquid::VODKA);

  mShotMap.push_back(water2);
}

inline void Barman::die() noexcept
{
  Cocktail d("Die");

  d.addStep(999, Liquid::VODKA);
  d.addStep(999, Liquid::VODKA);
  d.addStep(999, Liquid::VODKA);
  d.addStep(999, Liquid::VODKA);
  d.addStep(999, Liquid::VODKA);

  mShotMap.push_back(d);
}

inline void Barman::initShotMap() noexcept
{
   water();
   vlad();
   die();
}

inline void Barman::initBottleShelf() noexcept
{
   mBottleShelf.push_back(Bottle(14, Liquid::VODA));
   mBottleShelf.push_back(Bottle(15, Liquid::VODKA));
   mBottleShelf.push_back(Bottle(16, Liquid::NO_LIQUID));
   mBottleShelf.push_back(Bottle(17, Liquid::NO_LIQUID));
   mBottleShelf.push_back(Bottle(18, Liquid::NO_LIQUID));
   mBottleShelf.push_back(Bottle(19, Liquid::NO_LIQUID));
   mBottleShelf.push_back(Bottle(20, Liquid::NO_LIQUID));
   mBottleShelf.push_back(Bottle(21, Liquid::NO_LIQUID));
}

inline const Cocktail& Barman::getCocktailByIndex(const CocktailIdx index) const noexcept
{
   return mShotMap[index];
}

#endif // BARMAN_HPP