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