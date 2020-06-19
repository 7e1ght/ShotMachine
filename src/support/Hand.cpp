#include "support/Hand.hpp"

Hand::Hand()
: Stepper(cfg::hand::FULL_ROTATE_STEPS, cfg::hand::DIRECTION_PIN, cfg::hand::STEP_PIN)
{
    pinMode(cfg::hand::ENABLE_DISABLE_PIN, OUTPUT);
    digitalWrite(cfg::hand::ENABLE_DISABLE_PIN, LOW);
    Stepper::setSpeed(20);
}

Hand& Hand::getInstance() noexcept
{
    static Hand hand;

    return hand;
}