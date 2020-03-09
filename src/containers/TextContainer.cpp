#include "containers/TextContainer.hpp"

#include "support/debug.hpp"
#include "support/Screen.hpp"

void TextContainer::handleTouch(const supp::Point& point) const
{
    Serial.println("Text tapped.");
}

void TextContainer::draw() const
{
    Screen::getInstance().print(mText, IContainerBase::getPosition());
}