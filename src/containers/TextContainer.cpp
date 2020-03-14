#include "containers/TextContainer.hpp"

#include "support/debug.hpp"
#include "support/Screen.hpp"

void TextContainer::handleTouch(const supp::Point& point) const noexcept
{  
}

void TextContainer::draw() const noexcept
{
    Screen::getInstance().print(
            mText, 
            IContainerBase::getPosition(), 
            IContainerBase::getMainColor(), 
            mSecondaryColor, 
            mDeg,
        );
}

void TextContainer::setText(const String& text) noexcept
{
    mText = text;
    draw();
}