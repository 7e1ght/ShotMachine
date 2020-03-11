#ifndef SCREEN_H
#define SCREEN_H

#include <UTFT.h>

#include "config/config.hpp"
#include "support/support.hpp"

class Screen 
    : private UTFT
{
private:
    Screen();
    const bool isBigFont;
public:
    static Screen& getInstance();

    void print(
        const String& text, 
        const supp::Point& point,
        const supp::Color& bgColor,
        const supp::Color& fgColor
        );

    void fillRect(
        const supp::Point& upperLeft, 
        const supp::Point& lowerRight,
        const supp::Color& fgColor
        );

    const supp::Size getFontSize() const noexcept;
};

#endif // SCREEN_H