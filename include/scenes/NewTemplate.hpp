#ifndef NEW_TEMPLATE_HPP
#define NEW_TEMPLATE_HPP

#include "IScene.hpp"
#include "support/support.hpp"
#include "containers/TextContainer.hpp"
#include "containers/ButtonContainer.hpp"
#include "containers/TripleContainer.hpp"
#include "containers/ListContainer.hpp"
#include "support/Counter.hpp"

class NewTemplate
: public IScene
{
public:
    NewTemplate();
    ~NewTemplate();
private: 
    TripleContainer* mUpperBar;
    EmptyContainer* mMaxGlassCapacityWrapper;
    TextContainer* mMaxGlassCapacity;
    ListContainer* mLiquidList;
    ButtonContainer* mViewButton;
    ButtonContainer* mOkButton;
    EmptyContainer* mButtonLayout;
    EmptyContainer* mButtonWrapper;

    EmptyContainer* mButtonAndListWrapper;

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
    
    ListContainer::Item* item1 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item1->setMiddleWidth(15);
    item1->setLeft(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    item1->setRight(new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor()));
    mLiquidList->addItem(item1);

    ListContainer::Item* item2 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item2->setMiddleWidth(15);
    item2->setLeft(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    item2->setRight(new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor()));
    mLiquidList->addItem(item2);

    ListContainer::Item* item3 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item3->setMiddleWidth(15);
    item3->setLeft(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    item3->setRight(new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor()));
    mLiquidList->addItem(item3);

    ListContainer::Item* item4 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item4->setMiddleWidth(15);
    item4->setLeft(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    item4->setRight(new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor()));
    mLiquidList->addItem(item4);

    ListContainer::Item* item5 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item5->setMiddleWidth(15);
    item5->setLeft(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    item5->setRight(new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor()));
    mLiquidList->addItem(item5);

    ListContainer::Item* item6 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item6->setMiddleWidth(15);
    item6->setLeft(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    item6->setRight(new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor()));
    mLiquidList->addItem(item6);

    ListContainer::Item* item7 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item7->setMiddleWidth(15);
    item7->setLeft(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    item7->setRight(new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor()));
    mLiquidList->addItem(item7);

    ListContainer::Item* item8 = new ListContainer::Item(supp::NO_POSITION, {mLiquidList->getSize().width, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    item8->setMiddleWidth(15);
    TextContainer* tc = new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor());
    // item8->setLeft(tc);
    // // Counter* c = new Counter(10, supp::NO_POSITION, {90, mLiquidList->getItemHeight()}, mLiquidList->getMainColor());
    // // item8->setRight(new TextContainer("Water", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, mUpperBar->getMainColor()));
    // mLiquidList->addItem(item8);


    mViewButton = new ButtonContainer("Old Templates", [](){ Serial.println("View"); }, supp::NO_POSITION, {80, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);
    mOkButton = new ButtonContainer("OK", [](){ Serial.println("OK"); }, supp::NO_POSITION, {80, supp::DEFAULT_ELEMENT_HEIGHT}, supp::DEFAULT_BG_DARK_COLOR);

    mButtonLayout = new EmptyContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, 70}, mMainLayout->getMainColor());

    mContentLayout = new EmptyContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, 295}, mMainLayout->getMainColor());

    mButtonWrapper = new EmptyContainer(supp::NO_POSITION, {220, 60}, mMainLayout->getMainColor());

    mButtonAndListWrapper = new EmptyContainer(supp::NO_POSITION, {cfg::display::SCREEN_WIDTH, 270}, mMainLayout->getMainColor());
}

inline void NewTemplate::addElements() noexcept
{
    mButtonWrapper->addContainer(mViewButton, IContainerBase::POSITION_TOP);
    mButtonWrapper->addContainer(mOkButton, IContainerBase::POSITION_BOTTOM);
    mButtonLayout->addContainer(mButtonWrapper, IContainerBase::POSITION_CENTER);

    mButtonAndListWrapper->addContainer(mButtonLayout, IContainerBase::POSITION_BOTTOM);
    mButtonAndListWrapper->addContainer(mLiquidList, IContainerBase::POSITION_TOP);

    mMaxGlassCapacityWrapper->addContainer(mMaxGlassCapacity, IContainerBase::POSITION_CENTER);

    mContentLayout->addContainer(mMaxGlassCapacityWrapper, IContainerBase::POSITION_TOP);
    mContentLayout->addContainer(mButtonAndListWrapper, IContainerBase::POSITION_BOTTOM);
    
    mMainLayout->addContainer(mUpperBar, IContainerBase::POSITION_TOP);
    mMainLayout->addContainer(mContentLayout, IContainerBase::POSITION_BOTTOM);
}

#endif // NEW_TEMPLATE_HPP