#ifndef MAIN_SCENE_HPP
#define MAIN_SCENE_HPP

#include "IScene.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"
#include "containers/ButtonContainer.hpp"

#include "bar/Bottle.hpp"

#include "bar/Barman.hpp"

class MainScene
: public IScene
{
public:
   MainScene();
private:
   bool mIsCocktailEnable;

   void checkQueu() noexcept;


   enum DIRECTION 
   { 
      DIR_NONE,
      DIR_LEFT, 
      DIR_RIGHT 
   };

   void initElements() noexcept;
   void addElements() noexcept;

   void addItem(const Liquid::Type liquid, const uint16_t value, const bool isRed = false) noexcept;

   void changeGlass(DIRECTION d) noexcept;
   void changeCocktail(DIRECTION d) noexcept;
   void fillRecipe() noexcept;

   TripleContainer* mBar;

   EmptyContainer* mContentLayout;

   ListContainer* mCocktailContent;

   EmptyContainer* mButtonLayout;

   ButtonContainer* mCreateTemplate;
   ButtonContainer* mToQueu;
   ButtonContainer* mCoock;

   TextContainer* mCocktailName;
   TextContainer* mGlassNumber;

   Barman::CocktailIdx mCocktailIndex;

   ~MainScene()
   {
      delete mMainLayout;
   }
};

#endif // MAIN_SCENE_HPP