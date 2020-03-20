#include "containers/EmptyContainer.hpp"

#include "support/Screen.hpp"

void EmptyContainer::baseDraw() const noexcept
{
    Screen::getInstance().fillRect(
        {IContainerBase::getPosition().x, IContainerBase::getPosition().y},
        {IContainerBase::getPosition().x + IContainerBase::getSize().width, IContainerBase::getPosition().y + IContainerBase::getSize().height},
        IContainerBase::getMainColor()  
    );
    
    IContainerBase::baseDraw();
}