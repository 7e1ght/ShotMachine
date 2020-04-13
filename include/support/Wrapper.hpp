#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#include "containers/IContainerBase.hpp"

class Wrapper
: public IContainerBase
{
public:
    Wrapper(IContainerBase* wrappee, supp::Point position, supp::Size size, supp::Color color);

    void drawElement() noexcept override;
    void handleTouch(const supp::Point& touchPoint) noexcept override;

    ~Wrapper();
private:
    IContainerBase* mWrapped;
};

#endif // WRAPPER_HPP