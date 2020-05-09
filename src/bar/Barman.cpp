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
      if(mGlasses[mOrder[i].getKey()].isAvailable() && mOrder[i].getValue() != NO_VALID_COCKTAIL_INDEX)
      {
         moveHandToGlass(mOrder[i].getKey());
         Serial.println( mShotMap[mOrder[i].getValue()].getName() );
         makeCocktail(mOrder[i].getValue());
      }
   }
}

bool Barman::isOrderContains(const Barman::GlassId glass, const Barman::CocktailIdx cocktail) const noexcept
{
   int8_t idx =  getOrderByGlassId(glass);

   return (mOrder[idx].getKey() == glass && mOrder[idx].getValue() == cocktail);
}

bool Barman::isContainsGlass(Barman::GlassId id) const noexcept
{
   bool returnValue = false;

   int8_t idx = getOrderByGlassId(id);

   if(-1 != idx)
   {
      returnValue = mOrder[idx].getValue() != NO_VALID_COCKTAIL_INDEX;
   }

   return returnValue;
}

void Barman::addOrder(const GlassId id, const CocktailIdx index) noexcept
{
   if(!id || index < 0)
   {
      Serial.println("Barman::addOrder invalid order");
      return;
   }

   int8_t idx = getOrderByGlassId(id);

   if( isOrderContains(id, index) )
   {
      Serial.println("Delete ");
      mOrder[idx].setValue(NO_VALID_COCKTAIL_INDEX);
   }
   else if( -1 != idx )
   {
      Serial.println(String("Add new idx = ") + idx);
      mOrder[idx].setValue(index);
      Serial.println( String("Value = ") + mOrder[idx].getValue() );
      Serial.println("Change");
   }
   else
   {
      Serial.println("------- Add new order ------");
      Serial.println( mShotMap[index].getName() );
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

Barman::GlassId Barman::getNextGlassId() noexcept
{
   GlassId id = 0;

   for(uint8_t i = 0, startIndex = mLastGivenGlassIndex+1; i < mGlasses.size(); ++i, ++startIndex)
   {
      if( mGlasses.size()-1 < startIndex )
      {
         startIndex = 0;
      }

      if(true == mGlasses[startIndex].isAvailable())
      {
         id = mGlasses[startIndex].getId();
         mLastGivenGlassIndex = startIndex;
         break;
      }
   }

   return id;
}

Barman::GlassId Barman::getPreviousGlassId() noexcept
{
   GlassId id = 0;

   for(int8_t i = 0, startIndex = mLastGivenGlassIndex-1; i < mGlasses.size(); ++i, --startIndex)
   {
      if( 0 > startIndex )
      {
         startIndex = mGlasses.size() - 1;
      }

      Serial.println( String("Start index ") + startIndex );

      if(true == mGlasses[startIndex].isAvailable())
      {
         id = mGlasses[startIndex].getId();
         mLastGivenGlassIndex = startIndex;
         break;
      }

   }

   return id;
}

const bool Barman::isLiquidEnough( const Liquid::Type liquid, const uint16_t value) const noexcept
{
   uint16_t sum = 0;

   for(uint8_t i = 0; i < mOrder.size(); ++i)
   {
      Cocktail::RecipeVector recipe = getCocktailByIndex(mOrder[i].getValue()).getRecipe();

      for(uint8_t j = 0; j < recipe.size(); ++j)
      {
         if(recipe[j].getValue() == liquid)
         {
            sum += recipe[j].getKey();
         }
      }
   }

   Serial.println( String("Liquid: ") + Liquid::getName(liquid) );
   Serial.println( String("sum = " ) + String(sum) );

   return (sum + value) <= getBottleByLiquid(liquid).getCapacity();
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