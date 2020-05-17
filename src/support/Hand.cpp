#include "support/Hand.hpp"

Hand::Hand()
: Stepper(cfg::hand::FULL_ROTATE_STEPS, cfg::hand::DIRECTION_PIN, cfg::hand::STEP_PIN)
, stepped(0)
{
    pinMode(cfg::hand::ENABLE_DISABLE_PIN, OUTPUT);
    digitalWrite(cfg::hand::ENABLE_DISABLE_PIN, HIGH);
    Stepper::setSpeed(60);
}

Hand& Hand::getInstance() noexcept
{
    static Hand hand;

    return hand;
}

void Hand::moveHandTo(const uint8_t glassId) noexcept
{   
    digitalWrite(cfg::hand::ENABLE_DISABLE_PIN, HIGH);

    Serial.println(String("stepped = ") + stepped);

    const int16_t stepToGlass = (cfg::hand::INITIAL_STEP + cfg::hand::DISTANCE_STEP * glassId ) - stepped;

    Serial.println(String("Step to glass = ") + stepToGlass);
    Serial.println(String("Glass id = ") + glassId);

    Stepper::step(stepToGlass);

    stepped += stepToGlass;

    digitalWrite(cfg::hand::ENABLE_DISABLE_PIN, LOW);
}