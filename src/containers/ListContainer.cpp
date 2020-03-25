#include "containers/ListContainer.hpp"
#include "support/debug.hpp"

ListContainer::ListContainer(const uint8_t drawItemCount, 
                            const supp::Point& position, 
                            const supp::Size& size, 
                            const supp::Color& color, 
                            IContainerBase* parent)
: IContainerBase(position, size, color, parent)
, mDrawItemCount(drawItemCount)
, mItemHeight(size.height / mDrawItemCount)
, mLowerIndex(0)
, mHighIndex(mDrawItemCount)
{
}

TripleContainer* ListContainer::generateItem() noexcept
{
    supp::Point tPosition
    (
        IContainerBase::getPosition().x,
        IContainerBase::getPosition().y + (mItemBuffer.size() % mDrawItemCount) * mItemHeight
    );

    supp::Size tSize
    (
        IContainerBase::getSize().width,
        mItemHeight
    );
    
    // dbg::printPoint(tPosition);
    // dbg::printSize(tSize);
    Item* tItem = new Item(tPosition, tSize, IContainerBase::getMainColor(), this); 
    return tItem;
}

void ListContainer::baseDraw() const noexcept
{
    for(uint8_t i = mLowerIndex; i < mHighIndex; ++i)
    {
        if(nullptr != mItemBuffer[i])
        {
            mItemBuffer[i]->draw();
        }
    }
}

void ListContainer::moveRangeDown() noexcept
{
    if(mItemBuffer.size() != mHighIndex)
    {
        ++mLowerIndex;
        ++mHighIndex;
    }
}

void ListContainer::moveRangeUp() noexcept
{
    if(0 != mLowerIndex)
    {
        --mLowerIndex;
        --mHighIndex;
    }
}


void ListContainer::addItem(IContainerBase* leftBlock, IContainerBase* middleBlock, IContainerBase* rightBlock)
{
    Item* tItem = generateItem();
    Serial.println((int)tItem);

    tItem->setLeft(leftBlock);
    tItem->setMiddle(middleBlock);
    tItem->setRight(rightBlock);

    mItemBuffer.push_back(tItem);
    Serial.println((int)mItemBuffer[0]);
    delay(5000);
}