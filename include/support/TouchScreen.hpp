#ifndef TOUCH_HPP
#define TOUCH_HPP

#include <URTouch.h>

#include "config/config.hpp"
#include "support/support.hpp"

class TouchScreen
    : private URTouch
{
private: 
    TouchScreen();
public:
    static TouchScreen& getInstance();

    const supp::Point getTouch();
};

#endif // TOUCH_HPP