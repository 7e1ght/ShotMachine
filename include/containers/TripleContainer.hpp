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

        virtual void baseDraw() const noexcept;
    public:
        TripleContainer(
            const supp::Point& point, 
            const supp::Size& size,
            const supp::Color& color, 
            IContainerBase* parent = nullptr
            );

        void setLeft(IContainerBase* left) const noexcept;
        void setMiddle(IContainerBase* middle) const noexcept;
        void setRight(IContainerBase* right) const noexcept;
};

#endif // TRIPLE_CONTAINER_HPP