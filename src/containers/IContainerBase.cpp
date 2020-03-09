#include "containers/IContainerBase.hpp"

#include "support/debug.hpp"

void IContainerBase::draw() const
{
    auto drawForAll = 
        [](const supp::Pair<supp::Point, const IContainerBase*>&  pair)
        {
            pair.getValue()->draw();
        };

    mTouchMap.for_each(drawForAll);
}

void IContainerBase::handleTouch(const supp::Point& touchPoint) const
{
    dbg::printPoint(touchPoint);
    if(nullptr != mTouchMap.getPair(touchPoint))
    {
        mTouchMap.getPair(touchPoint)->getValue()->handleTouch(touchPoint);
    }
}

IContainerBase::~IContainerBase() {}