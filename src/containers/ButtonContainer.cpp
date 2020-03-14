#include "containers/ButtonContainer.hpp"
#include "support/support.hpp"

void ButtonContainer::draw() const
{
    Screen::getInstance().fillRoundRect(supp::Point(IContainerBase::getPosition().x, IContainerBase::getPosition().y), 
                                        supp::Point(IContainerBase::getPosition().x + IContainerBase::getSize().width , IContainerBase::getPosition().y + IContainerBase::getSize().height), 
                                        IContainerBase::getMainColor()
                                        );
    IContainerBase::draw();
}