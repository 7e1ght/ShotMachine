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

    const supp::Point getTouch() const noexcept;
    const supp::Point waitForTouch() const noexcept;
    bool readyTouch() const noexcept { return getTouch() != supp::NO_TOUCH; } 
};

#endif // TOUCH_HPP