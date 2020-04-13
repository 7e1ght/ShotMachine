// #include "scenes/IScene.hpp"

// IScene::IScene(IScene::SCENE_ID defaultSceneId)
// : mReturnSceneId(defaultSceneId)
// {
//     mMainLayout = new EmptyContainer(supp::Point(0), supp::FULLSCREEN, supp::DEFAULT_BG_LIGHT_COLOR);
// }

// IScene::SCENE_ID IScene::doLoop(supp::Point touchPoint)
// {
//     handleTouch(touchPoint);

//     specificStep();

//     return mReturnSceneId;
// }