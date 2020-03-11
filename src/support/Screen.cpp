#include "support/Screen.hpp"
#include "support/debug.hpp"

extern uint8_t BigFont[]; // Do not forget change flag

Screen::Screen()
    : UTFT(cfg::display::DISPLAY_MODEL, cfg::display::RS_PIN, cfg::display::WR_PIN, cfg::display::CS_PIN, cfg::display::RST_PIN)
    , isBigFont(true)
{
    UTFT::InitLCD(PORTRAIT);
    UTFT::clrScr();
    UTFT::setFont(BigFont);
}

Screen& Screen::getInstance()
{
    static Screen instance;

    return instance; 
}

const supp::Size Screen::getFontSize() const noexcept
{
    supp::Size res;
    if(true == isBigFont)
    {
        res = {16, 16};
    }
    else
    {
        res = {12, 8};
    }
    
    return res;
}

void Screen::fillRect(
        const supp::Point& upperLeft, 
        const supp::Point& lowerRight, 
        const supp::Color& color
    )
{
    UTFT::setColor(color.red, color.green, color.blue);
    UTFT::fillRect(upperLeft.x, upperLeft.y, lowerRight.x, lowerRight.y);
}

void Screen::print(
        const String& text, 
        const supp::Point& point,
        const supp::Color& fgColor,
        const supp::Color& bgColor
    )
{
    UTFT::setColor(fgColor.red, fgColor.green, fgColor.blue);
    UTFT::setBackColor(bgColor.red, bgColor.green, bgColor.blue);
    UTFT::print(text.c_str(), point.x, point.y);
}