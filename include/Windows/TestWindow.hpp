#ifndef TEST_WINDOW_HPP
#define TEST_WINDOW_HPP

#include "containers/EmptyContainer.hpp"
#include "containers/TextContainer.hpp"

class TestWindow
{
private: 
    EmptyContainer* mAllScreen;

    EmptyContainer* mUpperBar;
    EmptyContainer* mLoweBar;

    TextContainer* mUpperText;
    TextContainer* mLowerText;
public:
    TestWindow()
    : mAllScreen( new EmptyContainer({0,0}, supp::FULLSCREEN, supp::DEFAULT_BG_LIGHT_COLOR) ),
    mUpperBar( new EmptyContainer(supp::NO_POSITION, {0, 25}, supp::DEFAULT_BG_DARK_COLOR) ),
    mLoweBar( new EmptyContainer(supp::NO_POSITION, {0, 25}, supp::DEFAULT_BG_DARK_COLOR) ),
    mUpperText( new TextContainer("Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR) ),
    mLowerText( new TextContainer("Vlad", supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, supp::DEFAULT_BG_DARK_COLOR) )
    {
        mUpperBar->addContainer(mUpperText, IContainerBase::POSITION_CENTER);
        mLoweBar->addContainer(mLowerText, IContainerBase::POSITION_CENTER);

        mAllScreen->addContainer(mUpperBar,IContainerBase::POSITION_TOP);
        mAllScreen->addContainer(mLoweBar,IContainerBase::POSITION_BOTTOM);
    }

    void drawAll()
    {
        mAllScreen->draw();
    }

    void handleTouch(const supp::Point& touchPoint)
    {
        mAllScreen->handleTouch(touchPoint);
    }
};

#endif // TEST_WINDOW_HPP