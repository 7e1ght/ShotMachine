#include "scenes/MainScene.hpp"

MainScene::SCENE_ID MainScene::doLoop(supp::Point touchPoint)
{
    SCENE_ID returnSceneId = SCENE_ID::MAIN;

    return returnSceneId;
}

MainScene::MainScene()
{
    initElements();
    addElements();
}