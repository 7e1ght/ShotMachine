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

        EmptyContainer mMainContainer;

        supp::Vector<Item*> mDrawItems;
        supp::Vector<Item*> mItemBuffer;

        void changeInsidePositionSize(Item* item);

        const uint8_t mDrawItemCount;
        const uint8_t mItemHeight;
    public:
        void addItem(Item* newItem);
        void addItem(IContainerBase* leftBlock, IContainerBase* middleBlock, IContainerBase* rightBlock);

        ListContainer(const uint8_t drawItemCount, const supp::Point& position, const supp::Size& size, const supp::Color& color, IContainerBase* parent);
};

#endif // LIST_CONTAINER_HPP