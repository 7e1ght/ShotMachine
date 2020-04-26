#include "bar/Barman.hpp"

supp::Vector<Glass> Barman::allGlass;
supp::Vector<Cocktail> Barman::shotMap;

Barman& Barman::getInstance() noexcept
{
   static Barman barman;

   return barman;
}

void Barman::moveHandToGlass(const Glass& glass) const noexcept
{
   Serial.println(String("Move hand to ") + glass.getId() );
}

int8_t Barman::getOrderByGlass(const Glass& glass) const noexcept
{
   int8_t idx = -1;

   for (int i = 0; i < mCocktail.size(); ++i)
   {
      if( glass == mCocktail[i].getKey())
      {
         idx = i;
         break;
      }
   }
   
   return idx;
}

void Barman::executeOrder() noexcept
{
   for(uint8_t i = 0; i < mCocktail.size(); ++i)
   {
      moveHandToGlass(mCocktail[i].getKey());
      mCocktail[i].getValue().makeCocktail();
   }
}

void Barman::addOrder(const Glass& glass, const Cocktail& cocktail) noexcept
{
   int8_t idx = getOrderByGlass(glass);

   if( -1 != idx )
   {
      mCocktail[idx].setValue(cocktail);
   }
   else
   {
      mCocktail.push_back( supp::Pair<Glass, Cocktail>(glass, cocktail) );
   }
}