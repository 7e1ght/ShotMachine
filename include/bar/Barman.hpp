#ifndef BARMAN_HPP
#define BARMAN_HPP

#include "support/support.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Cocktail.hpp"

class Barman
{
public:
   using GlassId = int8_t;
   using CocktailIdx = int8_t;

   void executeOrder() noexcept;
   void addOrder(const GlassId glass, const CocktailIdx cocktail) noexcept;

   bool isOrderContains(const GlassId glass, const CocktailIdx cocktail) const noexcept;
   bool isContainsGlass(const GlassId id) const noexcept;
   bool isPossibleChange(const GlassId id, const CocktailIdx newCocktail) const noexcept;

   GlassId getPreviousGlassId() noexcept;
   GlassId getNextGlassId() noexcept;

   const Cocktail& getCocktailByIndex(const CocktailIdx index) const noexcept;
   const Bottle& getBottleByLiquid(const Liquid::Type liquid) const noexcept;

   supp::Vector<Glass>& get() { return mGlasses; }

   static Barman& getInstance() noexcept;

   const supp::Vector<Bottle>& getBottleShelf() const noexcept;
   const supp::Vector<Glass>& getGlasses() const noexcept;
   const supp::Vector<Cocktail>& getShotMap() const noexcept;

   const bool isLiquidEnough( const Liquid::Type liquid, const uint16_t value ) const noexcept;

private:
   int8_t NO_VALID_COCKTAIL_INDEX = -1;

   supp::Vector<supp::Pair<GlassId, CocktailIdx>> mOrder;

   int8_t getOrderByGlassId(const GlassId glass) const noexcept;
   void moveHandToGlass(const GlassId id) const noexcept;
   void makeCocktail(const CocktailIdx index) const noexcept;

   supp::Vector<Bottle> mBottleShelf;
   supp::Vector<Glass> mGlasses;
   supp::Vector<Cocktail> mShotMap;

   int8_t mLastGivenGlassIndex; 

   void initGlass() noexcept;
   void initShotMap() noexcept;
   void initBottleShelf() noexcept;

   Barman();

   void water() noexcept;
   void vlad() noexcept;
   void die() noexcept;
};

inline const supp::Vector<Bottle>& Barman::getBottleShelf() const noexcept
{
   return mBottleShelf;
}

inline const supp::Vector<Glass>& Barman::getGlasses() const noexcept
{
   return mGlasses;
}

inline const supp::Vector<Cocktail>& Barman::getShotMap() const noexcept
{
   return mShotMap;
}

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
  water.addStep(100, Liquid::VODKA);

  mShotMap.push_back(water);
}

inline void Barman::vlad() noexcept
{
  Cocktail water2("Vlad");

  water2.addStep(200, Liquid::VODA);
  water2.addStep(200, Liquid::VODKA);

  mShotMap.push_back(water2);
}

inline void Barman::die() noexcept
{
  Cocktail d("Die");

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