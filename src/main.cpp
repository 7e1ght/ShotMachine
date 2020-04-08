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

IScene::SCENE_ID prevSceneID;
IScene::SCENE_ID sceneID;

void setup()
{
    Serial.begin(9600);

    currentScene = new MainScene();

    sceneID = IScene::SCENE_ID::MAIN;
    prevSceneID = IScene::SCENE_ID::NO_SCENE;
}

void loop()
{
    supp::Point p = TouchScreen::getInstance().getTouch();
    dbg::printPoint(p);

    sceneID = currentScene->doLoop(p);

    if(sceneID != prevSceneID)
    {
        prevSceneID = sceneID;
        currentScene->renderScene();
    }
}