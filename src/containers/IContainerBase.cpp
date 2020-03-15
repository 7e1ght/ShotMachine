#include "containers/IContainerBase.hpp"

#include "support/debug.hpp"

void IContainerBase::draw() const
{
    auto drawForAll = 
        [](const supp::Pair<Rectangle, const IContainerBase*>&  pair)
        {
            pair.getValue()->draw();
        };

    mTouchMap.for_each(drawForAll);
}

void IContainerBase::redraw() noexcept
{
    mParent->addContainer(this, mPositionAlign);

    supp::overlap(
            mPosition, 
            mSize, 
            nullptr == mParent ? supp::Color{0, 0, 0} : mParent->mMainColor
        );

    draw();
}

void IContainerBase::setMainColor(const supp::Color& newColor) noexcept
{
    mMainColor = newColor;
    redraw();
}

void IContainerBase::setParent(IContainerBase* newParent) noexcept
{
    mParent = newParent;
    redraw();
}

void IContainerBase::setPosition(const supp::Point& newPosition) noexcept
{
    mPosition = newPosition;
    redraw();
}

void IContainerBase::setSize(const supp::Size& newSize) noexcept
{
    mSize = newSize;
    redraw();
}

void IContainerBase::handleTouch(const supp::Point& touchPoint) const
{
    auto handleTouchOnce = 
        [=](const supp::Pair<Rectangle, const IContainerBase*>&  pair)
        {
            if(true == pair.getKey().isInside(touchPoint))
            {
                pair.getValue()->handleTouch(touchPoint);
                pair.getKey();
            }
        };

    mTouchMap.for_each(handleTouchOnce);
}

void IContainerBase::setPositionAlign(const IContainerBase::POSITION newAlignPosition) noexcept
{
    mPositionAlign = newAlignPosition;
    redraw();
}

void IContainerBase::addContainer(IContainerBase* container, POSITION positionAlign)
{
    if(nullptr != container)
    {
        container->mParent = this;
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
                mPosition.x + container->mPosition.x, 
                mPosition.y + container->mPosition.y
            );
            break;
        default:
            Serial.print("IContainerBase: no such position.");
        }

        Rectangle tRect(
            container->mPosition,
            {container->mPosition.x + container->mSize.width, container->mPosition.y + container->mSize.height}
        );

        bool isExist = false;
        mTouchMap.for_each(
            [&](const supp::Pair<Rectangle, const IContainerBase*>&  pair)
            {
                isExist = isExist || (pair.getValue() == container);
            }
        );

        if(!isExist)
        {
            mTouchMap.emplace(tRect, container);
        }
    }

}

IContainerBase::~IContainerBase() {}