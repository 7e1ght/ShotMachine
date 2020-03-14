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
public:
    static Screen& getInstance();

    void print(
        const String& text, 
        const supp::Point& point,
        const supp::Color& bgColor,
        const supp::Color& fgColor,
        const int deg,
        const supp::FONT fontStyle
        );

    void fillRect(
        const supp::Point& upperLeft, 
        const supp::Point& lowerRight,
        const supp::Color& fgColor
        );

    void fillRoundRect(
        const supp::Point& upperLeft,
        const supp::Point& lowerRight,
        const supp::Color& fgColor
        );
};

#endif // SCREEN_H