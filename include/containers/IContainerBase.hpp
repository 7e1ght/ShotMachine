#ifndef I_CONTAINER_BASE_H
#define I_CONTAINER_BASE_H

#include "support/support.hpp"
#include "support/ListedMap.hpp"

#include "support/debug.hpp"

class IContainerBase
{
private:
    class Rectangle
    {
    private:
        const supp::Point upperLeft;
        const supp::Point lowerRight;
    public: 
        Rectangle(const supp::Point& p1, 
                  const supp::Point& p2) 
            : upperLeft(p1)
            , lowerRight(p2)
        {}

        bool isInside(const supp::Point& point)
        {
            return ( upperLeft >= point && point >= lowerRight );
        }
    };

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
    , mTouchMap()
    , mMainColor(color)
    , mParent(parent)
    , mPositionAlign(POSITION_ABSOLUTE)
    {}

    void addContainer(IContainerBase* container, POSITION alingType = POSITION_RELATIVE);

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

    void setPositionAlign(const POSITION newPositionAlign) noexcept;

    virtual void draw() const;
    virtual void redraw() noexcept;
    virtual void handleTouch(const supp::Point& touchPoint) const;
private:
    supp::Point mPosition;
    supp::Size mSize;
    supp::Color mMainColor;
    POSITION mPositionAlign;
    supp::ListedMap<Rectangle, const IContainerBase*> mTouchMap;
};

#endif // I_CONTAINER_BASE_H