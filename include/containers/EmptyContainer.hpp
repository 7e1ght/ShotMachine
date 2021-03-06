#ifndef EMPTY_CONTAINER_HPP
#define EMPTY_CONTAINER_HPP

#include "containers/IContainerBase.hpp"

#include "support/support.hpp"

class EmptyContainer
    : public IContainerBase
{
private:
    void baseDraw() noexcept override;
public:
EmptyContainer(
    const supp::Point& point, 
    const supp::Size& size,
    const supp::Color& color, 
    IContainerBase* parent = nullptr
    )
: IContainerBase(point, size, color, parent)
{}
};

#endif // EMPTY_CONTAINER_HPP