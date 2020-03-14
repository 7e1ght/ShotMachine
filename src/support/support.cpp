#include "support/support.hpp"
#include "support/Screen.hpp"

void supp::overlap(const supp::Point& position, const supp::Size& size, const supp::Color color)
{
    Screen::getInstance().fillRect(position, position + size, color);
}