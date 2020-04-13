#include "support/Wrapper.hpp"

Wrapper::Wrapper(IContainerBase* wrappee, supp::Point position, supp::Size size, supp::Color color)
: IContainerBase(position, size, color)
, mWrapped(wrappee)
{
    if(nullptr != wrappee)
    {
        mWrapped->setParent(this);
    }
}

void Wrapper::drawElement() noexcept
{
    if( nullptr != IContainerBase::getParent())
    {
        mWrapped->draw();
    }
    else
    {
        Serial.println("Wrapper without parent");
    }
}

void Wrapper::handleTouch(const supp::Point& touchPoint) noexcept
{
    if(nullptr != mWrapped)
    {
        mWrapped->handleTouch(touchPoint);
    }
}

Wrapper::~Wrapper()
{
    delete mWrapped;
}