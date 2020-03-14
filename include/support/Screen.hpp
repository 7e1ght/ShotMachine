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
    bool isBigFont;
    void setFont(uint8_t* newFont);
public:
    static Screen& getInstance();

    void print(
        const String& text, 
        const supp::Point& point,
        const supp::Color& bgColor,
        const supp::Color& fgColor,
        const int deg,
        uint8_t* font
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


    const supp::Size getFontSize() const noexcept;
};

#endif // SCREEN_H