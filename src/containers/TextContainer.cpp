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
            mFontStyle
        );
}

void TextContainer::setFont(supp::FONT newFontStyle)
{
    mFontStyle = newFontStyle;
    redraw();
    IContainerBase::setSize( calcTextSize(mText) );
}

void TextContainer::setText(const String& text) noexcept
{
    mText = text;
    redraw();
    IContainerBase::setSize( calcTextSize(mText) );
}

void TextContainer::redraw() const noexcept
{
    supp::overlap(IContainerBase::getPosition(), IContainerBase::getSize(), mSecondaryColor);
    draw();
}