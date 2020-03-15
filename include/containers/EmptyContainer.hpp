#ifndef EMPTY_CONTAINER_HPP
#define EMPTY_CONTAINER_HPP

#include "containers/IContainerBase.hpp"

#include "support/support.hpp"

class EmptyContainer
    : public IContainerBase
{
public:
    EmptyContainer(
        const supp::Point& point, 
        const supp::Size& size,
        const supp::Color& color, 
        IContainerBase* parent = nullptr
        )
    : IContainerBase(point, size, color, parent)
    {}

    void draw() const override;
};

#endif // EMPTY_CONTAINER_HPP