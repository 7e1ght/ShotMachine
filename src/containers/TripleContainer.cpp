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

void TripleContainer::setLeft(IContainerBase* left, IContainerBase::POSITION pos) const noexcept
{
    if(nullptr != mLeftBlock && nullptr != left)
    {
        mLeftBlock->clear();
        mLeftBlock->addContainer(left, pos);
        left->setParent(mLeftBlock);
    }
}

void TripleContainer::clear() noexcept
{
    mContainers.clear();
}

void TripleContainer::baseDraw() noexcept
{
    mLeftBlock->setSize( mLeftBlockSize );
    mMiddleBlock->setSize( mMiddleBlockSize );
    mRightBlock->setSize( mRightBlockSize );
    
    IContainerBase::baseDraw();
}

void TripleContainer::setMiddle(IContainerBase* middle, IContainerBase::POSITION pos) const noexcept
{
    if(nullptr != mMiddleBlock && nullptr != middle)
    {
        mMiddleBlock->clear();
        mMiddleBlock->addContainer(middle, pos);
        middle->setParent(mMiddleBlock);
    }
}

void TripleContainer::setRight(IContainerBase* right, IContainerBase::POSITION pos) const noexcept
{
    if(nullptr != mRightBlock && nullptr != right)
    {
        mRightBlock->clear();
        mRightBlock->addContainer(right, pos);
        right->setParent(mRightBlock);
    }
}

void TripleContainer::setMiddleWidth(const uint8_t newWidth) noexcept
{
    mMiddleBlockSize = {newWidth, IContainerBase::getSize().height} ;

    mLeftBlockSize = {(IContainerBase::getSize().width-newWidth)/2, IContainerBase::getSize().height};
    mRightBlockSize = {(IContainerBase::getSize().width-newWidth)/2, IContainerBase::getSize().height};
}