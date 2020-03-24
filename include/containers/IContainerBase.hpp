#ifndef I_CONTAINER_BASE_H
#define I_CONTAINER_BASE_H

#include "support/support.hpp"
#include "support/ListedMap.hpp"
#include "support/Vector.hpp"

#include "support/debug.hpp"

class IContainerBase
{
protected:
    virtual void baseDraw() const noexcept = 0;
    
private:
    using BaseVector = supp::Vector<IContainerBase*>;

    IContainerBase* mParent;
public:
    enum POSITION
    {
        POSITION_TOP, 
        POSITION_RIGHT,
        POSITION_BOTTOM,
        POSITION_LEFT,
        POSITION_CENTER,
        POSITION_RELATIVE,
        POSITION_ABSOLUTE
    };

    IContainerBase(const supp::Point& position, const supp::Size& size, const supp::Color& color, IContainerBase* parent)
    : mPosition(position)
    , mSize(size)
    , mMainColor(color)
    , mParent(parent)
    , mPositionAlign(POSITION_ABSOLUTE)
    {}

    void addContainer(IContainerBase* container, POSITION alingType = POSITION_RELATIVE);

    void IContainerBase::caclPositionSizeAlign(IContainerBase* container, POSITION positionAlign) noexcept;
    void IContainerBase::caclPositionSizeAlign(IContainerBase* container) noexcept;

    virtual ~IContainerBase() = 0;

    const supp::Size& getSize() const { return mSize; } 
    virtual void setSize(const supp::Size& newSize) noexcept;

    const supp::Point& getPosition() const { return mPosition; }
    virtual void setPosition(const supp::Point& newPosition) noexcept;

    const supp::Color& getMainColor() const { return mMainColor; }
    virtual void setMainColor(const supp::Color& newColor) noexcept;

    IContainerBase* getParent() const noexcept { return mParent; }
    void setParent(IContainerBase* newParent) noexcept;

    POSITION getPositionAlign() const noexcept { return mPositionAlign; }

    bool isInside(const supp::Point& point) const noexcept
    {
        return ( mPosition <= point && point <= mPosition + mSize );  
    }

    void setPositionAlign(const POSITION newPositionAlign) noexcept;

    void clear() const noexcept
    {
        mContainers.clear();

        draw();
    }

    void draw() const;
    virtual void handleTouch(const supp::Point& touchPoint) const;
private:
    void overlapThis() const noexcept 
    {
        supp::overlap(
            mPosition,
            mSize,
            nullptr == mParent ? supp::Color{0, 0, 0} : mParent->mMainColor
        );
    }

    supp::Point mRelativePosition;
    supp::Point mPosition;
    supp::Size mSize;
    supp::Color mMainColor;
    POSITION mPositionAlign;
    BaseVector mContainers; 
};

#endif // I_CONTAINER_BASE_H