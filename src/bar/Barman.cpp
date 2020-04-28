#include "bar/Barman.hpp"

Barman& Barman::getInstance() noexcept
{
   static Barman barman;

   return barman;
}

void Barman::moveHandToGlass(const GlassId id) const noexcept
{
   Serial.println(String("Move hand to ") + id );
}

int8_t Barman::getOrderByGlassId(const GlassId id) const noexcept
{
   int8_t idx = -1;

   for (int i = 0; i < mOrder.size(); ++i)
   {
      if( id == mOrder[i].getKey())
      {
         idx = i;
         break;
      }
   }
   
   return idx;
}

void Barman::makeCocktail(const CocktailIdx index) const noexcept
{
   auto recipe = mShotMap[index].getRecipe();

   for(uint8_t i = 0; i < recipe.size(); ++i)
   {
      getBottleByLiquid(recipe[i].getValue()).pour(recipe[i].getKey());
   }
}

void Barman::executeOrder() noexcept
{
   for(uint8_t i = 0; i < mOrder.size(); ++i)
   {
      moveHandToGlass(mOrder[i].getKey());
      makeCocktail(mOrder[i].getValue());
   }
}

void Barman::addOrder(const GlassId id, const CocktailIdx index) noexcept
{
   int8_t idx = getOrderByGlassId(id);

   if( -1 != idx )
   {
      mOrder[idx].setValue(index);
   }
   else
   {
      mOrder.push_back( supp::Pair<GlassId, CocktailIdx>(id, index) );
   }
}

const Bottle& Barman::getBottleByLiquid(const Liquid::Type liquid) const noexcept
{
   for(uint8_t i = 0; i < mBottleShelf.size(); ++i)
   {
      if(liquid == mBottleShelf[i].getLiquid())
      {
         return mBottleShelf[i];
      }
   }
}

Barman::GlassId Barman::getNextAvailableGlassId() const noexcept
{
   GlassId id = 0;

   for(uint8_t i = mLastGivenGlassIndex+1; i <= mGlasses.size() && mLastGivenGlassIndex != i; ++i)
   {
      if(mGlasses[i%mGlasses.size()].isAvailable())
      {
         mLastGivenGlassIndex = i;
         id = mGlasses[i].getId();
      }
   }

   return id;
}

Barman::Barman()
: mBottleShelf(8)
, mShotMap()
, mGlasses(8)
, mLastGivenGlassIndex(-1)
{
   initGlass();
   initBottleShelf();
   initShotMap();
}