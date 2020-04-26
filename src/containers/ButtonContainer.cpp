#include "containers/ButtonContainer.hpp"
#include "support/support.hpp"

void ButtonContainer::handleTouch(const supp::Point&) const
{
    if(millis() - mTimer >= supp::DEFAULT_TAP_DELAY && mIsAvailable)
    {
        mTimer = millis();
        mInvoker->invoke();
    }
}

void ButtonContainer::setAvailable(bool available) noexcept
{
    if(available != mIsAvailable)
    {
        mIsAvailable = available;

        mText.setMainColor(true == mIsAvailable ? supp::DEFAULT_TEXT_COLOR : supp::Color{255, 0, 0});
        mText.draw();
    }
}

void ButtonContainer::baseDraw() noexcept
{
    Screen::getInstance().fillRoundRect(supp::Point(IContainerBase::getPosition().x, IContainerBase::getPosition().y), 
                                        supp::Point(IContainerBase::getPosition().x + IContainerBase::getSize().width , IContainerBase::getPosition().y + IContainerBase::getSize().height), 
                                        IContainerBase::getMainColor()
                                        );
    IContainerBase::addContainer(&mText, IContainerBase::POSITION_CENTER);
    IContainerBase::baseDraw();
}