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

void IContainerBase::addContainer(IContainerBase* container, POSITION positionAlign)
{
    if(nullptr != container)
    {
        switch (positionAlign)
        {
        case POSITION_TOP:
            container->setSize(
                    { getSize().width, container->getSize().height }
                );
            container->setPosition(
                    getPosition()
                );
            break;
        case POSITION_RIGHT:
            container->setSize(
                    { container->getSize().width, getSize().height }
                );
            container->setPosition(
                    { getPosition().x - container->getSize().width }
                );
            break;
        default:
            break;
        }
    }

    Rectangle tRect(
        container->getPosition(),
        {container->getPosition().x + container->getSize().width, container->getPosition().y + container->getSize().height}
    );

    mTouchMap.emplace(tRect, container);
}

IContainerBase::~IContainerBase() {}