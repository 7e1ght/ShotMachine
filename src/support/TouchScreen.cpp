
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

const supp::Point TouchScreen::getTouch() const noexcept
{
    supp::Point touchPoint = supp::NO_TOUCH;

    URTouch::read();
    touchPoint = supp::Point(URTouch::getX(), URTouch::getY());
    
    return touchPoint;
}

const supp::Point TouchScreen::waitForTouch() const noexcept
{
    supp::Point touchPoint = getTouch();

    while (supp::NO_TOUCH == touchPoint)
    {
        touchPoint = getTouch();
    }
    
    return touchPoint;
}