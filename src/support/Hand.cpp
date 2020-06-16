#include "support/Hand.hpp"

Hand::Hand()
: Stepper(cfg::hand::FULL_ROTATE_STEPS, cfg::hand::DIRECTION_PIN, cfg::hand::STEP_PIN)
{
    Stepper::setSpeed(60);
}

Hand& Hand::getInstance() noexcept
{
    static Hand hand;

    return hand;
}