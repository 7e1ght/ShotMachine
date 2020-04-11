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

IScene* currentScene;
IScene::SCENE_ID currentSceneId;
IScene::SCENE_ID prevSceneId;

inline bool isSceneChanged()
{
  return prevSceneId != currentSceneId;
}

void setup()
{   
  Serial.begin(9600);

  currentScene = new MainScene();
  currentSceneId = IScene::SCENE_ID::MAIN;
  prevSceneId = IScene::SCENE_ID::NO_SCENE;
}

void loop()
{
  supp::Point touchPoint = TouchScreen::getInstance().getTouch();
  dbg::printPoint(touchPoint);

}

