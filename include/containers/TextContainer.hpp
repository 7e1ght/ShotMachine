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
        IContainerBase* parent = nullptr,
        const supp::FONT fontStyle = supp::FONT::BIG,
        const int deg = 0
        )
    : IContainerBase(position, calcTextSize(text, fontStyle), mainColor, parent)
    , mText(text)
    , mSecondaryColor(secondaryColor)
    , mDeg(deg)
    , mFontStyle(fontStyle)
    {
    }

    void draw() const noexcept override;
    void handleTouch(const supp::Point& point) const noexcept override;

    void setText(const String& text) noexcept;
    const String& getText() const noexcept { return mText; }

    const supp::Color& getSecondaryColor() { return mSecondaryColor; }
    void setSecondaryColor(const supp::Color& secondaryColor) { mSecondaryColor = secondaryColor; }

    const int getDeg() { return mDeg; }
    void setDeg(const int newDeg) { mDeg = newDeg; }

    static const supp::Size getFontSize(supp::FONT fontStyle) noexcept 
    { 
        return fontStyle == supp::FONT::BIG ? supp::Size(16, 16) : supp::Size(8, 12); 
    }

    const supp::FONT getFontStyle() const noexcept { return mFontStyle; };
    void setFont(supp::FONT newFontStyle) noexcept;

    static const supp::Size calcTextSize(const String& text, supp::FONT fontStyle);
private:
    using IContainerBase::addContainer;

    String mText;
    supp::Color mSecondaryColor;

    int mDeg;
    supp::FONT mFontStyle;
};

#endif // TEXT_CONTAINER_HPP