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
        const supp::Point& point
        )
    {
        UTFT::print(text.c_str(), point.x, point.y);
    }

    void setBackColor(const supp::Color& bgColor)
    {
        UTFT::setBackColor(bgColor.red, bgColor.green, bgColor.blue);
    }

    void setColor(const supp::Color& color)
    {
        UTFT::setColor(color.red, color.green, color.blue);
    }

    void fillRect(
        const supp::Point& upperLeft, 
        const supp::Point& lowerRight
        )
    {
        UTFT::fillRect(upperLeft.x, upperLeft.y, lowerRight.x, lowerRight.y);
    }

    const supp::Size getFontSize() const noexcept;

};

#endif // SCREEN_H