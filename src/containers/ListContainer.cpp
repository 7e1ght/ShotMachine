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

void ListContainer::baseDraw() noexcept
{
    for(uint8_t i = mLowerIndex; i < mHighIndex && i < mItemContainer.size(); ++i)
    {
        if(nullptr != mItemContainer[i])
        {
            mItemContainer[i]->draw();
        }
    }
}


void ListContainer::addItem(Item* newItem) noexcept
{
    newItem->setParent(this);
    newItem->setSize( { IContainerBase::getSize().width, mItemHeight} );

    newItem->setStartPosition( {0, mItemContainer.size() * mItemHeight} );

    mItemContainer.push_back(newItem);
    IContainerBase::addContainer(newItem, IContainerBase::POSITION_RELATIVE);
}

void ListContainer::addItem(IContainerBase* left, IContainerBase* middle, IContainerBase* right) noexcept
{
    Item* tItem = new Item( 
            {0, mItemContainer.size() * mItemHeight}, 
            {IContainerBase::getSize().width, mItemHeight},
            IContainerBase::getMainColor(),
            this
        );

    tItem->setLeft(left);    
    tItem->setMiddle(middle);    
    tItem->setRight(right);

    mItemContainer.push_back(tItem);    
    IContainerBase::addContainer(tItem, IContainerBase::POSITION_RELATIVE);
}

void ListContainer::moveRangeDown() noexcept
{
    if(mItemContainer.size() != mHighIndex)
    {
        ++mLowerIndex;
        ++mHighIndex;

        scrollDown();
    }
}

void ListContainer::moveRangeUp() noexcept
{
    if( 0 != mLowerIndex)
    {
        --mLowerIndex;
        --mHighIndex;

        scrollUp();
    }
}

void ListContainer::scrollUp() noexcept
{   
    for (int8_t i = mItemContainer.size()-1; 0 <= i; --i)
    {
        if(nullptr != mItemContainer[i])
        {
            mItemContainer[i]->setStartPosition( {0,  mItemContainer[i]->getStartPosition().y + mItemHeight} );
        }
    }
}

void ListContainer::scrollDown() noexcept
{
    for (uint8_t i = 0; i < mItemContainer.size(); ++i)
    {
        if(nullptr != mItemContainer[i])
        {
            mItemContainer[i]->setStartPosition( {0,  mItemContainer[i]->getStartPosition().y - mItemHeight} );
        }
    }
}
