#include "containers/TripleContainer.hpp"
#include "containers/EmptyContainer.hpp"

TripleContainer::TripleContainer(
            const supp::Point& point, 
            const supp::Size& size,
            const supp::Color& color, 
            IContainerBase* parent = nullptr
            )
: IContainerBase(point, size, color, parent)
, mLeftBlock( new EmptyContainer(supp::NO_POSITION, supp::Size(size.width/3, size.height), color) ) 
, mMiddleBlock( new EmptyContainer(supp::NO_POSITION, supp::Size(size.width/3, size.height), color) ) 
, mRightBlock( new EmptyContainer(supp::NO_POSITION, supp::Size(size.width/3, size.height), color) ) 
{
    IContainerBase::addContainer( mLeftBlock, IContainerBase::POSITION_LEFT );
    IContainerBase::addContainer( mMiddleBlock, IContainerBase::POSITION_CENTER );
    IContainerBase::addContainer( mRightBlock, IContainerBase::POSITION_RIGHT );
}

void TripleContainer::setLeft(IContainerBase* left) const noexcept
{
    if(nullptr != mLeftBlock)
    {
        mLeftBlock->clear();
        mLeftBlock->addContainer(left, IContainerBase::POSITION_CENTER);
    }
    else
    {
        Serial.println("TripleContainer::setLeft(): nullptr");
    }
    
}

void TripleContainer::setMiddle(IContainerBase* middle) const noexcept
{
    if(nullptr != mMiddleBlock)
    {
        mMiddleBlock->clear();
        mMiddleBlock->addContainer(middle, IContainerBase::POSITION_CENTER);
    }
    else
    {
        Serial.println("TripleContainer::setMiddle(): nullptr");
    }
    
}

void TripleContainer::setRight(IContainerBase* right) const noexcept
{
    if(nullptr != mRightBlock)
    {
        mRightBlock->clear();
        mRightBlock->addContainer(right, IContainerBase::POSITION_CENTER);
    }
    else
    {
        Serial.println("TripleContainer::setRight(): nullptr");
    }
}