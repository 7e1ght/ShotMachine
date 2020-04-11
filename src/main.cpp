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
#include "scenes/NewTemplate.hpp"
#include "support/Counter.hpp"


IScene* currentScene;
IScene::SCENE_ID currentSceneId;
IScene::SCENE_ID prevSceneId;

EmptyContainer* mainLayout;
TripleContainer* tc;
Counter* c;
TextContainer* textC;

ListContainer* lc;

void setup()
{   
  Serial.begin(9600);

  // currentScene = new NewTemplate();

  // currentScene->renderScene();
  lc = new ListContainer(8, {0, 20}, {240, 200}, supp::DEFAULT_BG_LIGHT_COLOR);
  lc->addItem(new TextContainer("+", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR));
  lc->draw();
}

void loop()
{
  supp::Point p = TouchScreen::getInstance().getTouch();
  dbg::printPoint(p);

  // mainLayout->handleTouch(p);
}

