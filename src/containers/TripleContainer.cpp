#include "containers/TripleContainer.hpp"
#include "containers/EmptyContainer.hpp"

TripleContainer::TripleContainer(
            const supp::Point& point, 
            const supp::Size& size,
            const supp::Color& color, 
            IContainerBase* parent = nullptr
            )
: IContainerBase(point, size, color, parent)
, mLeftBlock( new EmptyContainer(supp::NO_POSITION, supp::NO_SIZE, color) ) 
, mMiddleBlock( new EmptyContainer(supp::NO_POSITION, supp::NO_SIZE, color) ) 
, mRightBlock( new EmptyContainer(supp::NO_POSITION, supp::NO_SIZE, color) )
, mLeftBlockSize(supp::Size(size.width/3, size.height))
, mMiddleBlockSize(supp::Size(size.width/3, size.height))
, mRightBlockSize(supp::Size(size.width/3, size.height))
{
    IContainerBase::addContainer( mLeftBlock, IContainerBase::POSITION_LEFT );
    IContainerBase::addContainer( mMiddleBlock, IContainerBase::POSITION_CENTER );
    IContainerBase::addContainer( mRightBlock, IContainerBase::POSITION_RIGHT );
}

void TripleContainer::setSize( const supp::Size& newSize) noexcept
{
    IContainerBase::setSize(newSize);
}

void TripleContainer::setLeft(IContainerBase* left) const noexcept
{
    if(nullptr != mLeftBlock && nullptr != left)
    {
        mLeftBlock->clear();
        mLeftBlock->addContainer(left, IContainerBase::POSITION_CENTER);
        left->setParent(mLeftBlock);
    }
    else
    {
        Serial.println("TripleContainer::setLeft(): nullptr");
    }
}

void TripleContainer::baseDraw() noexcept
{
    mLeftBlock->setSize( mLeftBlockSize );
    mMiddleBlock->setSize( mMiddleBlockSize );
    mRightBlock->setSize( mRightBlockSize );

    dbg::printPoint(IContainerBase::getPosition());
    
    IContainerBase::baseDraw();
}

void TripleContainer::setMiddle(IContainerBase* middle) const noexcept
{
    if(nullptr != mMiddleBlock && nullptr != middle)
    {
        mMiddleBlock->clear();
        mMiddleBlock->addContainer(middle, IContainerBase::POSITION_CENTER);
        middle->setParent(mMiddleBlock);
    }
    else
    {
        Serial.println("TripleContainer::setMiddle(): nullptr");
    }
    
}

void TripleContainer::setRight(IContainerBase* right) const noexcept
{
    if(nullptr != mRightBlock && nullptr != right)
    {
        mRightBlock->clear();
        mRightBlock->addContainer(right, IContainerBase::POSITION_CENTER);
        right->setParent(mRightBlock);
    }
    else
    {
        Serial.println("TripleContainer::setRight(): nullptr");
    }
}

void TripleContainer::setMiddleWidth(const uint8_t newWidth) noexcept
{
    mMiddleBlockSize = {newWidth, IContainerBase::getSize().height} ;

    mLeftBlockSize = {(IContainerBase::getSize().width-newWidth)/2, IContainerBase::getSize().height};
    mRightBlockSize = {(IContainerBase::getSize().width-newWidth)/2, IContainerBase::getSize().height};
}