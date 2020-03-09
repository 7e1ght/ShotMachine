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
        const supp::Size& size
        )
    : IContainerBase(position, size)
    , mText(text)
    {
    }

    void draw() const override;
    void handleTouch(const supp::Point& point) const override;

    void setText(const String& text) { mText = text; }
    const String& getText() const { return mText; }

private:
    using IContainerBase::addContainer;

    String mText;
};

#endif // TEXT_CONTAINER_HPP