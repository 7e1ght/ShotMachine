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
    for(uint8_t i = mLowerIndex; i < mHighIndex && i < mContainers.size(); ++i)
    {
        if(nullptr != mContainers[i])
        {
            mContainers[i]->draw();
        }
    }
}


void ListContainer::addItem(Item* newItem) noexcept
{
    newItem->setParent(this);
    newItem->setSize( { IContainerBase::getSize().width, mItemHeight} );
    newItem->setMainColor( IContainerBase::getMainColor() );

    newItem->setStartPosition( {0, mContainers.size() * mItemHeight} );

    IContainerBase::addContainer(newItem, IContainerBase::POSITION_RELATIVE);
}

void ListContainer::addItem(IContainerBase* left, IContainerBase* middle, IContainerBase* right) noexcept
{
    Item* tItem = new Item( 
            supp::NO_POSITION, 
            { IContainerBase::getSize().width, mItemHeight},
            IContainerBase::getMainColor(),
            this
        );
    
    addItem(tItem);

    tItem->setLeft(left);    
    tItem->setMiddle(middle);    
    tItem->setRight(right);
}

void ListContainer::moveRangeDown() noexcept
{
    if(mContainers.size() > mHighIndex)
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
    for (int8_t i = mContainers.size()-1; 0 <= i; --i)
    {
        if(nullptr != mContainers[i])
        {
            mContainers[i]->setStartPosition( {0,  mContainers[i]->getStartPosition().y + mItemHeight} );
        }
    }
}

void ListContainer::scrollDown() noexcept
{
    for (uint8_t i = 0; i < mContainers.size(); ++i)
    {
        if(nullptr != mContainers[i])
        {
            mContainers[i]->setStartPosition( {0,  mContainers[i]->getStartPosition().y - mItemHeight} );
        }
    }
}

ListContainer::~ListContainer()
{

}