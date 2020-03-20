
#include "support/TouchScreen.hpp"

TouchScreen::TouchScreen()
    : URTouch(cfg::touchscreen::TCLK_PIN
            , cfg::touchscreen::TCS_PIN
            , cfg::touchscreen::TDIN_PIN
            , cfg::touchscreen::DOUT_PIN
            , cfg::touchscreen::IRQ_PIN
            )
{
    InitTouch(PORTRAIT);
    setPrecision(PREC_MEDIUM);
}

TouchScreen& TouchScreen::getInstance()
{
    static TouchScreen instance;

    return instance;
}

const supp::Point TouchScreen::getTouch()
{
    supp::Point touchPoint = supp::NO_TOUCH;

    // while (supp::NO_TOUCH == touchPoint)
    // {
        URTouch::read();
        touchPoint = supp::Point(URTouch::getX(), URTouch::getY());
    // }
    
    return touchPoint;
}