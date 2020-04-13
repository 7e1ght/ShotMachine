#include "containers/EmptyContainer.hpp"

#include "support/Screen.hpp"

EmptyContainer::EmptyContainer(
    const supp::Point& point, 
    const supp::Size& size,
    const supp::Color& color, 
    IContainerBase* parent = nullptr
    )
: IContainerBase(point, size, color, parent)
{}

void EmptyContainer::drawAllInside() const noexcept
{
    if(mContainers.size() != 0)
    {
        mContainers.for_each(
            [&](BaseVector::value_type container)
            {
                if(nullptr != container)
                {
                    container->draw();
                }

                return true;
            }
        );
    }
}


void EmptyContainer::drawElement() noexcept
{
    Screen::getInstance().fillRect(
        {IContainerBase::getPosition().x, IContainerBase::getPosition().y},
        {IContainerBase::getPosition().x + IContainerBase::getSize().width, IContainerBase::getPosition().y + IContainerBase::getSize().height},
        IContainerBase::getMainColor()  
    );

    drawAllInside();
}

void EmptyContainer::handleTouch(const supp::Point& touchPoint) noexcept
{   

    if(mContainers.size() != 0)
    {
        mContainers.for_each(
            [&](BaseVector::value_type container)
            {
                bool noTouchable = true;

                if(nullptr != container)
                {
                    if(true == container->isInside(touchPoint))
                    {
                        container->handleTouch(touchPoint);
                        noTouchable = false;
                    }
                }
                
                return noTouchable;
            }
        );
    }
    
}


void EmptyContainer::clear() noexcept
{
    mContainers.clear();
}

void EmptyContainer::addContainer(IContainerBase* container, POSITION positionAlign) noexcept
{
    if(nullptr != container)
    {
        container->setParent(this);
        container->setPositionAlign(positionAlign);
        
        bool isExist = false;
        mContainers.for_each(
            [&isExist, container](const BaseVector::value_type vectorContainer)
            {
                if(vectorContainer == container)
                {
                    isExist = true;
                }

                return !isExist;
            }
        );

        if(!isExist)
        {
            mContainers.push_back(container);
        }
    }
}