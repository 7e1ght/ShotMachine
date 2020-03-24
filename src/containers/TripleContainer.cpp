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

void TripleContainer::baseDraw() const noexcept
{
    IContainerBase::baseDraw();
}

void TripleContainer::setLeft(IContainerBase* left) const noexcept
{
    mLeftBlock->clear();
    mLeftBlock->addContainer(left, IContainerBase::POSITION_CENTER);
}

void TripleContainer::setMiddle(IContainerBase* middle) const noexcept
{
    mMiddleBlock->clear();
    middle->setSize( {10, 10} );
    mMiddleBlock->addContainer(middle, IContainerBase::POSITION_CENTER);
}

void TripleContainer::setRight(IContainerBase* right) const noexcept
{
    mRightBlock->clear();
    mRightBlock->addContainer(right, IContainerBase::POSITION_CENTER);
}