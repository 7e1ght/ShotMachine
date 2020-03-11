#ifndef TEXT_CONTAINER_HPP
#define TEXT_CONTAINER_HPP

#include "support/support.hpp"
#include "containers/IContainerBase.hpp"

class TextContainer
    : public IContainerBase
{
public:
    TextContainer(
        const String& text,
        const supp::Point& position,
        const supp::Size& size, 
        const supp::Color& mainColor,
        const supp::Color& secondaryColor
        )
    : IContainerBase(position, size, mainColor)
    , mText(text)
    , mSecondaryColor(secondaryColor)
    {
    }

    void draw() const noexcept override;
    void handleTouch(const supp::Point& point) const noexcept override;

    void setText(const String& text) noexcept { mText = text; }
    const String& getText() const noexcept { return mText; }

    const supp::Color& getSecondaryColor() { return mSecondaryColor; }
    void setSecondaryColor(const supp::Color& secondaryColor) { mSecondaryColor = secondaryColor; }
private:
    using IContainerBase::addContainer;

    String mText;
    supp::Color mSecondaryColor;
};

#endif // TEXT_CONTAINER_HPP