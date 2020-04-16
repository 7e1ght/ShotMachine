#ifndef TRIPLE_CONTAINER_HPP
#define TRIPLE_CONTAINER_HPP

#include "support/support.hpp"
#include "containers/EmptyContainer.hpp"

class TripleContainer 
: public IContainerBase
{
private:
    EmptyContainer* mLeftBlock;
    EmptyContainer* mMiddleBlock;
    EmptyContainer* mRightBlock;

    supp::Size mLeftBlockSize;
    supp::Size mMiddleBlockSize;
    supp::Size mRightBlockSize;

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

    void clear() noexcept;

    void setLeft(IContainerBase* left, IContainerBase::POSITION pos = IContainerBase::POSITION_CENTER) const noexcept;
    void setMiddle(IContainerBase* middle, IContainerBase::POSITION pos = IContainerBase::POSITION_CENTER) const noexcept;
    void setRight(IContainerBase* right, IContainerBase::POSITION pos = IContainerBase::POSITION_CENTER) const noexcept;

    void setLeftWidth(const uint8_t newWidth) noexcept;
    void setMiddleWidth(const uint8_t newWidth) noexcept;
    void setRightWidth(const uint8_t newWidth) noexcept;
};

inline void TripleContainer::resizeContent() noexcept
{
    supp::Size tSize = { IContainerBase::getSize().width/3, IContainerBase::getSize().height };

    mLeftBlockSize = tSize;
    mMiddleBlockSize = tSize;
    mRightBlockSize = tSize;
}

#endif // TRIPLE_CONTAINER_HPP