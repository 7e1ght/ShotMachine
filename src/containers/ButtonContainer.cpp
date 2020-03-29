#include "containers/ButtonContainer.hpp"
#include "support/support.hpp"

void ButtonContainer::handleTouch(const supp::Point&) const
{
    if(millis() - mTimer >= supp::DEFAULT_TAP_DELAY)
    {
        mTimer = millis();
        mInvoker->invoke();
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