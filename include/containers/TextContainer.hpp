#ifndef TEXT_CONTAINER_HPP
#define TEXT_CONTAINER_HPP

#include "support/support.hpp"
#include "containers/IContainerBase.hpp"
#include "support/Screen.hpp"

class TextContainer
    : public IContainerBase
{
public:
    TextContainer(
        const String& text,
        const supp::Point& position,
        const supp::Color& mainColor,
        const supp::Color& secondaryColor,
        const int deg = 0
        )
    : IContainerBase(position, {Screen::getInstance().getFontSize().width * text.length(), Screen::getInstance().getFontSize().height}, mainColor)
    , mText(text)
    , mSecondaryColor(secondaryColor)
    , mDeg(deg)
    {
    }

    void draw() const noexcept override;
    void handleTouch(const supp::Point& point) const noexcept override;

    void setText(const String& text) noexcept { mText = text; }
    const String& getText() const noexcept { return mText; }

    const supp::Color& getSecondaryColor() { return mSecondaryColor; }
    void setSecondaryColor(const supp::Color& secondaryColor) { mSecondaryColor = secondaryColor; }

    const int getDeg() { return mDeg; }
    void setDeg(const int newDeg) { mDeg = newDeg; }
private:
    using IContainerBase::addContainer;

    String mText;
    supp::Color mSecondaryColor;

    int mDeg;
};

#endif // TEXT_CONTAINER_HPP