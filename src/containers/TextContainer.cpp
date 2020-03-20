#include "containers/TextContainer.hpp"

#include "support/debug.hpp"
#include "support/Screen.hpp"

void TextContainer::handleTouch(const supp::Point& point) const noexcept
{  
}

void TextContainer::baseDraw() const noexcept
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

    IContainerBase::setSize( calcTextSize(mText, mFontStyle) );   
}

void TextContainer::setText(const String& text) noexcept
{
    mText = text;

    IContainerBase::setSize( calcTextSize(mText, mFontStyle) );
}

const supp::Size TextContainer::calcTextSize(const String& text, const supp::FONT fontStyle)
{ 
    supp::Size fontSize = getFontSize(fontStyle);
    return supp::Size(fontSize.width * text.length(), fontSize.height); 
}