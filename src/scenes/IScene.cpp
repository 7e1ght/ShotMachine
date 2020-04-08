#include "scenes/IScene.hpp"

IScene::IScene()
{
    mainLayout = new EmptyContainer(supp::Point(0), supp::FULLSCREEN, supp::DEFAULT_BG_LIGHT_COLOR);
}