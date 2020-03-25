#include "containers/ListContainer.hpp"

ListContainer::ListContainer(const uint8_t drawItemCount, const supp::Point& position, 
                            const supp::Size& size, const supp::Color& color, 
                            IContainerBase* parent = nullptr)
: IContainerBase(position, size, color, parent)
, mDrawItemCount(drawItemCount)
, mMainContainer(position, size, color, parent)
, mDrawItems(drawItemCount)
, mItemHeight(size.height / mDrawItemCount)
{
    IContainerBase::addContainer(&mMainContainer, IContainerBase::POSITION_CENTER);
}

void ListContainer::changeInsidePositionSize(Item* item)
{
    supp::Point tPosition
    (
        mMainContainer.getPosition().x,
        mMainContainer.getPosition().y + (mItemBuffer.size() % mDrawItemCount) * mItemHeight
    );

    supp::Size tSize
    (
        mMainContainer.getSize().width,
        mItemHeight
    );

    item->setPosition(tPosition);
    item->setSize(tSize);
}

void ListContainer::addItem(IContainerBase* leftBlock, IContainerBase* middleBlock, IContainerBase* rightBlock)
{
    
}