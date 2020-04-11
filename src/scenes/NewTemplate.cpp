#include "scenes/NewTemplate.hpp"

NewTemplate::NewTemplate()
: IScene(IScene::SCENE_ID::NEW_TEMPLATE)
{
    initElements();
    addElements();
}