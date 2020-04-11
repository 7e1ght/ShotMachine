#include "scenes/NewTemplate.hpp"

NewTemplate::NewTemplate()
: IScene(IScene::SCENE_ID::NEW_TEMPLATE)
{
    initElements();
    addElements();
}

NewTemplate::~NewTemplate()
{
    delete mUpperBar;
    delete mMaxGlassCapacityWrapper;
    delete mMaxGlassCapacity;
    delete mLiquidList;
    delete mViewButton;
    delete mOkButton;
    delete mButtonLayout;
    delete mButtonWrapper;
    delete mButtonAndListWrapper;
    delete mContentLayout;
}