#ifndef TRIPLE_CONTAINER_HPP
#define TRIPLE_CONTAINER_HPP

#include "support/support.hpp"
#include "IContainerBase.hpp"

class TripleContainer 
: public IContainerBase
{
private:
    IContainerBase* mLeftBlock;
    IContainerBase* mMiddleBlock;
    IContainerBase* mRightBlock;

public:
    TripleContainer(
        const supp::Point& point, 
        const supp::Size& size,
        const supp::Color& color, 
        IContainerBase* parent = nullptr
        );

    virtual void setSize( const supp::Size& newSize) noexcept override;

    virtual void baseDraw() noexcept;

    void resizeContent() noexcept;

    void setLeft(IContainerBase* left) const noexcept;
    void setMiddle(IContainerBase* middle) const noexcept;
    void setRight(IContainerBase* right) const noexcept;
};

inline void TripleContainer::resizeContent() noexcept
{
    supp::Size tSize = { IContainerBase::getSize().width/3, IContainerBase::getSize().height };

    mLeftBlock->setSize( tSize );
    mMiddleBlock->setSize( tSize );
    mRightBlock->setSize( tSize);
}

#endif // TRIPLE_CONTAINER_HPP