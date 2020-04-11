#ifndef NEW_TEMPLATE_HPP
#define NEW_TEMPLATE_HPP

#include "IScene.hpp"
#include "support/support.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"
#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"

class NewTemplate
: public IScene
{
public:
    NewTemplate();
private: 
    TripleContainer* mUpperBar;
    EmptyContainer* mMaxGlassCapacityWrapper;
    TextContainer* mMaxGlassCapacity;
    ListContainer* mLiquidList;
    ButtonContainer* mViewButton;
    ButtonContainer* mOkButton;
    EmptyContainer* mButtonLayout;
    EmptyContainer* mButtonWrapper;

    EmptyContainer* mContentLayout;

    void initElements() noexcept;
    void addElements() noexcept;
};

inline void NewTemplate::initElements() noexcept
{
    mUpperBar = new TripleContainer(supp::NO_POSITION, {240, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
    mUpperBar->setMiddleWidth(200);
    mUpperBar->setMiddle( new TextContainer("New template", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()) );

    mMaxGlassCapacityWrapper = new EmptyContainer(supp::NO_POSITION, {0, supp::DEFAULT_ELEMENT_HEIGHT}, mMainLayout->getMainColor());
    mMaxGlassCapacity = new TextContainer( String("Glass capacity: ") + String(cfg::glass::CAPACITY) + String("ml"), supp::NO_POSITION, {255, 0, 0}, mMainLayout->getMainColor(), nullptr, supp::FONT::SMALL );

    mLiquidList = new ListContainer(8, supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, 200}, mMainLayout->getMainColor());
    mLiquidList->addItem(new TextContainer("+", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    mLiquidList->addItem(new TextContainer("+", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));

    mViewButton = new ButtonContainer("Old Templates", [](){ Serial.println("View"); }, supp::NO_POSITION, {80, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
    mOkButton = new ButtonContainer("OK", [](){ Serial.println("OK"); }, supp::NO_POSITION, {80, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);

    mButtonLayout = new EmptyContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, 70}, mMainLayout->getMainColor());

    mContentLayout = new EmptyContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, 295}, mMainLayout->getMainColor());

    mButtonWrapper = new EmptyContainer(supp::NO_POSITION, {220, 60}, mMainLayout->getMainColor());
}

inline void NewTemplate::addElements() noexcept
{
    mButtonWrapper->addContainer(mViewButton, IContainerBase::POSITION_TOP);
    mButtonWrapper->addContainer(mOkButton, IContainerBase::POSITION_BOTTOM);
    mButtonLayout->addContainer(mButtonWrapper, IContainerBase::POSITION_CENTER);

    mMaxGlassCapacityWrapper->addContainer(mMaxGlassCapacity, IContainerBase::POSITION_CENTER);
    mContentLayout->addContainer(mMaxGlassCapacityWrapper, IContainerBase::POSITION_TOP);
    mContentLayout->addContainer(mLiquidList, IContainerBase::POSITION_CENTER);
    mContentLayout->addContainer(mButtonLayout, IContainerBase::POSITION_BOTTOM);
    
    mMainLayout->addContainer(mUpperBar, IContainerBase::POSITION_TOP);
    mMainLayout->addContainer(mContentLayout, IContainerBase::POSITION_BOTTOM);
}

#endif // NEW_TEMPLATE_HPP