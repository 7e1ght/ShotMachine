#include "containers/IContainerBase.hpp"

#include "support/debug.hpp"

void IContainerBase::draw()
{
    if(nullptr != mParent)
    {
        // mParent->addContainer(this, mPositionAlign);
        mParent->caclPositionSizeAlign(this, mPositionAlign);
    }

    baseDraw();
}

void IContainerBase::baseDraw() noexcept
{
    if(mContainers.size() != 0)
    {
        mContainers.for_each
        (
            [](BaseVector::value_type container)
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

void IContainerBase::setMainColor(const supp::Color& newColor) noexcept
{
    overlapThis();
    mMainColor = newColor;
}

void IContainerBase::setParent(IContainerBase* newParent) noexcept
{
    overlapThis();
    mParent = newParent;
}

void IContainerBase::setPosition(const supp::Point& newPosition) noexcept
{
    overlapThis();
    mPosition = newPosition;
}

void IContainerBase::setStartPosition(const supp::Point& newStartPosition) noexcept
{
    overlapThis();
    mStartPosition = newStartPosition;
} 

void IContainerBase::setSize(const supp::Size& newSize) noexcept
{
    overlapThis();
    mSize = newSize;
}

void IContainerBase::handleTouch(const supp::Point& touchPoint) const
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

void IContainerBase::setPositionAlign(const IContainerBase::POSITION newAlignPosition) noexcept
{
    overlapThis();
    mPositionAlign = newAlignPosition;
}

void IContainerBase::caclPositionSizeAlign(IContainerBase* container, POSITION positionAlign) noexcept
{
    if(nullptr != container)
    {
        container->mPositionAlign = positionAlign;

        switch (positionAlign)
        {
        case POSITION_TOP:
            container->mSize = supp::Size(
                mSize.width, 
                container->mSize.height
            );
            container->mPosition = mPosition;
            break;

        case POSITION_RIGHT:
            container->mSize= supp::Size(
                container->mSize.width, 
                mSize.height 
            );
            container->mPosition = supp::Point(
                mPosition.x + getSize().width - container->mSize.width, 
                mPosition.y
            );
            break;

        case POSITION_BOTTOM:
            container->mSize = supp::Size(
                mSize.width, 
                container->mSize.height
            );
            container->mPosition = supp::Point(
                mPosition.x, 
                mPosition.y + mSize.height - container->mSize.height
            );
            break;

        case POSITION_LEFT:
            container->mSize = supp::Size(
                container->mSize.width, 
                mSize.height 
            );
            container->mPosition = supp::Point(
                mPosition.x, 
                mPosition.y 
            );
            break;
        case POSITION_CENTER:
            container->mPosition = supp::Point(
                    (mPosition.x + mSize.width/2) - container->mSize.width/2, 
                    (mPosition.y + mSize.height/2) - container->mSize.height/2
            );
        case POSITION_ABSOLUTE:
            break;
        case POSITION_RELATIVE:
            container->mPosition = supp::Point(
                mPosition.x + container->mStartPosition.x, 
                mPosition.y + container->mStartPosition.y
            );
            break;
        default:
            break;
        }
    }
}

void IContainerBase::clear() noexcept
{
    mContainers.clear();
}

void IContainerBase::addContainer(IContainerBase* container, POSITION positionAlign) noexcept
{
    if(nullptr != container)
    {
        container->mParent = this;
        container->mPositionAlign = positionAlign;
        
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

IContainerBase::~IContainerBase() 
{
    overlapThis();
}