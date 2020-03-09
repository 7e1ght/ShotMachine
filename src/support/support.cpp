#include "support/support.hpp"
#include "support/Screen.hpp"

const supp::Size supp::calcTextSize(const String& text) noexcept
{
    return { Screen::getInstance().getFontSize().width * text.length(), Screen::getInstance().getFontSize().height};
}