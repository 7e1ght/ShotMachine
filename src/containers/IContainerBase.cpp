#include "containers/IContainerBase.hpp"

#include "support/debug.hpp"

IContainerBase::IContainerBase(const supp::Point& position, const supp::Size& size, const supp::Color& color, IContainerBase* parent = nullptr)
: mPosition(position)
, mStartPosition(position)
, mSize(size)
, mMainColor(color)
, mParent(parent)
, mPositionAlign(POSITION_ABSOLUTE)
{}

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

void IContainerBase::setPositionAlign(const IContainerBase::POSITION newAlignPosition) noexcept
{
    overlapThis();
    mPositionAlign = newAlignPosition;
}

void IContainerBase::draw() noexcept
{
    caclPositionSizeAlign();

    drawElement();
}

void IContainerBase::caclPositionSizeAlign() noexcept
{
    if(nullptr != mParent)
    {
        switch (mPositionAlign)
        {
        case POSITION_TOP:
            mSize = 
                supp::Size(
                    mParent->mSize.width, 
                    mSize.height
                );

            mPosition = mParent->mPosition;
            break;

        case POSITION_RIGHT:
            mSize = 
                supp::Size(
                    mSize.width, 
                    mParent->mSize.height
                );
            mPosition = 
                supp::Point(
                    mParent->mPosition.x + mParent->mSize.width - mSize.width, 
                    mPosition.y
                );
            break;

        case POSITION_BOTTOM:
            mSize = 
                supp::Size(
                    mParent->mSize.width, 
                    mSize.height
                );
            mPosition = 
                supp::Point(
                    mParent->getPosition().x, 
                    mParent->getPosition().y + mParent->getSize().height - mSize.height
                );
            break;

        case POSITION_LEFT:
            mSize = 
                supp::Size(
                    mSize.width, 
                    mParent->mSize.height 
                );
            mPosition = mParent->mPosition;
            break;
        case POSITION_CENTER:
            mPosition = 
                supp::Point(
                    (mParent->mPosition.x + mParent->mSize.width/2) - mSize.width/2, 
                    (mParent->mPosition.y + mParent->mSize.height/2) - mSize.height/2
                );
        case POSITION_ABSOLUTE:
            break;
        case POSITION_RELATIVE:
            mPosition = 
                supp::Point(
                    mParent->mPosition.x + mStartPosition.x, 
                    mParent->mPosition.y + mStartPosition.y
                );
            break;
        default:
            Serial.print("IContainerBase: no such position align.");
        }
    }
}

IContainerBase::~IContainerBase() {}