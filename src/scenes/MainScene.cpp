#include "scenes/MainScene.hpp"

#include "bar/Barman.hpp"

MainScene::MainScene()
: IScene(IScene::SCENE_ID::MAIN)
, mGlassIndex( 0 )
, mCocktailIndex( 0 )
{
   initElements();
   addElements();

   changeCocktail(DIR_NONE);
}

void MainScene::fillRecipe() noexcept
{
   cocktailContent->clear();

   bool isAvailableCocktail = true;

   // for(uint8_t i = 0; i < Barman::shotMap[mCocktailIndex].getRecipe().size(); ++i)
   // {
   //    const Bottle* bottle = Barman::shotMap[mCocktailIndex].getRecipe()[i].getValue();
   //    uint16_t value = Barman::shotMap[mCocktailIndex].getRecipe()[i].getKey();

   //    isAvailableCocktail = isAvailableCocktail && ( bottle->getCapacity() >= value );

   //    addItem(
   //       bottle, 
   //       value
   //       );
   // }

   toQueu->setAvailable( isAvailableCocktail );
}
void MainScene::changeCocktail(DIRECTION d) noexcept
{
   // switch (d)
   // {
   // case DIR_LEFT:
   //    if(0 > mCocktailIndex-1)
   //    {
   //       mCocktailIndex = Barman::shotMap.size()-1;
   //    }
   //    else
   //    {
   //       mCocktailIndex--;
   //    }
   //    break;
   // case DIR_RIGHT:
   //    if(Barman::shotMap.size()-1 < mCocktailIndex+1)
   //    {
   //       mCocktailIndex = 0;
   //    }
   //    else
   //    {
   //       mCocktailIndex++;
   //    }
   //    break;
   // default:
   //    break;
   // }

   // Serial.println( String("Index: ") + mCocktailIndex );
   // Serial.println( String("Name: ") + Barman::shotMap[mCocktailIndex].getName() );
   // mCocktailName->setText(Barman::shotMap[mCocktailIndex].getName());
   // fillRecipe();
}

void MainScene::addItem(const Bottle* leftSide, const uint16_t rightSide) noexcept
{
   TripleContainer* item = new TripleContainer(supp::NO_POSITION, {cocktailContent->getSize().width, 1}, mMainLayout->getMainColor());
   item->setMiddleWidth(1);
   item->setLeft( new TextContainer( Liquid::getName( leftSide->getLiquid() ), supp::NO_POSITION, rightSide > leftSide->getCapacity() ? supp::Color{255, 0, 0} : supp::DEFAULT_TEXT_COLOR, mMainLayout->getMainColor()), IContainerBase::POSITION_LEFT);
   item->setRight( new TextContainer( String(rightSide), supp::NO_POSITION, rightSide > leftSide->getCapacity() ? supp::Color{255, 0, 0} : supp::DEFAULT_TEXT_COLOR, mMainLayout->getMainColor()), IContainerBase::POSITION_RIGHT);

   cocktailContent->addItem(item);
}   

void MainScene::initElements() noexcept
{
   auto leftGlass = 
   []()
   {
      Serial.println("Glass left");
   };

   auto rightGlass = 
   []()
   {
      Serial.println("Glass right");
   };

   auto leftCocktail = 
   [this]()
   {
      changeCocktail(DIR_LEFT);
      mCocktailName->draw();
      cocktailContent->draw();
   };

   auto rightCocktail = 
   [this]()
   {
      changeCocktail(DIR_RIGHT);
      mCocktailName->draw();
      cocktailContent->draw();
   };

   mCocktailName = new TextContainer("", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, lowerBar->getMainColor());
   mGlassNumber = new TextContainer("GlassNumber", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, upperBar->getMainColor());

   upperBar = new TripleContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
   upperBar->setMiddleWidth(185);
   upperBar->setLeft( new ButtonContainer("<", leftGlass, supp::NO_POSITION, {upperBar->getSize().height, 25}, upperBar->getMainColor()) );
   upperBar->setMiddle( mGlassNumber );
   upperBar->setRight( new ButtonContainer(">", rightGlass, supp::NO_POSITION, {upperBar->getSize().height, 25}, upperBar->getMainColor()) );

   lowerBar = new TripleContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
   lowerBar->setMiddleWidth(185);
   lowerBar->setLeft( new ButtonContainer("<", leftCocktail, supp::NO_POSITION, {lowerBar->getSize().height, 25}, lowerBar->getMainColor()) );
   lowerBar->setMiddle( mCocktailName );
   lowerBar->setRight( new ButtonContainer(">", rightCocktail, supp::NO_POSITION, {lowerBar->getSize().height, 25}, lowerBar->getMainColor()) );

   contentLayout = new EmptyContainer({0, 25}, {220, cfg::display::SCREEN_HEIGHT-70}, mMainLayout->getMainColor() );

   cocktailContent = new ListContainer(8, supp::NO_POSITION, {220, 190}, mMainLayout->getMainColor());

   buttonLayout = new EmptyContainer(supp::NO_POSITION, {220, 60}, mMainLayout->getMainColor());
   toQueu = new ButtonContainer("To queu", [](){ Serial.println("To queu"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
   coock = new ButtonContainer("Coock", [](){ Serial.println("Coock"); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
}

void MainScene::addElements() noexcept
{
   buttonLayout->addContainer(toQueu, IContainerBase::POSITION_TOP);
   buttonLayout->addContainer(coock, IContainerBase::POSITION_BOTTOM);

   contentLayout->addContainer(buttonLayout, IContainerBase::POSITION_BOTTOM);
   contentLayout->addContainer(cocktailContent, IContainerBase::POSITION_TOP);

   mMainLayout->addContainer(upperBar, IContainerBase::POSITION_TOP);
   mMainLayout->addContainer(contentLayout, IContainerBase::POSITION_CENTER);
   mMainLayout->addContainer(lowerBar, IContainerBase::POSITION_BOTTOM);
}