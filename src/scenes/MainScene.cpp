#include "scenes/MainScene.hpp"

MainScene::MainScene()
: IScene(IScene::SCENE_ID::MAIN)
, mCocktailIndex( 0 )
, mIsCocktailEnable( true )
{
   initElements();
   addElements();

   changeCocktail(DIR_NONE);
}

void MainScene::fillRecipe() noexcept
{
   mCocktailContent->clear();

   mIsCocktailEnable = true;

   for(uint8_t i = 0; i < Barman::getInstance().getCocktailByIndex(mCocktailIndex).getRecipe().size(); ++i)
   {
      Liquid::Type bottle = Barman::getInstance().getCocktailByIndex(mCocktailIndex).getRecipe()[i].getValue();
      uint16_t value = Barman::getInstance().getCocktailByIndex(mCocktailIndex).getRecipe()[i].getKey();

      bool liquidEnough = Barman::getInstance().isLiquidEnough(bottle, value);

      mIsCocktailEnable = mIsCocktailEnable && liquidEnough;

      addItem(
         bottle, 
         value,
         !liquidEnough
         );
   }

   checkQueu();

   mCocktailName->draw();
   mCocktailContent->draw();
}

void MainScene::changeCocktail(DIRECTION d) noexcept  
{
   switch (d)
   {
   case DIR_LEFT:
      if(0 > mCocktailIndex-1)
      {
         mCocktailIndex = Barman::getInstance().getShotMap().size()-1;
      }
      else
      {
         mCocktailIndex--;
      }
      break;
   case DIR_RIGHT:
      if(Barman::getInstance().getShotMap().size()-1 < mCocktailIndex+1)
      {
         mCocktailIndex = 0;
      }
      else
      {
         mCocktailIndex++;
      }
      break;
   default:
      break;
   }

   Serial.println( String("Index: ") + mCocktailIndex );
   Serial.println( String("Name: ") + Barman::getInstance().getCocktailByIndex(mCocktailIndex).getName() );
   mCocktailName->setText(Barman::getInstance().getCocktailByIndex(mCocktailIndex).getName());
   fillRecipe();
}

void MainScene::addItem(const Liquid::Type liquid, const uint16_t value, const bool isRed) noexcept
{
   TripleContainer* item = new TripleContainer(supp::NO_POSITION, {mCocktailContent->getSize().width, 1}, mMainLayout->getMainColor());
   item->setMiddleWidth(0);

   supp::Color color = isRed ? supp::Color{255, 0, 0} : supp::DEFAULT_TEXT_COLOR;

   TextContainer* tempText = new TextContainer( Liquid::getName( liquid ), supp::NO_POSITION, color, mMainLayout->getMainColor());
   tempText->setFont(supp::FONT::SMALL);

   item->setLeft(tempText, IContainerBase::POSITION_LEFT);
   item->setRight( new TextContainer( String(value), supp::NO_POSITION, color, mMainLayout->getMainColor()), IContainerBase::POSITION_RIGHT);

   mCocktailContent->addItem(item);
}   

void MainScene::checkQueu() noexcept
{
   mToQueu->setAvailable(mIsCocktailEnable);
   mToQueu->draw();
}

void MainScene::initElements() noexcept
{
   auto leftCocktail = 
   [this]()
   {
      changeCocktail(DIR_LEFT);
   };

   auto rightCocktail = 
   [this]()
   {
      changeCocktail(DIR_RIGHT);
   };

   auto toQueu =
   [this]()
   {
      Barman::getInstance().addOrder(mCocktailIndex);

      fillRecipe();
   };

   mCocktailName = new TextContainer("", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR);

   mBar = new TripleContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
   mBar->setMiddleWidth(200);
   mBar->setLeft( new ButtonContainer("<", leftCocktail, supp::NO_POSITION, {mBar->getSize().height, 25}, mBar->getMainColor()) );
   mBar->setMiddle( mCocktailName );
   mBar->setRight( new ButtonContainer(">", rightCocktail, supp::NO_POSITION, {mBar->getSize().height, 25}, mBar->getMainColor()) );
   
   mContentLayout = new EmptyContainer({0, 25}, {220, cfg::display::SCREEN_HEIGHT-35}, mMainLayout->getMainColor() );

   mCocktailContent = new ListContainer(8, supp::NO_POSITION, {220, 190}, mMainLayout->getMainColor());

   mButtonLayout = new EmptyContainer(supp::NO_POSITION, {220, 60}, mMainLayout->getMainColor());
   mToQueu = new ButtonContainer("To queu", toQueu, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
   mCoock = new ButtonContainer("Coock", [](){ Barman::getInstance().executeOrder(); }, supp::NO_POSITION, {220, 25}, supp::DEFAULT_BG_DARK_COLOR);
}

void MainScene::addElements() noexcept
{
   mButtonLayout->addContainer(mToQueu, IContainerBase::POSITION_TOP);
   mButtonLayout->addContainer(mCoock, IContainerBase::POSITION_BOTTOM);

   mContentLayout->setPosition(supp::Point(10, 30));
   mContentLayout->addContainer(mButtonLayout, IContainerBase::POSITION_BOTTOM);
   mContentLayout->addContainer(mCocktailContent, IContainerBase::POSITION_TOP);

   mMainLayout->addContainer(mBar, IContainerBase::POSITION_TOP);
   mMainLayout->addContainer(mContentLayout, IContainerBase::POSITION_ABSOLUTE);
}