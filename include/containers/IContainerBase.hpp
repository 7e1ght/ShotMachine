#ifndef I_CONTAINER_BASE_H
#define I_CONTAINER_BASE_H

#include "support/support.hpp"
#include "support/ListedMap.hpp"
#include "support/Vector.hpp"

#include "support/debug.hpp"

class IContainerBase
{
private:
    IContainerBase* mParent;

public:

    IContainerBase(const supp::Point& position, const supp::Size& size, const supp::Color& color, IContainerBase* parent = nullptr);

    virtual ~IContainerBase();

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

    POSITION getPositionAlign() const noexcept { return mPositionAlign; }
    void setPositionAlign(const POSITION newPositionAlign) noexcept;

    const supp::Point getStartPosition() const { return mStartPosition; }
    virtual void setStartPosition(const supp::Point& newStartPosition) noexcept;

    const supp::Size& getSize() const { return mSize; } 
    virtual void setSize(const supp::Size& newSize) noexcept;

    const supp::Point& getPosition() const { return mPosition; }
    virtual void setPosition(const supp::Point& newPosition) noexcept;

    const supp::Color& getMainColor() const { return mMainColor; }
    virtual void setMainColor(const supp::Color& newColor) noexcept;

    IContainerBase* getParent() const noexcept { return mParent; }
    virtual void setParent(IContainerBase* newParent) noexcept;


    bool isInside(const supp::Point& point) const noexcept
    {
        return ( mPosition <= point && point <= mPosition + mSize );  
    }


    void draw() noexcept;

    void caclPositionSizeAlign() noexcept;

    virtual void handleTouch(const supp::Point& touchPoint) noexcept {}
protected:
    void overlapThis() const noexcept
    {
        supp::overlap(
            mPosition,
            mSize,
            nullptr == mParent ? supp::Color{0, 0, 0} : mParent->mMainColor
        );
    }

private:
    virtual void drawElement() noexcept = 0;
    
    POSITION mPositionAlign;
    supp::Point mRelativePosition;
    supp::Point mPosition;
    supp::Point mStartPosition;
    supp::Size mSize;
    supp::Color mMainColor;
};

#endif // I_CONTAINER_BASE_H