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
public:
    using Item = TripleContainer;

    ListContainer(const uint8_t drawItemCount, const supp::Point& position, const supp::Size& size, const supp::Color& color, IContainerBase* parent = nullptr);

    void addItem(Item* newItem) noexcept;
    void moveRangeDown() noexcept;
    void scrollDown() noexcept;
private:
    supp::Vector<Item*> mItemContainer;

    void baseDraw() noexcept override;

    const uint8_t mDrawItemCount;
    const uint8_t mItemHeight;

    uint8_t mLowerIndex;
    uint8_t mHighIndex;
};

#endif // LIST_CONTAINER_HPP