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
        );

    void addContainer(IContainerBase* container, POSITION alingType = POSITION_RELATIVE);

    void caclPositionSizeAlign() noexcept;

    void clear() noexcept;

    void handleTouch(const supp::Point& touchPoint) noexcept override;
protected:
    void drawAllInside() const noexcept;
private:
    void drawElement() noexcept override;
    
    using BaseVector = supp::Vector<IContainerBase*>;
    BaseVector mContainers; 
};

#endif // EMPTY_CONTAINER_HPP