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
      Serial.println( mShotMap[mOrder[i].getValue()].getName() );
      makeCocktail(mOrder[i].getValue());
   }
}

void Barman::addOrder(const GlassId id, const CocktailIdx index) noexcept
{
   if(!id)
   {
      Serial.println("Barman::addOrder GlassId == 0");
      return;
   }

   int8_t idx = getOrderByGlassId(id);

   if( -1 != idx )
   {
      Serial.println(String("Add new idx = ") + idx);
      mOrder[idx].setValue(index);
      Serial.println( String("Value = ") + mOrder[idx].getValue() );
      Serial.println("Change");
   }
   else
   {
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

Barman::GlassId Barman::getNextAvailableGlassId() const noexcept
{
   GlassId id = 0;

   for(uint8_t i = 0, startIndex = mLastGivenGlassIndex; i < mGlasses.size(); ++i, ++startIndex)
   {
      if(true == mGlasses[startIndex].isAvailable())
      {
         id = mGlasses[i].getId();
         break;
      }

      if( mGlasses.size()-1 == startIndex )
      {
         mLastGivenGlassIndex = 0;
      }
   }

   return id;
}

const bool Barman::isLiquidEnough( const Liquid::Type liquid, const uint16_t value) const noexcept
{
   struct Ingredient
   {
      Liquid::Type mLiquid;
      uint16_t mValue;

      Ingredient operator+(const Ingredient& other) const noexcept
      {
         return Ingredient{ mLiquid,  mValue + other.mValue};
      }

      bool operator==(const Ingredient& other) const noexcept
      {
         return mLiquid == other.mLiquid;
      }

   } ingredient{liquid, value};

   Ingredient sum{liquid, 0};
   
   for(uint8_t i = 0; i < mOrder.size(); ++i)
   {
      Cocktail::RecipeVector recipe = mShotMap[mOrder[i].getValue()].getRecipe();

      for(uint8_t j = 0; j < recipe.size(); ++j)
      {
         Ingredient tempIngredient{ recipe[i].getValue(), recipe[i].getKey() };

         if(tempIngredient == ingredient)
         {
            sum = sum + tempIngredient;
         }

      }
   }

   return sum.mValue <= getBottleByLiquid(liquid).getCapacity();
}

Barman::Barman()
: mBottleShelf(8)
, mShotMap()
, mGlasses(8)
, mLastGivenGlassIndex(0)
{
   initGlass();
   initBottleShelf();
   initShotMap();
}