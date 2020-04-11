#include <Arduino.h>

#include "config/config.hpp"
#include "support/Vector.hpp"

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"

#include "support/Screen.hpp"
#include "support/TouchScreen.hpp"

#include "support/debug.hpp"

#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"

#include "scenes/MainScene.hpp"
#include "support/Counter.hpp"


IScene* currentScene;
IScene::SCENE_ID currentSceneId;
IScene::SCENE_ID prevSceneId;

EmptyContainer* mainLayout;
TripleContainer* tc;
Counter* c;
TextContainer* textC;

void setup()
{   
  Serial.begin(9600);

  mainLayout = new EmptyContainer({0, 0}, supp::FULLSCREEN, {255, 0, 0});

  tc = new TripleContainer({0, 50}, {240, 25}, supp::DEFAULT_BG_LIGHT_COLOR);
  tc->setLeft( new TextContainer("Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mainLayout->getMainColor()) );
  c = new Counter(10, {0, 100}, {80, 25}, tc->getMainColor());
  tc->setRight(c);

  mainLayout->addContainer(tc, IContainerBase::POSITION_CENTER);

  mainLayout->draw();
}

void loop()
{
  supp::Point p = TouchScreen::getInstance().getTouch();
  dbg::printPoint(p);

  mainLayout->handleTouch(p);
}

