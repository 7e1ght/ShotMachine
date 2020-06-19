#include "bar/Barman.hpp"

#include "support/Hand.hpp"

Barman& Barman::getInstance() noexcept
{
   static Barman barman;

   return barman;
}

void Barman::makeCocktail(const CocktailIdx index) const noexcept
{
   auto recipe = mShotMap[index].getRecipe();
   Serial.println(mShotMap[index].getName());

   for(uint8_t i = 0; i < recipe.size(); ++i)
   {
      Serial.print("INT = ");
      Serial.println(Liquid::getName(recipe[i].getValue()));
      Serial.print("value = ");
      Serial.println(recipe[i].getKey());
      getBottleByLiquid(recipe[i].getValue()).pour(recipe[i].getKey());
   }
}

void Barman::executeOrder() noexcept
{
   Serial.print("mOrder size = ");
   Serial.println(mOrder.size());

   for(uint8_t i = 0; i < mOrder.size() && isNextGlassFound(); ++i)
   {
      if(mGlass.isAvailable())
      {
         makeCocktail(mOrder[i]);
         delay(3000);
         Hand::getInstance().makeSteps(135);
      }
   }

   mOrder.clear();
   Hand::getInstance().resetStepped();
}

bool Barman::isNextGlassFound() noexcept
{
   bool returnValue = false;

   for(int i = Hand::getInstance().getStepped(); i < cfg::hand::FULL_ROTATE_STEPS; i += 20)
   {
      Hand::getInstance().makeSteps(20);

      returnValue = mGlass.isAvailable();

      if(returnValue)
      {
         return returnValue;
      }
   }

   return returnValue;
}

void Barman::addOrder(const CocktailIdx index) noexcept
{
   mOrder.push_back(index);
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

const bool Barman::isLiquidEnough( const Liquid::Type liquid, const uint16_t value) const noexcept
{
   uint16_t sum = 0;

   for(uint8_t i = 0; i < mOrder.size(); ++i)
   {
      Cocktail::RecipeVector recipe = getCocktailByIndex(mOrder[i]).getRecipe();

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
: mGlass(A1, A0)
, mBottleShelf(8)
, mShotMap()
, mLastGivenGlassIndex(-1)
{
   initBottleShelf();
   initShotMap();
}