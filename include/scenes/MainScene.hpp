#ifndef MAIN_SCENE_HPP
#define MAIN_SCENE_HPP

#include "IScene.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"
#include "containers/ButtonContainer.hpp"

#include "bar/Bottle.hpp"

class MainScene
: public IScene
{
public:
   MainScene();
private:
   enum DIRECTION 
   { 
      DIR_NONE,
      DIR_LEFT, 
      DIR_RIGHT 
   };

   void initElements() noexcept;
   void addElements() noexcept;

   void addItem(const Bottle* leftSide, const uint16_t rightSide) noexcept;

   void changeGlass(DIRECTION d) noexcept;
   void changeCocktail(DIRECTION d) noexcept;
   void fillRecipe() noexcept;

   TripleContainer* upperBar;
   TripleContainer* lowerBar;

   EmptyContainer* contentLayout;

   ListContainer* cocktailContent;

   EmptyContainer* buttonLayout;

   ButtonContainer* createTemplate;
   ButtonContainer* toQueu;
   ButtonContainer* coock;

   TextContainer* mCocktailName;
   TextContainer* mGlassNumber;

   uint8_t mGlassIndex;
   uint8_t mCocktailIndex;

   ~MainScene()
   {
      delete mMainLayout;
   }
};

#endif // MAIN_SCENE_HPP