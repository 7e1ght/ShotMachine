#ifndef LIST_CONTAINER_HPP
#define LIST_CONTAINER_HPP

#include "support/support.hpp"
#include "containers/IContainerBase.hpp"
#include "containers/TripleContainer.hpp"
#include "EmptyContainer.hpp"
#include "support/Vector.hpp"

class ListContainer
    : public IContainerBase
{
    private:
        using Item = TripleContainer;

        supp::Vector<Item*> mItemBuffer;

        Item* generateItem() noexcept;
        void baseDraw() const noexcept override;

        const uint8_t mDrawItemCount;
        const uint8_t mItemHeight;

        uint8_t mLowerIndex;
        uint8_t mHighIndex;
    public:
        void addItem(IContainerBase* leftBlock, IContainerBase* middleBlock = nullptr, IContainerBase* rightBlock = nullptr);

        void moveRangeUp() noexcept;
        void moveRangeDown() noexcept;

        ListContainer(const uint8_t drawItemCount, const supp::Point& position, const supp::Size& size, const supp::Color& color, IContainerBase* parent = nullptr);
};

#endif // LIST_CONTAINER_HPP