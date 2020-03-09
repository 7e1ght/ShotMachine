#ifndef I_CONTAINER_BASE_H
#define I_CONTAINER_BASE_H

#include "support/support.hpp"
#include "support/ListedMap.hpp"

#include "support/debug.hpp"

class IContainerBase
{
public:
    IContainerBase(const supp::Point& position, const supp::Size& size)
    : mPosition(position)
    , mSize(size)
    , mTouchMap()
    {}

    void addContainer(const IContainerBase* container)
    {
        mTouchMap.emplace(container->getPosition(), container);
    }

    virtual ~IContainerBase() = 0;

    supp::Size getSize() const { return mSize; } 
    void setSize(supp::Size newSize) { mSize = newSize; }

    supp::Point getPosition() const { return mPosition; }
    void setPosition(supp::Point newPosition) { mPosition = newPosition; }

    virtual void draw() const;
    virtual void handleTouch(const supp::Point& touchPoint) const;
private:
    supp::Point mPosition;
    supp::Size mSize;
    supp::ListedMap<supp::Point, const IContainerBase*> mTouchMap;
};

#endif // I_CONTAINER_BASE_H